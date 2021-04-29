#ifndef MAIN_H
#define MAIN_H

int checkInput(char buffer[]);
void printLabyrinth(int n, int **labyrinth);
void pathFinder(int i, int j, int **labyrinth, int n);
int way(int n, int **labyrinth);

#endif