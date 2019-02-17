class move_rect :public rect{		//осуществляет изменение размеров отрисовываемых прямоугольников
public:
	move_rect();
	void increase(rect*, color);	//увеличивает значение координат вершин прямоугольника и отрисовывает его
	void decrease(rect*, color);	//уменьшает значение координат вершин прямоугольника и отрисовывает его

private:
	COORD left_bottom, right_top;
};