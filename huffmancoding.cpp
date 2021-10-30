#include<bits/stdc++.h>
using namespace std;


#define MAX_TREE_HT 100
 unordered_map<char, int> umap;

struct MinHeapNode {

	
	char data;


	unsigned freq;

	struct MinHeapNode *left, *right;
};


struct MinHeap {


	unsigned size;


	unsigned capacity;


	struct MinHeapNode** array;
};


struct MinHeapNode* newNode(char data, unsigned freq)
{
	struct MinHeapNode* temp
		= (struct MinHeapNode*)malloc
(sizeof(struct MinHeapNode));

	temp->left = temp->right = NULL;
	temp->data = data;
	temp->freq = freq;

	return temp;
}


struct MinHeap* createMinHeap(unsigned capacity)

{

	struct MinHeap* minHeap
		= (struct MinHeap*)malloc(sizeof(struct MinHeap));

	
	minHeap->size = 0;

	minHeap->capacity = capacity;

	minHeap->array
		= (struct MinHeapNode**)malloc(minHeap->
capacity * sizeof(struct MinHeapNode*));
	return minHeap;
}


void swapMinHeapNode(struct MinHeapNode** a,
					struct MinHeapNode** b)

{

	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}


void minHeapify(struct MinHeap* minHeap, int idx)

{

	int smallest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < minHeap->size && minHeap->array[left]->
freq < minHeap->array[smallest]->freq)
		smallest = left;

	if (right < minHeap->size && minHeap->array[right]->
freq < minHeap->array[smallest]->freq)
		smallest = right;

	if (smallest != idx) {
		swapMinHeapNode(&minHeap->array[smallest],
						&minHeap->array[idx]);
		minHeapify(minHeap, smallest);
	}
}


int isSizeOne(struct MinHeap* minHeap)
{

	return (minHeap->size == 1);
}


struct MinHeapNode* extractMin(struct MinHeap* minHeap)

{

	struct MinHeapNode* temp = minHeap->array[0];
	minHeap->array[0]
		= minHeap->array[minHeap->size - 1];

	--minHeap->size;
	minHeapify(minHeap, 0);

	return temp;
}


void insertMinHeap(struct MinHeap* minHeap,
				struct MinHeapNode* minHeapNode)

{

	++minHeap->size;
	int i = minHeap->size - 1;

	while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {

		minHeap->array[i] = minHeap->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}

	minHeap->array[i] = minHeapNode;
}


void buildMinHeap(struct MinHeap* minHeap)

{

	int n = minHeap->size - 1;
	int i;

	for (i = (n - 1) / 2; i >= 0; --i)
		minHeapify(minHeap, i);
}


void printArr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		cout<< arr[i];

	cout<<"\n";
}


int isLeaf(struct MinHeapNode* root)

{

	return !(root->left) && !(root->right);
}


struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)

{

	struct MinHeap* minHeap = createMinHeap(size);

	for (int i = 0; i < size; ++i)
		minHeap->array[i] = newNode(data[i], freq[i]);

	minHeap->size = size;
	buildMinHeap(minHeap);

	return minHeap;
}


struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)

{
	struct MinHeapNode *left, *right, *top;


	struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);


	while (!isSizeOne(minHeap)) {

		
		left = extractMin(minHeap);
		right = extractMin(minHeap);

	
		top = newNode('$', left->freq + right->freq);

		top->left = left;
		top->right = right;

		insertMinHeap(minHeap, top);
	}


	return extractMin(minHeap);
}


void printCodes(struct MinHeapNode* root, int arr[], int top)

{


	if (root->left) {

		arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}


	if (root->right) {

		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}


	if (isLeaf(root)) {

		cout<< root->data <<": ";
		printArr(arr, top);
	}
}

void CalculateCodes(struct MinHeapNode* root, int arr[], int top)

{


	if (root->left) {

		arr[top] = 0;
		CalculateCodes(root->left, arr, top + 1);
	}


	if (root->right) {

		arr[top] = 1;
		CalculateCodes(root->right, arr, top + 1);
	}


	if (isLeaf(root)) {

		umap[root->data]=top;
		
	}
}



void HuffmanCodes(char data[], int freq[], int size)

{

	struct MinHeapNode* root
		= buildHuffmanTree(data, freq, size);

	
	int arr[MAX_TREE_HT], top = 0;

	printCodes(root, arr, top);
}
void printPreorder(struct MinHeapNode* node)
{
    if (node == NULL)
        return;
 
   
    cout << node->data << " ";
 
    printPreorder(node->left);
 
  
    printPreorder(node->right);
}
 

int main()
{

	char arr[10]; 
	int freq[10]; 
	int n,i,j,ch=1;
	cout<<"\nEnter the size of the array ";
	cin>>n;
	while(ch)
	{
	cout<<"\nchoose\n0 to quit\n1 toEnter data\n2 to print the array\n3 to print huffmann  tree in preorder\n4 to print codes\n5 to compare huffmann codes with fixed length codes\nEnter your choice ";
	cin>>ch;
	
	switch (ch)
    {
      case 0:
          printf("quit");
           break;
      case 1:
          printf("characters : ");
          for(i=0;i<n;i++)
          cin>>arr[i];
          
          printf("frequencies:  ");
          for(i=0;i<n;i++)
          cin>>freq[i];
          
           break;
      case 2:
          printf("array\n");
          for(i=0;i<n;i++)
          {
              for(j=1;j<=freq[i];j++)
              cout<<arr[i]<<" ";
          }
          break;
      case 3:
      {
      struct MinHeapNode* root
		= buildHuffmanTree(arr, freq, n);
		printPreorder(root);
          printf("Case 3 executed. ");
          break;
      }
          case 4:
          HuffmanCodes(arr, freq, n);
          
          break;
          case 5:
          {
          int sumoffreq=0;
          for(int i=0;i<n;i++)
          {
             sumoffreq+=freq[i];
          }
          printf("\nFor fixed length coding size of message=%d",(sumoffreq*256));
          struct MinHeapNode* root
		= buildHuffmanTree(arr, freq, n);
		int pp[MAX_TREE_HT], top = 0;
	CalculateCodes(root,pp,top);
	
	int codesize=0;
	
		int i;
	for (auto x : umap)
	{
	  
	   for(i=0;i<n;i++)
	   {
	   if(x.first==arr[i])
	   break;
	   }
	   codesize+=x.second*freq[i];
	}
	cout<<"\nSize of variable length coding="<<codesize;
          printf("\nCase 5 executed. ");
          break;
    }
      default:
          printf("Default case executed. ");
    }
	}

	

	return 0;
}


