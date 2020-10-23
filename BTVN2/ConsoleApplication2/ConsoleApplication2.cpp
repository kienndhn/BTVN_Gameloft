// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <list>
#include "vld.h"

#include "Tree.h"
#include "House.h"
#include "Motorbike.h"
#include "Car.h"


int main()
{
	std::list<BaseObject*> objects;

	BaseObject *tree1 = new Tree(1, "tree 1", { 0, 0 });
	BaseObject *tree2 = new Tree(2, "tree 2", { 1, 4 });
	
	BaseObject *house1 = new House(3, "house 1", { 10, 9 });
	BaseObject *house2 = new House(4, "house 2", { 1, -9 });

	BaseObject *motor1 = new Motorbike(5, "motor 1", { 2, 3 });
	BaseObject *motor2 = new Motorbike(6, "motor 2", { 7, 4 });

	BaseObject *car1 = new Car(7, "car 1", { 3, 5 });
	BaseObject *car2 = new Car(8, "car 2", { -3, 0 });

	objects.push_back(tree1);
	objects.push_back(tree2);
	objects.push_back(house1);
	objects.push_back(house2);
	objects.push_back(motor1);
	objects.push_back(motor2);
	objects.push_back(car1);
	objects.push_back(car2);

	
	printf("Ten cac object: ");
	for (auto *iterator : objects) {
		printf("%s, ", iterator->getName());
	}
	printf("\n\n");
	 

	printf("id cac object: ");
	for (auto *iterator : objects) {
		printf("%d, ", iterator->getID());
	}
	printf("\n\n");


	printf("tao do ban dau:\n");
	for (auto *iterator : objects) {
		iterator->printPosition();
	}
	printf("\n\n");


	printf("dich chuyen");
	for (auto *iterator : objects) {
		iterator->move();
	}
	printf("\n\n");


	printf("tao do sau khi dich chuyen:\n");
	for (auto *iterator : objects) {
		iterator->printPosition();
	}

	//xoa danh sach doi tuong
	for (auto *iterator : objects) {
		delete iterator;
	}


	objects.clear();
	printf("\n");
	system("pause");
	return 0;
}

