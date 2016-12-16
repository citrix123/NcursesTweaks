#include <ncurses.h>

int main(int argc, char *argv[])
{
    initscr();
    
    int x , y;   
    getmaxyx(stdscr, y , x);

    WINDOW *win = newwin(y,x,1,1);
    
    printw("X : %d \n Y : %d \n", x , y);
    box(win, 0,0);
    touchwin(win);
    wrefresh(win);

    getchar();

    endwin();
    return 0;
}
