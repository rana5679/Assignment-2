/*
 Rana Taher
 900221430
 Assignment 2
*/

#include <iostream>
#include <cstring>
using namespace std;

class point
{

private:
    float x;
    float y;
    
public:
    point();
    point(float m_x , float m_y);
    void set_x(float X);
    void set_y(float Y);
    float get_x();
    float get_y();
    void display();
    float distance(float curr_1, float curr_2 , float xp , float yp);
    
    
};


