# collatz-conjecture

This is a threaded C++ algorithm that calculates the iteration length of Collatz Conjecture pathways up to a given value of n. The algorithm outputs the findings into a csv file.  The processing is conducted in blocks to expand beyond the limits of system memory, and after each block is calculated its findings are written to the output file before calculation continues, reusing the memory space of the previous block. Code written in the XCode IDE, using the Intel C++ complier - running on an Early 2015 Macbook Pro 13inch (i5 2-Core, 8gb RAM).

Detailed comments are provided within the main cpp file - they should statasfy your curiosities. 
      Kindest regards, 
        George
