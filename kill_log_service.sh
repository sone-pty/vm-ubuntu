#!/bin/bash

#ps aux | grep "./Logservice" | awk '{print $2}' | xargs kill -9

pgrep -f './Logservice' | xargs kill -9