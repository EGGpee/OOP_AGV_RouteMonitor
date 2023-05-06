#pragma once
#ifndef MODEL_H_
#define MODEL_H_
#include<iostream>

class Position {
private:
	float x, y;
	float desX, desY;
	float speed;
	bool ShortestPath;

public:
	Position();
	Position(float, float, float, float, float, bool);
	~Position();
	
	float& operator[](int i);
	float& getValue(int );
	void updateInformation(float, float, float, float, float, bool);
	bool updatePosition();
};

#endif