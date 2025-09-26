#include "Solutions.h"




int main(int argc, char** argv){
	Solutions tasks;
	

	std::vector<int> abc = { 1,3,5,6 };
	std::cout << tasks.searchInsert(abc, 5) << std::endl;

	return 0;
}
