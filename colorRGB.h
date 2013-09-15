#ifndef colorRGB_h_
#define colorRGB_h_
/**
* struct colorRGB
* structure for color in the rgb format
*/
struct colorRGB {
	colorRGB()  {
		r = 255;
		g = 255;
		b = 255;
	}
    int r, g, b;
};
#endif
