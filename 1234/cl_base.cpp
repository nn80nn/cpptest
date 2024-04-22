#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "cl_base.h"

cl_base :: cl_base (cl_base * p_head_object, string s_object_name)
{
	this -> s_object_name = s_object_name;
	this -> p_head_object = p_head_object;
	if (p_head_object != nullptr)
	{
		p_head_object -> subordinate_objects.push_back (this);
	}
}

bool cl_base::set_object_name (string s_new_object_name){
	if (this->p_head_object)
		for (int i = 0; i < p_head_object-> subordinate_objects.size(); i++ )
			if (p_head_object->subordinate_objects[i]->get_object_name() == s_new_object_name)
				return false;
	this->s_object_name= s_new_object_name;
	return true;

}

cl_base::~cl_base()
{
	for (int i = 0; i < subordinate_objects.size(); i++)
		delete subordinate_objects[i];
}

cl_base* cl_base::get_subordinate_object(string s_object_name)
{
	for (int i = 0; i < p_head_object-> subordinate_objects.size(); i++ )
		if (subordinate_objects[i]->get_object_name() == s_object_name)
			return subordinate_objects[i];
	return nullptr;
}

void cl_base::print_tree()
{
	if(subordinate_objects.size() != 0)
	{
		cout << endl << this->get_object_name();
		for (int i = 0; i < p_head_object-> subordinate_objects.size(); i++ )
		{cout << " " << subordinate_objects[i]->get_object_name();
		subordinate_objects[i]->print_tree();}
	}
}

string cl_base::get_object_name() {
	return s_object_name;
}

int cl_base::getsize() {
	return subordinate_objects.size();
}
