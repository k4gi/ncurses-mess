#!/usr/bin/python3

# now that i'm starting to get a handle on ncurses, it might be nice to learn to use it in python
# python should make certain things easier than c++, right?

import curses
from curses import wrapper

stdscr = curses.initscr()

def main(stdscr):
    # curses.echo()
    stdscr.addstr("Hello world")
    stdscr.refresh()

    user_input = ''
    while user_input != 'q':
        user_input = stdscr.getkey()
        stdscr.addstr(">" + user_input)

wrapper(main)
# seems like using the wrapper stops echoing so if you want it, enable it

curses.endwin()
