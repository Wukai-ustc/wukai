#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "menu.h"
int Quit(int argc, char **argv)
{
    exit(0);
}
int argtest(int argc, char **argv)
{
    const char *optString = "lah";
    opterr = 0;
    int opt;
    while ((opt = getopt(argc, argv, optString)) != -1)
    {
        switch (opt)
        {
            case 'l':
                printf("this -l option\n");
                break;
            case 'a':
                printf("this -a option\n");
                break;
            case 'h':
                printf("in this cmd, you have 3 option can use:\n");
                printf("-l\n");
                printf("-a\n");
                printf("-h\n");
                break;
            default:
                break;
        }
    }
    // reset global valuable optind
    optind = 0;
    return 0;
}
int main(int argc, char **argv)
{
    MenuConfig("version", "xxx v1.0(Menu program v1.0 inside)", NULL);
    MenuConfig("argtest", "test arg option", argtest);
    MenuConfig("quit", "quit from xxx", Quit);
    ExcuteMenu();
    return 0;
}
