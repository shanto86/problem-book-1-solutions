/**
 * Problem: UVa 220 - Othello
 * Author: sjsakib
 *
**/
#include <bits/stdc++.h>

using namespace std;

int t;
char board[9][9];
char cp;
int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

void read() {
    for (int i = 0; i < 8; i++) {
        scanf("%s\n", board[i]);
    }
}

bool inside(int r, int c) {
    return r >=0 && r < 8 && c >= 0 && c < 8;
}

void show() {
    for (int i = 0; i < 8; i++) {
        printf("%s\n", board[i]);
    }
}

void toggle_p() {
    if(cp == 'B') cp = 'W';
    else cp = 'B';
}

bool check_line(int r, int c, int dx, int dy) {
    int k = 1;
    bool found = 0; // found opponent color
    while(1) {
        int rr = r + dx*k;
        int cc = c + dy*k;
        char c = board[rr][cc];
        if(!inside(rr,cc) || c == '-' || (!found && c == cp)) return 0;
        else if(c != cp) found = 1;
        else if(c == cp && found) return 1;

        k++;
    }
}

void fill_line(int r, int c, int dx, int dy) {
    int k = 1;
    while(1) {
        int rr = r + dx*k;
        int cc = c + dy*k;
        if(board[rr][cc] == cp) return;
        board[rr][cc] = cp;
        k++;
    }
}

bool valid(int r, int c) {
    if(board[r][c] != '-') return 0;
    for (int i = 0; i < 8; i++) {
        if (check_line(r, c, dx[i], dy[i])) return 1;
    }
    return 0;
}

void lst() {
    bool found = 0; // found valid move
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if(valid(i,j)) {
                if(found) printf(" ");
                printf("(%d,%d)", i+1, j+1);
                found = 1;
            }
        }
    }
    if(!found) {
        printf("No legal move.\n");
    }
    else printf("\n");
}

void move() {
    char r,c;
    scanf("%c%c\n", &r, &c);
    r = r - '0' - 1;
    c = c - '0' - 1;
    if(!valid(r,c)) toggle_p();
    board[(int) r][(int) c] = cp;
    for (int i = 0; i < 8; i++) {
        if(check_line(r, c, dx[i], dy[i])) {
            fill_line(r, c, dx[i], dy[i]);
        }
    }
    int b = 0,w = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if(board[i][j] == 'B') b++;
            else if(board[i][j] == 'W') w++;
        }
    }
    printf("Black - %2d White - %2d\n", b, w);
    toggle_p();
}

int main() {
    scanf("%d\n", &t);
    for (int i = 0; i < t; i++) {
        if(i != 0) printf("\n");
        read();
        char c;
        scanf("%c\n", &cp);
        while(1) {
            scanf("%c\n", &c);
            if( c == 'Q' ) {
                show();
                break;
            }
            else if( c == 'L') lst();
            else move();
        }
    }
    return 0;
}