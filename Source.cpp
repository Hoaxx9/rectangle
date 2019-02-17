#include "Head.h"


rect::rect(){
	hWin = GetConsoleWindow();
	hDeviceContext = GetDC(hWin);
	RECT rc;
	GetClientRect(hWin, &rc);

	COORD left_bottom = { rc.right / 2 - 32, rc.bottom / 2 + 15 },	//��������� ���������� �������������� ����������� ������ ��
		  right_top = { rc.right / 2 + 32, rc.bottom / 2 - 15 };	//�������� ���� ��������� 
																	//(����� 32 � 15 ���������� ������� �������� ����� ���� �������������)
	
	left_bottom_point = left_bottom;
	right_top_point = right_top;
	c = { 250, 0, 0 };
}
void rect::set_rect(COORD left_bottom, COORD right_top, color color_rect){
	c = color_rect;
	left_bottom_point = left_bottom;
	right_top_point = right_top;
}
void rect::draw_rect()const{
	hWin = GetConsoleWindow();
	hDeviceContext = GetDC(hWin);
	hPen = CreatePen(PS_SOLID, 1, RGB(c.red, c.green, c.blue));
	SelectObject(hDeviceContext, hPen);
	int hide = abs(left_bottom_point.Y - right_top_point.Y);
	for (int i = 0; i < hide; i++){
		MoveToEx(hDeviceContext, right_top_point.X, right_top_point.Y + i, NULL);
		LineTo(hDeviceContext, left_bottom_point.X, right_top_point.Y + i);
	}
}

move_rect::move_rect(){
	rect::rect();
	left_bottom = left_bottom_point;
	right_top = right_top_point;
}
void move_rect::increase(rect *obj, color color_rect){
	left_bottom.X -= 32;
	left_bottom.Y += 15;
	right_top.X += 32;
	right_top.Y -= 15;
	obj->set_rect(left_bottom, right_top, color_rect);
	obj->draw_rect();
}
void move_rect::decrease(rect *obj, color color_rect){
	left_bottom.X += 32;
	left_bottom.Y -= 15;
	right_top.X -= 32;
	right_top.Y += 15;
	obj->set_rect(left_bottom, right_top, color_rect);
	obj->draw_rect();
}

int main(){
	srand(time(0));		
	
	GetConsoleCursorInfo(hStdout, &cursor);
	cursor.bVisible = FALSE;					//��������� ��������� �������
	SetConsoleCursorInfo(hStdout, &cursor);
	
	color cl;
	int i = 0;				//�������	
	move_rect rect1;
	rect obj, *rect = &obj;

	rect->draw_rect();		//������������ ������ ������������� � ���������� �����������

	while (i < 13){
		Sleep(500);			
		cl = { rand() % 255, rand() % 255, rand() % 255 };
		rect1.increase(rect, cl);
		i++;
	}
	while (i >= 0){
		Sleep(500);
		cl = { rand() % 255, rand() % 255, rand() % 255 };
		rect1.decrease(rect, cl);
		i--;
	}
	return 0;
}