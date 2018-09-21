//  Collatz Conjecture C++
//  Created by George Maier on 20/09/2018.
//  Copyright © 2018 George Maier. All rights reserved.


#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>

using namespace std::this_thread;
using namespace std::chrono_literals;

//  !!! WARNINGS !!!
//  endvalue is the length of each block - i.e. how many start values does each block cover. Don't increase beyond 59,999,999.
//  If you are running this code for the first time you may wish to set endvalue to a small number (e.g. 500) to test memory usage on your system.
//  Please note that large values of endvalue (block length) and numberofblocks (the number of blocks) will result in a very large file being produced.
//  If you do not change these values, the output file will be many gigabytes in length. Make sure you have at least 20gb if you intend to run as is.
//  This code is produced on a MacbookPro 13-inch Early 2015.
//  This code will attempt to run 4 threads.


long startValue = 1;                                                                                    //This variable is not used! It is here simply for future use
long endvalue = 50000000;                                                                               //!!!NUMBER OF OUTPUTS FOR EACH BLOCK!!!
long numberofblocks = 20;                                                                               //!!!NUMBER OF BLOCKS!!!

long blockcount = 0;                                                                                    //Establishes the key iteration variable.
long findings[60000000];                                                                                //This will store the first block of findings to speed up computation
long findingsoutput[60000000];                                                                          //Stores each block of output [NB, positions in array must be > endvalue]



//Pathfinder is the main calculation function

long pathfinder (long player, long passed){                                                             //passes the player startpoint and the number of blocks passed
    long holder = player;                                                                               //stores the player startpoint for use later in assignment
    long count = 0;                                                                                     //initialises the count that will be used to output itterations
    while (player > 1){
        if (player < endvalue){                                                                         //Part of the loop checks if the remaining pathway length is already known.
            if (findings[player] == 0){
                if (player % 2 == 0){
                    player = player/2;
                    count ++;
                }
                else{
                    player = ((3*player)+1)/2;
                    count = count + 2;                                                                  //If confused: Because this is two moves in one.
                }
            }
            else{
                count = count + findings[player];
                player = 1;
            }
        }
        else{
            if (player % 2 == 0){
                player = player/2;
                count ++;
            }
            else{
                player = ((3*player)+1)/2;
                count = count + 2;
            }
        }
    }
    if (holder < endvalue){                                                                             //The first block of findings are stored in memory here
        findings[holder] = count;                                                                       //and will be kept to speed up future calculations
    }
    findingsoutput[holder - (endvalue*passed)] = count;                                                 //This is the variable that will be used for output
    return count;                                                                                       //Not used, but included in case ever need.
}



//Calculation is split between 4 threads in this code. Each thread gets assigned to, and runs, one of these functions.
//The math here is such that each thread does the calculation for every 4th value. Collectively, all 4 cover every value in the range.

void task1 (long passedblockcount){
    sleep_for(0.5s);
    std::cout << "Thread 1 activated" << std::endl;
    for (long i=1; i < (endvalue + 1); i+=4){
        pathfinder((i + (endvalue*passedblockcount)), passedblockcount);
    }
}


void task2 (long passedblockcount) {
    sleep_for(1s);
    std::cout << "Thread 2 activated" << std::endl;
    for (long i=2; i < (endvalue + 1); i+=4){
        pathfinder((i + (endvalue*passedblockcount)), passedblockcount);
    }
}

void task3 (long passedblockcount) {
    sleep_for(1.5s);
    std::cout << "Thread 3 activated" << std::endl;
    for (long i=3; i < (endvalue + 1); i+=4){
        pathfinder((i + (endvalue*passedblockcount)), passedblockcount);
    }
}


void task4 (long passedblockcount) {
    sleep_for(2s);
    std::cout << "Thread 4 activated" << std::endl;
    for (long i=4; i < (endvalue + 1); i+=4){
        pathfinder((i + (endvalue*passedblockcount)), passedblockcount);
    }
}




//Writing to storage proved quite slow for large values, so I added the progress function to print updates on progress.
//Will only work if endvalue is dividable by 20.

void progress (long i){
    if (i == (endvalue/20)){
        std::cout << "5%" << " complete..." << std::endl;
    }
    if (i == 2*(endvalue/20)){
        std::cout << "10%" << " complete..." << std::endl;
    }
    if (i == 3*(endvalue/20)){
        std::cout << "15%" << " complete..." << std::endl;
    }
    if (i == 4*(endvalue/20)){
        std::cout << "20%" << " complete..." << std::endl;
    }
    if (i == 5*(endvalue/20)){
        std::cout << "25%" << " complete..." << std::endl;
    }
    if (i == 6*(endvalue/20)){
        std::cout << "30%" << " complete..." << std::endl;
    }
    if (i == 7*(endvalue/20)){
        std::cout << "35%" << " complete..." << std::endl;
    }
    if (i == 8*(endvalue/20)){
        std::cout << "40%" << " complete..." << std::endl;
    }
    if (i == 9*(endvalue/20)){
        std::cout << "45%" << " complete..." << std::endl;
    }
    if (i == 10*(endvalue/20)){
        std::cout << "50%" << " complete..." << std::endl;
    }
    if (i == 11*(endvalue/20)){
        std::cout << "55%" << " complete..." << std::endl;
    }
    if (i == 12*(endvalue/20)){
        std::cout << "60%" << " complete..." << std::endl;
    }
    if (i == 13*(endvalue/20)){
        std::cout << "65%" << " complete..." << std::endl;
    }
    if (i == 14*(endvalue/20)){
        std::cout << "70%" << " complete..." << std::endl;
    }
    if (i == 15*(endvalue/20)){
        std::cout << "75%" << " complete..." << std::endl;
    }
    if (i == 16*(endvalue/20)){
        std::cout << "80%" << " complete..." << std::endl;
    }
    if (i == 17*(endvalue/20)){
        std::cout << "85%" << " complete..." << std::endl;
    }
    if (i == 18*(endvalue/20)){
        std::cout << "90%" << " complete..." << std::endl;
    }
    if (i == 19*(endvalue/20)){
        std::cout << "95%" << " complete..." << std::endl;
    }
}




int main() {
    unsigned concurentThreadsSupported = std::thread::hardware_concurrency();                           //Retuns the number of threads.
    std::cout << "Collatz Conjecture Calculator - George Maier 2018" << std::endl;
    std::cout << "Number of threads on system: " << concurentThreadsSupported << std::endl;
    std::cout << "Executing " << numberofblocks << " blcoks with a block size of " << endvalue << std::endl << std::endl;
    
    //Establishing the first block findings variable to make sure it's defined as 0.
    for (long i = 1; i < endvalue; i++){
        findings[i] = 0;
    }
    
    // This for loop is the main loop of code, it iterates up to the number of blocks.
    for (long mainloopcount = 0; mainloopcount < numberofblocks; mainloopcount++){
        std::cout << "Begining block number " << (mainloopcount+1) << std::endl;
        std::cout << "Building memory space for findings..." << std::endl << std::endl;
        for (long i = 1; i < endvalue; i++){
            findingsoutput[i] = 0;
        }
        std::cout << "Beginning search for pathways..." << std::endl << std::endl;
        std::cout << "Calling 4 threads: " << std::endl << std::endl;
    
        std::thread t1(task1, mainloopcount);
        std::thread t2(task2, mainloopcount);
        std::thread t3(task3, mainloopcount);
        std::thread t4(task4, mainloopcount);
    
        if (t1.joinable()){
            t1.join();
        }
    
        if (t2.joinable()){
            t2.join();
        }
    
        if (t3.joinable()){
            t3.join();
        }
    
        if (t4.joinable()){
            t4.join();
        }
        
        std::cout << std::endl << std::endl << "Calculaton for block " << (mainloopcount+1) << " of " << numberofblocks << " completed" << std::endl;
        std::cout << std::endl << "Printing findings to output file" << std::endl;
        std::cout << "This process may take a few moments if a lage block size is being used" << std::endl << std::endl;
        
        
        std::ofstream outputfile;
        
        //The following line includes the output file name. You may need to, or wish to, change the name/directory used.
        outputfile.open("Collatz_output_1.csv", std::ios::app);
        for (long i = 1; i < (endvalue + 1); i++){
            outputfile << (i+(mainloopcount*endvalue)) << "," << findingsoutput[i] << std::endl;
            progress(i);
        }
        outputfile.close();
        std::cout << "Block" << (mainloopcount+1) << "File print sucsessful!" << std::endl << std::endl;
        
        //The code will now start the next block, if there is one. Otherwise, done.
        
    }
    std::cout << std::endl << std::endl << "!!!COMPLETE!!!" << std::endl;
    return 0;
}
