#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct block {
	vector<block>* children;//pointer to the children
	block* parent;
	vector<int> items;
	int size;


	block() {

	}
	block(int intSize, block* par) {
		this->parent = par;
		this->size = intSize;

	}
	vector<block>* getChildren() {
		return this->children;
	}
	block* getParent() {
		return this->parent;
	}
	bool add(int newItem) {
		if (items.size() == this->size) { return false; }
		for (int i = 0; i < items.size(); i++) {
			if (items.at(i) < newItem) {
				continue;
			}
			items.insert(items.begin() + i, newItem);
			return true;
		}
		this->items.push_back(newItem);
		return true;
	}
	bool remove(int delItem) {
		if (items.size() == 0) { return false; }
		for (int i = 0; i < items.size(); i++) {
			if (items.at(i) == delItem) {
				items.erase(items.begin() + i);
				return true;
			}
		}
		return false;
	}
	void setRoot(block* newRoot) {
		this->parent = newRoot;
	}
	void addChild(block newChild) {
		this->children->push_back(newChild);
	}
	void removeChild(block removeB) {
		for (int i = 0; i < this->children->size(); i++) {
			if (this->children->at(i) == removeB) {
				this->children->erase(children->begin+i);
			}
		}
	}
	void toString() {

		for (int i = 0; i < this->items.size(); i++) {
			cout << items.at(i);
		}
		cout << endl;
	}

};
bool operator ==(block a, block b) {
	if (a.size != b.size) { return false; }
	for (int i = 0; i < a.size; i++) {
		if (a.items.at(i) != b.items.at(i)) {
			return false;
		}
	}
	return true;
}

class bplustreemk3 {
	private:
		//Header Record Variables
		int headerSize;
		int blockSize;
		int totalBlocks;
		int numAvalBlocks;//Number of open blocks
		int numOfLevels;
		int rbnRoot; //Relative offest to root node
		int rbnLevels;//Relative offset to levels
		int rbnAvailList;//Relative offset to the avial list
		int totalNumRecords;//total number of records
		int sizeofRecords;
		int numFieldsPerRecord;
		block root;
		//String variable
		string description;
		string time;
		string lastMod;
	public:
		bplustreemk3();
		bool insert(int insertE);
		bool remove();
		bool checkEmpty();
		bool isPresent();
		int size();
		bool headerToFile();
		int getBlockSize();
};