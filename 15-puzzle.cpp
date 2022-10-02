// Program to print path from root node to destination node
// for N*N -1 puzzle algorithm using Branch and Bound
// The solution assumes that instance of puzzle is solvable
#include <bits/stdc++.h>
using namespace std;
#define N 4

// state space tree nodes
struct Node
{
	// stores the parent node of the current node
	// helps in tracing path when the answer is found
	Node* parent;

	// stores matrix
	int mat[N][N];

	// stores blank tile coordinates
	int x, y;

	// stores the number of misplaced tiles
	int cost;

	// stores the number of moves so far
	int level;
};

// Function to print N x N matrix
int printMatrix(int mat[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

// Function to allocate a new node
Node* newNode(int mat[N][N], int x, int y, int newX,
			int newY, int level, Node* parent)
{
	Node* node = new Node;

	// set pointer for path to root
	node->parent = parent;

	// copy data from parent node to current node
	memcpy(node->mat, mat, sizeof node->mat);

	// move tile by 1 position
	swap(node->mat[x][y], node->mat[newX][newY]);

	// set number of misplaced tiles
	node->cost = INT_MAX;

	// set number of moves so far
	node->level = level;

	// update new blank tile coordinates
	node->x = newX;
	node->y = newY;

	return node;
}

// bottom, left, top, right
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

// Function to calculate the number of misplaced tiles
// ie. number of non-blank tiles not in their goal position
int calculateCost(int initial[N][N], int final[N][N])
{
	int count = 0;
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		if (initial[i][j] && initial[i][j] != final[i][j])
		count++;
	return count;
}

int isSafe(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < N);
}
int countt=0;
void printPath(Node* root)
{
	if (root == NULL)
		return;
	// printPath(root->parent);
	printMatrix(root->mat);
	cout<<"Number of misplaced elements: "<<root->cost<<endl;
	cout<<"Cost(number of misplaced + level of current node) : "<<root->cost+countt<<endl;
	cout<<"Count: "<<countt++<<endl;
	cout<<"----------------------\n";

	printf("\n");
}

struct comp
{
	bool operator()(const Node* lhs, const Node* rhs) const
	{
		return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
	}
};

void solve(int initial[N][N], int x, int y,
		int final[N][N])
{
	priority_queue<Node*, std::vector<Node*>, comp> pq;

	Node* root = newNode(initial, x, y, x, y, 0, NULL);
	root->cost = calculateCost(initial, final);

	pq.push(root);

	while (!pq.empty())
	{
		Node* min = pq.top();
 
 		printPath(min);

		pq.pop();

		if (min->cost == 0)
		{

			return;
		}


		for (int i = 0; i < 4; i++)
		{
			if (isSafe(min->x + row[i], min->y + col[i]))
			{


				Node* child = newNode(min->mat, min->x,
							min->y, min->x + row[i],
							min->y + col[i],
							min->level + 1, min);
				child->cost = calculateCost(child->mat, final);


				pq.push(child);
			}
		}
	}
}

int findX(int initial[N][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(initial[i][j]==0)
				return i;
		}
	}
}
int findY(int initial[N][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(initial[i][j]==0)
				return j;
		}
	}
}

// Driver code
int main()
{

	int initial[N][N] =
	{
		{1, 2, 3,4},
		{5, 6, 7,8},
		{9,10,11,12},
		{0,13,14,15}
	};


	int final[N][N] =
	{
		
		{1, 2, 3,4},
		{5, 6, 7,8},
		{9,10,11,12},
		{13,14,15,0}
	};


	int x = findX(initial);
	int y = findY(initial);

	solve(initial, x, y, final);

	return 0;
}
