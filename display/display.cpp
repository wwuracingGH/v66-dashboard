#include "display.h"

void display::setPixel(int x, int y, uint8_t value, uint8_t** buffer){
    buffer[y][x] = value;
}

//this is someone elses code. Probably dont read it
void display::drawLine(int x, int y, int x2, int y2, uint8_t** buffer) {
	bool yLonger = false;
	int incrementVal, endVal;
	int shortLen = y2 - y;
	int longLen = x2 - x;
	if (abs(shortLen) > abs(longLen)) {
		int swap = shortLen;
		shortLen = longLen;
		longLen = swap;
		yLonger = true;
	}
	endVal = longLen;
	if (longLen < 0) {
		incrementVal = -1;
		longLen = -longLen;
	} else incrementVal = 1;
	int decInc;
	if (longLen == 0) decInc = 0;
	else decInc = (shortLen << 16) / longLen;
	int j = 0;
	if (yLonger) {	
		for (int i = 0; i != endVal; i += incrementVal) {
			setPixel(x + (j >> 16), y + i, 255, buffer);	
			j += decInc;
		}
	} else {
		for (int i=0;i!=endVal;i+=incrementVal) {
			setPixel(x + i, y + (j >> 16), 255, buffer);
			j += decInc;
		}
	}
}