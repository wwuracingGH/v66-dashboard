#pragma once
#include <stdint.h>
#include <string>

#define DISPLAY_PIN_RW          9
#define DISPLAY_PIN_RS          10
#define DISPLAY_PIN_ENABLE      15
#define DISPLAY_PIN_RESET       13
#define DISPLAY_PIN_CS1         22
#define DISPLAY_PIN_CS2         23

//was written to be used by https://www.crystalfontz.com/product/cfag12864istitn-128x64-graphical-display-module-lcd
namespace display {
    const int WIDTH = 128, HEIGHT = 64;

    //struct containing the buffers for the segment halves
    struct buffer {
        uint8_t seg1[HEIGHT/8][WIDTH/2] = {{0}};
        uint8_t seg2[HEIGHT/8][WIDTH/2] = {{0}};
    };
    
    extern buffer *_active, *_display;

    /**
     * @brief inits the display
     */
    void init();

    /**
     * @brief swaps buffers, called at the end of the rendering function
     */
    void swapBuffers();
    /**
     * @brief clears the active buffer, called after the swap function and before drawing
     */
    void clearBuffer();

    /**
     * @brief Sets a pixel in the active buffer
     * 
     * @param x 
     * @param y 
     * @param value the value to write
     * @param buffer the buffer to write to
     */
    void setPixel(int x, int y);

    /*
     * Extremely Fast Line Algorithm Var D (Addition Fixed Point)
     * Copyright 2001, By Po-Han Lin
     *
     *
     * Freely useable in non-commercial applications as long as 
     * credits to Po-Han Lin and link to http://www.edepot.com is 
     * provided in source code and can been seen in compiled executable.  
     * Commercial applications please inquire about licensing the algorithms.
     *
     * Lastest version at http://www.edepot.com/phl.html
     */ 
    void drawLine(int x1, int y1, int x2, int y2);
    void drawText(int x, int y, int font, const char* text);

    void renderCar(double rot);

    void debugDrawToSerial();
}