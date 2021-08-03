// TicTacToe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <Windows.h>

VOID ErrorExit(LPCSTR);

int main(VOID)
{
    int const nScreenWidth = 80;
    int const nScreenHeigth = 30;

    wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeigth];
    for (int i = 0; i < nScreenHeigth * nScreenHeigth; i++)
        screen[i] = L' ';

    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    CloseHandle(hConsole);
    system("pause");
    return 0;
}