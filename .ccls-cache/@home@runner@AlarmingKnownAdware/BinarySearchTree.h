struct Node
{
  int data;
  Node *left;
  Node *right;
  Node():data(0), left(nullptr), right(nullptr){}
};

class BinarySearchTree
{
  public:
    BinarySearchTree();
    ~BinarySearchTree();
    static Node* insertNode(int val, Node* node = nullptr);
    static Node* findNode(int val);
    static Node* removeNode(int val, Node* node);
    static Node* minValueNode(Node* node);
    static void inOrderTraversal(Node* node);
    static void postOrderTraversal(Node* node);
};