#include "Solutions.h"




int main(int argc, char** argv){
	Solutions tasks;
	
	std::vector nums = {2, 5, 5, 11};
	for(auto i : tasks.twoSum(nums, 10)){
		std::cout << i << std::endl;
	}
	
	return 0;
}
