#include "Solutions.h"




int main(int argc, char** argv){
	Solutions tasks;
	
	std::vector<std::string> strs{"a"};
	std::cout << tasks.longestCommonPrefix(strs) << std::endl;
	
	return 0;
}
