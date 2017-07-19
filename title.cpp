#include <iostream>
#include <vector>
using namespace std;
string board[8][8];
int turn = 0;//0 is white, 1 is black
void setup();
struct Node{//a new node will be put in the vector for every move possible
  int a;//original position a
  int b;//original position b
  int newa;//new a position
  int newb;//new b position
};
vector<Node*> PossibleMoves();
//vector<Node*> list;
void Pawn(int i,int b, vector<Node*> &list);
void Rook(int i,int b, vector<Node*> &list);
void Knight(int i,int b, vector<Node*> &list);
void Bishop(int i,int b, vector<Node*> &list);
void King(int i,int b, vector<Node*> &list);
void Queen(int i,int b, vector<Node*> &list);
void print(vector<Node*> list);
int main(){
  setup();
  //PossibleMoves();
  print(PossibleMoves());
  return 0;
}
//printing out stuff for debugging purposes
void print(vector<Node*> list){
  int size = list.size();
  for(int i = 0;i < size;i++){
    cout << list[i]->a << list[i]->b << list[i]->newa << list[i]->newb << endl;
  }
}
//setting up the board
void setup(){
  for(int i = 7;i > -1;i--){
    for(int b = 7;b > -1;b--){
      board[i][b] = "x";
    }
  }
  //setting up the board for white
  for(int i = 0;i < 8;i++){
    board[1][i] = "P";
  }
  board[0][0] = "R";
  board[0][1] = "K";
  board[0][2] = "B";
  board[0][3] = "Q";
  board[0][4] = "A";
  board[0][5] = "B";
  board[0][6] = "K";
  board[0][7] = "R";
  //setting up the board for black
  for(int i = 0;i < 8;i++){
    board[6][i] = "p";
  }
  board[6][0] = "r";
  board[6][1] = "k";
  board[6][2] = "b";
  board[6][3] = "q";
  board[6][4] = "a";
  board[6][5] = "b";
  board[6][6] = "k";
  board[6][7] = "r";
}
vector<Node*> PossibleMoves(){
  vector<Node*> list;
  for(int i = 0;i < 8;i++){
    for(int b = 0;b < 8;b++){
      if(turn == 0){
	if(board[i][b] == "R"){
	  //Rook(i,b);
	}
	if(board[i][b] == "K"){
	  //Knight(i,b);
	}
	if(board[i][b] == "B"){
	  //Bishop(i,b);
	}
	if(board[i][b] == "Q"){
	  //Queen(i,b);
	}
	if(board[i][b] == "A"){
	  //King(i,b);
	}
	if(board[i][b] == "P"){
	  Pawn(i,b,list);
	}
      }
      else{//blacks turn
	
      }
    }
  }
  return list;
}
//pawn possible move
void Pawn(int a, int b, vector<Node*> &list){
  if(board[a+1][b] == "x"){
    Node* name = new Node();
    name->a = a;
    name->b = b;
    name->newa = a+1;
    name->newb = b;
    list.push_back(name);
  }
  if(board[a+2][b] == "x" && board[a+1][b] == "x"){
    Node* name = new Node();
    name->a = a;
    name->b = b;
    name->newa = a+2;
    name->newb = b;
    list.push_back(name);
  }
  //also captures, two diagonals
  if(board[a+1][b-1] == "p" || board[a+1][b-1] == "r" || board[a+1][b-1] == "b" || board[a+1][b-1] == "k" || board[a+1][b-1] == "q"){
    Node* name = new Node();
    name->a = a;
    name->b = b;
    name->newa = a+1;
    name->newb = b-1;
    list.push_back(name);
  }
  if(board[a+1][b+1] == "p" || board[a+1][b+1] == "r" || board[a+1][b+1] == "b" || board[a+1][b+1] == "k" || board[a+1][b+1] == "q"){
    Node* name = new Node();
    name->a = a;
    name->b = b;
    name->newa = a+1;
    name->newb = b+1;
    list.push_back(name);
  }
}
//King moving
void King(int a,int b, vector<Node*> &list){
  if(board[a+1][b-1] == "x"){
    Node* name = new Node();
    name->a = a;
    name->b = b;
    name->newa = a+1;
    name->newb = b-1;
    list.push_back(name);
  }
  if(board[a+1][b] == "x"){
    Node* name = new Node();
    name->a = a;
    name->b = b;
    name->newa = a+1;
    name->newb = b;
    list.push_back(name);
  }
  if(board[a+1][b+1] == "x"){
    Node* name = new Node();
    name->a = a;
    name->b = b;
    name->newa = a+1;
    name->newb = b+1;
    list.push_back(name);
  }
  if(board[a][b-1] == "x"){
    Node* name = new Node();
    name->a = a;
    name->b = b;
    name->newa = a;
    name->newb = b-1;
    list.push_back(name);
  }
  if(board[a][b+1] == "x"){
    Node* name = new Node();
    name->a = a;
    name->b = b;
    name->newa = a;
    name->newb = b+1;
    list.push_back(name);
  }
  if(a-1 > -1 && b-1 > -1){
    if(board[a-1][b-1] == "x"){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a-1;
      name->newb = b-1;
      list.push_back(name);
    }
  }
  if(a-1 > -1){
    if(board[a-1][b] == "x"){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a-1;
      name->newb = b;
      list.push_back(name);
    }
  }
  if(a-1 > -1 && b+1 < 8){
    if(board[a-1][b+1] == "x"){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a-1;
      name->newb = b+1;
      list.push_back(name);
    }
  }
  //castling and captures and kingcheck
}
//moves for the knight
void Knight(int a,int b, vector<Node*> &list){
  if(board[a+2][b-1] == "x" && a+2 < 8 && b-1 > -1){
    Node* name = new Node();
    name->a = a;
    name->b = b;
    name->newa = a+2;
    name->newb = b-1;
    list.push_back(name);
  }
  if(board[a+2][b+1] == "x" && a+2 < 8 && b+1 < 8){
    Node* name = new Node();
    name->a = a;
    name->b = b;
    name->newa = a+2;
    name->newb = b+1;
    list.push_back(name);
  }
  if(board[a+1][b-2] == "x" && a+1 < 8 && b-2 > -1){
    Node* name = new Node();
    name->a = a;
    name->b = b;
    name->newa = a+1;
    name->newb = b-2;
    list.push_back(name);
  }
  if(board[a+1][b+2] == "x" && a+1 < 8 && b+2 < 8){
    Node* name = new Node();
    name->a = a;
    name->b = b;
    name->newa = a+1;
    name->newb = b+2;
    list.push_back(name);
  }
  //below
  /*
  if(board[a-2][b-1] == "x"){
    Node* name = new Node();
    name->a = a;
    name->b = b;
    name->newa = a-2;
    name->newb = b-1;
    list.push_back(name);
  }
  if(board[a-2][b+1] == "x"){
    Node* name = new Node();
    name->a = a;
    name->b = b;
    name->newa = a-2;
    name->newb = b+1;
    list.push_back(name);
  }
  if(board[a-1][b-2] == "x"){
    Node* name = new Node();
    name->a = a;
    name->b = b;
    name->newa = a-1;
    name->newb = b-2;
    list.push_back(name);
  }
  if(board[a-1][b+2] == "x"){
    Node* name = new Node();
    name->a = a;
    name->b = b;
    name->newa = a-1;
    name->newb = b-2;
    list.push_back(name);
  }
  */
}
//Rook movement
void Rook(int a, int b, vector<Node*> &list){
  //up
  for(int i = 1;i < 8;i++){
    if(a+i == 8){
      break;
    }
    if(board[a+i][b] == "x"){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a+i;
      name->newb = b;
      list.push_back(name);
    }
    else{
      break;
    }
    //else if(){} if it is a enemy piece then we can take it
  }
  //down
  for(int i = 1;i < 8;i++){
    if(a-i == -1){
      break;
    }
    if(board[a-i][b] == "x"){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a-i;
      name->newb = b;
      list.push_back(name);
    }
    else{
      break;
    }
  }
  //left and right
}
