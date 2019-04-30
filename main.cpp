#include <ncurses.h>
#include <unistd.h>

void app() {
	wmove(stdscr, 0, 0);
	waddch(stdscr, 'a');
	wrefresh(stdscr);
	sleep(5);
}

int main() {
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	app();
	endwin();
	return 0;
}
