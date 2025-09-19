#include "Solutions.h"




int main(int argc, char** argv){
	Solutions tasks;
	
	ListNode list1(1);
	list1.next = new ListNode(2);
	list1.next->next = new ListNode(4);

	ListNode list2(1);
	list2.next = new ListNode(3);
	list2.next->next = new ListNode(4);


	ListNode* list3 = tasks.mergeTwoLists(&list1, &list2);

	for (ListNode* iter = list3; iter != nullptr; iter = iter->next)
		std::cout << iter->val << " ";
	std::cout << std::endl;

	return 0;
}
