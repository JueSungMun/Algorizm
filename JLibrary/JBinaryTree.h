#ifndef JBINARYTREE_H
#define JBINARYTREE_H

/*
	http://wonthing86.blogspot.kr/2014/07/binary-search-tree.html
	http://blog.naver.com/4717010/60209820587
*/
namespace JLib
{
	/*
		BST Ʈ���� ����
		1. ���� ����Ʈ���� Ű���� ��Ʈ�� Ű������ �۴�.
		2. ������ ����Ʈ���� Ű ���� ��Ʈ�� Ű ������ ũ��.
		3. ��/������ ����Ʈ���� ��� ����Ž��Ʈ���� ���Ǹ� �����Ѵ�.
		4. BST ��� ����� Ű ������ �����ϴ�. 
		   (�������� �ʰ� �����Ϸ���, Ű ���� ���� ��� ������ ���Ͽ� ���� ����Ʈ���� ������ ����)
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
		BST Ʈ���� ���Կ���
		1. ���� Ž�� ���� �ʿ�
		2. BST ����� Ű���� �����ϹǷ� ���ο� Ű������ �����Ϸ��� �ϸ� Ž�� ������ �ݵ�� ����
		3. Ž�������� ������ �ٷ� �� ��ġ�� ���ο� ��带 ����
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
		BST ���� ����
		1. ���Կ���� ���������� Ž�� ������� ����
		2. �����Ϸ��� ����� ������ ���� �������� (����� ���� => �ش� ����� �ڽ� ��� ����)
			- ������ 0�϶� => �ܼ��� ��� ���� (�θ� ���� ���� ����, �޸� ����)
			- ������ 1�϶� => �����Ϸ��� ��尡 ���� ����Ʈ���� ������ ����Ʈ�� �� �ϳ��� ������ �ִٸ�
							  �ܼ��� �� ��带 �����ϰ� ����Ʈ���� ������ �ڸ��� �̵�
			- ������ 2�϶� => ������ ��带 ��ü�� ��� ã��
			                  (������ ����� ���� ����Ʈ���� ���� ū��, ������ Ʈ���� ���� ���� ��)
	*/
	template <typename T>
	void BinaryTree<T>::Delete(T input)
	{
		BinaryTreeData<T>* temp = new BinaryTreeData<T>;
		temp->data = input;
		
		if(Search(root, temp))
		{
			// �ڽ� ��尡 ���� ���
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
			// �Ѱ��� �ڽ� ��尡 �ִ� ���
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
			// �ΰ��� �ڽ� ��带 ������ �ִ� ���
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
		BST Ž������
		1. ���� �˻��� ���� ��尡 NULL�̸� �˻��� ����
		2. �Էµ� Ű���� Ȯ���Ͽ� �˻��ϰ� Ű ���� Ʈ���ȿ� ������ �˻� ����
		3. �˻� Ű ���� ���� �˻��� ��Ʈ��庸�� ������ ���� ����Ʈ���� �̵�
		4. �˻� Ű ���� ���� �˻��� ��Ʈ��庸�� ũ�� ������ ����Ʈ���� �̵�
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