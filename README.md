Disk And Memory Eater
==
Current version:2.3.0.3
==
 About
=
The program takes a large amount of hard disk space and RAM. It is intended for testing.

 how to run
=

You can run Disk And Memory Eater v2.2(further dame) with arguments:

    ./dame {ed|edl|em|edm|edml} [/path/to/eat] [spacetoeat {b|k|m|g}] 

1) Run with argument with the catalog in in wich the file which will eat disk drive space will be written

      /dame {ed|edl|em|emd|emdl} [/path/to/eat] [spacetoeat {b|k|m|g}] 

First block is a mode selector

    ed - disk eater
    em - memory eater
    emd - memory and disk eater
    edl - disk eater with limit
    emdl - memory and disk eater with limit

second block is only needed when selected one of modes('emd','ed','edml','edl'). 
It is a adress where files to write space will be placed

Third block only needed when using limits
You can enter number and size multiplier

    1000 b   - 1000 bytes
    1000 k   - 1000 kilobytes
    1000 m   - 1000 megabytes
    1000 g   - 1000 gigabytes

