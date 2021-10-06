BashCustomiser guide

This application will help you to easily customize the appearance of the 
bash program. From the possibilities:

1)There are 15 colors for the line before entering the command and 
 for the text. Here is the list:
    white, 
    red, 
    green, 
    yellow, 
    blue, 
    magneta, 
    gray, 
    light red, 
    light green, 
    light yellow, 
    light blue, 
    light magneta, 
    light gray, 
        
2)You can use some values, they are listed below:
    username, 
    hostname, 
    data, 
    time 24h hh:mm:ss, 
    time 12h hh:mm:ss, 
    time 12h am/pm, 
    time 24h hh:mm, 
    current working directory, 
    basename of current working directory, 
    version of bash, 
    newline, 
        
3)It weighs very little(only 984.4 KiB)
    
4)You can customize bash even on behalf of the superuser
    
How to compile?
    First, you need to make sure that your graphical environment supports 
    running Qt applications. For example, I use KDE. Open the official 
    website(http://kde.org/#kPatrons) and see that it supports Qt
    Then, install qt5, qt5 compiler, zip and git. Download repository and 
    unpack archive in it. Compile file and run:
        
   On debian-based systems
   
        $ sudo apt-get update -y
        $ sudo apt-get install qt5-default build-essential git zip unzip
        $ git clone https://github.com/mrybs/bashcustomiser
        $ cd bashcustomiser
        $ unzip BashCustomisersV100.zip
        $ cd BashCustomisersV100
        $ qmake BashCusomiser.pro
        $ make 
        
   On arch-based systems
   
        $ sudo pacman -Sy
        $ sudo pacman -S qt make git zip unzip
        $ git clone https://github.com/mrybs/bashcustomiser
        $ cd bashcustomiser
        $ unzip BashCustomisersV100.zip
        $ cd BashCustomisersV100
        $ qmake BashCusomiser.pro
        $ make
        
   Then run executable file:
    
        $./BashCusomiser
        
Please, if you notice a typo, inaccuracy, error, bug, then write about it in 
the "issues" tab. Thanks!
    
