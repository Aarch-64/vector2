// Version: 0.2.1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/var.h"
#include "include/function.h"

PLAYER P;
OPTION O;

char dir[100];
char dir2[100];

char ini_music[100];
char g_music[100];

int main(int argc, char *argv[])
{
    cli(argc, argv);
    unsigned short int select = 5, gst; //selector, game st

    init_option(&O);
    init_dir();
    LoadOptions(&O);

    do
    {
        system("clear");    // clear terminal
        printf("Welcome to Vector\n\n"); 
        menu();
        printf("> ");
        scanf("%hu", &select);

        if (select == 1)
        {
            ngame(&P);
            SaveGame(&P);
            
            if(O.mstate)
            exit_vlc();
            
            start();
            select = 5;
        }
        else if (select == 2)
        {
            gst = LoadGame(&P);

            if (gst)
            {
                if(O.mstate)
                exit_vlc();
            
                start();
                select = 5;
            }
            else
            {
                select = 5;
                continue;
            }
        }

        else if (select == 3)
        {
            options();
            SaveOptions(&O);
            select = 5;
        }

        else if (select == 4)
        {
            controls();
            select = 5;
        }

        else if (select == 0)
            continue;

        else
        {
            printf("Wrong selection, press enter to select again");
            setbuf(stdin, NULL);
            getchar();
        }
    } while (select > 4);

    exit(EXIT_SUCCESS);
}
