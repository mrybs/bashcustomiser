#!/bin/bash

#----------------------#
#---Created by mrybs---#
#---GitHub: /mrybs/----#
#---License: GPL-3.0---#
#----------------------#

printf "\033[0;35m" #sets magneta foreground color

clear

printf "#----------------------#\n"
printf "#---Created by mrybs---#\n"
printf "#---GitHub: /mrybs/----#\n"
printf "#---License: GPL-3.0---#\n"
printf "#----------------------#\n\n"

printf "\033[0m" #sets default color

whoami="$(whoami)"

if [[ "$whoami" = "root" ]]; then
    #pacman (arch)
        pacman -Sy
        pacman -S qt make git zip unzip
        unzip BashCustomisersV101.zip
        cd BashCustomisersV101
        qmake BashCustomiser.pro
        make
        chmod a+x .

    #apt-get (debian)
        apt-get update -y
        apt-get install qt5-default build-essential git zip unzip
        unzip BashCustomisersV101.zip
        cd BashCustomisersV101
        qmake BashCustomiser.pro
        make
        chmod a+x .

    mv ./BashCusomiser /bin/bashcustomiser
    printf "\nWrite\nbashcustomiser\n for run program\n\n"
else
    printf "\033[0;31mCritical error\033[0m: $whoami user cannot install the BashCusomiser. \nLaunch the installer on behalf on the super-user\n\n"
fi
