FROM --platform=$BUILDPLATFORM ubuntu:latest as build

# Main dependencies
RUN apt-get update && \
    apt-get install -y git build-essential python3 cmake ninja-build

WORKDIR /emsdk
RUN git clone https://github.com/emscripten-core/emsdk.git .
RUN git pull

RUN ./emsdk install latest && \
    ./emsdk activate latest && \
    echo ". /emsdk/emsdk_env.sh" >> ~/.bashrc && \
    . ~/.bashrc

WORKDIR /raylib
RUN git clone https://github.com/raysan5/raylib.git .

# Book dependencies (putting those here so we don't rebuild scratch every time we add a dependency)
# Tools we'll use while building packages + OpenGL support + SDL2 support
# RUN apt-get install -y \
#     procps gcc vim libz-dev autoconf libtool \
#     libgles2-mesa-dev \
#     libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev \
#     curl

RUN apt-get install -y libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev

RUN mkdir build
RUN cd /emsdk && . /emsdk/emsdk_env.sh && cd /raylib && emcmake cmake -S . -B build "-DPLATFORM=Web"
RUN cd /emsdk && . /emsdk/emsdk_env.sh && cd /raylib && cmake --build build --target install

WORKDIR /app

COPY . .

RUN cd /emsdk && . /emsdk/emsdk_env.sh && cd /app && ./scripts/generate.sh
RUN cd /emsdk && . /emsdk/emsdk_env.sh && cd /app && ./scripts/build.sh

FROM node:18.3.0

WORKDIR /app

COPY --from=build /app/public /app

EXPOSE 3000
ENTRYPOINT [ "npx", "serve", "-s", "." ]
