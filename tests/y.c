#include <ncurses.h>
#include <unistd.h>

int main() {
    initscr();            // Initialize the window
    noecho();             // Don't echo keypresses to the screen
    curs_set(FALSE);      // Don't display the cursor

    int x = 10, y = 10;
    while (1) {
        clear();
        mvprintw(y, x, "O");
        refresh();

        // Update position or other game logic here
        // x++;
        // y++;

        // Handle input
        int ch = getch();
        if (ch == 'q') break;
        if (ch == 'l') {
            x += 5;
        }
        if (ch == 'h') {
            x -= 5;
        }
        if (ch == 'k') {
            y -= 5;
        }
        if (ch == 'j') {
            y += 5;
        }
        

        // Sleep to control frame rate
        usleep(100); // 1 ms
    }

    endwin(); // Restore normal terminal behavior
    return 0;
}

