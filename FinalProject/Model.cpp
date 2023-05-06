#include"Model.h"

using std::abs;

Position::Position()
{
	x = 0;
	y = 0;
	desX = 0;
	desY = 0;
	speed = 0;
	ShortestPath = true;
}

Position::Position(float startX, float startY, float finalX, float finalY, float startSpeed, bool shortest)
{
	x = startX;
	y = startY;
	desX = finalX;
	desY = finalY;
	speed = startSpeed;
	ShortestPath = shortest;
}

Position::~Position()
{
}

float& Position::operator[](int i)
{
	if (i == 0) {
		return this->x;
	}
	else if (i == 1) {
		return this->y;
	}
	else {
		exit(EXIT_FAILURE);
	}
}


float& Position::getValue(int i)
{
	if (i == 0) {
		return this->x;
	}
	else if (i == 1) {
		return this->y;
	}
	else {
		exit(EXIT_FAILURE);
	}
}

void Position::updateInformation(float startX, float startY, float finalX, float finalY, float startSpeed, bool shortest)
{
	x = startX;
	y = startY;
	desX = finalX;
	desY = finalY;
	speed = startSpeed;
	ShortestPath = shortest;
}

bool Position::updatePosition()
{
	float distanceX = desX - x;
	float distanceY = desY - y;

	if (abs(distanceX) <= speed * 0.5 && abs(distanceY) <= speed * 0.5) return false;

	else {
		if (ShortestPath) {
			float ratio = abs(distanceX) / (abs(distanceX) + abs(distanceY));
			if (distanceX > 0) {
				x += speed * ratio;
			}
			else {
				x -= speed * ratio;
			}

			if (distanceY > 0) {
				y += speed * (1 - ratio);
			}
			else {
				y -= speed * (1 - ratio);
			}
		}

		else {
			if (abs(distanceX) > 0.5*speed) {
				if (distanceX > 0) {
					x += speed;
				}
				else {
					x -= speed;
				}
			}
			else {
				if (abs(distanceY) > 0.5*speed) {
					if (distanceY > 0) {
						y += speed;
					}
					else {
						y -= speed;
					}
				}
			}
		}
		return true;
	}
}
