/*
Marco Zuniga
903662273
hw2.cpp
How to compile:
1. Make sure file is saved and open command prompt.
2. Change directory to 'Documents' by entering 'cd Directory'.
3. Compile by entering the following: "g++ -o hw2 hw2.cpp".
4. Execute the program by entering "./hw2".
The slides from class was the only resource 
used to complete this homework.
*/
/**
How code works:
The main program will be responsible for handling input, and 
checking to see whether the player has lost, won, or should keep going.
The character class holds all of the information for the player, also 
all of the methods needed to adjust the player when needed. The encounter class
is responsible for handling and generating an encounter. The puzzle class
will generate some random puzzle when needed. Lastly the highScores class is what is responsible for
updating the high scores when someone wins.
*/

#include <fstream>
#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cassert>
#include <cstring>
using namespace std;
/**
Will get the high scores from game
*/
void getHighScores();
/**
Create a character object and make sure that no attribute is initially 0;
*/

string test_character_createPlayer();
/**
After creating player, the player should initially start at 0 steps.
*/
string test_character_getSteps();
/**
Tests to see if the player moves after calling movePlayer() method 3 times.
*/
string test_character_movePlayer();
/**
After decrementing money more than the highest possible amount given to player,
attributeIsZero() should return 2.
*/
string test_character_decMoney();
/**
After decrementing intelligence more than the highest possible amount given to player,
attributeIsZero() should return 1.
*/
string test_character_decIntelligence();
/**
After decrementing money more than the highest possible amount given to player,
attributeIsZero() should return 3.
*/
string test_character_decTime();

class menuApp {
public:
	//Outputs first menu option
	void output1();
	//outputs second menu option
	void output2();
	void runOption(int& optionIn);
	//Quits the game is asked by player
	void quit();

	void highScores();
private:
	//string name;
};
//---------------------------------
class character {
public:
//Outputs the remaining steps and time
void output();
//Outputs the characters attributes
void viewCharacter();
//Will create the player and generate all 3 attributes
void createPlayer(string& nameIn);
//Will move player one step
void movePlayer();
//Will increase the player's intelligence by some random number
void increaseIntelligence();
//Will increase the player's time by some random number
void increaseTime();
//Will increase the player's money by some random number
void increaseMoney();
//Will decrement the player's money by some random number
void decMoney();
//Will decremenet the player's time by some random number
void decTime();
//Will decrement the player's intelligence by some random number
void decIntelligence();
/**
Will check to see which attribute has fallen to 0
0:None
1:Intelligence
2:Money
3:Time
*/
int attributeIsZero();
//Will get the current steps of the player
int getSteps();
//Will return all 3 attributes multiplied once player has won the game
int generateHighScore();


private:
int intelligence;
int time;
int money;
int steps;
string name;
};
/**
class systemApp {
public:
void generateOption(int optionIn);
private:
int option;
};
*/
//---------------------------------
class puzzle {
public:
void generatePuzzle(character& playerIn);
};
//---------------------------------
class encounter {
public:
//void setPlayer(character& playerIn);
void generateEncounter(character& playerIn, puzzle& playerPuzzle);
private:
//character player;	
};





//---------------------------------

class highScores {
public:
//Will set the new score variable equal to the score entered in the parameters as well as the desired file.
highScores(int scoreIn, string fileIn);
//Will update the high score file
void updateScores();

private:
ofstream outputScores;
ifstream getScores;

int newScore;
string scoreFile;
//Used to shift the values in the high score file to keep the scores in order
int scoreArray[5];

};

//---------------------------------



int main() {
srand(time(NULL));
string test1 = test_character_createPlayer();
string test2 = test_character_getSteps();
string test3 = test_character_movePlayer();
string test4 = test_character_decMoney();
string test5 = test_character_decIntelligence();
string test6 = test_character_decTime();

ofstream testResults;
string testFile = "Project1_test.txt";
testResults.open((char*)testFile.c_str());
 if (testResults.fail()) {
cout << "File open failed\n";
exit(1);
}

testResults << test1;
testResults << endl;
testResults << test2;
testResults << endl;
testResults << test3;
testResults << endl;
testResults << test4;
testResults << endl;
testResults << test5;
testResults << endl;
testResults << test6;
testResults << endl;

testResults.close();
string name; 
int option;
bool continueLoop = true;

cout << "What's your name? ";
cin >> name;
cout << endl << endl;
cout << "===============================================================\n"
     << "|                        Welcome, " << name << "!                      |\n"
     << "===============================================================\n\n";

menuApp menu;
//systemApp system;
character player;
puzzle playerPuzzle;
menu.output1();
//Loop will continue until player enters a valid option.
do {
//std::cin.getline (option, 100);
cin >> option;

if (cin.fail()) {
cout << "\n\nInvalid option! Please select one of the options displayed.\n";
menu.output1();
cin.clear();
cin.ignore(256, '\n');
continue;
}


switch (option) {
case 1:
cout << "\n\nEntering the Game...";
player.createPlayer(name);
player.viewCharacter();
player.output();
continueLoop = false;
break;

case 2:
getHighScores();
menu.output1();
cin.clear();
break;

case 3:
menu.quit();
/**
default: 
cout << "\nInvalid option. Please select one of the options displayed.\n";
menu.output1();
cin.clear();
*/

}


} while(continueLoop);

menu.output2();
encounter playerEncounter;
continueLoop = true;
int returnNum = 0;
//Loop will continue until player enters a valid option.
do {
	
cin >> option;

if (cin.fail()) {
cout << "\n\nInvalid option! Please select one of the options displayed.\n";
menu.output2();
cin.clear();
cin.ignore(256, '\n');
continue;
}
switch (option) {
case 1:
//playerEncounter.setPlayer(player);
playerEncounter.generateEncounter(player, playerPuzzle);

break;
case 2:
player.increaseIntelligence();
player.decTime();
cout << "You gained intelligence, but lost time.";

break;
case 3:
player.increaseMoney();
player.decTime();
cout << "You gained money, but lost time.";

break;
case 4:
player.viewCharacter();
break;
case 5:
menu.quit();

default:
cout << "";
}

returnNum = player.attributeIsZero();
//Will check to see if player has died.
if (returnNum != 0) {
string attribute;
switch (returnNum) {
case 1:
attribute = "INTELLIGENCE";
break;
case 2:
attribute = "MONEY";
break;
case 3:
attribute = "TIME";
break;

default:;
}

cout << attribute << " HAS FALLEN TO ZERO. YOU DIE.\n";

 exit(1);
}
//Will check to see if player has won.
else if(player.getSteps() == 20) {
int winningScore = player.generateHighScore();
string fileName = "scoreFile.txt";
highScores newScore(winningScore, fileName);
newScore.updateScores();
cout << "\nYou won! \nYour Score: " << winningScore << endl;
exit(1);
}

player.output();
menu.output2();
cin.clear();


}while(continueLoop);

return 0;
}

void menuApp::output1() {
cout << "1) Start a New Game of Shelby Center and Dragons!\n"
<< "2) View top 10 High Scores\n"
<< "3) Quit\n\n"
<< "Please choose an option: ";
}

void menuApp::output2() {
cout << "1) Move forward (takes time, could be risky...)\n"
<< "2) Read technical papers (boost intelligence, takes time)\n"
<< "3) Search for loose change (boost money, takes time)\n"
<< "4) View character\n"
<< "5) Quit the game\n\n"
<< "Please choose an option: ";
}


void menuApp::quit() {
exit(1);
}

/**
void systemApp::generateOption(int optionIn){
option = optionIn;
}
*/

void character::output() {

cout << "\n\nYou are " << (20 - steps) << " steps from the goal. Time left: " << time << ".\n\n";
}

void character::viewCharacter() {
	cout << "\n\nYou have:\n\n"
<< "intelligence: " << intelligence 
<< "\ntime: " << time
<< "\nmoney: $" << money;
}

void character::createPlayer(string& nameIn) {
int randomNum = rand() % (20 - 8 + 1) + 8;
intelligence = randomNum;
randomNum = rand() % (30 - 24 + 1) + 22;
time = randomNum;
money = rand() % (19 - 8 + 1) + 8;
steps = 0;
name = nameIn;
}

void character::increaseIntelligence() {
int randomNum = rand() % (3 - 1 + 1) + 1;
	intelligence = intelligence + randomNum;
}

void character::increaseMoney() {
int randomNum = rand() % (3 - 1 + 1) + 1;
	money = money + randomNum;
}

void character::increaseTime() {
int randomNum = rand() % (3 - 1 + 1) + 1;
	time = time + randomNum;
}

void character::decTime() {
int randomNum = rand() % (2 - 1 + 1) + 1;
	time = time - randomNum;
}

int character::attributeIsZero() {
int returnNum = 0;
if (intelligence <= 0) {
returnNum = 1;
}
else if (money <= 0) {
returnNum = 2;
}
else if(time <= 0) {
returnNum = 3;
}
return returnNum;
}

int character::getSteps() {
return steps;
}

void character::movePlayer() {
steps++;
}

void character::decIntelligence() {
int randomNum = rand() % (4 + 1 + 1) + 1;
	intelligence = intelligence - randomNum;	
}
void character::decMoney() {
int randomNum = rand() % (4 + 1 + 1) + 1;
	money = money - randomNum;	
}
int character::generateHighScore() {
return intelligence*money*time;
}

highScores::highScores(int scoreIn, string fileIn)
      :newScore(scoreIn),scoreFile(fileIn)
      {}

void highScores::updateScores() {

getScores.open((char*)scoreFile.c_str());
if (getScores.fail()) {
cout << "File open failed\n";
exit(1);
}

int index = 0;
	while (getScores >> scoreArray[index]) {
		index++;
    }

if (index == 0){
	scoreArray[0] = newScore;
	scoreArray[1] = 0;
	scoreArray[2] = 0;
	scoreArray[3] = 0;
	scoreArray[4] = 0;
}

else{
 for (int i = 0; i < 5; i++){
 	 
 if (newScore > scoreArray[i]) {
 for (int j = 4; j > i; j--) {
 scoreArray[j] = scoreArray[j - 1];
 }	
 scoreArray[i] = newScore;
 
 }
 break;
 }
}



 getScores.close();

 outputScores.open((char*)scoreFile.c_str());
 if (outputScores.fail()) {
cout << "File open failed\n";
exit(1);
}

 for (int k = 0; k < 5; k++){
 	outputScores << scoreArray[k] << endl;
}
getScores.close();

}
/**
void encounter::setPlayer(character& playerIn) {
player = playerIn;
}
*/

void encounter::generateEncounter(character& playerIn, puzzle& playerPuzzle) {
int randNum = rand() % 100 + 1;

if (randNum <= 25){
playerIn.movePlayer();
cout << "\nYou're very lucky, you didn't encounter anything. You moved forward one step. ";
}

else if (randNum > 25 && randNum <= 50) {
//puzzle
cout << "\nYou encountered a puzzle!\n";
 playerPuzzle.generatePuzzle(playerIn);
}

else if (randNum > 50 && randNum <= 60) {
playerIn.decTime();
playerIn.increaseIntelligence();
cout << "\nYou encountered a professor. You lost a little time, but increased intelligence.";
}

else if (randNum > 60 && randNum <= 70) {
playerIn.decTime();
cout << "\nYou ecountered another graduate student and lost time. ";
}

else if (randNum > 70 && randNum <= 85) {
playerIn.decTime();
playerIn.decIntelligence();
cout << "\nYou were attacked by a grunt work! You lost both time and intelligence. ";
}

else {
	playerIn.decTime();
playerIn.increaseMoney();
playerIn.movePlayer();
cout << "\nYou had to stop and grade some papers. You lost time, but gained money. ";
	}
}

void getHighScores() {
	string file = "scoreFile.txt";
	int fileArray[5];
ifstream inStreamFirst;
inStreamFirst.open((char*)file.c_str());
if (inStreamFirst.fail()) {
cout << "File open failed\n";
exit(1);
}
int index = 0;
	while (inStreamFirst >> fileArray[index]) {
		index++;
    }
for (int i = 0; i < index; i++) {
	cout << fileArray[i] << endl;
}
cout << endl;
}

void puzzle::generatePuzzle(character& playerIn){
	//The random number is to display a random question.
int randNum = rand() % (3) + 1;
int answer;
switch (randNum) {
case 1:
cout << "What is Auburn's mascot?\n";
cout << "1)Tiger\n2)Lion\n3)Bear\n4)Stupid Elephant\nEnter Answer: ";
cin >> answer;
if (cin.fail()) {
cin.clear();
cin.ignore(256, '\n');
cout << "\nWrong! Your intelligence went down, and you lost time!";	
playerIn.decIntelligence();
playerIn.decTime();
}

else if (answer == 1){
cout << "\nCorrect! You gained intelligence.";
playerIn.increaseIntelligence();
playerIn.movePlayer();
}

else {
cout << "\nWrong! Your intelligence went down, and you lost time!";	
playerIn.decIntelligence();
playerIn.decTime();
}

break;
case 2:
cout << "How many nickels are in a US dollar?\n";
cout << "1)20 \n2)32\n3)29\n4)4\nEnter Answer: ";
cin >> answer;
if (cin.fail()) {
cin.clear();
cin.ignore(256, '\n');
cout << "\nWrong! Your money went down, and you lost time!";	
playerIn.decMoney();
playerIn.decTime();
}

else if  (answer == 1){
cout << "\nCorrect! You gained money.";
playerIn.movePlayer();
playerIn.increaseMoney();
}

else {
cout << "\nWrong! Your money went down, and you lost time!";	
playerIn.decMoney();
playerIn.decTime();
}

break;
case 3:
cout << "Where is Auburn University Located??\n";
cout << "1)Auburn, AL \n2)Ozark, AL\n3)Dothan, AL\n4)Not on earth\nEnter Answer: ";
cin >> answer;

if (cin.fail()) {
cin.clear();
cin.ignore(256, '\n');
cout << "\nWrong! Your intelligence went down, and you lost time!";	
playerIn.decIntelligence();
playerIn.decTime();
}
else if (answer == 1){
cout << "\nCorrect! You gained intelligence.";
playerIn.increaseIntelligence();
playerIn.movePlayer();
}
else {
cout << "\nWrong! Your intelligence went down, and you lost time!";	
playerIn.decIntelligence();
playerIn.decTime();
}


}

cin.clear();
}

/**
Create a character object and make sure that no attribute is initially 0;
*/

string test_character_createPlayer() {
//Once player is created, no attribute should be 0 which means the method attributeIsZero should return 0.
	

character test;
string name = "Marco";
test.createPlayer(name);
int testVar = test.attributeIsZero();
assert(testVar == 0);
return "Testing case 1\nTest passed";
}
/**
After creating player, the player should initially start at 0 steps.
*/
string test_character_getSteps() {
character test;
string name = "Marco";
test.createPlayer(name);
assert (test.getSteps() == 0);
return "Testing case 2\nTest passed";

}

/**
Tests to see if the player moves after calling movePlayer() method 3 times.
*/
string test_character_movePlayer() {
character test;
string name = "Marco";
test.createPlayer(name);
test.movePlayer();
test.movePlayer();
test.movePlayer();
assert (test.getSteps() == 3);
return "Testing case 3\nTest passed";

}
/**
After decrementing money more than the highest possible amount given to player,
attributeIsZero() should return 2.
*/
string test_character_decMoney() {
	character test;
string name = "Marco";
test.createPlayer(name);
for (int i = 0; i < 18; i++) {
	test.decMoney();
}
int testVar = test.attributeIsZero();
assert (testVar == 2);
return "Testing case 4\nTest passed";
}

/**
After decrementing intelligence more than the highest possible amount given to player,
attributeIsZero() should return 1.
*/
string test_character_decIntelligence() {
	character test;
string name = "Marco";
test.createPlayer(name);
for (int i = 0; i < 18; i++) {
	test.decIntelligence();
}
int testVar = test.attributeIsZero();
assert (testVar == 1);
return  "Testing case 5\nTest passed";
}

/**
After decrementing money more than the highest possible amount given to player,
attributeIsZero() should return 3.
*/
string test_character_decTime() {
	character test;
string name = "Marco";
test.createPlayer(name);
for (int i = 0; i < 31; i++) {
	test.decTime();
}
int testVar = test.attributeIsZero();
assert (testVar == 3);
return "Testing case 6\nTest passed";
}


