#include "bplustreemk3.h"
#include <fstream>
#include <iostream>
using namespace std;
bplustreemk3::bplustreemk3()
{

	this->headerSize = 0;
	this->blockSize = 1;
	this->totalNumRecords = 2;
	this->blockSize = 3;
	this->totalBlocks = 4;
	this->numAvalBlocks = 5;
	this->numOfLevels = 6;
	this->rbnRoot = 7; // RBN of root is first item after header then it is avail list seqence 
	this->rbnLevels = 8;
	this->rbnAvailList = 9;
	this->sizeofRecords = 10;
	this->numFieldsPerRecord = 11;
	this->root=block(this->blockSize, NULL);

}
int bplustreemk3::size() {
	return this->totalNumRecords;
}
bool bplustreemk3::insert(int insertE) {
	if (root.items.size<this->blockSize || root.items.size==(this->blockSize-1)) {
		root.add(insertE);
	}
	else {
		while (true) {
			if(root)
		}
	}
	return false;
}
bool bplustreemk3::remove() {
	return false;
}
bool bplustreemk3::checkEmpty() {
	return false;
}
bool bplustreemk3::isPresent() {
	return false;
}
bool bplustreemk3::headerToFile() {
	ofstream myfile;
	myfile.open("test.txt");
	myfile << this->headerSize << "|" << this->blockSize << "|" << this->totalBlocks << "|" << this->numAvalBlocks << "|" << this->numOfLevels << "|" << this->rbnAvailList << "|" << this->rbnLevels << "|" << this->rbnRoot << "|";
	myfile.close();
	return true;
}
int bplustreemk3::getBlockSize() {
	return this->blockSize;
}