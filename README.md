### Copyright 2022 Toma-Ioan Dumitrescu


### Description

Given a piece on a 8 x 8 board, the program will find the positions
the piece can reach. Arguments of the function: x = the line, y =
the column, table = the 8 x 8 matrix. For simplification, only one
piece will be on the board. The assembly code interacts with
check_checkers.c, by implementing the following function:

void checkers(int x, int y, char table[8][8]);
