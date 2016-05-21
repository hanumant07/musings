#!/bin/bash

if [ ! -d "scripts" ]; then
	echo "Please run from root directory."
	usage
	exit 1
fi

mkdir -p tests
if [ $? -ne 0 ]; then
	echo "failed to create test diretory"
	exit 1
fi

mkdir -p src/obj
if [ $? -ne 0 ]; then
	echo "failed to create obj directory"
	exit 1
fi

export PARSER_ENV_SETUP=DONE

