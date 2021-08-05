// TicTacToe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <Windows.h>

int const nScreenWidth = 80;
int const nScreenHeight = 30;

void drawSign(int field, wchar_t* screen)
{
    for (int i = 0; i < nScreenWidth / 3 * nScreenHeight / 3; i++)
    {
        screen[i] = L'X';
    }
}

int main()
{
    wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
    for (int i = 0; i < nScreenHeight * nScreenHeight; i++)
        screen[i] = L' ';
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    while (1)
    {
        bool bKeys[9] = {0};
        int field = -1;

        //Clear Screen
        for (int i = 0; i < nScreenHeight * nScreenWidth; i++)
        {
            screen[i] = L' ';
        }

        //Draw Field
        for (int i = 0; i < nScreenWidth; i++)
        {
            screen[10 * nScreenWidth + i] = L'#';
            screen[20 * nScreenWidth + i] = L'#';
        }

        for (int i = 0; i < nScreenHeight; i++)
        {
            screen[i * nScreenWidth + 26] = L'#';
            screen[i * nScreenWidth + 54] = L'#';
        }

        // Get Input
        /*for (int i = 0; i < 9; i++)
        {
            bKeys[i] = (0x8000 & GetAsyncKeyState((unsigned char)('\x3' + ++i))) != 0;
        }
        for (int i = 0; i < 9; i++)
        {
            if (bKeys[i])
            {
                field = i;
                break;
            }
        }*/
        //drawSign(field, screen);

        //Draw Sign
        int t1 = 55;
        int t2 = 20;
        wsprintf(&screen[(0 + t2) + t1],                L" X                      X");
        wsprintf(&screen[(1 + t2) * nScreenWidth + t1], L"    X                 X  ");
        wsprintf(&screen[(2 + t2) * nScreenWidth + t1], L"       X           X     ");
        wsprintf(&screen[(3 + t2) * nScreenWidth + t1], L"         X      X        ");
        wsprintf(&screen[(4 + t2) * nScreenWidth + t1], L"            XX           ");
        wsprintf(&screen[(5 + t2) * nScreenWidth + t1], L"            XX           ");
        wsprintf(&screen[(6 + t2) * nScreenWidth + t1], L"         X      X        ");
        wsprintf(&screen[(7 + t2) * nScreenWidth + t1], L"       X           X     ");
        wsprintf(&screen[(8 + t2) * nScreenWidth + t1], L"    X                 X  ");
        wsprintf(&screen[(9 + t2) * nScreenWidth + t1], L" X                      X");

        //Display Frame
        WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0, 0 }, &dwBytesWritten);
    }

    return 0;
}