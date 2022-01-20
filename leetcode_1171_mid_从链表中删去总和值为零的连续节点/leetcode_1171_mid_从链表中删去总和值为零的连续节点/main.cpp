#include<iostream>
#include<map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode* head) {
	ListNode* temp = head;
	while (temp) {
		cout << temp->val << " ";
		temp = temp->next;
	}
}

void printMap(map<int, ListNode*>mapPreSum) {
	for (map<int, ListNode*>::iterator it = mapPreSum.begin();it != mapPreSum.end();it++) {
		cout << "preSum: " << it->first << " NodeVal: " << it->second->val << endl;
	}
}
//给你一个链表的头节点 head，请你编写代码，反复删去链表中由 总和 值为 0 的连续节点组成的序列，直到不存在这样的序列为止。
//删除完毕后，请你返回最终结果链表的头节点。

int main() {
	int a[5] = { 1,2,-3,3,1 };
	ListNode* head = new ListNode(a[0]);
	ListNode* temp = head;
	for (int i = 1;i < 5;++i) {
		ListNode* cur = new ListNode(a[i]);
		temp->next = cur;
		temp = temp->next;
	}
	printList(head);
	//不会做查看题解之后利用map，和前缀和来计算
	ListNode* virtualHead = new ListNode;
	virtualHead->next = head;
	ListNode* cur = virtualHead;
	map<int, ListNode*>mapPreSum;//<sum,Node>
	int preSum = 0;
	while (cur) {
		preSum += cur->val;
		mapPreSum[preSum] = cur;
		cur = cur->next;
	}
	//printMap(mapPreSum);
	cur = virtualHead;
	preSum = 0;
	while (cur) {
		preSum += cur->val;
		cur->next = mapPreSum[preSum]->next;//*************超级重要这步***********
		cur = cur->next;
	}
	//return virtualHead->next;
	printList(virtualHead->next);


}

 