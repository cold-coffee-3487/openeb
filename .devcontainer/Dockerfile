FROM mcr.microsoft.com/devcontainers/cpp:ubuntu-22.04

ENV DEBIAN_FRONTEND=noninteractive

# 1. Install OpenEB System Dependencies
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    git \
    pkg-config \
    libboost-all-dev \
    libhdf5-dev \
    libopencv-dev \
    libglew-dev \
    libglfw3-dev \
    libeigen3-dev \
    libcanberra-gtk-module \
    libcanberra-gtk3-module \
    libusb-1.0-0-dev \
    libprotobuf-dev \
    protobuf-compiler \
    ffmpeg \
    python3-dev \
    python3-pip \
    python3-pybind11 \
    && rm -rf /var/lib/apt/lists/*

# 2. Clone and build OpenEB
WORKDIR /tmp
RUN git clone --branch main https://github.com/prophesee-ai/openeb.git --depth 1 \
    && mkdir openeb/build && cd openeb/build \
    && cmake .. \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_TESTING=OFF \
        -DPYTHON3_EXECUTABLE=/usr/bin/python3 \
    && cmake --build . --config Release -j$(nproc) \
    && cmake --build . --target install \
    && cd /tmp && rm -rf openeb

# Set runtime library paths for OpenEB
ENV LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH
ENV HDF5_PLUGIN_PATH=/usr/local/lib/hdf5/plugin:$HDF5_PLUGIN_PATH
