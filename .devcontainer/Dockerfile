FROM ubuntu

RUN apt-get update && apt-get install -y curl

# replace shell with bash so we can source files
RUN rm /bin/sh && ln -s /bin/bash /bin/sh

# install node and npm
RUN curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.35.3/install.sh | bash
ENV NVM_DIR /root/.nvm
ENV NODE_VERSION 12.16.1
RUN source $NVM_DIR/nvm.sh \
    && nvm install $NODE_VERSION \
    && nvm alias default $NODE_VERSION \
    && nvm use default
# add node and npm to path so the commands are available
ENV NODE_PATH $NVM_DIR/v$NODE_VERSION/lib/node_modules
ENV PATH $NVM_DIR/versions/node/v$NODE_VERSION/bin:$PATH

# install xpm
RUN npm install -global xpm@latest

# install xpack tools
RUN xpm install --global @xpack-dev-tools/qemu-arm@latest @xpack-dev-tools/arm-none-eabi-gcc@latest

# install dependencies
RUN apt-get install -y libx11-6

# Install vnc stuff
RUN apt-get install -y net-tools x11vnc xvfb novnc

# Install vnc test stuff
RUN apt-get install -y x11-apps

# Locale setting
RUN apt-get install -y locales && locale-gen en_US.UTF-8
RUN echo "LANG=en_US.utf-8" >> /etc/environment "LC_ALL=en_US.utf-8" >> /etc/environment

WORKDIR /home/workspace