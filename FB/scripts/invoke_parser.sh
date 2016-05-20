#!/bin/bash

parser=../src/parser

if [ ! -f $parser ]; then
	echo "Please run make first in src directory"
	exit 1
fi

function usage {
	echo "Usage: "
	echo "./invoke_parser -i input_file -o output_file"
}

while getopts "i:o:" opt; do
	case ${opt} in
		i )
		  input_file="$OPTARG"
		;;
		o )
		  output_file="$OPTARG"
		;;
		\? )
		   usage
		   exit 1
		;;
	   	: )
		  echo "Error: Invalid option: $OPTARG requires an argument" 1>&2
		  usage
		  exit 1
		;;
		* )
		  echo "Error: Unimplemented option: -$OPTARG" 1>&2
		  usage
		  exit 1
	esac
done
shift $((OPTIND -1))

if [ -z $input_file ]; then
	echo "File not specified"
	usage
	exit 1
fi

if [ -z $output_file ]; then
	echo "File not specified"
	usage
	exit 1
fi

if [ ! -f $input_file ]; then
	echo "Input file does not exist" 1>&2
	exit 1
fi

echo "Invoking parser on input file $input_file"
`$parser $input_file $output_file`
if [ $? -eq 0 ]; then
	echo "Output at $output_file"
fi
exit
