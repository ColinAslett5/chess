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
bool KingSafe();
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
//is the king going to be in check
bool KingSafe(){
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
  board[5][4] = "A";
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
	  King(i,b,list);
	}
	if(board[i][b] == "P"){
	  //Pawn(i,b,list);
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
  if(turn == 0){
    if(board[a+1][b] == "x" && KingSafe()){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a+1;
      name->newb = b;
      list.push_back(name);
    }
    if(board[a+2][b] == "x" && board[a+1][b] == "x" && KingSafe()){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a+2;
      name->newb = b;
      list.push_back(name);
    }
    //also captures, two diagonals
    if((board[a+1][b-1] == "p" || board[a+1][b-1] == "r" || board[a+1][b-1] == "b" || board[a+1][b-1] == "k" || board[a+1][b-1] == "q") && KingSafe()){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a+1;
      name->newb = b-1;
      list.push_back(name);
    }
    if((board[a+1][b+1] == "p" || board[a+1][b+1] == "r" || board[a+1][b+1] == "b" || board[a+1][b+1] == "k" || board[a+1][b+1] == "q") && KingSafe()){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a+1;
      name->newb = b+1;
      list.push_back(name);
    }
  }
  else if(turn == 1){
    if(board[a-1][b] == "x" && KingSafe()){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a-2;
      name->newb = b;
      list.push_back(name);
    }
    if(board[a-2][b] == "x" && KingSafe()){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a-2;
      name->newb = b;
      list.push_back(name);
    }
    if((board[a-1][b-1] == "P" || board[a-1][b-1] == "R" || board[a-1][b-1] == "B" || board[a-1][b-1] == "K" || board[a-1][b-1] == "Q") && KingSafe()){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a-1;
      name->newb = b-1;
      list.push_back(name);
    }
    if((board[a-1][b+1] == "P" || board[a-1][b+1] == "R" || board[a-1][b+1] == "B" || board[a-1][b+1] == "K" || board[a-1][b+1] == "Q") && KingSafe()){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a-1;
      name->newb = b+1;
      list.push_back(name);
    }
  }
}
//King moving
void King(int a,int b, vector<Node*> &list){
  if(a+1 < 8 && b-1 > -1){
    if((board[a+1][b-1] == "x" || board[a+1][b-1] == "p" || board[a+1][b-1] == "r" || board[a+1][b-1] == "b" || board[a+1][b-1] == "k" || board[a+1][b-1] == "q") && KingSafe()){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a+1;
      name->newb = b-1;
      list.push_back(name);
    }
  }
  if(a+1 < 8){
    if((board[a+1][b] == "x" || board[a+1][b] == "p" || board[a+1][b] == "r" || board[a+1][b] == "b" || board[a+1][b] == "k" || board[a+1][b] == "q") && KingSafe()){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a+1;
      name->newb = b;
      list.push_back(name);
    }
  }
  if(a+1 < 8 && b+1 < 8){
    if((board[a+1][b+1] == "x" || board[a+1][b+1] == "p" || board[a+1][b+1] == "r" || board[a+1][b+1] == "b" || board[a+1][b+1] == "k" || board[a+1][b+1] == "q") && KingSafe()){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a+1;
      name->newb = b+1;
      list.push_back(name);
    }
  }
  if(b-1 > -1){
    if((board[a][b-1] == "x" || board[a][b-1] == "p" || board[a][b-1] == "r" || board[a][b-1] == "b" || board[a][b-1] == "k" || board[a][b-1] == "q") && KingSafe()){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a;
      name->newb = b-1;
      list.push_back(name);
    }
  }
  if(b+1 < 8){
    if((board[a][b+1] == "x" || board[a][b+1] == "p" || board[a][b+1] == "r" || board[a][b+1] == "b" || board[a][b+1] == "k" || board[a][b+1] == "q") && KingSafe()){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a;
      name->newb = b+1;
      list.push_back(name);
    }
  }
  if(a-1 > -1 && b-1 > -1){
    if((board[a-1][b-1] == "x" || board[a-1][b-1] == "p" || board[a-1][b-1] == "r" || board[a-1][b-1] == "b" || board[a-1][b-1] == "k" || board[a-1][b-1] == "q") && KingSafe()){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a-1;
      name->newb = b-1;
      list.push_back(name);
    }
  }
  if(a-1 > -1){
    if((board[a-1][b] == "x" || board[a-1][b] == "p" || board[a-1][b] == "r" || board[a-1][b] == "b" || board[a-1][b] == "k" || board[a-1][b] == "q") && KingSafe()){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a-1;
      name->newb = b;
      list.push_back(name);
    }
  }
  if(a-1 > -1 && b+1 < 8){
    if((board[a-1][b+1] == "x" || board[a-1][b+1] == "p" || board[a-1][b+1] == "r" || board[a-1][b+1] == "b" || board[a-1][b+1] == "k" || board[a-1][b+1] == "q") && KingSafe()){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a-1;
      name->newb = b+1;
      list.push_back(name);
    }
  }
  //castling
}
//moves for the knight
void Knight(int a,int b, vector<Node*> &list){
  if(a+2 < 8 && b-1 > -1){
    if(board[a+2][b-1] == "x"){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a+2;
      name->newb = b-1;
      list.push_back(name);
    }
  }
  if(a+2 < 8 && b+1 < 8){
    if(board[a+2][b+1] == "x"){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a+2;
      name->newb = b+1;
      list.push_back(name);
    }
  }
  if(a+1 < 8 && b-2 > -1){
    if(board[a+1][b-2] == "x"){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a+1;
      name->newb = b-2;
      list.push_back(name);
    }
  }
  if(a+1 < 8 && b+2 < 8){
    if(board[a+1][b+2] == "x"){
      Node* name = new Node();
      name->a = a;
      name->b = b;
      name->newa = a+1;
      name->newb = b+2;
      list.push_back(name);
    }
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
  for(int i = 1;i < 8;i++){
    if(b+i == 8){
      break;
    }
    if(board[a][b+i] == "x"){
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
    if(board[a][b-i] == "x"){
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
//bishop possible moves
void Bishop(int a, int b, vector<Node*> &list){
  //up diagonals
  for(int i = 1;i < 8;i++){
    if((a+i == 8) || (b+i == 8)){
      break;
    }
    if(board[a+i][b+i] == "x"){
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
    if(board[a+i][b-i] == "x"){
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
    if(board[a-i][b+i] == "x"){
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
    if(board[a-i][b-i] == "x"){
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
//queen movements
