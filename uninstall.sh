#!/usr/bin/bash

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

chk_root

exist_youdao=`ls /usr/local/bin | grep youdao`
if [ -n ${exist_youdao} ];then
	echo ""
	echo "remove softlink of youdao..."
	sudo rm -r -f /usr/local/bin/youdao
	echo "removed!"
fi

python_path=`echo $PYTHONPATH | grep EngInt`
if [ -n python_path ]; then
	echo ""
	echo "delete EngInt ..."
	sed /EngInt/d /home/$(whoami)/.xinitrc >> .xinitrc
	echo "deleted!"
fi












