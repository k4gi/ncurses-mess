import curses

def main(stdscr):
    stdscr.box(0,0)
    stdscr.addstr(0,0, "Gday mate")
    stdscr.addstr(1,1, "boy i die")
    stdscr.addstr(2,2, "shit boy")
    stdscr.addstr(3,3, str(curses.LINES) )
    stdscr.addstr(4,4, str(curses.COLS) )

    stdscr_yx = stdscr.getmaxyx()
    stdscr.addstr(5,5, str(stdscr_yx) )

    stdscr.refresh()
    stdscr.getch()

curses.wrapper(main)
