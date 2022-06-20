//main 
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctime>
#include "mainfunction.h"

class mainClass{

public:

std::string function(){
//class from mainFunction header
indexRand mainClass;
std::string currentDay;

//Get time/Day/Week/Month
std::time_t t = time(NULL);
tm *tPtr = localtime(&t);

//MainClass.findDay is a function that is in the main class and it is used to match the number of the weekday to the name of the actual day
//Example : If the argument is findDay is 0 then it is Sunday
currentDay = mainClass.findDay(tPtr->tm_wday);

//Output the name of the day. This is going to be used to print the Day of the UI
//std::cout << currentDay << std::endl;

return currentDay;
}

std::string randomDo(){
    
    indexRand mainClass;
    int randomDoNumber;

    //2D Array of the Do list
    std::string doListPerDay[7][9] = {
    //Sunday Evolution
    {"Be on the lookout for synchronicity.", "Change your daily narrative for the better.", "Look for a chance to be compasionate.", 
    "Openly express love and appreciation", "Be generous of spirit."}
    //Monday Anti-inflammation diet
    ,{"Add some anti-inflammatory foods to your diet.", "Include more organic food to your grocery shopping.", "Increase the fiber in your diet."
    "Take a probiotic supplement.", "switch to olive or safflower oil", "Drink coffee 1 to 5 times a day, preferably at the heavier end."}
     //Tuesday Stress Reduction
    ,{"Meditate", "Go to a yoga class.", "Practice mindful breathing.", "Schedule downtime and quiet time.", "Practice being centered", 
    "Recognize the stages of stress."}
    //Wednesday Anti-Aging
    ,{"Meditate", "Join a social support group.", "Strengthen emotional bonds with family and close friends.", "Take a multivitamin and mineral supplement.", 
    "Maintain a balance of rest and activity.", "Explore a new interest.", "Take up a challenging mental activity."}
    //Thursday Stand, Walk, Rest, Sleep
    ,{"Stand up and move around once an hour if you are workinng at the computer or a desk job.", "Walk 5 minutes for every hour you work.", 
    "Take the stairs instead of the elevator.", "Be regular in your sleep routine.","Make your bedroom an optimal sleeping enviroment.", 
    "Walk for 20 to 30 minutes in the evening.", "Take 10 minutes of quiet alone time, preferable in meditation, twice today.", 
    "Spend more time with a physically active friend or family member."  }
    //Friday Core Beliefs
    ,{"Write down five core believes and evaluate why you believe them.", "Put a core belief into action.", "Read a poem, scripture , or spiritual passage for inspiration.",
     "Have a family discussion about which core beliefs everyone holds.", "Take your favorite role model and list what core beliefs they held."}
    //Saturday Non-Struggle
    ,{"Take an allowing attitude.", "Approach a situation without resistance.", "Act Gracefully.", "Share a responsibility", "Encourage areas of flow"}
    };

    //Get time/Day/Week/Month
    std::time_t t = time(NULL);
    tm *tPtr = localtime(&t);

    //Get a 2 random index number between a certain range.
switch (tPtr->tm_wday)

{
case 0 :
do{
mainClass.randomizedNumber();  
randomDoNumber = mainClass.randomizedNumber(); 
}while (randomDoNumber > 4);
break;

case 1 :
do{
mainClass.randomizedNumber();  
randomDoNumber = mainClass.randomizedNumber(); 
} while (randomDoNumber > 4);
break;

case 2 :
do
{
mainClass.randomizedNumber();  
randomDoNumber = mainClass.randomizedNumber(); 
} while (randomDoNumber > 5);
break;

case 3 :
do
{
mainClass.randomizedNumber();  
randomDoNumber = mainClass.randomizedNumber(); 
} while (randomDoNumber > 6);
break;

    case 4 :
do
{
mainClass.randomizedNumber();  
randomDoNumber = mainClass.randomizedNumber(); 
} while (randomDoNumber > 7);
break;

    case 5 :
do
{
mainClass.randomizedNumber();  
randomDoNumber = mainClass.randomizedNumber();
} while (randomDoNumber > 3);
break;

    case 6 :
do
{
mainClass.randomizedNumber();  
randomDoNumber = mainClass.randomizedNumber(); 
} while (randomDoNumber > 4);
break;

default:
    break;

}

    return doListPerDay[tPtr->tm_wday] [randomDoNumber];
}

std::string randomUndo(){

indexRand mainClass;
int randomUndoNumber;
//2D Array of the Undo List
std::string undoListPerDay[7][6] = {

//Sunday Evolution
{"Resist the voice of fear.", "if you find yourself expecting the worst step away from that expectation and remain neutral.", 
"if you have a negative though that keeps returning, ask if it truly serving or a is a relic of the past.", "If you feel emotionaly upset, find a quiet place to become more calm and centered",
"Seek the company of people who inspire and uplift you."},
//Monday Anti-inflammation diet
{"Cut down sharply on your sugar intake", "Cut out junk food and fast food.", "Throw out stale food, including stale cooking oils and leftovers more than a day old.",
 "Reduce overall fat intake", "Reduce salt intake.", "Use no alcohol."},
//Tuesday Stress Reduction
{"Stop adding to a stressful situtation.", "Refraing from ignoring stressful events in life.", "Walk away from stress as soon as you can.", "Resolve a repeated stress.",
 "Examine a problem you have been putting up with out of frustration.", "Turn irregular habits into a regular routine."},
 //Wednesday
 {"Don't be sedentary - stand up and move throughout the day.", "Examine your negative emotions.", "Heal Injured relationships that are meaningful to you.", "Be mindful of lapses and imbalances in your diet.",
 "Adress negative stereotypes about aging and ageism", "Consider how to heal the fear of death."},
 //Thursday Stand, Walk, Rest, Sleep
 {"Replace 10 minutes of sofa time in front of the TV with a walk instead,", "Break the habit of waiting until the weekend to catch up on lost sleep.", "If you drink alcohol, do it early in the evening - go to bed without alcohol in your bloodstream",
 "Replace the midmoring coffee and doughnut break with a walk.", "Walk to one place close by that you usually drive to.", "Examine your excuses for not being more active."},
 //Friday Core Beliefs
 {"Examine your negative belifes as they relate to fear and mistrust.", "Open a line of communication with someone who holds radically different values", "If you are stuck on a negative belief, be a devil's advocate and argue against it.",
 "End your participation in us-versus-them thinking."},
 //Saturday Non-Struggle
 {"Stop resisting where you don't need to.", "Let someone else have their way.", "Help reduce an area of conflict.", "Remove obstacles from someone else's path.", "Ease competition if favor of cooperation."}
};

//Get time/Day/Week/Month
std::time_t t = time(NULL);
tm *tPtr = localtime(&t);

//Get a 2 random index number between a certain range.
switch (tPtr->tm_wday)
{
case 0 :
do{
    mainClass.randomizedUndoNumber();
    randomUndoNumber = mainClass.randomizedUndoNumber();
}while(randomUndoNumber > 4);
break;

case 1 :
do{
    mainClass.randomizedUndoNumber();
    randomUndoNumber = mainClass.randomizedUndoNumber(); 
} while (randomUndoNumber >5);
    break;

case 2 :
do
{
    mainClass.randomizedUndoNumber();
    randomUndoNumber = mainClass.randomizedUndoNumber(); 
} while (randomUndoNumber >5);
break;

case 3 :
do
{
    mainClass.randomizedUndoNumber();
    randomUndoNumber = mainClass.randomizedUndoNumber(); 
} while (randomUndoNumber >5);
break;

    case 4 :
do
{
mainClass.randomizedUndoNumber();
randomUndoNumber = mainClass.randomizedUndoNumber(); 
} while (randomUndoNumber >5);
break;

    case 5 :
    do
{
mainClass.randomizedUndoNumber();
randomUndoNumber = mainClass.randomizedUndoNumber(); 
} while (randomUndoNumber > 4);
break;

    case 6 :
do{
   mainClass.randomizedUndoNumber();
   randomUndoNumber = mainClass.randomizedUndoNumber();
}while (randomUndoNumber > 3);

    break;

default:
    break;
}

return undoListPerDay[tPtr->tm_wday] [randomUndoNumber];
}

};
    



