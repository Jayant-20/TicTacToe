#include <iostream>
using namespace std;

char board[3][3] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char currentPlayer = 'X';

void drawBoard() {
  cout << "  1 2 3" << endl;
  for (int i = 0; i < 3; i++) {
    cout << i+1 << " ";
    for (int j = 0; j < 3; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

bool checkWin() {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
      return true;
    }
  }
  for (int j = 0; j < 3; j++) {
    if (board[0][j] == currentPlayer && board[1][j] == currentPlayer && board[2][j] == currentPlayer) {
      return true;
    }
  }
  if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
    return true;
  }
  if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
    return true;
  }
  return false;
}

bool checkTie() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        return false;
      }
    }
  }
  return true;
}

void switchPlayer() {
  if (currentPlayer == 'X') {
    currentPlayer = 'O';
  } else {
    currentPlayer = 'X';
  }
}

void play() {
  int row, col;
  cout << "It's " << currentPlayer << "'s turn. Enter row (1-3): ";
  cin >> row;
  cout << "Enter column (1-3): ";
  cin >> col;
  if (row < 1 || row > 3 || col < 1 || col > 3) {
    cout << "Invalid input. Try again." << endl;
    play();
    return;
  }
  row--;
  col--;
  if (board[row][col] != ' ') {
    cout << "That spot is already taken. Try again." << endl;
    play();
    return;
  }
  board[row][col] = currentPlayer;
  if (checkWin()) {
    drawBoard();
    cout << currentPlayer << " wins!" << endl;
    return;
  }
  if (checkTie()) {
    drawBoard();
    cout << "It's a tie!" << endl;
    return;
  }
  switchPlayer();
  drawBoard();
  play();
}

int main() {
  drawBoard();
  play();
  return 0;
}
