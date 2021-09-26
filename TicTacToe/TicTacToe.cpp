// TicTacToe.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <thread>

using namespace std::chrono_literals;

int const nScreenWidth = 80;
int const nScreenHeight = 32;

void drawSign(wchar_t* screen, int field, char sign = 'x')
{
    int x = 0;
    int y = 0;
    switch (field)
    {
    case 1:
        x = 0;
        y = 0;
        break;
    case 2:
        x = 27;
        y = 0;
        break;
    case 3:
        x = 54;
        y = 0;
        break;
    case 4:
        x = 0;
        y = 11;
        break;
    case 5:
        x = 27;
        y = 11;
        break;
    case 6:
        x = 54;
        y = 11;
        break;
    case 7:
        x = 0;
        y = 22;
        break;
    case 8:
        x = 27;
        y = 22;
        break;
    case 9:
        x = 54;
        y = 22;
        break;
    default:
        x = -1;
        y = -1;
        break;
    }

    if (x >= 0 && y >= 0)
    {
        if (sign == 'x')
        {
            wsprintf(&screen[(0 + y) * nScreenWidth + x], L" X                      X");
            wsprintf(&screen[(1 + y) * nScreenWidth + x], L"    X                 X  ");
            wsprintf(&screen[(2 + y) * nScreenWidth + x], L"       X           X     ");
            wsprintf(&screen[(3 + y) * nScreenWidth + x], L"         X      X        ");
            wsprintf(&screen[(4 + y) * nScreenWidth + x], L"            XX           ");
            wsprintf(&screen[(5 + y) * nScreenWidth + x], L"            XX           ");
            wsprintf(&screen[(6 + y) * nScreenWidth + x], L"         X      X        ");
            wsprintf(&screen[(7 + y) * nScreenWidth + x], L"       X           X     ");
            wsprintf(&screen[(8 + y) * nScreenWidth + x], L"    X                 X  ");
            wsprintf(&screen[(9 + y) * nScreenWidth + x], L" X                      X");
        }
        else
        {
            wsprintf(&screen[(0 + y) * nScreenWidth + x], L"            OO           ");
            wsprintf(&screen[(1 + y) * nScreenWidth + x], L"         O      O        ");
            wsprintf(&screen[(2 + y) * nScreenWidth + x], L"       O          O      ");
            wsprintf(&screen[(3 + y) * nScreenWidth + x], L"     O              O    ");
            wsprintf(&screen[(4 + y) * nScreenWidth + x], L"   O                  O  ");
            wsprintf(&screen[(5 + y) * nScreenWidth + x], L"   O                  O  ");
            wsprintf(&screen[(6 + y) * nScreenWidth + x], L"     O              O    ");
            wsprintf(&screen[(7 + y) * nScreenWidth + x], L"       O          O      ");
            wsprintf(&screen[(8 + y) * nScreenWidth + x], L"         O      O        ");
            wsprintf(&screen[(9 + y) * nScreenWidth + x], L"            OO           ");
        }
    }
}

int main()
{
    wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
    for (int i = 0; i < nScreenHeight * nScreenWidth; i++)
        screen[i] = L' ';
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    int field[9] = { 0 };
    bool bKey[9] = { 0 };

    bool bGameOver = false;
    while (!bGameOver)
    {
        //Draw Field
        for (int i = 0; i < nScreenWidth; i++)
        {
            screen[10 * nScreenWidth + i] = L'#';
            screen[21 * nScreenWidth + i] = L'#';
        }

        for (int i = 0; i < nScreenHeight; i++)
        {
            screen[i * nScreenWidth + 26] = L'#';
            screen[i * nScreenWidth + 53] = L'#';
        }

        //Input
        for (int k = 0; k < 9; k++)
        {                                                         
            bKey[k] = (0x8000 & GetAsyncKeyState((unsigned char)("123456789"[k]))) != 0;
        }

        //Game Logic
        if (bKey[0])
        {
            field[0] = 1;
        }
        if (bKey[1])
        {
            field[1] = 1;
        }
        if (bKey[2])
        {
            field[2] = 1;
        }
        if (bKey[3])
        {
            field[3] = 1;
        }
        if (bKey[4])
        {
            field[4] = 1;
        }
        if (bKey[5])
        {
            field[5] = 1;
        }
        if (bKey[6])
        {
            field[6] = 1;
        }
        if (bKey[7])
        {
            field[7] = 1;
        }
        if (bKey[8])
        {
            field[8] = 1;
        }

        bool bFlag = 1;
        for (int i = 0; i < 9; i++)
        {
            if (field[i] == 0)
            {
                bFlag = 0;
                break;
            }
        }

        //Draw Sign
        for (int i = 0; i < 9; i++)
        {
            if (field[i] == 1)
            {
                if (i % 2)
                {
                    drawSign(screen, i + 1, 'o');
                }
                else
                {
                    drawSign(screen, i + 1, 'x');
                }
            }
        }

        //Display Frame
        WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0, 0 }, &dwBytesWritten);

        //Game End
        if (bFlag)
        {
            bGameOver = true;
            Sleep(5000);
        }
    }

    CloseHandle(hConsole);
    std::cout << "Game End";
    return 0;
}