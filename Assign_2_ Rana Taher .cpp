/*
 Rana Taher
 900221430
 Assignment 2
*/

#include <iostream>
#include <math.h>
#include <cstdlib>
#include "point.h"
using namespace std;

point::point() // default constructor
{
    x=0;
    y=0;
}

point::point(float m_x , float m_y) // a second constructor that intializes the variables
{
    x=m_x;
    y=m_y;
}

void point::set_x(float X) // sets the x coordinate of the point
{
    x=X;
}

void point::set_y(float Y) // sets the y coordinate of the point
{
    y=Y;
}

float point::get_x() // returns the x coordinate of the point
{
    return x;
}

float point::get_y() // returns the y coordinate of the point
{
    return y;
}

void point::display() // displays the coordinates of a point
{
    cout<<'('<<x<<','<<y<<')';
}

float point::distance(float curr_1, float curr_2 , float xp , float yp) // returns the distance between cuurnet point and centre of clusters
{
    float dis=0;
    dis=sqrt(pow(xp-curr_1,2)+pow(yp-curr_2,2));
    
    return dis;
}


void fill_array_A(point *array_A , int n) // fills the array for cluster A
{
    
    srand(time(NULL));
    
    for(int i=0; i<n ; i++)
    {
        (*(array_A+i)).set_x(rand()%19+71);
        
        (*(array_A+i)).set_y(rand()%19+71);
        
    }
}

void fill_array_B(point *array_B , int n) // fills the array for cluster B
{
    
    srand(time(NULL));
    
    for(int i=0; i<n ; i++)
    {
        (*(array_B+i)).set_x(rand()%19+21);
        
        (*(array_B+i)).set_y(rand()%19+21);
        
    }
}

void fill_array_P(point *array_P , int m) // fills the array that has many points
{
    
    srand(time(NULL));
    
    for(int i=0; i<m ; i++)
    {
        (*(array_P+i)).set_x(rand()%94+6);
        
        (*(array_P+i)).set_y(rand()%94+6);
        
    }
}

void Center(point *C , int n , float &X , float &Y) // looks for the centre of both clusters
{
    float total_x=0;
    float total_y=0;
    
    for(int i=0 ; i<n ; i++)
    {
        total_x=total_x+(*(C+i)).get_x();
        total_y=total_y+(*(C+i)).get_y();
    }
    
    X=total_x/n;
    Y=total_y/n;
    
}

char close_to_point(point *array_p,float x_A, float y_A, float x_B , float y_B ,int i) // looks for the cluster that a point belongs to
{
    float distance_A , distance_B;
    
    
    distance_A=(*(array_p+i)).distance(x_A,y_A,(*(array_p+i)).get_x(),(*(array_p+i)).get_y());
    distance_B=(*(array_p+i)).distance(x_B,y_B,(*(array_p+i)).get_x(),(*(array_p+i)).get_y());
    
    if(distance_A<distance_B)
    {
        return 'A';
    }
    
    return 'B';

}

int main()
{
    int n;
    int m=20;
    
    cout<<"Enter the number of points in cluster A and B"<<endl;
    cin>>n;
    
    point *A= new point[n];
    point *B= new point[n];
    point *P= new point[m];
    
    float X_A ,Y_A ,X_B ,Y_B;
    char cluster;
    
    fill_array_A(A,n);
    fill_array_B(B,n);
    fill_array_P(P,m);
    
    Center(A,n,X_A,Y_A);
    Center(B,n,X_B,Y_B);
    
    for(int i=0 ; i<m ;i++) // loops through the elements of the array of points 
    {
        cluster=close_to_point(P,X_A, Y_A, X_B , Y_B ,i);
        
        if(cluster=='A')
        {
            cout<<"The point ";
            (*(P+i)).display();
            cout<<" "<<"Is part of cluster A"<<endl;
        }
        else
        {
            cout<<"The point ";
            (*(P+i)).display();
            cout<<" "<<"Is part of cluster B"<<endl;
        }
    }
    
    delete[] A;
    delete[] B;
    delete[] P;
    
    A=nullptr;
    B=nullptr;
    P=nullptr;
    
    
    return 0;
    
}

