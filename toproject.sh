#!/bin/sh
usage(){
	echo "usage toproject.sh:" > /dev/stderr
	echo "Move / copy libknsll to your project diretory" > /dev/stderr
	echo "<this script> <action> <project dir>" > /dev/stderr
	echo "Actions: install | update" > /dev/stderr
	echo "Moves / copies libknsll to <project dir>/" > /dev/stderr
}
if [ $# -ne 2 ]
then
	usage
	exit 1
fi
if [ "$1" = "install" ]
then
	cp -r libknsll $2/
elif [ "$1" = "update" ]
then
	rm -rf $2/libknsll
	cp -r libknsll $2/
else
	echo "No valid action! -> $1" > /dev/stderr
	usage
	exit 1
fi
exit 0
