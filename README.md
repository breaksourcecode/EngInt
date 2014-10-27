EngInt
======
A English interpret software. The words can be synchronized to the network.

![image](https://github.com/breaksourcecode/EngInt/blob/master/screenshots/2014-10-10-185454_588x339_scrot.png)
How To Use:
-----------------------------------------------------------------------
Download  EngInt

Step 1 : Install Qt4 Library  And Python 3.0 More
-----------------------------------------------------------------------
download Qt 4.8 from http://qt-project.org/downloads

install qt

Step 2 : Test your qmake
-----------------------------------------------------------------------
$qmake

If the following information is displayed,  the qmake is installed. Otherwise,
you can install qmake using pacman or apt-get.

Usage: qmake [mode] [options] [files]
QMake has two modes, one mode for generating project files based on
some heuristics, and the other for generating makefiles. Normally you
shouldn't need to specify a mode, as makefile generation is the default
mode for qmake, but you may use this to test qmake on an existing project
... ...

Step 3 : Copy EngInt To Any Directory And Enter The Main Directory
-----------------------------------------------------------------------
You will see the following dirs and files

com  install.sh  README.md  uninstall.sh  youdao  youdao.sh

Among them, com is a part of server, and youdao represents the client. The
other files are used to install or uninstall youdao.

Step 4 : Install Server And Compile Client
-----------------------------------------------------------------------
$install.sh

Maybe needs root privilege.

Step 5 : Execute Youdao
-----------------------------------------------------------------------
It is very easy to start youdao.

$./youdao.sh

youdao.sh just was executed once.And then if you want to restart youdao , you just
$youdao in the terminal.

Now enjoy yourself!





