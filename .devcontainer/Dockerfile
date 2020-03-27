FROM ubuntu

# replace shell with bash so we can source files
RUN rm /bin/sh && ln -s /bin/bash /bin/sh

# Installing basic tools and settings
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y \
    # Basic tools
    curl \
    locales \
    python3 \
    python3-pip \
    python3-tk \
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
    && locale-gen en_US.UTF-8

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

# install python tools
RUN pip3 install watchdog autopep8 matplotlib

# Setup VNC Services
COPY xvfb /etc/init.d/xvfb
COPY x11vnc /etc/init.d/x11vnc
COPY novnc /etc/init.d/novnc
ENV DISPLAY ":1.0"
RUN mkdir ~/.vnc && x11vnc -storepasswd embedit ~/.vnc/passwd && \
    chmod +x /etc/init.d/xvfb /etc/init.d/x11vnc /etc/init.d/novnc