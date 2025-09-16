#include "Solutions.h"




int main(int argc, char** argv){
	Solutions tasks;
	
	ListNode list1(1);

	ListNode list2(2);

	ListNode* list3 = tasks.mergeTwoLists(&list1, &list2);

	for (ListNode* iter = list3; iter != nullptr; iter = iter->next)
		std::cout << iter->val << " ";
	std::cout << std::endl;

	return 0;
}
