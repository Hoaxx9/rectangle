class move_rect :public rect{		//������������ ��������� �������� �������������� ���������������
public:
	move_rect();
	void increase(rect*, color);	//����������� �������� ��������� ������ �������������� � ������������ ���
	void decrease(rect*, color);	//��������� �������� ��������� ������ �������������� � ������������ ���

private:
	COORD left_bottom, right_top;
};