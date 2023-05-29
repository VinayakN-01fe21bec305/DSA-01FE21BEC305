#include <stdio.h>


char chessboard[8][8] = {
    {'e', 'k', 'm', 'q', 'k', 'm', 'k', 'e'},
    {'s', 's', 's', 's', 's', 's', 's', 's'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S'},
    {'E', 'K', 'M', 'Q', 'K', 'M', 'K', 'E'}
};


 void display_board() {
    for(int row = 0; row < 8; row++) {
        for(int col = 0; col < 8; col++) {
            printf("%c ", chessboard[row][col]);
        }
        printf("\n");
    }
}

  int main()
  {
      display_board();
      return 0;
  }
