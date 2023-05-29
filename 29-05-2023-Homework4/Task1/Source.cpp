#include<iostream>
#include<ostream>

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int data, Node* left = nullptr, Node* right = nullptr) :
		data(data), left(left), right(right) {}
};

class BTree
{
private:
	Node* root;

	void Insert(Node*& root, Node* node)
	{
		if (root == nullptr)
		{
			root = node;
			return;
		}
		if (root->data > node->data)
		{
			return Insert(root->left, node);
		}
		if (root->data < node->data)
		{
			return Insert(root->right, node);
		}
		if (root->data == node->data)
		{
			return;
		}
	}

	void Print(std::ostream& stream, Node*& root, int depth = 0)
	{
		if (root == nullptr)
		{
			return;
		}
		Print(stream, root->left, depth + 1);
		for (int i = 0; i < depth; ++i)
		{
			std::cout << "\t";
		}
		stream << root->data << std::endl;
		Print(stream, root->right, depth + 1);
	}

	Node*& GetNode(Node*& root, int element)
	{
		if (root == nullptr || root->data == element)
		{
			return root;
		}
		if (root->data > element)
		{
			return GetNode(root->left, element);
		}
		if (root->data < element)
		{
			return GetNode(root->right, element);
		}
	}
	Node*& GetNode(Node*& root, int element, Node*& previously)
	{
		if (root == nullptr || root->data == element)
		{
			return root;
		}
		if (root->data > element)
		{
			previously = root;
			return GetNode(root->left, element, previously);
		}
		if (root->data < element)
		{
			previously = root;
			return GetNode(root->right, element, previously);
		}
	}
	void UnlinkParent(Node*& child, Node*& parent)
	{
		if (parent->left == child)
			parent->left = nullptr;
		if (parent->right == child)
			parent->right = nullptr;
	}
	void LinkNode(Node*& child, Node*& parent)
	{
		if (parent->data > child->data)
		{
			parent->left = child;
		}
		if (parent->data < child->data)
		{
			parent->right = child;
		}
	}
	Node*& GetRootSubTree(Node*& parent)
	{
		if (parent->left != nullptr)
		{
			//std::cout << "Y LOX";
			return parent->left;
		}
		if (parent->right != nullptr)
			//std::cout << "Y NE LOX";
		{
			return parent->right;
		}
	}
	bool isSheet(Node*& check)
	{
		return (check->right == nullptr && check->left == nullptr);
	}
	bool isStick(Node*& check)
	{
		return ((check->right != nullptr && check->left == nullptr) || check->right == nullptr && check->left != nullptr);
	}
	bool isDBTree(Node*& check)
	{
		return (check->right != nullptr || check->left != nullptr);
	}
	bool isExist(Node*& check)
	{
		return (check != nullptr);
	}

	Node*& FindMinInTree(Node*& root)
	{
		if (root->left == nullptr)
			return root;
		else
			FindMinInTree(root->left);
	}
	Node*& FindNewRoot(Node*& root)
	{
		if (root == nullptr)
			return root;
		return FindMinInTree(root->right);
	}

	Node* Extract(Node*& root)
	{
		Node* temp = nullptr;
		Node* M = nullptr;
		if (!isExist(root))
			return nullptr;
		temp = root;
		if (isSheet(root))
		{
			root = nullptr;
			return temp;
		}
		if (isStick(root))
		{
			root = GetRootSubTree(root);
			return temp;
		}
		if (isDBTree(root))
		{
			M = Extract(FindNewRoot(root));
			M->left = root->left;
			M->right = root->right;
			root = M;
			return temp;
		}
	}

	Node* ExtractLesha(Node*& root)
	{
		Node* p;
		Node* t;
		p = root;
		if (root->left == nullptr)
		{
			std::cout << "1 slychai" << std::endl;
			root = root->right;
			return p;
		}
		if (root->right == nullptr)
		{
			std::cout << "2 slychai" << std::endl;
			p = root;
			root = root->left;

			return p;
		}
		if (root->right != nullptr && root->left != nullptr)
		{
			Node* p;
			Node* parent = root;
			p = ExtractPlus(root, parent);

			if (parent->left == p)
				parent->left = nullptr;
			if (parent->left == p)
				parent->left = nullptr;

			root->data = p->data;

			return p;
		}
	}

	Node* ExtractPlus(Node*& root, Node*& parent, bool flag = 1)
	{
		if (flag == 1)
		{
			return ExtractPlus(root->right, parent, 0);
		}
		else
		{
			if (root->left == nullptr)
			{
				return root;
			}
			parent = root;
			return ExtractPlus(root->left, parent, 0);
		}
	}





public:
	BTree() : root(nullptr) {}

	void Add(int data)
	{
		Insert(root, new Node(data));
	}

	void Remove(int data)
	{
		Node*& node = GetNode(root, data);
		if (node != nullptr)
		{
			Node* extracted = ExtractLesha(node);
			delete extracted;
		}
	}

	bool Contains(int data)
	{
		return (GetNode(root, data) != nullptr);
	}

	friend std::ostream& operator<<(std::ostream& stream, BTree& tree)
	{
		stream << "__________________" << std::endl;
		if (tree.root == nullptr)
		{
			stream << "EMPTY" << std::endl;
		}
		else
		{
			tree.Print(stream, tree.root);
		}
		stream << "__________________" << std::endl;
		return stream;
	}
	void ThankMe(int data)
	{
		Node* A = nullptr;
		Node*& B = FindMinInTree(A);
		std::cout << "B = " << B->data << std::endl;
		if (isExist(A))
			std::cout << "A = " << A->data << std::endl;
		else
			std::cout << "A not exist" << std::endl;
	}
};

int main(int argc, char* argv[])
{
	BTree tree;
	tree.Add(8);
	tree.Add(4);
	tree.Add(12);
	tree.Add(2);
	tree.Add(6);
	tree.Add(10);
	tree.Add(14);
	tree.Add(1);
	tree.Add(3);
	tree.Add(5);
	tree.Add(7);
	tree.Add(9);
	tree.Add(11);
	tree.Add(13);
	tree.Add(15);
	std::cout << tree << std::endl;


	//tree.Remove(1);
	tree.Remove(4);
	tree.Remove(12);
	tree.Remove(8);



	//tree.Remove(2);
	std::cout << tree << std::endl;
	return EXIT_SUCCESS;
}