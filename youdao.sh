#!/usr/bin/bash

cur_path=$(pwd)

#python $cur_path/com/engint/tools/server.py  &


start()
{
	echo ""
	exist_server=`ps aux | grep /com/engint/tools/server.py | grep -v grep | awk '{print $2}'`
	if [ -z $exist_server ];then
		python $cur_path/com/engint/tools/server.py  &
	fi

	exist_youdao=`ps aux | grep /usr/local/bin/youdao | grep -v grep | awk '{print $2}'`
	if [ -z $exist_youdao ];then
		youdao &
	fi
}

start
