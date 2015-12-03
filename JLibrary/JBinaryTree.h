#ifndef JBINARYTREE_H
#define JBINARYTREE_H

/*
	http://wonthing86.blogspot.kr/2014/07/binary-search-tree.html
	http://blog.naver.com/4717010/60209820587
*/
namespace JLib
{
	/*
		BST 트리의 정의
		1. 왼쪽 서브트리의 키값은 루트의 키값보다 작다.
		2. 오른쪽 서브트리의 키 값은 루트의 키 값보다 크다.
		3. 왼/오른쪽 서브트리은 모두 이진탐색트리의 정의를 만족한다.
		4. BST 모든 노드의 키 값들은 유일하다. 
		   (유일하지 않게 구성하려면, 키 값이 같을 경우 기준을 정하여 한쪽 서브트리에 들어가도록 구성)
	*/
	template <typename T>
	struct BinaryTreeData
	{
		T data;
		BinaryTreeData<T>* parent;
		BinaryTreeData<T>* left;
		BinaryTreeData<T>* right;

		BinaryTreeData()
		{
			data = 0;
			parent = nullptr;
			left = nullptr;
			right = nullptr;
		}
	};

	template <typename T>
	class BinaryTree
	{
		BinaryTreeData<T>* root;
	public:
		BinaryTree();
		~BinaryTree();
		void Insert(T input);
		void Delete(T input);
		void ShowTheTree();
		bool Search(T input);
		bool Search(BinaryTreeData<T>* pivot, BinaryTreeData<T>* input);
		void DestroyTree(BinaryTreeData<T>* input);
		BinaryTreeData<T>* SearchMinNode(BinaryTreeData<T>* input);
		void PreOrderPrintTree(BinaryTreeData<T>* input);
	};

	template <typename T>
	void BinaryTree<T>::ShowTheTree()
	{
		PreOrderPrintTree(root);
	}

	template <typename T>
	BinaryTree<T>::BinaryTree()
	{
		root = nullptr;
	}

	template <typename T>
	BinaryTree<T>::~BinaryTree()
	{
		DestroyTree(root);
	}

	template <typename T>
	BinaryTreeData<T>* BinaryTree<T>::SearchMinNode(BinaryTreeData<T>* input)
	{
		if(input == nullptr)
			return nullptr;
		if(input->left == nullptr)
			return input;
		else
			return SearchMinNode(input->left);
	}

	template <typename T>
	void BinaryTree<T>::DestroyTree(BinaryTreeData<T>* input)
	{
		if(input->left != nullptr)
			DestroyTree(input->left);
		
		if(input->right != nullptr)
			DestroyTree(input->right);

		input->parent = nullptr;
		input->left = nullptr;
		input->right = nullptr;
		delete input;
	}
	/*
		BST 트리의 삽입연산
		1. 먼저 탐색 연산 필요
		2. BST 노드의 키값은 유일하므로 새로운 키값들을 삽입하려고 하면 탐색 연산은 반드시 실패
		3. 탐색연산이 실패한 바로 그 위치에 새로운 노드를 삽입
	*/
	template <typename T>
	void BinaryTree<T>::Insert(T input)
	{
		BinaryTreeData<T>* temp = new BinaryTreeData<T>;
		temp->data = input;

		if(root == nullptr)
		{
			root = temp;
		}
		else
		{
			bool result = !Search(root, temp);

			if(result)
			{
				if(temp->parent->data > temp->data)
				{
					temp->parent->left = temp;
					std::cout<<temp->data<<" parent is : "<<temp->parent->data<<std::endl;
				}
				else
				{
					temp->parent->right = temp;
					std::cout<<temp->data<<" parent is : "<<temp->parent->data<<std::endl;
				}
			}
		}
	}

	/*
		BST 삭제 연산
		1. 삽입연산과 마찬가지로 탐색 연산부터 시작
		2. 삭제하려는 노드의 차수에 따라 삭제연산 (노드의 차수 => 해당 노드의 자식 노드 개수)
			- 차수가 0일때 => 단순히 노드 삭제 (부모 노드와 연결 끊기, 메모리 해제)
			- 차수가 1일때 => 삭제하려는 노드가 왼쪽 서브트리나 오른쪽 서브트리 중 하나를 가지고 있다면
							  단순히 그 노드를 삭제하고 서브트리를 삭제한 자리로 이동
			- 차수가 2일때 => 삭제할 노드를 대체할 노드 찾기
			                  (삭제할 노드의 왼쪽 서브트리의 가장 큰값, 오른쪽 트리의 가장 작은 값)
	*/
	template <typename T>
	void BinaryTree<T>::Delete(T input)
	{
		BinaryTreeData<T>* temp = new BinaryTreeData<T>;
		temp->data = input;
		
		if(Search(root, temp))
		{
			// 자식 노드가 없는 경우
			if(temp->left==nullptr && temp->right == nullptr)
			{
				if(root == temp)
					root = nullptr;
				else if (temp->parent->left == temp)
				{
					delete temp->parent->left;
					temp->parent->left = nullptr;
				}
				else
				{
					delete temp->parent->right;
					temp->parent->right = nullptr;
				}
			}
			// 한개의 자식 노드가 있는 경우
			else if (temp->left == nullptr || temp->right == nullptr)
			{
				BinaryTreeData<T>* child;
				if(temp->left != nullptr)
					child = temp->left;
				else
   				    child = temp->right;

				if(temp->parent == nullptr)
					root = child;
				else if(temp->parent->left == temp)
				{
					delete temp->parent->left;
					temp->parent->left = child;
				}else
				{
					delete temp->parent->right;
					temp->parent->right = child;
				}
			}
			// 두개의 자식 노드를 가지고 있는 경우
			else {
				BinaryTreeData<T>* min = SearchMinNode(temp->right);
				T minValue = min->data;
				Delete(minValue);
				temp->data = minValue;
				//delete min;
			}
		}
		else
		{
			std::cout<<"The Tree dosen't include input node!"<<std::endl;
		}
		delete temp;
	}
	
	template <typename T>
	void BinaryTree<T>::PreOrderPrintTree(BinaryTreeData<T>* input)
	{
		if(input != nullptr)
		{
			std::cout<<input->data << ' ';
			PreOrderPrintTree(input->left);
			PreOrderPrintTree(input->right);
		}
	}
	/*
		BST 탐색연산
		1. 현재 검색의 기준 노드가 NULL이면 검색은 실패
		2. 입력된 키값을 확인하여 검색하고 키 값이 트리안에 있으면 검색 성공
		3. 검색 키 값이 현재 검색의 루트노드보다 작으면 왼쪽 서브트리로 이동
		4. 검색 키 값이 현재 검색의 루트노드보다 크면 오른쪽 서브트리로 이동
	*/
	template <typename T>
	bool BinaryTree<T>::Search(T input)
	{
		BinaryTreeData<T>* temp = new BinaryTreeData<T>;
		temp->data = input;
		
		if(Search(root, temp))
		{
			delete temp;
			return true;
		}
		delete temp;
		return false;
	}

	template <typename T>
	bool BinaryTree<T>::Search(BinaryTreeData<T>* pivot, BinaryTreeData<T>* input)
	{
		if(pivot == nullptr)
		{
			return false;
		}

		if(pivot->data < input->data)
		{
			input->parent = pivot;
			Search(pivot->right, input);
		}
		else if(pivot->data > input->data)
		{
			input->parent = pivot;
			Search(pivot->left, input);
		}
		else
		{
			return true;
		}
	}
}

#endif