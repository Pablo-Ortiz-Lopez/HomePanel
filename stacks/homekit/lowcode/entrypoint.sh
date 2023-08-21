#!/bin/bash

cd /data
npm install
cd -

/usr/src/node-red/entrypoint.sh $@