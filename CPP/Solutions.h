#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <math.h>
#include <stack>

//$env:GIT_SSH_COMMAND = "ssh -i 'C:\Users\СтарМарк Про\.ssh\id_rsa'"

//class ListNode {
//
//public:
//	ListNode() : _value(0), _next(nullptr) {}
//	ListNode(int val) : _value(val), _next(nullptr) {}
//	ListNode(int val, ListNode* nextNode) : _value(val), _next(nextNode) {}
//
//	ListNode* push_back(int value) {
//		if(_next == nullptr)
//			_next = new ListNode(value);
//		else {
//			ListNode* item = _next;
//			while (item->_next != nullptr)
//				item = item->_next;
//			item->_next = new ListNode(value);
//		}
//		
//		_size++;
//
//		return _next;
//	}
//
//	ListNode* nextNode() { return _next; }
//	int value() { return _value; };
//	int size() { return _size; }
//private:
//	int _value;
//	ListNode* _next;
//	static int _size;
//};

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solutions{
public:

	//1317. Convert Integer to the Sum of Two No-Zero Integers
	bool has_zero(int n){
		if(n == 0) return true;
		while(n > 0){
			if(n % 10 == 0) return true;
			n /= 10;
		}
		return false;
	}
	std::vector<int> getNoZeroIntegers(int n) {
		int B = 0;
		for(int A = 1; A <= n; A++){
			B = n - A;
			
			if(!has_zero(A) && !has_zero(B))
				return {A, B};
		}
		return {};
    }
		
	//1. Two Sum
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::unordered_map<int, int> mp;
		
		for(int i = 0; i < nums.size(); i++){
			int piece = target - nums[i];
			
			if(mp.find(piece) != mp.end()) return {mp[piece], i};
			mp.insert({nums[i], i});
			
		}
		
		return {};
    }
	
	//9. Palindrome Number
    bool isPalindrome(int x) {
		if( x < 0 || (x % 10 == 0 && x != 0)) return false;
		
		int reverse = 0;
		while(x > reverse){    
			reverse = reverse * 10 + x % 10;
			x /= 10;
		}
		
		return x == reverse || x == reverse / 10;
    }
	
	//13. Roman to Integer
	int romanToInt(std::string s) {
		int num = 0;

		for(int i = 0; i < s.size(); i++){
			
			if(s[i] == 'I'){
				if(i + 1 < s.size() && s[i + 1] == 'V'){ num += 4; i++; }
				else if(i + 1 < s.size() && s[i + 1] == 'X'){ num += 9; i++; }
				else num += 1;
			}
			else if(s[i] == 'V') num += 5;
			else if(s[i] == 'X'){
				if(i + 1 < s.size() && s[i + 1] == 'L'){ num += 40; i++; }
				else if(i + 1 < s.size() && s[i + 1] == 'C'){ num += 90; i++; }
				else num += 10;
			}
			else if(s[i] == 'L') num += 50;
			else if(s[i] == 'C'){
				if(i + 1 < s.size() && s[i + 1] == 'D'){ num += 400; i++; }
				else if(i + 1 < s.size() && s[i + 1] == 'M'){ num += 900; i++; }
				else num += 100;
			}
			else if(s[i] == 'D') num += 500;
			else if(s[i] == 'M') num += 1000;
		}
		
		return num;
    }
	
	//14. Longest Common Prefix
	std::string longestCommonPrefix(std::vector<std::string>& strs) {
		int size = 0;
		std::string sub = "";
		std::string resultStr = "";
		
		if(strs.empty()) return "";
		std::string firstStr = strs[0];
		if(firstStr.empty()) return "";
		
		for(int i = 0; i < firstStr.size(); i++){
			sub += firstStr[i];
			for(int j = 1; j < strs.size(); j++){
				if(strs[j].compare(0, sub.size(), sub)){
					return resultStr;
				}
			}
			resultStr += firstStr[i];
		}
		
		return resultStr;
    }
	
	//20. Valid Parentheses	
	bool isValid(std::string s) {
		std::stack<char> brackets;

		for(auto& item : s){
			if(item == ')' && !brackets.empty() && brackets.top() == '(') brackets.pop();
			else if(item == '}' && !brackets.empty() && brackets.top() == '{') brackets.pop();
			else if(item == ']' && !brackets.empty() && brackets.top() == '[') brackets.pop();
            else brackets.push(item);
		}
		
		if(brackets.empty()) return true;
	
		return false;
    }
	
	//21. Merge Two Sorted Lists
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (list1 == nullptr)
			return list2;
		if (list2 == nullptr)
			return list1;


		if (list1->val < list2->val) {
			list1->next = mergeTwoLists(list1->next, list2);
			return list1;
		}
		else {
			list2->next = mergeTwoLists(list1, list2->next);
			return list2;
		}
    }
};