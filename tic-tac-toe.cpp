#include <iostream>  
#include <ctime> 
using namespace std; 

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void compMove(char *spaces, char comp);
bool checkWinner(char *spaces, char player, char comp);
bool checkTie(char *spaces);


int main(){
  char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  char player, comp;
  bool running = true;
  
  cout << "_*_*_*_*_TIC_TAC_TOE_*_*_*_*_\n";
  cout << "Select your marker:" <<'\n';
  cout << "'X' or 'O'\n";
  cin >> player;
  
  if (player == 'x' || player == 'X'){
    comp = 'O';
    cout << "Your marker is "<<player<<" and the computer's marker is "<<comp<<".\n";
  }
  else if (player == 'o' || player == 'O'){
    comp = 'X';
    cout << "Your marker is "<<player<<" and the computer's marker is "<<comp<<".\n";
  }
  
  
  drawBoard(spaces);
  
  while (running){
    playerMove(spaces, player);
    drawBoard(spaces);
    if (checkWinner(spaces, player, comp)){
      running = false;
      break;
    }
    else if(checkTie(spaces)){
      running = false; 
      break;
    }
    
    compMove(spaces, comp);
    drawBoard(spaces);
    if (checkWinner(spaces, player, comp)){
      running = false;
      break;
    }
    else if(checkTie(spaces)){
      running = false; 
      break;
    }
  }
  
  return 0;
}


void drawBoard(char *spaces){
  cout << '\n';
  cout << "|      |      |      |" << '\n';
  cout << "|  "<<spaces[0]<<"   |  "<<spaces[1]<<"   |  "<<spaces[2]<<"   |" << '\n';
  cout << "|______|______|______|" << '\n';
  cout << "|      |      |      |" << '\n';
  cout << "|  "<<spaces[3]<<"   |  "<<spaces[4]<<"   |  "<<spaces[5]<<"   |" << '\n';
  cout << "|______|______|______|" << '\n';
  cout << "|      |      |      |" << '\n';
  cout << "|  "<<spaces[6]<<"   |  "<<spaces[7]<<"   |  "<<spaces[8]<<"   |" << '\n';
  cout << "|______|______|______|" << '\n';
  cout << '\n';
}

void playerMove(char *spaces, char player){
  int num;
  
  do{
    cout << "Enter a position (1-9) to place your marker\n";
    cin >> num;
    num--;
    
    if (spaces[num] == ' '){
      spaces[num] = player;
      break;
    }
  }while(!(num > 0) || !(num < 8));
}

void compMove(char *spaces, char comp){
  int num;
  srand(time(0));
  
  while(true){
    num = rand() % 9;
    
    if (spaces[num] == ' '){
      spaces[num] = comp;
      break;
    }
  }
}

bool checkWinner(char *spaces, char player, char comp){
  if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])){
    spaces[0] == player ?
      cout << "YOU WIN ! \n":
        cout << "YOU LOSE ! \n";
  }
  else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])){
    spaces[3] == player ?
      cout << "YOU WIN ! \n":
        cout << "YOU LOSE ! \n";
  }
  else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])){
    spaces[6] == player ?
      cout << "YOU WIN ! \n":
        cout << "YOU LOSE ! \n";
  }
  else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])){
    spaces[0] == player ?
      cout << "YOU WIN ! \n":
        cout << "YOU LOSE ! \n";
  }
  else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])){
    spaces[1] == player ?
      cout << "YOU WIN ! \n":
        cout << "YOU LOSE ! \n";
  }
  else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])){
    spaces[2] == player ?
      cout << "YOU WIN ! \n":
        cout << "YOU LOSE ! \n";
  }
  else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])){
    spaces[0] == player ?
      cout << "YOU WIN ! \n":
        cout << "YOU LOSE ! \n";
  }
  else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[8])){
    spaces[4] == player ?
      cout << "YOU WIN ! \n":
        cout << "YOU LOSE ! \n";
  }
  else {
    return false;
  }
  
  return true;
}

bool checkTie(char *spaces){
  for (int i = 0; i < 9; i++){
    if (spaces[i] == ' '){
      return false;
    }
  }
  cout << "IT'S A TIE ! \n";
  return true;
}