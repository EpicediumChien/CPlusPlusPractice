#ifndef NODE_LIST_TWO_NUM_H_
#define NODE_LIST_TWO_NUM_H_

#include <iostream>
#include <string>
#include "NodeList.h"

struct Example {
	ListNode* left;
	ListNode* right;
	ListNode* answer;
	Example* next = NULL;
	Example(ListNode* left, ListNode* right, ListNode* answer) : left(left), right(right), answer(answer) {}
};

ListNode* CreateListNode(std::string number)
{
	ListNode* nodePtr = NULL;
	ListNode* nodeCache = NULL;

	for (int i = 0; i < number.length(); i++)
	{
		nodePtr = new ListNode(number[i], nodeCache);
		nodeCache = nodePtr;
	}

	return nodePtr;
}

Example* InitExamples()
{
	Example* examplePtr;
	Example* exampleInit;

	ListNode* sample1 = CreateListNode("342");
	ListNode* sample2 = CreateListNode("465");
	ListNode* sum = CreateListNode("807");

	examplePtr = new Example(sample1, sample2, sum);
	exampleInit = examplePtr;

	sample1 = CreateListNode("0");
	sample2 = CreateListNode("0");
	sum = CreateListNode("0");

	examplePtr->next = new Example(sample1, sample2, sum);
	examplePtr = examplePtr->next;

	sample1 = CreateListNode("9999999");
	sample2 = CreateListNode("9999");
	sum = CreateListNode("100009998");

	examplePtr->next = new Example(sample1, sample2, sum);
	examplePtr = examplePtr->next;

	return exampleInit;
}

#endif