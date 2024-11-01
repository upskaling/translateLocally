FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
    && apt-get install -y git wget cmake build-essential libpcre++-dev libarchive-dev libpcre2-dev ccache libunwind-dev libgoogle-perftools-dev libxkbcommon-x11-dev libvulkan-dev libgl1-mesa-dev qt6-base-dev qt6-base-dev-tools qt6-tools-dev qt6-tools-dev-tools qt6-l10n-tools qt6-translations-l10n libqt6svg6-dev \
    && wget -qO- "https://apt.repos.intel.com/intel-gpg-keys/GPG-PUB-KEY-INTEL-SW-PRODUCTS.PUB" | apt-key add - \
    && sh -c "echo deb https://apt.repos.intel.com/mkl all main > /etc/apt/sources.list.d/intel-mkl.list" \
    && apt-get update -o Dir::Etc::sourcelist="/etc/apt/sources.list.d/intel-mkl.list" \
    && apt-get install -y --no-install-recommends intel-mkl-64bit-2020.0-088 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . /app

ARG BUILD_JOB=4

RUN mkdir build \
    && cd build \
    && cmake .. \
    && cmake --build . -j${BUILD_JOB}

CMD ["/bin/bash", "-c"]
