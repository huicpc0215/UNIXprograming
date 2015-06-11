#APUE(Advanced programing in the Unix Enviorment)

Learn it by doing it. 

And step by step.

##contaning:

cp[0,9]{2,2} are chapter from the book APUE

lib/ are libraries that are common used by all programs

usage:

first compile the library in lib/ using:

gcc -c apue.c 

and it can produce apue.o


libraries are compiled in the lib/, so every individual program
can be compiled using the command:

gcc ${source} ../lib/apue.o  -o ${destination}



