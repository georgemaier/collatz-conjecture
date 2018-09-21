# collatz-conjecture

This is a threaded C++ algorithm that calculates the iteration length of Collatz Conjecture pathways up to a given value of n. The algorithm outputs the findings into a csv file.  The processing is conducted in blocks to expand beyond the limits of system memory, and after each block is calculated its findings are written to the output file before calculation continues, reusing the memory space of the previous block. Code written in the XCode IDE, using the Intel C++ complier - running on an Early 2015 Macbook Pro 13inch (i5 2-Core, 8gb RAM).

This code includes a number of speed oriented features such as: 

- Multi-threading (4 threads)

- Utilising known pathway lengths to reduce clock cycles (e.g. if 100 is halved to 50, and the length from 50 to 1 is already known, we can simply add this length)

- Calculating in blocks means system memory usage can be controlled and overflows avoided. 

- Mathematically, 3n+1 on an odd number always results in an even result, meaning the operation can be combined with the resultant need to divide by two. Thus, 3n+1 becomes (3n+1)/2 and an additional process cycle is avoided. 

Detailed comments are provided within the main cpp file - they should statasfy your curiosities. 
      Kindest regards, 
        George
