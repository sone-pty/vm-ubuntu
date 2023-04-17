#!/bin/bash

pids=$(pgrep -f './Entry')
if [ -n "$pids" ]; then
  echo "$pids" | xargs kill -9
fi

pids=$(pgrep -f './Logservice')
if [ -n "$pids" ]; then
  echo "$pids" | xargs kill -9
fi