class rect{
public:
	rect();
	void draw_rect() const;					//������������ �������������
	void set_rect(COORD, COORD, color);		//������������� ���������� �������� � ���� ��������������
protected:
	COORD left_bottom_point, right_top_point;
	color c;
};