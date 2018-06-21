#include <iostream>
#include "windows.h" //necessary for the showConsoleCursor function

//forward declaration
void showConsoleCursor(bool showFlag);

int main() {
    showConsoleCursor(false);
    return 0;
}

//enables or disable the console cursor by setting the boolean
void showConsoleCursor(bool showFlag) {
    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
