EngInt
======
A English interpret software. The words can be synchronized to the network.


How To Use:
-----------------------------------------------------------------------
Download  

Step 1 : Install Qt4 library
-----------------------------------------------------------------------
download Qt 4.8 from http://qt-project.org/downloads

install qt

Step 2 : Test your qmake
-----------------------------------------------------------------------
$qmake

If the following information is displayed,  the qmake is installed.

Usage: qmake [mode] [options] [files]
QMake has two modes, one mode for generating project files based on
some heuristics, and the other for generating makefiles. Normally you
shouldn't need to specify a mode, as makefile generation is the default
mode for qmake, but you may use this to test qmake on an existing project
... ...

Step 3 : Copy EngInt to any directory and enter the main dir
------------
You will see the following dirs and files

com  install.sh  README.md  uninstall.sh  youdao  youdao.sh

Among them, com is a part of server, and youdao represents the client. The
other files are used to install or uninstall youdao.

Step 4 : Install Server And Compile Client
------------
$install.sh
Maybe need root privileges.

Step 5 : Execute Our Youdao
-------------
It is very easy to start youdao.
$./youdao.sh
Youdao.sh just was executed once.And then if you want to restart youdao , you just
$youdao in the terminal.

Now enjoy it.





