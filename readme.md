Bash customiser guide

This application will help you to easily customise the appearance of the
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
    user's name,
    host's name,
    data,
    time 24h hh:mm:ss,
    time 12h hh:mm:ss,
    time 12h am/pm,
    time 24h hh:mm,
    current working directory,
    basename of current working directory,
    version of bash,
    newline,

3)It weighs very little (smaller then 1MiB)

4)You can customize bash even on behalf of the superuser

How to compile?
    First, you need to make sure that your graphical environment supports
    running Qt applications. For example, I use KDE. Open the official
    website(http://kde.org/#kPatrons) and see that it supports Qt
    Then, install qt5, qt5 compiler, zip and git. Download repository and
    enter in repository's path. Compile file and run:

        $ cd latestVersion
        $ sudo sh install.sh

   Then run the program:

        $ bashcustomiser

Please, if you notice a typo, inaccuracy, error, bug, then write about it in
the "issues" tab. Thanks!
