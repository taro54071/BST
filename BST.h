
// An integer binary search tree

struct treeNode {                                           
   struct treeNode *leftPtr; // pointer to left subtree 
   int data; // node value                               
   struct treeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode         

typedef struct treeNode TreeNode; // synonym for struct treeNode
typedef TreeNode *TreeNodePtr; // synonym for TreeNode*
                    
typedef struct {
	int size;
	TreeNodePtr rootPtr;
}BST;

// prototypes
void insertNode( BST *b, int value ){

	 TreeNodePtr t =b->rootPtr,new_node;
	 int inserted=0; //สำเร็จ =1 ไม่สำเร็จ =0
    new_node=(TreeNodePtr) malloc(sizeof(TreeNode));
	if(new_node){
		new_node->leftPtr=NULL;
		new_node->rightPtr=NULL;
		new_node->data=value;
	/*First Node*/
	if(!b->rootPtr) // if(b->root==NULL)
  	b->rootPtr=new_node;
	else {
    while(!inserted){ // while(insert!=1)
      if(t->data >= value){// ฝั่งซ้ายของ node
        if(t->leftPtr)t = t->leftPtr;// if(t->leftPtr != NULL)
        else
        {
          t->leftPtr = new_node;
          inserted = 1; // successfully insert
          b->size++;

        }
       }
       else{ //ฝั่งขวาของ node
       if(t->rightPtr)t = t->rightPtr; // if(t->rightPtr != NULL)
        
        else
        {
          t->rightPtr = new_node;
          inserted = 1; // successfully insert
          b->size++;
        }
	     }

    }//end while		
 }//end else;
}
}//end function


void inOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {                
      inOrder( treePtr->leftPtr ); //Recursion to the left 
      printf( "%3d", treePtr->data );  //print the value    
      inOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if                          
} // end function 

void preOrder( TreeNodePtr treePtr )
{
  if ( treePtr != NULL )
  {
    printf("%3d", treePtr->data); // printf the value
    preOrder(treePtr->leftPtr);
    preOrder(treePtr->rightPtr);
  }
}
void postOrder( TreeNodePtr treePtr )
{
  if (treePtr != NULL)
  {
    postOrder(treePtr->leftPtr);
    postOrder(treePtr->rightPtr);
    printf("%3d", treePtr->data);
  }
}

void printTree( TreeNodePtr treePtr, int level)
{
  
  // if ( treePtr != NULL)
  // { 
  //   printTree(treePtr->rightPtr,level+1);
  //   for(int i=0; i<level; i++) 
  //   {
  //     printf("\t");
  //   }
  //   printf("%3d",treePtr->data);
  //   printf("\n");
  //   // printf("%d",level);
  //   printTree(treePtr->leftPtr,level--);
  // }
  if(treePtr != NULL)
  {
    printTree(treePtr->rightPtr, level+1);
    // printf("%d",level);
    for(int i = 0; i < level; i++)
    {
      printf("\t");
    }
    printf("%3d",treePtr->data);
    printf("\n");
    printTree(treePtr->leftPtr,level+1);
  }
}
