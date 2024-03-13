#include<iostream>
#include<vector>
int main(){
	std::vector<int> nums(5);
	for(int i=0;i<nums.size();i++)
	{
		nums[i]=i+1;
	 } 
	nums.erase(nums.begin()+1);
	for(int i=0;i<nums.size();i++)
	{
		std::cout<<nums[i]<<' ';
	}
} 
