#include"point.h"
#include<iostream>
#include<math.h>
Point::Point(){
  m_x=0;
  m_y=0;   
}
Point::Point(int _m_x,int _m_y){
    m_x=_m_x;
    m_y=_m_y;
}
Point::Point(const Point& ref){
    m_x=ref.m_x;
    m_y=ref.m_y;
}
double Point::distanceFromOrigin() const{
    return sqrt((m_y*m_y)+(m_x)*(m_x));
}

Quadrant Point::quadrant() const{
        if(m_x!=0 && m_y==0)
            return X_axis;
        else if(m_x==0 && m_y!=0)
            return Y_axis;
        else if(m_x>0&&m_y>0)
            return Q1;
        else if(m_x<0&&m_y>0)
            return Q2;
        else if(m_x<0&&m_y<0)
            return Q3;
        else if(m_x>0&&m_y<0)
            return Q4;
        else
            return Origin;
}
bool Point::isOrigin() const{
    if (m_x==0&&m_y==0){
        return true;
    }
    else{
        return false;
    }
}
bool Point::isOnXAxis() const{
    if(m_x==0){
            return true;
    }
    else{
        return false;
    }
}
bool Point::isOnYAxis() const{
    if(m_y==0){
            return true;
    }
    else{
        return false;
    }
}