#include "SLLSet.h"
#include <iostream>

SLLSet::SLLSet()
{
	size = 0;
	head = NULL;
}


SLLSet::SLLSet(int sortedArray[], int arrSize)
{
	size = arrSize;//store set info

	SLLNode *starting = new SLLNode(sortedArray[arrSize - 1], NULL);
	head = starting;

	for (int i = arrSize - 2; i>=0;i--){
		SLLNode *newNode = new SLLNode(sortedArray[i],head);
		head = newNode;//update old var and create new node
	}
}


int SLLSet::getSize()
{
	//current node and size var
	int size = 0;
	SLLNode *node = head;

	//keep going and iterate till next pointer isnt NULL and update the pointer
	while (node != NULL){
		size++;
		node = node -> next;
	}
	//return size
	return size;
}


SLLSet SLLSet::copy()
{
	int arrSize = size;
	int array[arrSize] = {0};

	//var stores the copied node
	SLLNode *node = head;

	for(int i = 0; i<arrSize; i++){ //for loop updates pointer and sorts array
		array[i] = node ->value;
		node = node->next;
	}
	SLLSet *copy = new SLLSet(array, arrSize); //copy

	//return *copy
	return *copy;
}


bool SLLSet::isIn(int v)
{
	SLLNode *isIn = head;
	//loop till get to node with v or greater, not when NULL
	while(isIn != NULL && isIn->value < v){
		isIn = isIn->next;
	}

	//the applicable conditions if v is there
	if(isIn != NULL && isIn->value == v) {
		return true;
	}
	//return false if no v found
	return false;
}


void SLLSet::add(int v)
{
	//v = head if size is equal to nothing (empty)
    if(size == 0){
        head = new SLLNode(v,NULL);
        size = size+1;
    }
    //if set not empty and v not in then run
    else if (not this ->isIn(v)){
        SLLNode *node = head;//node and old definition
        SLLNode *old = NULL;

        //
        bool ending = false;

        //loop till equal v to set end
        while(node->value <v){
            if(node->next !=NULL){
                old = node;
                node = node->next;
            }
            else{
                ending = true;
                node->next = new SLLNode(v,NULL);
                size= size+1;
                break;
            }
        }
        //v at start
        if(head->value >v){
            SLLNode *newnode = new SLLNode(v,head);
            head = newnode;
            size = size+1;
        }
        //v before the ending  makes new node
        else if(not ending){
            old->next = new SLLNode(v,node);
            size = size+1;
        }
    }

}


void SLLSet::remove(int v)
{
	//if v isIn
	if(this->isIn(v)){
		SLLNode *node = head;
		SLLNode *old = NULL;
		//v is first val, head = 2nd node
		if(head->value == v){
			head = head ->next;
			size=size-1;
		}
		//if not then go through the rest
		else{
			while(node->value!=v){
				old = node;
				node = node->next;

			}
			//remove node with v
			old ->next = node->next;
			size=size-1;
		}
	}
}


SLLSet SLLSet::setUnion(SLLSet s)
{
	SLLSet unionSet = s.copy();//take the s inputs
	SLLNode *temp = head;

	while(temp!=NULL){//loop through and add vals
		unionSet.add(temp->value);
		temp=temp->next;
	}
	//return the unionset
	return unionSet;
}


SLLSet SLLSet::intersection(SLLSet s)
{
	//stores intersection
	SLLSet *intersection = new SLLSet();
	SLLNode *temp = head;
	//checking vals if they are in input using isIn
	for(int i = 0; i<size;i++){
		if(s.isIn(temp->value)){
			intersection->add(temp->value); //add val to intersection
		}
		temp = temp ->next;
	}
	return *intersection;
}


SLLSet SLLSet::difference(SLLSet s)
{
	if(head == NULL)
		{
		SLLSet differ = SLLSet();
		return differ;
		}
	if(s.head == NULL)
		{
		SLLSet differ = copy();
		return differ;
		}

	SLLSet *differ = new SLLSet();

	int i = 0;

	SLLNode *lead = head;

//go through list if not null head
	while(lead != NULL)
	{
		if(s.isIn(lead -> value) == false)//use isIn in s
		{
			(*differ).add(lead -> value);//adds val from list to other
			i ++;
		}
		lead = lead-> next;
	}
	(*differ).size = i;

	return *differ;
}


SLLSet SLLSet::setUnion(SLLSet sArray[],int size)
{
	SLLSet final;//new unused list
	int i = 0;
	while (i<size){//loop over set array
		final = final.setUnion(sArray[i]);
		i++;
	}
	return final;
}


string SLLSet::toString()
{
	string out;

	//iterate through nodes
	while(head != NULL)
	{
		//changes to string
        out = out + to_string(head->value);
        out = out + ", ";//adds , for separation
        head = head->next;
	}

	//removes the ','
	if(!out.empty())
	{
		out.resize(out.size() - 2);
	}
	return out;
}

