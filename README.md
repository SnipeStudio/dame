Disk And Memory Eater
==
Current version:2.3.0.4-beta
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
    edl - disk eater with limit
    eml - memory eater with limit
    emlr - memory eater with limit and rate


Second block is only needed when selected one of modes('ed' and 'edl'). 
It is a path to files to write space will be placed

Third block only needed when using limits
You can enter number and size multiplier

    1000 b   - 1000 bytes
    1000 k   - 1000 kilobytes
    1000 m   - 1000 megabytes
    1000 g   - 1000 gigabytes

When you eating memory with modes eml or emlr you don't need to enter path but you need to enter limits like above

In the emlr mode you also need to enter rate and time option

    ./dame emlr 15 m m
it's mean eat 15 megabytes of RAP per minute
other time options:
    s - second
    m - minute
    h - hour
    d - day