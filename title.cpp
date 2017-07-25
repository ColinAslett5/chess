#include <iostream>
#include <vector>
using namespace std;
string board[8][8];
int turn = 1;//0 is white, 1 is black
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
bool KingSafe(int a, int b, int c, int d);
void MakeMove(int a, int b, int c, int d);//makes the move
void UndoMove(int a, int b, int c, int d);//undo's the last move
void Outlay();//prints out the board
int main(){
  setup();
  //PossibleMoves();
  print(PossibleMoves());
  Outlay();
  return 0;
}
//printing out stuff for debugging purposes
void print(vector<Node*> list){//if there are no moves then we have to check for stalemate or checkmate
  int size = list.size();
  for(int i = 0;i < size;i++){
    cout << list[i]->a << list[i]->b << list[i]->newa << list[i]->newb << endl;
    MakeMove(list[i]->a,list[i]->b,list[i]->newa,list[i]->newb);
    UndoMove(list[i]->a,list[i]->b,list[i]->newa,list[i]->newb);
  }
}
//prints out the board
void Outlay(){
  cout << endl;
  cout << "Board" << endl;
  for(int i = 8;i > 0;i--){
    cout << i;
    for(int b = 0;b < 8;b++){
      cout << board[i-1][b];
    }
    cout << endl;
  }
}
//makes the move
void MakeMove(int a, int b, int c, int d){
  board[c][d] = board[a][b];
  board[a][b] = "x";
}
//undo's the MakeMove function
void UndoMove(int a, int b, int c, int d){
  board[a][b] = board[c][d];
  board[c][d] = "x";
}
//is the king going to be in check
bool KingSafe(int a, int b, int c, int d){
  if(turn == 0){}
  else if(turn == 1){}
  return true;
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
  board[7][0] = "r";
  board[7][1] = "k";
  board[7][2] = "b";
  board[7][3] = "q";
  board[7][4] = "a";
  board[7][5] = "b";
  board[7][6] = "k";
  board[7][7] = "r";
}
vector<Node*> PossibleMoves(){
  vector<Node*> list;
  for(int i = 0;i < 8;i++){
    for(int b = 0;b < 8;b++){
      if(turn == 0){
	if(board[i][b] == "R"){
	  //Rook(i,b,list);
	}
	if(board[i][b] == "K"){
	  //Knight(i,b,list);
	}
	if(board[i][b] == "B"){
	  //Bishop(i,b,list);
	}
	if(board[i][b] == "Q"){
	  //Queen(i,b,list);
	}
	if(board[i][b] == "A"){
	  //King(i,b,list);
	}
	if(board[i][b] == "P"){
	  //Pawn(i,b,list);
	}
      }
      else if(turn == 1){//blacks turn
        if(board[i][b] == "r"){
          Rook(i,b,list);
        }
        if(board[i][b] == "k"){
          //Knight(i,b,list);
        }
        if(board[i][b] == "b"){
          //Bishop(i,b,list);
        }
        if(board[i][b] == "q"){
          //Queen(i,b,list);
        }
        if(board[i][b] == "a"){
          //King(i,b,list);
        }
        if(board[i][b] == "p"){
          //Pawn(i,b,list);
        }
      }
    }
  }
  return list;
}
//COMPELTED
void Pawn(int a, int b, vector<Node*> &list){//Have to Do Promotion
  if(turn == 0){
    if(board[a+1][b] == "x" && KingSafe(a,b,a+1,b)){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a+1;
      name->newb = b;
      list.push_back(name);
    }
    if(board[a+2][b] == "x" && board[a+1][b] == "x" && KingSafe(a,b,a+2,b)){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a+2;
      name->newb = b;
      list.push_back(name);
    }
    //also captures, two diagonals
    if((board[a+1][b-1] == "p" || board[a+1][b-1] == "r" || board[a+1][b-1] == "b" || board[a+1][b-1] == "k" || board[a+1][b-1] == "q") && KingSafe(a,b,a+1,b-1)){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a+1;
      name->newb = b-1;
      list.push_back(name);
    }
    if((board[a+1][b+1] == "p" || board[a+1][b+1] == "r" || board[a+1][b+1] == "b" || board[a+1][b+1] == "k" || board[a+1][b+1] == "q") && KingSafe(a,b,a+1,b-1)){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a+1;
      name->newb = b+1;
      list.push_back(name);
    }
  }
  else if(turn == 1){
    if(board[a-1][b] == "x" && KingSafe(a,b,a-1,b)){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a-1;
      name->newb = b;
      list.push_back(name);
    }
    if(board[a-2][b] == "x" && KingSafe(a,b,a-2,b)){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a-2;
      name->newb = b;
      list.push_back(name);
    }
    if((board[a-1][b-1] == "P" || board[a-1][b-1] == "R" || board[a-1][b-1] == "B" || board[a-1][b-1] == "K" || board[a-1][b-1] == "Q") && KingSafe(a,b,a-1,b-1)){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a-1;
      name->newb = b-1;
      list.push_back(name);
    }
    if((board[a-1][b+1] == "P" || board[a-1][b+1] == "R" || board[a-1][b+1] == "B" || board[a-1][b+1] == "K" || board[a-1][b+1] == "Q") && KingSafe(a,b,a-1,b+1)){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a-1;
      name->newb = b+1;
      list.push_back(name);
    }
  }
}
//JUST NEED FOR BLACK PIECES, ALSO HAVE TO MAKE SURE IT CANT GO WITHIN ONE SQUARE OF A KING
void King(int a,int b, vector<Node*> &list){
  if(turn == 0){
    if(a+1 < 8 && b-1 > -1){
      if((board[a+1][b-1] == "x" || board[a+1][b-1] == "p" || board[a+1][b-1] == "r" || board[a+1][b-1] == "b" || board[a+1][b-1] == "k" || board[a+1][b-1] == "q") && KingSafe(a,b,a+1,b-1)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a+1;
	name->newb = b-1;
	list.push_back(name);
      }
    }
    if(a+1 < 8){
      if((board[a+1][b] == "x" || board[a+1][b] == "p" || board[a+1][b] == "r" || board[a+1][b] == "b" || board[a+1][b] == "k" || board[a+1][b] == "q") && KingSafe(a,b,a+1,b)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a+1;
	name->newb = b;
	list.push_back(name);
      }
    }
    if(a+1 < 8 && b+1 < 8){
      if((board[a+1][b+1] == "x" || board[a+1][b+1] == "p" || board[a+1][b+1] == "r" || board[a+1][b+1] == "b" || board[a+1][b+1] == "k" || board[a+1][b+1] == "q") && KingSafe(a,b,a+1,b+1)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a+1;
	name->newb = b+1;
	list.push_back(name);
      }
    }
    if(b-1 > -1){
      if((board[a][b-1] == "x" || board[a][b-1] == "p" || board[a][b-1] == "r" || board[a][b-1] == "b" || board[a][b-1] == "k" || board[a][b-1] == "q") && KingSafe(a,b,a,b-1)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a;
	name->newb = b-1;
	list.push_back(name);
      }
    }
    if(b+1 < 8){
      if((board[a][b+1] == "x" || board[a][b+1] == "p" || board[a][b+1] == "r" || board[a][b+1] == "b" || board[a][b+1] == "k" || board[a][b+1] == "q") && KingSafe(a,b,a,b+1)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a;
	name->newb = b+1;
	list.push_back(name);
      }
    }
    if(a-1 > -1 && b-1 > -1){
      if((board[a-1][b-1] == "x" || board[a-1][b-1] == "p" || board[a-1][b-1] == "r" || board[a-1][b-1] == "b" || board[a-1][b-1] == "k" || board[a-1][b-1] == "q") && KingSafe(a,b,a-1,b-1)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a-1;
	name->newb = b-1;
	list.push_back(name);
      }
    }
    if(a-1 > -1){
      if((board[a-1][b] == "x" || board[a-1][b] == "p" || board[a-1][b] == "r" || board[a-1][b] == "b" || board[a-1][b] == "k" || board[a-1][b] == "q") && KingSafe(a,b,a-1,b)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a-1;
	name->newb = b;
	list.push_back(name);
      }
    }
    if(a-1 > -1 && b+1 < 8){
      if((board[a-1][b+1] == "x" || board[a-1][b+1] == "p" || board[a-1][b+1] == "r" || board[a-1][b+1] == "b" || board[a-1][b+1] == "k" || board[a-1][b+1] == "q") && KingSafe(a,b,a-1,b+1)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a-1;
	name->newb = b+1;
	list.push_back(name);
      }
    }
  }
  else if(turn == 1){
    //everything above but with capital letter pieces
  }
  //castling
}
//COMPELTED
void Knight(int a,int b, vector<Node*> &list){
  if(turn == 0){
    if(a+2 < 8 && b-1 > -1){
      if((board[a+2][b-1] == "x" || board[a+2][b-1] == "p" || board[a+2][b-1] == "r" || board[a+2][b-1] == "b" || board[a+2][b-1] == "k" || board[a+2][b-1] == "q") && KingSafe(a,b,a+2,b-1)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a+2;
	name->newb = b-1;
	list.push_back(name);
      }
    }
    if(a+2 < 8 && b+1 < 8){
      if((board[a+2][b+1] == "x" || board[a+2][b+1] == "p" || board[a+2][b+1] == "r" || board[a+2][b+1] == "b" || board[a+2][b+1] == "k" || board[a+2][b+1] == "q") && KingSafe(a,b,a+2,b+1)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a+2;
	name->newb = b+1;
	list.push_back(name);
      }
    }
    if(a+1 < 8 && b-2 > -1){
      if((board[a+1][b-2] == "x" || board[a+1][b-2] == "p" || board[a+1][b-2] == "r" || board[a+1][b-2] == "b" || board[a+1][b-2] == "k" || board[a+1][b-2] == "q") && KingSafe(a,b,a+1,b-2)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a+1;
	name->newb = b-2;
	list.push_back(name);
      }
    }
    if(a+1 < 8 && b+2 < 8){
      if((board[a+1][b+2] == "x" || board[a+1][b+2] == "p" || board[a+1][b+2] == "r" || board[a+1][b+2] == "b" || board[a+1][b+2] == "k" || board[a+1][b+2] == "q") && KingSafe(a,b,a+1,b+2)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a+1;
	name->newb = b+2;
	list.push_back(name);
      }
    }
    //half
    if(a-2 > -1 && b-1 > -1){
      if((board[a-2][b-1] == "x" || board[a-2][b-1] == "p" || board[a-2][b-1] == "r" || board[a-2][b-1] == "b" || board[a-2][b-1] == "k" || board[a-2][b-1] == "q") && KingSafe(a,b,a-2,b-1)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a-2;
	name->newb = b-1;
	list.push_back(name);
      }
    }
    if(a-2 > -1 && b+1 < 8){
      if((board[a-2][b+1] == "x" || board[a-2][b+1] == "p" || board[a-2][b+1] == "r" || board[a-2][b+1] == "b" || board[a-2][b+1] == "k" || board[a-2][b+1] == "q") && KingSafe(a,b,a-2,b+1)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a-2;
	name->newb = b+1;
	list.push_back(name);
      }
    }
    if(a-1 > -1 && b-2 > -1){
      if((board[a-1][b-2] == "x" || board[a-1][b-2] == "p" || board[a-1][b-2] == "r" || board[a-1][b-2] == "b" || board[a-1][b-2] == "k" || board[a-1][b-2] == "q") && KingSafe(a,b,a-1,b-2)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a-1;
	name->newb = b-2;
	list.push_back(name);
      }
    }
    if(a-1 > -1 && b+2 < 8){
      if((board[a-1][b+2] == "x" || board[a-1][b+2] == "p" || board[a-1][b+2] == "r" || board[a-1][b+2] == "b" || board[a-1][b+2] == "k" || board[a-1][b+2] == "q") && KingSafe(a,b,a-1,b+2)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a-1;
	name->newb = b+2;
	list.push_back(name);
      }
    }
  }
  //for black pieces
  else if(turn == 1){
    if(a+2 < 8 && b-1 > -1){
      if((board[a+2][b-1] == "x" || board[a+2][b-1] == "P" || board[a+2][b-1] == "R" || board[a+2][b-1] == "B" || board[a+2][b-1] == "K" || board[a+2][b-1] == "Q") && KingSafe(a,b,a+2,b-1)){
        Node* name = new Node();
        name->a = a;
        name->b = b;
        name->newa = a+2;
        name->newb = b-1;
        list.push_back(name);
      }
    }
    if(a+2 < 8 && b+1 < 8){
      if((board[a+2][b+1] == "x" || board[a+2][b+1] == "P" || board[a+2][b+1] == "R" || board[a+2][b+1] == "B" || board[a+2][b+1] == "K" || board[a+2][b+1] == "Q") && KingSafe(a,b,a+2,b+1)){
        Node* name = new Node();
        name->a = a;
        name->b = b;
        name->newa = a+2;
        name->newb = b+1;
        list.push_back(name);
      }
    }
    if(a+1 < 8 && b-2 > -1){
      if((board[a+1][b-2] == "x" || board[a+1][b-2] == "P" || board[a+1][b-2] == "R" || board[a+1][b-2] == "B" || board[a+1][b-2] == "K" || board[a+1][b-2] == "Q") && KingSafe(a,b,a+1,b-2)){
        Node* name = new Node();
        name->a = a;
        name->b = b;
        name->newa = a+1;
        name->newb = b-2;
        list.push_back(name);
      }
    }
    if(a+1 < 8 && b+2 < 8){
      if((board[a+1][b+2] == "x" || board[a+1][b+2] == "P" || board[a+1][b+2] == "R" || board[a+1][b+2] == "B" || board[a+1][b+2] == "K" || board[a+1][b+2] == "Q") && KingSafe(a,b,a+1,b+2)){
        Node* name = new Node();
        name->a = a;
        name->b = b;
        name->newa = a+1;
        name->newb = b+2;
        list.push_back(name);
      }
    }
    //half
    if(a-2 > -1 && b-1 > -1){
      if((board[a-2][b-1] == "x" || board[a-2][b-1] == "P" || board[a-2][b-1] == "R" || board[a-2][b-1] == "B" || board[a-2][b-1] == "K" || board[a-2][b-1] == "Q") && KingSafe(a,b,a-2,b-1)){
        Node* name = new Node();
        name->a = a;
        name->b = b;
        name->newa = a-2;
        name->newb = b-1;
        list.push_back(name);
      }
    }
    if(a-2 > -1 && b+1 < 8){
      if((board[a-2][b+1] == "x" || board[a-2][b+1] == "P" || board[a-2][b+1] == "R" || board[a-2][b+1] == "B" || board[a-2][b+1] == "K" || board[a-2][b+1] == "Q") && KingSafe(a,b,a-2,b+1)){
        Node* name = new Node();
        name->a = a;
        name->b = b;
        name->newa = a-2;
        name->newb = b+1;
        list.push_back(name);
      }
    }
    if(a-1 > -1 && b-2 > -1){
      if((board[a-1][b-2] == "x" || board[a-1][b-2] == "P" || board[a-1][b-2] == "R" || board[a-1][b-2] == "B" || board[a-1][b-2] == "K" || board[a-1][b-2] == "Q") && KingSafe(a,b,a-1,b-2)){
        Node* name = new Node();
        name->a = a;
        name->b = b;
        name->newa = a-1;
        name->newb = b-2;
        list.push_back(name);
      }
    }
    if(a-1 > -1 && b+2 < 8){
      if((board[a-1][b+2] == "x" || board[a-1][b+2] == "P" || board[a-1][b+2] == "R" || board[a-1][b+2] == "B" || board[a-1][b+2] == "K" || board[a-1][b+2] == "Q") && KingSafe(a,b,a-1,b+2)){
        Node* name = new Node();
        name->a = a;
        name->b = b;
        name->newa = a-1;
        name->newb = b+2;
        list.push_back(name);
      }
    }
  }
}
//Compelted
void Rook(int a, int b, vector<Node*> &list){
  if(turn == 0){
    //up
    for(int i = 1;i < 8;i++){
      if(a+i == 8){
	break;
      }
      if((board[a+i][b] == "x" || board[a+i][b] == "p" || board[a+1][b] == "r" || board[a+i][b] == "b" || board[a+i][b] == "k" || board[a+i][b] == "q") && KingSafe(a,b,a+i,b)){
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
    }
    //down
    for(int i = 1;i < 8;i++){
      if(a-i == -1){
	break;
      }
      if((board[a-i][b] == "x" || board[a-i][b] == "p" || board[a-1][b] == "r" || board[a-i][b] == "b" || board[a-i][b] == "k" || board[a-i][b] == "q") && KingSafe(a,b,a-i,b)){
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
    for(int i = 1;i < 8;i++){
      if(b+i == 8){
	break;
      }
      if((board[a][b+i] == "x" || board[a][b+i] == "p" || board[a][b+i] == "r" || board[a][b+i] == "b" || board[a][b+i] == "k" || board[a][b+i] == "q") && KingSafe(a,b,a,b+i)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a;
	name->newb = b+i;
	list.push_back(name);
      }
      else{
	break;
      }
    }
    for(int i = 1;i < 8;i++){
      if(b-i == -1){
	break;
      }
      if((board[a][b-i] == "x" || board[a][b-i] == "p" || board[a][b-i] == "r" || board[a][b-i] == "b" || board[a][b-i] == "k" || board[a][b-i] == "q") && KingSafe(a,b,a,b-i)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a;
	name->newb = b-i;
	list.push_back(name);
      }
      else{
	break;
      }
    }
  }
  else if(turn == 1){
    //up
    for(int i = 1;i < 8;i++){
      if(a+i == 8){
        break;
      }
      if((board[a+i][b] == "x" || board[a+i][b] == "P" || board[a+1][b] == "R" || board[a+i][b] == "B" || board[a+i][b] == "K" || board[a+i][b] == "Q") && KingSafe(a,b,a+i,b)){
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
      if((board[a-i][b] == "x" || board[a-i][b] == "P" || board[a-1][b] == "R" || board[a-i][b] == "B" || board[a-i][b] == "K" || board[a-i][b] == "Q") && KingSafe(a,b,a-i,b)){
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
    for(int i = 1;i < 8;i++){
      if(b+i == 8){
        break;
      }
      if((board[a][b+i] == "x" || board[a][b+i] == "P" || board[a][b+i] == "R" || board[a][b+i] == "B" || board[a][b+i] == "K" || board[a][b+i] == "Q") && KingSafe(a,b,a,b+i)){
        Node* name = new Node();
        name->a = a;
        name->b = b;
        name->newa = a;
        name->newb = b+i;
        list.push_back(name);
      }
      else{
        break;
      }
    }
    for(int i = 1;i < 8;i++){
      if(b-i == -1){
        break;
      }
      if((board[a][b-i] == "x" || board[a][b-i] == "P" || board[a][b-i] == "R" || board[a][b-i] == "B" || board[a][b-i] == "K" || board[a][b-i] == "Q") && KingSafe(a,b,a,b-i)){
        Node* name = new Node();
        name->a = a;
        name->b = b;
        name->newa = a;
        name->newb = b-i;
        list.push_back(name);
      }
      else{
        break;
      }
    }
  }
}
//COMPLETED
void Bishop(int a, int b, vector<Node*> &list){
  if(turn == 0){
    //up diagonals
    for(int i = 1;i < 8;i++){
      if((a+i == 8) || (b+i == 8)){
	break;
      }
      if((board[a+i][b+i] == "x" || board[a+i][b+i] == "p" || board[a+i][b+i] == "r" || board[a+i][b+i] == "b" || board[a+i][b+i] == "k" || board[a+i][b+i] == "q") && KingSafe(a,b,a+i,b+i)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a+i;
	name->newb = b+i;
	list.push_back(name);
      }
      else{
	break;
      }
    }
    for(int i = 1;i < 8;i++){
      if((a+i == 8) || (b-i == -1)){
	break;
      }
      if((board[a+i][b-i] == "x" || board[a+i][b-i] == "p" || board[a+i][b-i] == "r" || board[a+i][b-i] == "b" || board[a+i][b-i] == "k" || board[a+i][b-i] == "q") && KingSafe(a,b,a+i,b-i)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a+i;
	name->newb = b-i;
	list.push_back(name);
      }
      else{
	break;
      }
    }
    //downward diagonals
    for(int i = 1;i < 8;i++){
      if((a-i == -1) || (b+i == 8)){
	break;
      }
      if((board[a-i][b+i] == "x" || board[a-i][b+i] == "p" || board[a-i][b+i] == "r" || board[a-i][b+i] == "b" || board[a-i][b+i] == "k" || board[a-i][b+i] == "q") && KingSafe(a,b,a-i,b+i)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a-i;
	name->newb = b+i;
	list.push_back(name);
      }
      else{
	break;
      }
    }
    for(int i = 1;i < 8;i++){
      if((a-i == -1) || (b-i == -1)){
	break;
      }
      if((board[a-i][b-i] == "x" || board[a-i][b-i] == "p" || board[a-i][b-i] == "r" || board[a-i][b-i] == "b" || board[a-i][b-i] == "k" || board[a-i][b-i] == "q") && KingSafe(a,b,a-i,b-i)){
	Node* name = new Node();
	name->a = a;
	name->b = b;
	name->newa = a-i;
	name->newb = b-i;
	list.push_back(name);
      }
      else{
	break;
      }
    }
  }
  else if(turn == 1){
    //up diagonals
    for(int i = 1;i < 8;i++){
      if((a+i == 8) || (b+i == 8)){
        break;
      }
      if((board[a+i][b+i] == "x" || board[a+i][b+i] == "P" || board[a+i][b+i] == "R" || board[a+i][b+i] == "B" || board[a+i][b+i] == "K" || board[a+i][b+i] == "Q") && KingSafe(a,b,a+i,b+i)){
        Node* name = new Node();
        name->a = a;
        name->b = b;
        name->newa = a+i;
        name->newb = b+i;
        list.push_back(name);
      }
      else{
        break;
      }
    }
    for(int i = 1;i < 8;i++){
      if((a+i == 8) || (b-i == -1)){
        break;
      }
      if((board[a+i][b-i] == "x" || board[a+i][b-i] == "P" || board[a+i][b-i] == "R" || board[a+i][b-i] == "B" || board[a+i][b-i] == "K" || board[a+i][b-i] == "Q") && KingSafe(a,b,a+i,b-i)){
        Node* name = new Node();
        name->a = a;
        name->b = b;
        name->newa = a+i;
        name->newb = b-i;
        list.push_back(name);
      }
      else{
        break;
      }
    }
    //downward diagonals
    for(int i = 1;i < 8;i++){
      if((a-i == -1) || (b+i == 8)){
        break;
      }
      if((board[a-i][b+i] == "x" || board[a-i][b+i] == "P" || board[a-i][b+i] == "R" || board[a-i][b+i] == "B" || board[a-i][b+i] == "K" || board[a-i][b+i] == "Q") && KingSafe(a,b,a-i,b+i)){
        Node* name = new Node();
        name->a = a;
        name->b = b;
        name->newa = a-i;
        name->newb = b+i;
        list.push_back(name);
      }
      else{
        break;
      }
    }
    for(int i = 1;i < 8;i++){
      if((a-i == -1) || (b-i == -1)){
        break;
      }
      if((board[a-i][b-i] == "x" || board[a-i][b-i] == "P" || board[a-i][b-i] == "R" || board[a-i][b-i] == "B" || board[a-i][b-i] == "K" || board[a-i][b-i] == "Q") && KingSafe(a,b,a-i,b-i)){
        Node* name = new Node();
        name->a = a;
        name->b = b;
        name->newa = a-i;
        name->newb = b-i;
        list.push_back(name);
      }
      else{
        break;
      }
    }
  }
}
//queen movements
void Queen(int i,int b, vector<Node*> &list){
  if(turn == 0){
    
  }
  else if(turn == 1){
    
  }
}
