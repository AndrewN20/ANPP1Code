#include <iostream>
#include <vector>
using namespace std;

const char mazeWidth = 10;
const char mazeHeight = 10;
unsigned char playerIcon = 'P';
int posX = 1;
int posY = 1;
bool isOn = true;
unsigned char action;
vector<int> keyNum;
vector<string> itemString;

void playerInput();

unsigned char mapDesign[mazeHeight][mazeWidth] = {
{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},//0
{'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X'},//1
{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', 'X'},//2
{'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X'},//3
{'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},//4
{'X', ' ', ' ', ' ', 'X', 'X', ' ', ' ', ' ', 'X'},//5
{'X', ' ', 'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X'},//6
{'X', ' ', 'X', ' ', ' ', ' ', ' ', ' ', 'E', 'X'},//7
{'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X', 'X'},//8
{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X',},};//9
//0    1    2    3    4    5    6    7    8    9

int main(){
    unsigned int i;
    unsigned int j;
    unsigned char space = ' ';
    string userResponse;

    //Prints out the prologue
    cout << "You mysteriously wake up in a maze. Inside your pocket, you find a slip of papersaying you must find all the keys to escape or you die. Find all the possible keys in this maze to escape. Search around and interact in each space to try to find more information." << endl << endl;

    //Main part of the program
    while (isOn == true) {
        mapDesign[posX][posY] = playerIcon;
        for (j = 0; j < mazeHeight; ++j) {
          cout << endl;
          for (i = 0; i < mazeWidth; ++i) {
            cout << mapDesign[j][i];
          }
        }
        if (mapDesign [posX][posY] == mapDesign[7][7]) {
         cout << endl << "You are at the exit. Type \"x\" to exit."  << endl;
        }
      playerInput();
      if (action == 'x' && mapDesign[7][7]) {
        cout << "Want to play again? Type \"y\" for \"yes\" or \"n\" for \"no\"." << endl;
        cin >> userResponse;
        if (userResponse == "y") {
          system("cls");
          cout << "You mysteriously wake up in a maze. Inside your pocket, you find a slip of papersaying you must find all the keys to escape or you die. Find all the possible keys in this maze to escape. Search around and interact in each space to try to find more information." << endl << endl;
          mapDesign[posX][posY] = space;
          posX = 1;
          posY = 1;
          mapDesign[posX][posY] = playerIcon;
          keyNum.clear();
          itemString.clear();
          mapDesign[4][8] = 'X';
        }
        else if (userResponse == "n") {
          cout << endl << "The program has now ended! Please exit the program!" << endl;
          isOn = false;
        }
        else {
          system("cls");
          cout << "Incorrect answer. Type in \"y\" or \"n\" in lowercase. We will automatically restart the game." << endl << endl;
          cout << "You mysteriously wake up in a maze. Inside your pocket, you find a slip of papersaying you must find all the keys to escape or you die. Find all the possible keys in this maze to escape. Search around and interact in each space to try to find more information." << endl << endl;
          mapDesign[posX][posY] = space;
          posX = 1;
          posY = 1;
          mapDesign[posX][posY] = playerIcon;
          keyNum.clear();
          itemString.clear();
          mapDesign[4][8] = 'X';
        }
      }
    }
  return 0;
}

void playerInput() {
  int prevPosX = posX;
  int prevPosY = posY;
  unsigned char space = ' ';
  unsigned int i;
  unsigned int x;
  unsigned int y;
  string userResponse;

  keyNum.resize(5);
  itemString.resize(2);

  //Some Instructions
  cout << endl << "If you need help, type \"h\"!";
  cout << endl << "Input: ";
  cin >> action;

  switch (action) {
    //Move Left
    case 'a':
      if (mapDesign [posX][posY - 1] != 'X') {
        posY = posY - 1;
        mapDesign [prevPosX] [prevPosY] = space;
      }
      system("cls");
      //Update Position
      for (y = posY; y >= posY ; --y) {
        for (x = posX; x <= posX; ++x)
        cout << "Position: " << y << ", " << x << endl;
      }
      break;

    //Move Right
    case 'd':
      if (mapDesign [posX][posY + 1] != 'X' && mapDesign [posX][posY + 1] != 'E') {
        posY = posY + 1;
        mapDesign [prevPosX] [prevPosY] = space;
      }
      system("cls");
      //Update Position
      for (y = posY; y <= posY ; ++y) {
        for (x = posX; x <= posX; ++x)
        cout << "Position: " << y << ", " << x << endl;
      }
      break;

    //Move Up
    case 'w':
      if (mapDesign [posX - 1][posY] != 'X') {
        posX = posX - 1;
        mapDesign [prevPosX] [prevPosY] = space;
      }
      system("cls");
      //Update Position
      for (y = posY; y <= posY ; ++y) {
        for (x = posX; x >= posX; --x)
        cout << "Position: " << y << ", " << x << endl;
      }
      break;

    //Move Down
    case 's':
      if (mapDesign [posX + 1][posY] != 'X') {
        posX = posX + 1;
        mapDesign [prevPosX] [prevPosY] = space;
      }
      system("cls");
      //Update Position
      for (y = posY; y <= posY ; ++y) {
        for (x = posX; x <= posX; ++x)
        cout << "Position: " << y << ", " << x << endl;
      }
      break;

    //Quit Button
    case 'q':
      cout << "Program Quit." << endl;
      isOn = false;
      break;

    //Check Inventory
    case 'e':
      system("cls");
      cout << endl << "Inventory List:" << endl << "You have: " << endl;
      for (i = 0; i < keyNum.size(); ++i) {
        if (keyNum.at(i) == 0) {
          cout << "";
        }
        else {
          cout << "Key " << keyNum.at(i) << endl;
        }
      }
      for (i = 0; i < itemString.size(); ++i) {
        if (itemString.at(i) == "") {
          cout << "";
        }
        else {
          cout << itemString.at(i) << endl;
        }
      }
      break;

    //Help Instructions
    case 'h':
      system("cls");
      cout << endl << "Type \"w\", \"a\", \"s\", or \"d\" to move! Type \"q\" to quit! Type \"e\" to check inventory! Type \"f\" to search for items or interact with npcs. Only supports lowercase letters! When you are next to \"E\", type \"x\" to be given a prompt to either exit or playthe game again. Note that you can type in multiple letters on one input, so you can type in any letter multiple times to move or interact multiple times, as long it is valid input." << endl;
      break;

    //Interact with items
    case 'f':
      //Key 1
      if (mapDesign [1][8] == mapDesign[posX][posY]) {
        if (mapDesign [1][8] == mapDesign[posX][posY] && keyNum.at(0) == 1) {
          system("cls");
          cout << endl << "There is nothing!" << endl;
          break;
        }
        else {
          system("cls");
          cout << endl << "You found Key 1!" << endl;
          mapDesign [prevPosX] [prevPosY] = space;
          keyNum.at(0) = 1;
          break;
        }
      }
      //Key 2
      else if (mapDesign [posX][posY] == mapDesign [3][4]) {
        if (mapDesign [3][4] == mapDesign[posX][posY] && keyNum.at(1) == 2) {
          system("cls");
          cout << endl << "There is nothing!" << endl;
          break;
        }
        else {
          system("cls");
          cout << endl << "You found Key 2!" << endl;
          mapDesign [prevPosX] [prevPosY] = space;
          keyNum.at(1) = 2;
          break;
        }
      }
      //Cheese
      else if (mapDesign [posX][posY] == mapDesign [8][6]) {
        if (mapDesign [5][3] == mapDesign[posX][posY] && itemString.at(0) == "Cheese") {
          system("cls");
          cout << endl << "There is nothing!" << endl;
          break;
        }
        else {
          system("cls");
          cout << endl << "You found some Cheese!" << endl;
          mapDesign [prevPosX] [prevPosY] = space;
          itemString.at(0) = "Cheese";
          break;
        }
      }
      //Key 3
      else if (mapDesign [posX][posY] == mapDesign [8][3]) {
        if (mapDesign [8][3] == mapDesign[posX][posY] && keyNum.at(2) == 3) {
          system("cls");
          cout << endl << "There is nothing!" << endl;
          break;
        }
        else {
          system("cls");
          cout << endl << "You found Key 3!" << endl;
          mapDesign [prevPosX] [prevPosY] = space;
          keyNum.at(2) = 3;
          break;
        }
      }
      //Key 4
      else if (mapDesign [posX][posY] == mapDesign [5][6]) {
        if (mapDesign [5][6] == mapDesign[posX][posY] && keyNum.at(3) == 4) {
          system("cls");
          cout << endl << "There is nothing!" << endl;
          break;
        }
        else {
          system("cls");
          cout << endl << "You found Key 4!" << endl;
          mapDesign [prevPosX] [prevPosY] = space;
          keyNum.at(3) = 4;
          break;
        }
      }
      //Poster
      else if (mapDesign [posX][posY] == mapDesign [1][4]) {
          system("cls");
          cout << endl << "You noticed a tacked-on poster, stating there are 5 keys scattered around the maze!" << endl;
          mapDesign [prevPosX] [prevPosY] = space;
          break;
      }
      //Disk
      else if (mapDesign [posX][posY] == mapDesign [5][3]) {
        if (mapDesign [5][3] == mapDesign[posX][posY] && itemString.at(1) == "Disk") {
          system("cls");
          cout << endl << "There is nothing!" << endl;
          break;
        }
        else {
          system("cls");
          cout << endl << "You found a mysterious disk!" << endl;
          itemString.at(1) = "Disk";
          mapDesign [prevPosX] [prevPosY] = space;
          break;
        }
      }
      //Rat
      else if (mapDesign [posX][posY] == mapDesign [8][1]) {
          system("cls");
          cout << endl << "You found a rat guarding a key. Probably some cheese will do!" << endl;
          if (itemString.at(0) == "Cheese") {
            cout << "You gave some cheese. The rat gave you key 5!" << endl;
            mapDesign [prevPosX] [prevPosY] = space;
            itemString.at(0) = "";
            keyNum.at(4) = 5;
            break;
          }
          else {
            mapDesign [prevPosX] [prevPosY] = space;
            break;
          }
      }
      //Golem
      else if (mapDesign [posX][posY] == mapDesign [3][8]) {
          system("cls");
          cout << endl << "A golem is blocking this path! You noticed a slot in its palm." << endl;
          if (itemString.at(1) == "Disk") {
            cout << "You inserted the disk in the slot. The golem moved aside from the path" << endl;
            mapDesign[4][8] = space;
            mapDesign [prevPosX] [prevPosY] = space;
            itemString.at(1) = "";
            break;
          }
          else {
            mapDesign [prevPosX] [prevPosY] = space;
            break;
          }
      }
      //Nothing
      else {
        system("cls");
        cout << endl << "There is nothing!" << endl;
        break;
      }

    case 'x':
      system("cls");
      if (keyNum.at(0) == 1 && keyNum.at(1) == 2 && keyNum.at(2) == 3 && keyNum.at(3) == 4 && keyNum.at(4) == 5 && mapDesign [posX][posY] == mapDesign[7][7]) {
        cout << endl << "You escaped from the maze." << endl << endl;
      }
      else {
        cout << endl << "Due to not obtaining all of the keys, the door judge you unworthy of escaped and you died." << endl << endl;
      }
      break;

    //Default Message
    default:
      system("cls");
      cout << endl << "Not valid input." << endl;
      break;
  }
}
