//����� ������������ ��� ����������� ������ � �����

#include <iostream>
#include <Windows.h>
#include <ctime>
#include "rect.h"
#include "move_rect.h"

HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cursor;
HWND hWin = NULL;
HDC hDeviceContext;
HPEN hPen;

struct color		//��������� �������� ��� �������� ������ � ������
{
	int red, blue, green;
};