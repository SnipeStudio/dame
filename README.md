Disk And Memory Eater
==
Current version:2.3.2.4
Platform: Windows
 About
=
The program takes a large amount of hard disk space and RAM. It is intended for testing.

 how to run
=

You can run Disk And Memory Eater v2.3(further dame) with arguments:

    ./dame {ed|edl|em|edm|edml} [/path/to/eat] [spacetoeat {b|k|m|g}] 

1) Run with argument with the catalog in in wich the file which will eat disk drive space will be written

      /dame {ed|edl|em|emd|emdl} [/path/to/eat] [spacetoeat {b|k|m|g}] 

First block is a mode selector

    ed - disk eater
    em - memory eater
    edl - disk eater with limit
    eml - memory eater with limit
    edlr - disk eater with limit and rate


Second block is only needed when selected one of modes('ed', 'edl','edlr'). 
It is a path to files to write space will be placed

In the edlr mode you also need to enter rate and time option

    ./dame edlr 1 15 m s 1 m
it's tell to eat 15 MiB of disk drive space with speed 1 MiB per second
other time options:
    s - second
    m - minute
    h - hour
    d - day

Third block only needed when using limits
You can enter number and size multiplier

    1000 b   - 1000 bytes
    1000 k   - 1000 kilobytes
    1000 m   - 1000 megabytes
    1000 g   - 1000 gigabytes

When you eating memory with modes eml you don't need to enter path but you need to enter limits like above

