class rect{
public:
	rect();
	void draw_rect() const;			//отрисовывает прямоугольник
	void set_rect(COORD, COORD, color);	//устанавливает координаты вершинам и цвет прямоугольнику
protected:
	COORD left_bottom_point, right_top_point;
	color c;
};
