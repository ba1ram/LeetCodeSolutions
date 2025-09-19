#include "Solutions.h"




int main(int argc, char** argv){
	Solutions tasks;
	
	std::vector<int> nums = { 3,2,2,3 };
	std::cout << tasks.removeElement(nums, 3) << std::endl;


	for (auto i : nums) {
		std::cout << i << " ";
	}

	return 0;
}
