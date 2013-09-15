#ifndef Border_h_
#define Border_h_
/**
* struct Border
* structure for borders
*/
struct Border {
	Border() {
		width = 1.0;
		type = "solid";
	}
    double width;
    string type;
    colorRGB RGB;
};
#endif
