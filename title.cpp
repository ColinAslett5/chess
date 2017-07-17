#include <iostream>
using namespace std;
void board();// the board
void setup();//setting up the starting positions
int score();//calculates score, positive score is good for white, negative good for black
string move();//computer decides what piece to move
char white[8][8];//char array for the white pieces, will keep the location of all white pieces
char black[8][8];//char array for the black pieces, will keep the location of all black pieces
//checking all possible moves for certain piece types
string Pawn(int a, int b);
string Rook(int a, int b);
string Bishop(int a, int b);
string Knight(int a, int b);
string Queen(int a, int b);
string King(int a, int b);
//turn calculations
int turn = 0;//0 = white, 1 = black
bool Kingsafe();//have to make sure the moves dont induce a check
//global strings for notation purposes
string letter[] = {"H","G","F","E","D","C","B","A"};//might want to make this global
string number[] = {"1","2","3","4","5","6","7","8"};
int main(){
  //initially setting all squares to NULL
  for(int i = 0;i < 8;i++){
    for(int b = 0;b < 8;b++){
      white[i][b] = 'x';
      black[i][b] = 'x';
    }
  }
  setup();
  board();
  cout << "Possible Moves: " << move() << endl;
  cout << "Evaluation: " << score();
  return 0;
}
//printing out the board
void board(){
  for(int i = 7;i > -1;i--){
    for(int b = 7;b > -1;b--){
      if(white[i][b] != 'x'){
	cout << white[i][b];
      }
      else if(black[i][b] != 'x'){
	cout << black[i][b];
      }
      else{
	cout << black[i][b];
      }
    }
    cout << endl;
  }
}
//setting up the board
void setup(){
  //white
  for(int i = 0;i < 8;i++){
    white[1][i] = 'P';
  }
  white[2][0] = 'R';
  white[0][7] = 'R';
  white[0][1] = 'H';
  white[0][6] = 'H';
  white[0][2] = 'B';
  white[0][5] = 'B';
  white[0][3] = 'Q';
  white[0][4] = 'K';
  //black
  for(int i = 0;i < 8;i++){
    black[6][i] = 'p';
  }
  black[7][0] = 'r';
  black[7][7] = 'r';
  black[7][1] = 'h';
  black[7][6] = 'h';
  black[7][2] = 'b';
  black[7][5] = 'b';
  black[7][3] = 'q';
  black[7][4] = 'k';
}
//score calculations
int score(){
  //looks at pieces first
  int wsc = 0;//whites score
  int bsc = 0;//blacks score
  for(int i = 0;i < 8;i++){
    for(int b = 0;b < 8;b++){
      if(white[i][b] == 'P'){
	wsc++;
      }
      else if(white[i][b] == 'H' || white[i][b] == 'B'){
	wsc += 3;
      }
      else if(white[i][b] == 'R'){
	wsc += 5;
      }
      else if(white[i][b] == 'Q'){
	wsc += 8;
      }
    }
  }
  for(int i = 0;i < 8;i++){
    for(int b = 0;b < 8;b++){
      if(black[i][b] == 'p'){
        bsc++;
      }
      else if(black[i][b] == 'h' || black[i][b] == 'b'){
        bsc += 3;
      }
      else if(black[i][b] == 'r'){
        bsc += 5;
      }
      else if(black[i][b] == 'q'){
        bsc += 8;
      }
    }
  }
  return wsc-bsc;
}
//what move to do?
string move(){
  string list = " ";//contains the list of all possible moves
  //deciding who moves
  for(int i = 0;i < 8;i++){
    for(int b = 0;b < 8;b++){
      if(white[i][b] == 'P'){
	list = list+Pawn(i,b);
      }
      else if(white[i][b] == 'H'){
	list = list+Knight(i,b);
      }
      else if(white[i][b] == 'B'){
	//list = list+Bishop(i,b);
      }
      else if(white[i][b] == 'R'){
	list = list+Rook(i,b);
      }
      else if(white[i][b] == 'Q'){
	list = list+Queen(i,b);
      }
      else if(white[i][b] == 'K'){
	list = list+King(i,b);
      }
    }
  }
  return list;
}
//pawn moves
string Pawn(int a, int b){//strings need spaces when they are initialized
  string rtstr = " ";//return string
  if(white[a+1][b] == 'x' && black[a+1][b] == 'x' && Kingsafe()){
    //rtstr = rtstr + letter[a+1] + to_string(b);
    rtstr = rtstr + letter[b] + number[a] + "->" + letter[b] + number[a+1];
  }
  if(white[a+2][b] == 'x' && black[a+2][b] == 'x' && Kingsafe()){
    rtstr = rtstr + letter[b] + number[a] + "->" + letter[b] + number[a+2];
  }
  return rtstr;
}
string Rook(int a, int b){
  string rtstr = " ";
  //right to left
  for(int i = b+1;i < 8;i++){
    if(white[a][i] == 'x' && black[a][i] == 'x' && Kingsafe()){
      rtstr = rtstr + letter[b] + number[a] + "->" + letter[i] + number[a];
    }
    else{
      break;
    }
  }
  return rtstr;
}
string Bishop(int a, int b){
  string rtstr = " ";
  return rtstr;
}
string Knight(int a, int b){
  string rtstr = " ";
  if(white[a+2][b+1] == 'x' && black[a+2][b+1] == 'x' && Kingsafe()){
    rtstr = rtstr + letter[b] + number[a] + "->" + letter[b+1] + number[a+2];
  }
  if(white[a+2][b+1] == 'x' && black[a+2][b-1] == 'x' && Kingsafe()){
    rtstr = rtstr + letter[b] + number[a] + "->" + letter[b-1] + number[a+2];
  }
  if(white[a+1][b+2] == 'x' && black[a+1][b+2] == 'x' && Kingsafe()){
    rtstr = rtstr + letter[b] + number[a] + "->" + letter[b+2] + number[a+1];
  }
  if(white[a+1][b-2] == 'x' && black[a+1][b-2] == 'x' && Kingsafe()){
    rtstr = rtstr + letter[b] + number[a] + "->" + letter[b-2] + number[a+1];
  }
  if(white[a-2][b+1] == 'x' && black[a-2][b+1] == 'x' && Kingsafe()){
    rtstr = rtstr + letter[b] + number[a] + "->" + letter[b+1] + number[a-2];
  }
  if(white[a-2][b-1] == 'x' && black[a-2][b-1] == 'x' && Kingsafe()){
    rtstr = rtstr + letter[b] + number[a] + "->" + letter[b-1] + number[a-2];
  }
  return rtstr;
}
string Queen(int a, int b){
  string rtstr = " ";
  //right movement
  for(int i = b+1;i < 8;i++){
    if(white[a][i] == 'x' && black[a][i] == 'x' && Kingsafe()){
      rtstr = rtstr + letter[b] + number[a] + "->" + letter[i] + number[a];
    }
    else{//there is a piece in the way
      break;
    }
  }
  //left movement
  for(int i = b-1;i > -1;i--){
    if(white[a][i] == 'x' && black[a][i] == 'x' && Kingsafe()){
      rtstr = rtstr + letter[b] + number[a] + "->" + letter[i] + number[a];
    }
    else{
      break;
    }
  }
  //Up movement
  for(int i = a+1;i < 8;i++){
    if(white[i][b] == 'x' && black[i][b] == 'x' && Kingsafe()){
      rtstr = rtstr + letter[b] + number[a] + "->" + letter[b] + number[i];
    }
    else{
      break;
    }
  }
  //down movement
  for(int i = a-1;i > -1;i--){
    if(white[i][b] == 'x' && black[i][b] == 'x' && Kingsafe()){
      rtstr = rtstr + letter[b] + number[a] + "->" + letter[b] + number[i];
    }
    else{
      break;
    }
  }
  return rtstr;
}
string King(int a, int b){
  string rtstr = " ";
  //eight possible moves
  if(white[a+1][b-1] == 'x' && black[a+1][b-1] == 'x' && Kingsafe()){
    rtstr = rtstr + letter[b] + number[a] + "->" + letter[b-1] + number[a+1];
  }
  if(white[a+1][b] == 'x' && black[a+1][b] == 'x' && Kingsafe()){
    rtstr = rtstr + letter[b] + number[a] + "->" + letter[b] + number[a+1];
  }
  if(white[a+1][b+1] == 'x' && black[a+1][b+1] == 'x' && Kingsafe()){
    rtstr = rtstr + letter[b] + number[a] + "->" + letter[b+1] + number[a+1];
  }
  if(white[a][b-1] == 'x' && black[a][b-1] == 'x' && Kingsafe()){
    rtstr = rtstr + letter[b] + number[a] + "->" + letter[b-1] + number[a];
  }
  if(white[a][b+1] == 'x' && black[a+1][b+1] == 'x' && Kingsafe()){
    rtstr = rtstr + letter[b] + number[a] + "->" + letter[b+1] + number[a];
  }
  if(white[a-1][b-1] == 'x' && black[a-1][b-1] == 'x' && Kingsafe()){
    rtstr = rtstr + letter[b] + number[a] + "->" + letter[b-1] + number[a-1];
  }
  if(white[a-1][b] == 'x' && black[a-1][b] == 'x' && Kingsafe()){
    rtstr = rtstr + letter[b] + number[a] + "->" + letter[b] + number[a-1];
  }
  if(white[a-1][b+1] == 'x' && black[a-1][b+1] == 'x' && Kingsafe()){
    rtstr = rtstr + letter[b] + number[a] + "->" + letter[b+1] + number[a-1];
  }
  //castling also
  return rtstr;  
}
//have to make sure the king is not in check when a move is made
bool Kingsafe(){
  return true;
}
