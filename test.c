#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

void readFile(){

  char * line = NULL;
  size_t len = 0;
  ssize_t read;

  FILE * fp = fopen("./Headings.txt", "r");
  if(fp == NULL)
  printf("Unable to file Headings.txt");

  while ((read = getline(&line, &len, fp)) != -1) {
    line[read-1]=0x0;
    printw("%s \t", line);
  }
  fclose(fp);

}


/**
 *  Read Headings.txt
 *  Line by Line
 *  and Print them
 */
void setHeading() {
  readFile();
}


/**
 * [main description]
 * 1. Init windows
 * 2. Set Headers
 * 3. Set Data
 * 4. Refresh
 */
int main()
{
  int ch;
  initscr();                      /* Start curses mode            */

  /** Set Headers **/

  setHeading();

  raw();                          /* Line buffering disabled      */
  keypad(stdscr, TRUE);           /* We get F1, F2 etc..          */

  noecho();                       /* Don't echo() while we do getch */

  printw("Type any character to see it in bold\n");
  ch = getch();                   /* If raw() hadn't been called
                                   * we have to press enter before it
                                   * gets to the program          */
  if(ch == KEY_UP)                /* Without keypad enabled this will */
          printw("UP Key pressed");/*  not get to us either       */
                                  /* Without noecho() some ugly escape
                                   * charachters might have been printed
                                   * on screen                    */
  else
  {       printw("The pressed key is ");
          attron(A_BOLD);
          printw("%c", ch);
          attroff(A_BOLD);
  }
  refresh();                      /* Print it on to the real screen */
  getch();                        /* Wait for user input */
  endwin();                       /* End curses mode                */

  return 0;
}
