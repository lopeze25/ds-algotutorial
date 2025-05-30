#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct LinkedNode {

	int data;
	LinkedNode* next;
	LinkedNode(int val = 0) {
		this->data = val;
		next = nullptr;
	}
};

struct Node {
	int data;
	std::vector<Node*> children;

	Node(int val) {
		data = val;
	}

	void BFS() {
		std::queue<Node*> q;
		q.push(this);
		while (!q.empty()) {
			Node* current = q.front();
			q.pop();
			std::cout << current->data << "";
			for (Node* child : current->children) {
				q.push(child);
			}
		}
		std::cout << std::endl;
	}
};



int binarySearch(const std::vector<int>& arr, int target) {
	int left = 0, right = arr.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2; // avoid overflow
		if (arr[mid] == target) return mid;
		else if (arr[mid] < target) left = mid + 1;
		else right = mid - 1;
	}
	return -1; 
}

int main() {
	printf("text\n");
	LinkedNode* head = new LinkedNode(10);
	head->next = new LinkedNode(20);
	head->next->next = new LinkedNode(30);
	LinkedNode* current = head;

	std::vector<int> values;

	while (current != nullptr) {
		values.push_back(current->data);
		current = current->next;
	}
	std::vector<int> format;
	for (int val : values) {

		std::cout << val;
		int data = values.back();
		values.pop_back();
		format.push_back(data);

	}


	std::vector<int> values2 = { 1, 9, 8, 10, 14, 6, 5, 4 , 2 ,3 };
	std::sort(values2.begin(), values2.end());
	int store = binarySearch(values2, 2);
	std::cout << "\nValue " << values2[store] << "at index:" << store; 

	Node* head2 = new Node(20);
	Node* node1 = new Node(30);

	head2->children.push_back(node1);

	Node* node2 = new Node(40);
	node1->children.push_back(node2);

	Node* node3 = new Node(50);
	node1->children.push_back(node3);
	Node* node4 = new Node(10);
	node1->children.push_back(node4);

	std::cout << "\n";
	head2->BFS();
	
	delete node3;
	delete node2;
	delete node1;
	delete node4;
	delete head2;


	return 0;

}

