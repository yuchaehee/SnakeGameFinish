#include "Map.h"
#include <random>

class Food {
public:
	// foodId:3 -> 싱싱한사과, foodId:4 -> 썩은 사과 foodId: 5 -> 황금사과 foodId:6 --> 반대로 사과
	int foodId;

	int foodPosX;
	int foodPosY;

	int prevPosX;
	int prevPosY;

public:
	Food() {
		foodPosX = 4;
		foodPosY = 4;
		foodId = 3;
		prevPosX = foodPosX;
		prevPosY = foodPosY;
	}

	Food(int x, int y)
		: foodPosX{ 4 }, foodPosY{ 4 }, foodId{ 3 }
	{
		prevPosX = foodPosX;
		prevPosY = foodPosY;
	}

	void setFoodInfo(int x, int y, int id) {
		foodId = id;
		foodPosX = x;
		foodPosY = y;
	}
};