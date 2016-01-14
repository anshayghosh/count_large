# count_large
Example use of code:
given the output of ls -l:

    total 329
    -rwx------  1 reid  staff    1734 22 Jun 14:52 prog
    -rw-------  1 reid  staff   21510  6 Apr 12:10 tmp.txt
    -rwxr-xr-x  1 reid  staff    8968  1 Feb  2013 xyz*
    -rw-r--r--  1 reid  staff      88 15 Feb  2013 xyz.c
Running count_large 1000 rwx------

will print 2 because prog and xyz are both larger than 1000 bytes and have at least the permissions specified.

Running count_large 1000 will print 3 because there are three files larger than 1000 bytes.


