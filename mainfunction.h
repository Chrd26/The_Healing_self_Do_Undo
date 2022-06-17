//mainFunction.h

#include <iostream>
#include <random>

class indexRand{

public:

//This function gets the number of the weekday and prints the right day.
std::string findDay(int thisDay){ 
//A string that should be equal to the right day
 std::string currentDay;
//currentDay is equal to the number of the weekday. This is achieved by getting the right case

switch (thisDay)
{
case 0:
currentDay = "Sunday";
    break;

case 1:
currentDay = "Monday";
    break;

case 2:
currentDay = "Tuesday";
    break;

case 3:
currentDay = "Wednesday";
    break;

case 4:
currentDay = "Thursday";
    break;

case 5:
currentDay = "Friday";
    break;

case 6:
currentDay = "Saturday";
    break;

default:
    break;
}

return currentDay;
}

//Generate a random number from 0 to 8

int randomizedNumber(){
    
std::random_device randomIndex;
std::default_random_engine e1(randomIndex());
    std::uniform_int_distribution<int> uniform_dist(0, 8);
    int doIndex = uniform_dist(e1);
    return doIndex;
}

int randomizedUndoNumber(){
    
std::random_device randomUnoNumber;
std::default_random_engine e1(randomUnoNumber());
    std::uniform_int_distribution<int> uniform_dist(0, 5);
    int undoIndex = uniform_dist(e1);
    return undoIndex;
}


};




