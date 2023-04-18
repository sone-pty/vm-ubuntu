#!/bin/bash

set -e

# build proto
protoc --cpp_out=. ./Logservice/LogMessage.proto
protoc --cpp_out=. ./test/*.proto
protoc --cpp_out=. ./game/proto/*.proto