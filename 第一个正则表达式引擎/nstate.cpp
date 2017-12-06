#include"nstate.h"
#include<iostream>
int nstate::id = 0;
bool operator <(std::shared_ptr<nstate> lhs, std::shared_ptr<nstate> rhs) {
	return lhs->ID < rhs->ID;
}
bool operator ==(std::shared_ptr<nstate> lhs, std::shared_ptr<nstate> rhs) {

	return lhs->ID == rhs->ID;
}