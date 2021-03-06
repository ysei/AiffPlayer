/*
 *  3d.h
 *  Oscilloscope
 *
 *  Created by koji on 11/02/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <math.h>
#import <Cocoa/Cocoa.h>

struct SimpleVertex3{
	float x;
	float y;
	float z;
public:
    SimpleVertex3(){
        ;
    }
    
    SimpleVertex3(const SimpleVertex3 &other){
        x = other.x;
        y = other.y;
        z = other.z;
    }
    inline SimpleVertex3(float x, float y, float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    
    
	SimpleVertex3 operator -(const SimpleVertex3 &right) const{
        return SimpleVertex3( x - right.x, y - right.y, z - right.z);
	}
	
	SimpleVertex3 cross(const SimpleVertex3 &right) const{
	    SimpleVertex3 result;
        result.x = y*right.z - z * right.y;
        result.y = z*right.x - x * right.z;
        result.z = x*right.y - y * right.x;
        return result;
	}
};

//free functions


void cross(const float *v1, const float *v2, float *result_vector);
void norm_from_triangle(const float *v0, const float *v1, const float *v2, float *norm);

SimpleVertex3 norm_from_triangle(const SimpleVertex3 *v0, const SimpleVertex3 *v1, const SimpleVertex3 *v2);
SimpleVertex3 mean_norm_from_triangles(/*const */SimpleVertex3 triangles[][3], int triangleNum);

float rad(float degree);

class Point3D{
	
private:
	float mX,mY,mZ;
	void update(float x,float y, float z){
		mX = x;
		mY = y;
		mZ = z;
	}
public:
	Point3D(float x,float y,float z){
		update(x,y,z);
	}
	
	Point3D &rotateX(float theta){
		//mX = mX;
		
		float newY = mY * cos(theta) + mZ * sin(theta);
		float newZ = -mY * sin(theta) + mZ * cos(theta);
		update(mX, newY, newZ);
		return *this;
	}
	Point3D &rotateY(float theta){
		float newX =  mX*cos(theta) - mZ*sin(theta);
		float newZ =  mX*sin(theta) + mZ*cos(theta);
		update(newX, mY, newZ);
		return *this;
	}
	Point3D &rotateZ(float theta){
		float newX = mX*cos(theta) - mY*sin(theta);
		float newY = mX*sin(theta) + mY*cos(theta);
		update(newX,newY,mZ);
		return *this;
	}
	
	float operator[] (int i){
		switch(i){
			case 0:
				return mX;
			case 1:
				return mY;
			case 2:
				return mZ;
			default:
				return 0.0f;
		}
	}
	
	float x(){
		return mX;
	}
	float y(){
		return mY;
	}
	float z(){
		return mZ;
	}
	
	Point3D copy(){
		return Point3D(mX,mY,mZ);
	}
	
	Point3D &shift(float x, float y, float z){
		mX += x;
		mY += y;
		mZ += z;
		return *this;
	}
	
	Point3D &scale(float x, float y, float z){
		mX *= x;
		mY *= y;
		mZ *= z;
		return *this;
	}
	
	//Perspective(透視投影)
	NSPoint toCamera(float d1, float d2){
		float cameraX = mX * d1 / (d2 + mZ);
		float cameraY = mY * d1 / (d2 + mZ);
		return NSMakePoint(cameraX, cameraY);
		//return NSMakePoint(mX, m
	}
	
	//平行投影
	NSPoint toCamera_noPerspective(){
		return NSMakePoint(mX,mY);
	}
	
	NSPoint toNSPoint(){
		return NSMakePoint(mX, mY);
	}
	
	void log(){
		NSLog(@"point3d, x=%f,y=%f,z=%f", mX,mY,mZ);
	}
	
	
};
