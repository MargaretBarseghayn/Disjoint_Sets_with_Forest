// pr-2.cpp : Defines the entry point for the console application.

using namespace std;

class ForestNode {
public:
	ForestNode* parent_;
	int		element_;
	int		rank_;
	ForestNode(ForestNode* parent = 0, int element = 0, int rank = 0) :
		parent_(parent), element_(element), rank_(rank) {}
};

void make_set(ForestNode* x)
{
	x->parent_ = x;
	x->rank_ = 0;
}

ForestNode* find_set(ForestNode* x)
{
	ForestNode* root = x, * tmp;
	while (root->parent_ != root)
		root = root->parent_;

	while (x->parent_ != root) {
		tmp = x->parent_;
		x->parent_ = root;
		x = tmp;
	}

	return root;
}

void un_sets(ForestNode* x, ForestNode* y)
{
	x = find_set(x);	y = find_set(y);

	if (x->rank_ > y->rank_)
		swap(x, y);

	x->parent_ = y;
	if (x->rank_ == y->rank_)
		y->rank_++;
}

void print(ForestNode** x, int number)
{
	for (int i = 1; i <= number; i++)
	{
		cout << "rank(x[" << i << "]) = " << x[i]->rank_ << ", ";
		cout << "leader(x[" << i << "]) = x[" << find_set(x[i])->element_ << ']' << endl;
	}
	cout << endl;
}

