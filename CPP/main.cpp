#include "Solutions.h"




int main(int argc, char** argv){
	Solutions tasks;
	
	std::vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	std::cout << tasks.removeDuplicates(nums) << std::endl;


	for (auto i : nums) {
		std::cout << i << " ";
	}

	return 0;
}
