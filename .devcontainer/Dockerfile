FROM ubuntu:22.04

RUN apt update && \
    apt install -y \
    git \
    gdb \
    g++ \
    cmake \
    libgtest-dev \
    && apt clean


RUN git config --global user.email "robboeckermann@gmail.com"
RUN git config --global user.name "Rob Boeckermann"
