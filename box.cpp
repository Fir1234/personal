#include"box.h"
#include<iostream>
Box::Box(){
    m_length=0;
    m_breadth=0;
    m_height=0;
}
Box::Box(double _m_length,double _m_breadth,double _m_height){
    m_length=_m_length;
    m_breadth=_m_breadth;
    m_height=_m_height;
}
Box::Box(const Box& ref){
    m_length=ref.m_length;
    m_breadth=ref.m_breadth;
    m_height=ref.m_height;
}
double Box::length() const{
    return m_length;
}
double Box::breadth() const{
    return m_breadth;
}
double Box::height() const{
    return m_height;
}
double Box::volume() const{
    return m_length*m_breadth*m_height;
}