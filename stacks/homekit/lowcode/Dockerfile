FROM nodered/node-red:latest

USER root

RUN apk add --no-cache sudo openssh

RUN echo "node-red ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

USER node-red

RUN npm config set update-notifier false