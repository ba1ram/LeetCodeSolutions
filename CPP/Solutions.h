#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <math.h>

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
	
};