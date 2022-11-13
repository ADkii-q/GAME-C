#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void printTab(int Tab);
void Instructions();
//void PrintMatrix(int** masW, const int H);

int H, V;
int** masW;
int** masV;
int Q = 0, Z = 0, X = 0, R = 0;
int C = 1, S = 1;

void OutputInstruction() {
    printTab(27);
    printf("MAZE\n");
    printTab(20);
    printf("CREATIVE COMPUTING\n");
    printTab(18);
    printf("MORRISTOWN, NEW JERSEY\n\n\n");
    printf("DO YOU NEED INSTRUCTIONS?\n");

    char answer;
    scanf_s(" %c", &answer);

    if (answer == 'Y') {
        Instructions();
    }

    printf("WHAT ARE YOUR DIMENSIONS (HORIZONTAL, VERTICAL)\n");

    scanf_s(" %i", &H);
    scanf_s(" %i", &V);

    if (H < 5 || V < 5) {
        Instructions();
    }
    if (H < 0) { H * (-1); }
    if (V < 0) { V * (-1); }
}

void СreatingMazeField() {
    //Памядь под указатели на строки
    masW = (int**)malloc(H * sizeof(int*));
    for (int i = 0; i < H; i++)
    {
        //Память под элементы строки
        masW[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++)
            printf("%i ", (masW[i][j] = 2));
        printf("\n");
    }

    int** masV = (int**)malloc(H * sizeof(int*));
    for (int i = 0; i < H; i++)
    {
        masV[i] = (int*)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++)
            printf("%02d ", (masV[i][j] = i + j));
        printf("\n");
    }
}

void Rnd() {
    X = rand() % H;
    printf("%i random =  ", X);
}

void ExitFromMaze() {
    // Ввод элементов массива
    for (int i = 0; i <= H; i++)
    {
        if (i == X) {
            printf(":  ");
        }
        else { printf(":--"); }
    }
    printf(":");

    masW[X][1] = C;
    C = C + 1;
    R = X;
}

void go_400() {
    if (R != H) { 
        R = R + 1; 
    }
    else if (S != V) {
        R = 1;
        S = S + 1;
    }
    else {
        R = 1;
        S = 1;
    }
    go_460();
}

void go_460() {
    if (masW[R][S] == 0) {
        go_400();
    }
    else {
        StructureTheMaze();
    }
}

void StructureTheMaze() {
    if (R == 1 || masW[R - 1][S] > 0) { //470, 480
        go_830();
    }
    else if (S == 1 || masW[R][S - 1] != 0){
        go_640(); //490, 500
    }
    else if (R == H || masW[R + 1][S] > 0) {
        go_550(); //510, 520
    }
}

void Rnd_530() { 

    /*
    if (X == 1) {
        go_1200();
    }
    else if (X == 2) {
        go_1240();
    }
    else if (X == 3) {
        go_1280();
    }
    */
}

void go_550() {
    if (S != V) {
        if (masW[R][S + 1] > 0) {
            Rnd_620();
        }
        else {
            Rnd_600;
        }
    }
    else if (Z == 1) {
        Rnd_620();
    }
    else {
        Q = 1;
        Rnd_600();
    }
    if (masW[R][S + 1] > 0) {
        Rnd_620();
    }
    else {
        Rnd_600();
    }
}

void Rnd_600() {

    /*
    if (X == 1) {
        go_1200();
    }
    else if (X == 2) {
        go_1240();
    }
    else if (X == 3) {
        go_1370();
    }
    */
}


void Rnd_620() {
 
    /*
    if (X == 1) {
        go_1200();
    }
    else if (X == 2) {
        go_1240();
    }
    */
}

void go_640() {
    if (R == H || masW[R + 1][S] > 0) {
        go_750;
    }
    else if (S != V) {
        if (masW[R][S + 1] > 0) {
            Rnd_730;
        }
        else {
            Rnd_710;
        }
    }
    else if (Z == 1) {
        Rnd_730;
    }
    else {
        Q = 1;
        Rnd_710;
    }
}

void Rnd_710() {
   
    /*
    if (X == 1) {
        go_1200();
    }
    else if (X == 2) {
        go_1280();
    }
    else if (X == 3) {
        go_1370();
    }
    */
}

void Rnd_730() {
  
    /*
    if (X == 1) {
        go_1200();
    }
    else if (X == 2) {
        go_1280();
    }
    */
}

void go_750() {
    if (S != V) {
        if (masW[R][S + 1] > 0) {
            go_1200();
        }
        else {
            Rnd_800();
        }
    }
    else if (Z == 1) {
        go_1200();
    }
    else {
        Q = 1;
        Rnd_800();
    }
}

void Rnd_800() {
  
    /*
    if (X == 1) {
        go_1200();
    }
    else if (X == 2) {
        go_1370();
    }
    */
    go_1200();
}

void go_830() {
    if (S == 1 || masW[R][S - 1] > 0) {
        go_1040();
    }
    else if (R == H || masW[R + 1][S] > 0) {
        go_960();
    }
    else if (S != V) {
        if (masW[R][S + 1] > 0) {
            Rnd_940();
        }
        else {
            Rnd_920();
        }
    }
    else if (Z == 1) {
        Rnd_940();
    }
    else {
        Q = 1;
    }
}

void Rnd_920() {
   
    /*
    if (X == 1) {
        go_1240();
    }
    else if (X == 2) {
        go_1280();
    }
    else if (X == 3) {
        go_1370();
    }
    */
}

void Rnd_940() {
   
    /*
   if (X == 1) {
       go_1240();
   }
   else if (X == 2) {
       go_1280();
   }
   */
}

void go_960() {
    if (S != V) {
        if (masW[R][S + 1] > 0) {
            go_1240();
        }
        else {
            Rnd_1010();
        }
    }
    else if (Z == 1) {
        go_1240();
    }
    else {
        Q = 1;
        Rnd_1010();
    }
}

void Rnd_1010() {
   
    /*
   if (X == 1) {
       go_1240();
   }
   else if (X == 2) {
       go_1370();
   }
   go_1240();
   */
}

void go_1040() {
    if (R == H || masW[R + 1][S] > 0) {
        go_1140();
    }
    else if (S != V) {
        if (masW[R][S + 1] > 0) {
            go_1280();
        }
        else {
            Rnd_1110();
        }
    }
    else if (Z == 1) {
        go_1280();
    }
    else {
        Q = 1;
        Rnd_1110();
    }
}

void Rnd_1110() {
   
    /*
   if (X == 1) {
       go_1280();
   }
   else if (X == 2) {
       go_1370();
   }
   go_1280();
   */
}

void go_1140() {
    if (S != V) {
        if (masW[R][S + 1] > 0) {
            go_400;
        }
        else {
            go_1370;
        }
    }
    else if (Z == 1) {
        go_400;
    }
    else {
        Q = 1;
        go_1370();
    }
}

void go_1200() {
    masW[R - 1][S] = C;
    C = C + 1;
    masV[R - 1][S] = 2;
    R = R - 1;

    if (C == H * V + 1) {
        go_1510();
    }
    else {
        Q = 0;
        StructureTheMaze();
    }
}

void go_1240() {
    masW[R][S - 1] = C;
    C = C + 1;
    masV[R][S - 1] = 1;
    S = S - 1;

    if (C == H * V + 1) {
        go_1510();
    }
    else {
        Q = 0;
        StructureTheMaze();
    }
}

void go_1280() {
    masW[R + 1][S] = C
    C = C + 1

    if (masV[R][S] == 0) {
        masV[R][S] = 2; //1320
        R = R + 1;
        //go_1340();
    }
    else {
        masV[R][S] = 3;
        R = R + 1;
        //go_1340();
    }
}

void go_1340() {
    if (C == H * V + 1) {
        go_1510();
    }
    else {
        Q = 0;
        go_830();
    }
}

void go_1370() {
    if (Q == 1) {
        Z = 1;
        if (masV[R][S] == 0) {
            masV[R][S] = 1;
            Q = 0;
            R = 1;
            S = 1;
            go_460();
        }
        else {
            V[R][S]) = 3;
            Q = 0;
            go_400;
        }
    }
    else {
        masW[R][S + 1] = C;
        C = C + 1;

        if (masV[R][S] == 0) {
            masV[R][S] = 3;
            S = S + 1;
            if (C == H * V + 1) {
                go_1510();
            }
            else {
                StructureTheMaze();
            }
        }
        else {
            masV[R][S] = 3;
            S = S + 1;
            if (C == H * V + 1) {
                go_1510();
            }
            else {
                StructureTheMaze();
            }
        }
    }
}

void go_1510() {
    if (Z == 1) {
        gosub_1540();
    }
    else {
        //R=INT(RND(1)*H)+1
        S = V;
        masV[R][S] = masV[R][S] + 1;
        gosub_1540();
    }
}

void gosub_1540() { //2320
    int n;
    int m;
    for (n = 1; n <= V; n++) //n=L m=I
    {
        printf("I");
        for (m = 1; m <= H; m++) {
            if (masV[m][n] > 3) { //2350
                Z = masV[m][n] - 4; 
                if (Z < 2) { //2370
                    if (Z != masV[m][n]) { //2420
                        printf("**I");
                        break;
                    }
                    else {
                        printf("  I");
                        break;
                    }
                }
                else if (Z != V && masV[m + 1][n] > 3) {
                    printf("***");
                    break;
                }
                else if (Z != masV[m][n]) {
                    printf("** ");
                    break;
                }
                else {
                    printf("   ");
                    break;
                }

            }
            else {
                Z = masV[m][n];
                if (Z < 2) { //2370
                    if (Z != masV[m][n]) { //2420
                        printf("**I");
                        break;
                    }
                    else {
                        printf("  I");
                        break;
                    }
                }
                else if (Z != V && masV[m + 1][n] > 3) {
                    printf("***");
                    break;
                }
                else if (Z != masV[m][n]) {
                    printf("** ");
                    break;
                }
                else {
                    printf("   ");
                    break;
                }
            }
        }//for m

        printf("\n");
        for (m = 1; m <= H; m++) { //2460
            if (masV[m][n] > 3) {
                Z = masV[m][n] - 4;
                if (Z == 0) { //2490
                    printf(":--");
                    break;
                }
                else if (Z == 2) {
                    printf(":--");
                    break;
                }
                else if (Z != masV[m][n] && n == V) {
                    printf(":**");
                    break;
                }
                else if (m != masV[m][n] && masV[m][n + 1] > 3) {
                    printf(":**");
                    break;
                }
                else {
                    printf(":  "); //2540
                    break;
                }
            } else {
                Z = masV[m][n];
                if (Z == 0) { //2490
                    printf(":--");
                    break;
                }
                else if (Z == 2) {
                    printf(":--");
                    break;
                }
                else if (Z != masV[m][n] && n == V) {
                    printf(":**");
                    break;
                }
                else if (m != masV[m][n] && masV[m][n + 1] > 3) {
                    printf(":**");
                    break;
                }
                else {
                    printf(":  "); //2540
                    break;
                }
            }
        }

        printf("I");
        break;
    }//for n

    printf("\n");
    printf("\n");
}

void Solution() {
    printf("DO YOU WANT THE SOLUTION");

    char answer;
    scanf_s(" %c", &answer);

    if (answer != 'Y') {
        printf("\n\n\n");
        printf("DO YOU WANT ANOTHER MAZE");
        scanf_s(" %c", &answer);

        if (answer == 'Y') {
            //все заново
        }
    }
    else {
        printf("DO YOU WANT TO SEE EACH STEP\n\n");
    }

    for (int i = 1; i <= H; i++) {
        if (masW[i][1] == 1) {
            go_1720();
        }
        else {
            break;
        }
    }
}

void go_1720() {
    for (int i = 1; i <= H; i++) {
        for (int j = 1; i <= V; j++) {
            masW[i][j] = 0;

            if (j == 1) { //1750
                //go_1780();
                if (j == V) {
                    //go_1810();
                    if (i == H) {
                        //go_1840();
                        if (i == 1) {
                            break;
                        }
                        else (masV[i][j] == 2 || masV[i][j] == 3) {
                            masW[i][j] = masW[i][j] + 8;
                        }
                    }
                    else if (masV[i][j] == 2 || masV[i][j] == 3) {
                        masW[i][j] = masW[i][j] + 4;
                    }
                    else if (i == 1) {
                        break;
                    }
                    else (masV[i][j] == 2 || masV[i][j] == 3) {
                        masW[i][j] = masW[i][j] + 8;
                    }
                }
                else if (masV[i][j] == 1 || masV[i][j] == 3) {
                    masW[i][j] = masW[i][j] + 2;
                }
                else if (i == H) {
                    //go_1840();
                    if (i == 1) {
                        break;
                    }
                    else (masV[i][j] == 2 || masV[i][j] == 3) {
                        masW[i][j] = masW[i][j] + 8;
                    }
                }
                else if (masV[i][j] == 2 || masV[i][j] == 3) {
                    masW[i][j] = masW[i][j] + 4;
                }
                else if (i == 1) {
                    break;
                }
                else (masV[i][j] == 2 || masV[i][j] == 3) {
                    masW[i][j] = masW[i][j] + 8;
                }
            }
            else if (masV[i][j - 1] == 1 || masV[i][j - 1] == 3) {
                masW[i][j] = masW[i][j] + 1;
            }
            else if (j == V) {
                //go_1810();
                if (i == H) {
                    //go_1840();
                    if (i == 1) {
                        break;
                    }
                    else (masV[i][j] == 2 || masV[i][j] == 3) {
                        masW[i][j] = masW[i][j] + 8;
                    }
                }
                else if (masV[i][j] == 2 || masV[i][j] == 3) {
                    masW[i][j] = masW[i][j] + 4;
                }
                else if (i == 1) {
                    break;
                }
                else (masV[i][j] == 2 || masV[i][j] == 3) {
                    masW[i][j] = masW[i][j] + 8;
                }
            }
            else if (masV[i][j] == 1 || masV[i][j] == 3) {
                masW[i][j] = masW[i][j] + 2;
            }
            else if (i == H) {
                //go_1840();
                if (i == 1) {
                    break;
                }
                else (masV[i][j] == 2 || masV[i][j] == 3) {
                    masW[i][j] = masW[i][j] + 8;
                }
            }
            else if (masV[i][j] == 2 || masV[i][j] == 3) {
                masW[i][j] = masW[i][j] + 4;
            }
            else if (i == 1) {
                break;
            }
            else if (masV[i][j] == 2 || masV[i][j] == 3) {
                masW[i][j] = masW[i][j] + 8;
            }
            else {
                break;
            }
        }
    }
}
/*
void go_1780() {
    if (j == V) {
        go_1810();
    }
    else if (masV[i][j] == 1 || masV[i][j] == 3) {
        masW[i][j] = masW[i][j] + 2;
    }
    else if (i == H) {
        go_1840();
    }
    else if (masV[i][j] == 2 || masV[i][j] == 3) {
        masW[i][j] = masW[i][j] + 4;
    }
    else if (i == 1) {
        break;
    }
    else (masV[i][j] == 2 || masV[i][j] == 3) {
        masW[i][j] = masW[i][j] + 8;
    }
}

void go_1810() {
    if (i == H) {
        go_1840();
    }
    else if (masV[i][j] == 2 || masV[i][j] == 3) {
        masW[i][j] = masW[i][j] + 4;
    }
    else if (i == 1) {
        break;
    }
    else (masV[i][j] == 2 || masV[i][j] == 3) {
        masW[i][j] = masW[i][j] + 8;
    }
}

void go_1840() {
    if (i == 1) {
        break;
    }
    else (masV[i][j] == 2 || masV[i][j] == 3) {
        masW[i][j] = masW[i][j] + 8;
    }
}
*/

void go_1880() {
    for (int i = 1; i <= H; i++) {
        if (masV[i][V] == 1 || masV[i][V] == 3) {
            masW[i][V] = masW[i][V] + 2;
            E = i;
            Y = 1;
            X = S;
            masV[X][Y] = masV[X][Y] + 4;
            go_1950();
        }
    }
}

void go_1950() {
    if (Y == V && X == E) {
        printf("\n");
        for (int i = 1; i <= H; i++) {
            if (i == S) {
                printf(":**");
            }
            else {
                printf(":--");
            }
        }
        gosub_1540(); //2320
    }
    printf("\n\n");
    //go_2620 ?
}

void go_1980() {
    if ((masW[X][Y] && 2) != 0) {
        go_2030();
    } 
    go_1990();
}

void go_1990() {
    if ((masW[X][Y] && 4) != 0) {
        go_2080();
    }
    go_2000();
}

void go_2000() {
    if ((masW[X][Y] && 8) != 0) {
        go_2130();
    }
    go_2010();
}

void go_2010() {
    if ((masW[X][Y] && 1) != 0) {
        go_2180();
    }
    go_1950();
}

void go_2030() {
    if ((masV[X][Y + ] + 1) > 3 && (masW[X][Y] AND 13) == 0) {
        masV[X][Y] = masV[X][Y] - 4;
        masW[X][Y] = (masW[X][Y] AND 13);
        Y = Y + 1;
        masW[X][Y] = (masW[X][Y] AND 14);
    }
    else if (masV[X][Y + 1] > 3) {
        go_1990();
    }
    else {
        Y = Y + 1;
        masV[X][Y] = masV[X][Y] + 4;
        go_1950();
    }
}

void go_2080() {
    if (masV[X + 1][Y] > 3 AND((masW[X][Y] AND 11) == 0)) {
        masV[X][Y] = masV[X][Y] - 4;
        masW[X][Y] = (masW[X][Y] AND 11);
        X = X + 1;
        masW[X][Y] = (masW[X][Y] AND 7);
    }
    else if (masV[X + 1][Y] > 3) {
        go_2000();
    }
    else {
        X = X + 1;
        masV[X][Y] = masV[X][Y] + 4;
        go_1950();
    }
}

void go_2130() {
    if (masV[X - 1][Y] AND((masW[X][Y] AND 7) == 0)) {
        masV[X][Y] = masV[X][Y] - 4;
        masW[X][Y] = (masW[X][Y] AND 7);
        X = X - 1;
        masW[X][Y] = (masW[X][Y] AND 11);
    }
    else if (masV[X - 1][Y] > 3) {
        go_2010();
    }
    else {
        X = X - 1;
        masV[X][Y] = (masV[X][Y] + 4);
        go_1950();
    }
}

void go_2180() {
    if (masV[X][Y - 1] > 3 AND(masW[X][Y] AND 14) == 0) {
        masV[X][Y] = masV[X][Y] - 4;
        masW[X][Y] = (masW[X][Y] AND 14);
        Y = Y - 1;
        masW[X][Y] = (masW[X][Y] AND 13);
    }
    else if (masV[X][Y-1] > 3) {
        go_1980();
    }
    else {
        Y = Y - 1;
        masV[X][Y] = (masV[X][Y] + 4);
        go_1950();
    }
}

int main()
{
    OutputInstruction();
    СreatingMazeField();
    Rnd();
    ExitFromMaze();
    gosub_1540();
    
}
    //void PrintMatrix(int** masW, const int H, const int V);
    //printf("Исходная матрица");
    //PrintMatrix(**masW, H, V);
    //masW = (int*)malloc(sizeof(int) * H * V);
    //masV = (int*)malloc(sizeof(int) * H * V);


/*
void PrintMatrix(int** masW, const int H) {

    printf("%i ", masW[1][1]);
}
*/
void printTab(int Tab)
{
    for (int T = 0; T < Tab; T++)
    {
        printf(" ");
    }
}

void Instructions() 
{
    printf("THIS PROGRAM WILL SIMULATE A NEAR-SIGHTED MOUSE IN\n");
    printf("A MAZE.  YOU SELECT THE DIFFICULTY FACTOR -SIZE!\n");
    printf("YOU MAY HAVE A MAZE OF ANY SIZE PERMITTED BY THE SIZE OF YOUR\n");
    printf("SYSTEM. DIMENSIONS LESS THAN 5 ARE TOO TRIVIAL.\n");
    printf("EACH MAZE IS DIFFERENT, AND HAS ONLY ONE WAY THROUGH IT.\n\n");
}


