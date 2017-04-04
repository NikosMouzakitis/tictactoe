#include <stdio.h>
#include <stdlib.h>

    /* Tic Tac Toe Game
                        written in C.
        User got the first move on this game.
    AI shows boths defensive reactions as well
    as making move to win,instead of avoiding
    to lose if its one move away of winning.
        Mouzakitis Nikolaos,Crete April 2017.
                                            */

int ai_driver[24][3] = {        //Used to determine the winning state,as well as for AI's decisions.
    {1,2,3},
    {1,3,2},
    {2,3,1},
    {4,5,6},
    {4,6,5},
    {5,6,4},
    {7,8,9},
    {7,9,8},
    {9,8,7},
    {1,4,7},
    {1,7,4},
    {4,7,1},
    {2,8,5},
    {2,5,8},
    {8,5,2},
    {3,6,9},
    {6,9,3},
    {3,9,6},
    {1,5,9},
    {1,9,5},
    {5,9,1},
    {3,5,7},
    {3,7,5},
    {5,7,3}
};

char tic_grid[3][3];
int run_state = 1;
int squares_filled = 0;
int step = 0;

struct square
{
    int r;
    int c;
};


void display_grid()
{
    int i,j;
    printf("------------------\n");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            printf("  %c  |",tic_grid[i][j]);
        }
        printf("\n------------------\n");
    }
}

struct square * decode(int src)
{
    struct square *rv;

    switch(src)
    {
        case 1:
                rv->r = 0;
                rv->c = 0;
                return rv;
        case 2:
                rv->r = 0;
                rv->c = 1;
                return rv;
        case 3:
                rv->r = 0;
                rv->c = 2;
                return rv;
        case 4:
                rv->r = 1;
                rv->c = 0;
                return rv;
        case 5:
                rv->r = 1;
                rv->c = 1;
                return rv;
        case 6:
                rv->r = 1;
                rv->c = 2;
                return rv;
        case 7:
                rv->r = 2;
                rv->c = 0;
                return rv;
        case 8:
                rv->r = 2;
                rv->c = 1;
                return rv;
        case 9:
                rv->r = 2;
                rv->c = 2;
                return rv;
        default:
                fprintf(stderr,"Error,exit schedulled.\n");
                exit(2);
    }
}

void game_check()
{
    int i;

    for(i = 0; i < 24; i++)
    {
        int a,b,c,d,e,f;

        switch(ai_driver[i][0])
        {
            case 1:
                a = 0;
                b = 0;
                break;
            case 2:
                a = 0;
                b = 1;
                break;
            case 3:
                a = 0;
                b = 2;
                break;
            case 4:
                a = 1;
                b = 0;
                break;
            case 5:
                a = 1;
                b = 1;
                break;
            case 6:
                a = 1;
                b = 2;
                break;
            case 7:
                a = 2;
                b = 0;
                break;
            case 8:
                a = 2;
                b = 1;
                break;
            case 9:
                a = 2;
                b = 2;
                break;
        }

        switch(ai_driver[i][1])
        {
            case 1:
                c = 0;
                d = 0;
                break;
            case 2:
                c = 0;
                d = 1;
                break;
            case 3:
                c = 0;
                d = 2;
                break;
            case 4:
                c = 1;
                d = 0;
                break;
            case 5:
                c = 1;
                d = 1;
                break;
            case 6:
                c = 1;
                d = 2;
                break;
            case 7:
                c = 2;
                d = 0;
                break;
            case 8:
                c = 2;
                d = 1;
                break;
            case 9:
                c = 2;
                d = 2;
                break;
        }

        switch(ai_driver[i][2])
        {
            case 1:
                e = 0;
                f = 0;
                break;
            case 2:
                e = 0;
                f = 1;
                break;
            case 3:
                e = 0;
                f = 2;
                break;
            case 4:
                e = 1;
                f = 0;
                break;
            case 5:
                e = 1;
                f = 1;
                break;
            case 6:
                e = 1;
                f = 2;
                break;
            case 7:
                e = 2;
                f = 0;
                break;
            case 8:
                e = 2;
                f = 1;
                break;
            case 9:
                e = 2;
                f = 2;
                break;
        }


        if( (tic_grid[a][b] == 'X') && (tic_grid[c][d] == 'X') && (tic_grid[e][f] == 'X') )
        {
               printf("You are the winner!!\n");
               system("pause");
               exit(0);
        }
        if( (tic_grid[a][b] == 'O') && (tic_grid[c][d] == 'O') && (tic_grid[e][f] == 'O') )
        {
               printf("You have just lost!!\n");
               system("pause");
               exit(0);
        }
    }
}

void danger_check(int *flag,int *tr,int *tc)
{
    int i;

    for(i = 0; i < 24; i++)
    {
        int a,b,c,d,e,f;

        switch(ai_driver[i][0])
        {
            case 1:
                a = 0;
                b = 0;
                break;
            case 2:
                a = 0;
                b = 1;
                break;
            case 3:
                a = 0;
                b = 2;
                break;
            case 4:
                a = 1;
                b = 0;
                break;
            case 5:
                a = 1;
                b = 1;
                break;
            case 6:
                a = 1;
                b = 2;
                break;
            case 7:
                a = 2;
                b = 0;
                break;
            case 8:
                a = 2;
                b = 1;
                break;
            case 9:
                a = 2;
                b = 2;
                break;
        }

        switch(ai_driver[i][1])
        {
            case 1:
                c = 0;
                d = 0;
                break;
            case 2:
                c = 0;
                d = 1;
                break;
            case 3:
                c = 0;
                d = 2;
                break;
            case 4:
                c = 1;
                d = 0;
                break;
            case 5:
                c = 1;
                d = 1;
                break;
            case 6:
                c = 1;
                d = 2;
                break;
            case 7:
                c = 2;
                d = 0;
                break;
            case 8:
                c = 2;
                d = 1;
                break;
            case 9:
                c = 2;
                d = 2;
                break;
        }

        switch(ai_driver[i][2])
        {
            case 1:
                e = 0;
                f = 0;
                break;
            case 2:
                e = 0;
                f = 1;
                break;
            case 3:
                e = 0;
                f = 2;
                break;
            case 4:
                e = 1;
                f = 0;
                break;
            case 5:
                e = 1;
                f = 1;
                break;
            case 6:
                e = 1;
                f = 2;
                break;
            case 7:
                e = 2;
                f = 0;
                break;
            case 8:
                e = 2;
                f = 1;
                break;
            case 9:
                e = 2;
                f = 2;
                break;
        }



        if( (tic_grid[a][b] == 'X') && (tic_grid[c][d] == 'X') && (tic_grid[e][f] == 0) )
        {
            *flag = 1;

            *tr = e;
            *tc = f;
        }
    }


}

void one_move_check(int *rv,int *or,int *oc)
{

int i;

    for(i = 0; i < 24; i++)
    {
        int a,b,c,d,e,f;

        switch(ai_driver[i][0])
        {
            case 1:
                a = 0;
                b = 0;
                break;
            case 2:
                a = 0;
                b = 1;
                break;
            case 3:
                a = 0;
                b = 2;
                break;
            case 4:
                a = 1;
                b = 0;
                break;
            case 5:
                a = 1;
                b = 1;
                break;
            case 6:
                a = 1;
                b = 2;
                break;
            case 7:
                a = 2;
                b = 0;
                break;
            case 8:
                a = 2;
                b = 1;
                break;
            case 9:
                a = 2;
                b = 2;
                break;
        }

        switch(ai_driver[i][1])
        {
            case 1:
                c = 0;
                d = 0;
                break;
            case 2:
                c = 0;
                d = 1;
                break;
            case 3:
                c = 0;
                d = 2;
                break;
            case 4:
                c = 1;
                d = 0;
                break;
            case 5:
                c = 1;
                d = 1;
                break;
            case 6:
                c = 1;
                d = 2;
                break;
            case 7:
                c = 2;
                d = 0;
                break;
            case 8:
                c = 2;
                d = 1;
                break;
            case 9:
                c = 2;
                d = 2;
                break;
        }

        switch(ai_driver[i][2])
        {
            case 1:
                e = 0;
                f = 0;
                break;
            case 2:
                e = 0;
                f = 1;
                break;
            case 3:
                e = 0;
                f = 2;
                break;
            case 4:
                e = 1;
                f = 0;
                break;
            case 5:
                e = 1;
                f = 1;
                break;
            case 6:
                e = 1;
                f = 2;
                break;
            case 7:
                e = 2;
                f = 0;
                break;
            case 8:
                e = 2;
                f = 1;
                break;
            case 9:
                e = 2;
                f = 2;
                break;
        }
        if( (tic_grid[a][b] == 'O') && (tic_grid[c][d] == 'O') && (tic_grid[e][f] == 0) )
        {
            *rv = 1;

            *or = e;
            *oc = f;
        }
    }
}

void ai_step()
{
    int i,j;
    int danger_flag = 0;    //initialized to 0
    int one_move_win = 0;   //if AI can win within' a move.
    int tr,tc,or,oc;  // target column,row.

    one_move_check(&one_move_win,&or,&oc);
    danger_check(&danger_flag,&tr,&tc);


    if( (step == 3) && ( tic_grid[1][1] == 'X') && (tic_grid[2][2] == 'X') )
    {
        tic_grid[0][2] = 'O';                         // to avoid losing by choosing the best suitable move at this step.
        squares_filled++;

        return;
    }

    if( (step == 3) && (tic_grid[0][0] == 'X') && (tic_grid[2][2] == 'X') && (tic_grid[1][1] == 'O') )
    {
        tic_grid[2][1] = 'O';                         // to avoid losing by choosing the best suitable move at this step.
        squares_filled++;

        return;

    }

    if( (step == 3) && (tic_grid[0][0] == 'X') && (tic_grid[2][1] == 'X') && (tic_grid[1][1] == 'O') )
    {
        tic_grid[2][0] = 'O';                         // to avoid losing by choosing the best suitable move at this step.
        squares_filled++;

        return;

    }

    if( (step == 3) && (tic_grid[1][2] == 'X') && (tic_grid[2][0] == 'X') && (tic_grid[1][1] == 'O') )
    {
        tic_grid[2][2] = 'O';                         // to avoid losing by choosing the best suitable move at this step.
        squares_filled++;

        return;

    }

    if( (step == 3) && (tic_grid[0][2] == 'X') && (tic_grid[2][0] == 'X') && (tic_grid[1][1] == 'O') )
    {
        tic_grid[2][1] = 'O';                         // to avoid losing by choosing the best suitable move at this step.
        squares_filled++;

        return;

    }


    if( (step == 3) && (tic_grid[0][2] == 'X') && (tic_grid[2][1] == 'X') && (tic_grid[1][1] == 'O') )
    {
        tic_grid[2][2] = 'O';                         // to avoid losing by choosing the best suitable move at this step.
        squares_filled++;

        return;

    }


    if( (step == 5) && (tic_grid[0][0] == 'X') && (tic_grid[0][1] == 'O') && (tic_grid[1][1] == 'O') && (tic_grid[1][2] == 'X') && (tic_grid[2][1] == 'X') )
    {
        printf("i m working\n");
        tic_grid[2][2] = 'O';                         // to avoid losing by choosing the best suitable move at this step.
        squares_filled++;

        return;

    }


    if(one_move_win)
    {
        tic_grid[or][oc] = 'O';
        squares_filled++;

        return;
    }


    if(danger_flag)
    {
        tic_grid[tr][tc] = 'O';
        squares_filled++;
    }
    else
    {





        if(tic_grid[1][1] == 0)
        {
            tic_grid[1][1] = 'O';
            squares_filled++;

            return;
        }
        else
        {
            for(i = 0; i < 3; i++)
            {
                for(j = 0; j < 3; j++)
                {
                    if(tic_grid[i][j] == 0)
                    {
                        tic_grid[i][j] = 'O';
                        squares_filled++;
                        return;
                    }
                }
            }
        }
    }
}

void set_square(int choice)
{

    struct square *p;
    p = decode(choice);
    tic_grid[p->r][p->c] = 'X';
    squares_filled++;
}


int is_valid(int choice)
{
    struct square *p;

    p = decode(choice);

    if(tic_grid[p->r][p->c] != 0)
        return 0;   // not valid
    return 1;       //valid
}

void display_ai_driver()
{

    int i;
    for(i = 0; i < 23; i++)
        printf("%d %d %d\n",ai_driver[i][0],ai_driver[i][1],ai_driver[i][2]);

}

int main(int argc,char *argv[])
{
    int choice;
    printf("SUPER DEFFENCIVE AI\n");
    display_grid();

    while(run_state)
    {
        printf("Select square(1-9)\n");
        scanf("%d",&choice);

        while(!is_valid(choice))
        {
            printf("Enter a valid square to set\n");
            scanf("%d",&choice);
        }

        set_square(choice);
        step++;
        printf("\n");
        display_grid();
        game_check();
        ai_step();
        step++;
        printf("\n");

        display_grid();
        game_check();

        if(squares_filled == 9)
            run_state = 0;

    }
    printf("Draw\nGame ends\n");
    system("pause");
    return 0;
}
