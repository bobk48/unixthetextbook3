#!/bin/sh
echo "The command name is: $0."
echo "The number of command line arguments passed as
parameters is: $#."
echo "The value of the command line arguments are: $1 $2 $3 $4
$5 $6 $7 $8 $9."
echo "Another way to display values of all the arguments: $@."
echo "Yet another way is: $*."
exit 0
