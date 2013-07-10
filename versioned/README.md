
Disk And Memory Eater
====
Current version:2.1


About

The program takes a large amount of hard disk space and RAM. It is intended for testing.

how to run

You can run Disk And Memory Eater v2.1(further DaMe2.1) in two ways:

1) just run it without any arguments and DaMe2 ask you about the catalog in wich the file which will eat disk drive space
will be written

    ./DaMe2.1

2) Run with argument with the catalog in in wich the file which will eat disk drive space will be written

      ./DaMe2.1 /data/outgoing/trolling.baggy

in version 2.0.1 added option to separately occupy memory and hard drive space.
When appears the message 

      Enter mode: (d|m|b|dl|bl)

you should enter one of this three possibilities 

    d - disk eater
m - memory eater
b - memory and disk eater
dl - disk eater with limit
bl - memory and disk eater with limit

when option 'm' is selected it's not necessary to enter path to the file




When selected options 'dl' or 'bl' you should enter max size of file

      Enter limit in bytes

You can enter number and size multiplier

    1000 b   - 1000 bytes
1000 k   - 1000 kilobytes
1000 m   - 1000 megabytes
1000 g   - 1000 gigabytes
