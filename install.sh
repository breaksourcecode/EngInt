#!/usr/bin/bash

CC=gcc
CXX=g++
QMAKE=qmake
PACKAGE_NAME=install.sh
NAME="youdao"
BIN_PATH="/usr/local/bin"
chk_user()
{
	echo ""
	echo "Checkin script user ..."
	if [ $(whoami) = "root" ]; then
		echo "Failed."
		echo "Root user not allowed, please run this script as a regular user."
		echo "Exiting ..."
		exit 1
	fi
	echo "Passed"
}

chk_root()
{
	echo ""
	echo "Checkin for a root access..."
	s=`sudo cat /etc/issue`
	if [ -n "$s" ]; then
		return 
	fi
	echo "Authorization failed."
	echo "Exiting ..."
	exit 1
}

usage()
{
	N=$(basename "$0")
	echo "Usage: [sudo] $N "  >&2
	exit 1
}


exit_qmake=`qmake`
if [ -z $(exit_qmake) ]; then
	echo "qmake do not exist, please install qmake..."	
fi

cd ./youdao
echo ""
echo "clean youdao ..."
make clean
rm -f -r  $(NAME)
echo "clean youdao finished!"
echo ""
echo "qmake youdao ..."
qmake youdao.pro
echo "qmake youdao finished!"
echo ""
echo "make youdao ..."
make 
echo "make youdao finished!"
echo ""

chk_root

cur_path=$(pwd)
exe_youdao="${cur_path}/${NAME}"
#ln -s youdao
youdao=`ls -l ${BIN_PATH} | grep youdao`
if [ -z ${youdao} ] ; then
	cd "${BIN_PATH}"
	sudo  ln -s $exe_youdao "${BIN_PATH}/youdao" 
	echo ""
	echo "youdao installed!"
fi

#setup PYTHONPATH
python_path=`cat /home/$(whoami)/.xinitrc | grep EngInt`
echo $cur_path
if [ -z "${python_path}" ]; then
	echo ""
	echo "set PYTHONPATH..."
	echo "export PYTHONPATH=$PYTHONPATH:$cur_path" >> /home/$(whoami)/.xinitrc
	source /home/$(whoami)/.xinitrc
	echo "set finished!"
fi





