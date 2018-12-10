bool IsColliding(int left, int top, int right, int bottom, int left1, int top1, int right1, int bottom1)

{
	int x = (top - left) / 2 + left;
	int y = (bottom - right) / 2 + right;
	int x1 = (top1 - left1) / 2 + left1;
	int y1 = (bottom1 - right1) / 2 + right1;
	int radius = (right - left) / 2, radius2 = (right1 - left1) / 2;


	if (sqrt(((x1 - x)*(x1 - x)) + ((y1 - y)*(y1 - y))) <= radius + radius2)
		return true;
	
	return false;
}
