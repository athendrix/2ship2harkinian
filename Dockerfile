FROM ubuntu:24.04 as build

RUN apt update && \
apt install -y gcc g++ git cmake ninja-build lsb-release libsdl2-dev \
libpng-dev libsdl2-net-dev zipcmp zipmerge ziptool \
nlohmann-json3-dev libtinyxml2-dev libspdlog-dev libboost-dev libopengl-dev \
build-essential libusb-dev libusb-1.0-0-dev libglew-dev curl file wget
# libzip-dev

WORKDIR /src

COPY . .

RUN mkdir deps && \
wget https://github.com/nih-at/libzip/releases/download/v1.10.1/libzip-1.10.1.tar.gz && \
tar -xzf libzip-1.10.1.tar.gz -C deps && \
cd deps/libzip-1.10.1 && \
mkdir -p build && \
cd build && \
cmake .. -DENABLE_COMMONCRYPTO=OFF -DENABLE_GNUTLS=OFF -DENABLE_MBEDTLS=OFF -DENABLE_OPENSSL=OFF && \
make && \
make install && \
cp -av /usr/local/lib/libzip* /lib/x86_64-linux-gnu/

RUN cmake --no-warn-unused-cli -H. -Bbuild-cmake -GNinja -DCMAKE_BUILD_TYPE:STRING=Release && \
cmake --build build-cmake --config Release --target Generate2ShipOtr -j3

RUN cmake --no-warn-unused-cli -H. -Bbuild-cmake -GNinja -DCMAKE_BUILD_TYPE:STRING=Release -DBUILD_REMOTE_CONTROL=1 && \
cmake --build build-cmake --config Release -j3 && \
(cd build-cmake && cpack -G External)

FROM scratch
COPY --from=build /src/build-cmake/*.appimage /