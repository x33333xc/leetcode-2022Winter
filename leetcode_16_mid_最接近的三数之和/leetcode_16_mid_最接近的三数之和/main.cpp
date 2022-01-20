#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define MAX 2147483647
using namespace std;

void print_vec(vector<int>& nums) {
	for (int i = 0;i < nums.size();++i) {
		cout << nums[i] << " ";
	}
	cout << endl;
}

int main() {
	int num[4] = { -1,2,1,-4 };
	int target = 1;
	vector<int>nums(num, num + 4);
	//print_vec(nums);
	
	/*
	����
	int diff = MAX;
	for (int i = 0;i < nums.size() - 2;++i) {
		for (int j = i + 1;j < nums.size() - 1;++j) {
			for (int k = j + 1;k < nums.size();++k) {
				int temp = nums[i] + nums[j] + nums[k];
				if (abs(temp - target) < diff) {
					diff = abs(temp - target);
					result = temp;
				}
			}
		}
	}*/
	//����֮������ָ��ֱ���ǰ�ƽ� ������Ŀ�� �ҵ�С��Ŀ����ӽ��ģ��������������
	//�鿴���֮���������˼·��Щ�񣬵��һ��ǲ����ˣ����õķ���������+˫ָ��
	//ѡ��a֮��b+cӦ��Ҫ�ӽ�target-a��ָ��pbָ��a��һ����ָ��pcָ��β�����ƶ�pbʹa+b+cֵ����ƶ�pcʹa+b+cֵ��С
	int result = 0;
	int diff = 2147483647;
	sort(nums.begin(), nums.end());
	// ���ݲ�ֵ�ľ���ֵ�����´�from leetcode
	auto update = [&](int cur) {
		if (abs(cur - target) < diff) {
			diff = abs(cur - target);
			result = cur;
		}
	};
	for (int a = 0;a < nums.size() - 2;++a) {
		int b = a + 1;				//pb
		int c = nums.size() - 1;	//pc
		int b0, c0;
		int temp;
		/*if (temp == target) {
			result = target;
			break;
		}*/
		while (b < c) {
			temp = nums[a] + nums[b] + nums[c];
			/*if (abs(temp - target) < diff) {
				diff = abs(temp - target);
				result = temp;
			}*/
			update(temp);
			if (temp < target) {
				b0 = b + 1;
				while (b0 < c && nums[b0] == nums[b])
					b0++;
				b = b0;
			}
			else if (temp > target) {
				c0 = c - 1;
				while (c0 > b && nums[c0] == nums[c])
					c0--;
				c = c0;
			}
			else {
				diff = 0;
				result = target;
				break;
			}
		}
	}
	return result;
}