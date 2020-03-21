FROM ubuntu

# replace shell with bash so we can source files
RUN rm /bin/sh && ln -s /bin/bash /bin/sh

# Installing basic tools and settings
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
    # Basic tools
    curl \
    locales \
    python \
    python-pip \
    # Build tools
    gcc-arm-none-eabi \
    ninja-build \
    # VNC tools
    net-tools \
    x11vnc \
    xvfb \
    novnc \
    libx11-6 \
    # Settings
    && locale-gen en_US.UTF-8 \
    && pip install watchdog autopep8

# install node and npm
ENV NVM_DIR /root/.nvm
ENV NODE_VERSION 12.16.1
RUN curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.35.3/install.sh | bash && \
    source $NVM_DIR/nvm.sh \
    && nvm install $NODE_VERSION \
    && nvm alias default $NODE_VERSION \
    && nvm use default
# add node and npm to path so the commands are available
ENV NODE_PATH $NVM_DIR/v$NODE_VERSION/lib/node_modules
ENV PATH $NVM_DIR/versions/node/v$NODE_VERSION/bin:$PATH

# Get CMake
RUN mkdir cmake && \
    cd cmake && \
    curl -L -o cmake-3.16.0-rc2-Linux-x86_64.sh  https://github.com/Kitware/CMake/releases/download/v3.16.0-rc2/cmake-3.16.0-rc2-Linux-x86_64.sh && \
    chmod +x cmake-3.16.0-rc2-Linux-x86_64.sh && \
    ./cmake-3.16.0-rc2-Linux-x86_64.sh --skip-license && \
    mv ./bin/* /usr/local/bin && \
    mv ./man/* /usr/local/man && \
    mv ./share/* /usr/local/share && \
    cd .. && \
    rm -rf cmake 

# install xpm and tools
RUN npm install --global xpm@latest && xpm install --global @xpack-dev-tools/qemu-arm@latest
