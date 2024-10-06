#include <stdio.h>
#include <stdlib.h>


typedef struct Treenode { // Tree Node structure in  struct datatype.

    int data; // Data that stored in the node.
    struct Treenode *left; // Pointer which stores the left child's address.
    struct Treenode *right; //Pointer which stores the right child's address.


}Treenode;


Treenode *createNode(int data){ // Creates the nodes in the tree.

   Treenode *newNode = malloc(sizeof(Treenode)); // Create a dynamically memory for the node
   if(newNode == NULL){
      printf("Failed to allocate memory for the node\n"); // if there is no space in the memory for the node.
      fflush(stdout); // Force the buffer to flush.
      exit(1);
   }
   newNode->data = data; // Adding the value to the node that created.
   newNode->left = NULL; // Newly created node have no children.
   newNode->right = NULL; // Newly created node have no children.
   return newNode;

}

Treenode *insert(Treenode *root, int data){ // This method does the insertion to the tree. If tree is empty, it creates the root node using createNode method.
    // It inserts the values to the tree recursively. Because it is a binary search tree, if the value is equal or lower than its parent, it inserts to the
    // left child, if it is greater than its parent, it inserts to the right child.

     if(root == NULL){ // Creating the root node, if tree is empty.
        root = createNode(data);
     }
     else if(data <= root->data){ // Value is lower than the parent's value, inserting to the left side of the tree using recursion.
         root->left = insert(root->left, data);
     }
     else { // Value is greater than the parent's value, inserting to the right side of the tree using recursion.
        root->right = insert(root->right, data);
     }
     return root;

}


void inorder(Treenode* root) { // It performs inorder traversal on the tree and prints the keys of every visiting node.
    // Because it is BTS, it prints the values in ascending order. prints order, left -> root -> right.

    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        fflush(stdout); // Force the buffer to flush.
        inorder(root->right);
    }
}

void findParent(Treenode *root, int data){ // Takes the input value, searches it in the tree and prints its parent.

   if(root->data == data){ // Checks whether the value is root or not.
     printf("It is a root node\n");
     fflush(stdout); // Force the buffer to flush.
   }else{
   Treenode *parent = NULL; // Creating a temporary node to store parent.
   Treenode *curr = root; // Creating a temporary node to traverse the tree.

   while(curr != NULL && curr->data!= data){

      parent = curr; // During the traversal, at each step, it updates the parent pointer to the current node if the value
   // we are searching for is not found in the current node. Then it moves down to the left or right child depending
   // on whether the value we are searching for is less than or greater than the current node's value.
      if( data < curr->data ){ // If the data is lesser than the current value, it checks the left side of the tree.
        curr = curr->left;
      }else{ // If the data is greater than the current value, it checks the right side of the tree.
          curr = curr->right;
      }
   }
   printf("The parent of %d is %d\n", data, parent->data); // Prints the parent of the node.
   fflush(stdout); // Force the buffer to flush.

   }
}

Treenode* findMin(Treenode* root) { // Left most element in the tree is the smallest one.

    if (root == NULL){ // If the tree is empty, return NULL.
        return NULL;
    }
    while (root->left != NULL){ // Traverse to the leftmost node.
        root = root->left;
    }
    return root; // Return the leftmost node (minimum value).
}

Treenode *deleteFromTree(Treenode *root, int data){
    // Looking for data to be deleted.
    if(root == NULL){ // If tree is empty.
        return root;
    }else if(data < root->data){ // If the data that we are looking for is less than the data in the root, then its in the left subtree.
      root->left = deleteFromTree(root->left, data); // Store the address of the modified root of the left subtree. Because root of the left subtree may change after the deletion.
    }else if(data > root->data){ // If the data that we are looking for is greater than the data in the root, then its in the right subtree.
       root->right = deleteFromTree(root->right, data); // Store the address of the modified root of the right subtree. Because root of the right subtree may change after the deletion.
    }else{ // If the data is neither greater nor lesser, i.e. its equal.

        if(root->left == NULL && root->right == NULL){ // CASE 1: the data to be deleted has no children.
            free(root); // Reclaiming the memory allocated to the node being deleted.
            // Now root is dangling pointer because object in heap is deleted but root still has its address.
            root = NULL; // So we will set as NULL;


        }else if(root->left == NULL){ // CASE 2: the data to be deleted has ONE child and if only the left child is null.
            Treenode *temp = root; // Storing the address of current node that which will be deleted.
            root = root->right; // Moving root to the root's right child. Thus, the right child becomes the root of this subtree.
            free(temp); // Reclaiming the memory allocated to the node being deleted.

        }else if(root->right == NULL){ // CASE 2: the data to be deleted has ONE child and if only the right child is null.
            Treenode *temp = root; // Storing the address of current node that which will be deleted.
            root = root->left; // Moving root to the root's left child. Thus, the left child becomes the root of this subtree.
            free(temp); // Reclaiming the memory allocated to the node being deleted.

        }else{ // CASE 3: the data to be deleted has TWO children.
            Treenode *temp = findMin(root->right); // To preserve the structure of BST, we replace the node to be deleted with the minimum value in the right subtree.
            root->data = temp->data; // Replacing the node to be deleted with the minimum value in the right subtree.
            root->right = deleteFromTree(root->right, temp->data); // Deleting the duplicate or the node with minimum value from right subtree.
        }

    }
     return root; // Returning the pointer of the root node. Because root may change after deletion.



}


int main()
{

   Treenode *root = NULL; // Pointer to root node and setting tree as empty.
   char input[55]; // It stores the commands from the user.
   int value; // It stores the integer value associated with certain commands.


   while(1){ // An infinite loop to accept commands from the user until the program is terminated.
   // strcmp() is comparing the inputs with various possible commands like "CONSTRUCT", "INSERT", "LIST", "PARENT", and "DELETE".
      // Read the input from the user.
     if(scanf("%s", input) == EOF){ // This code continuously reads commands from the user until the EOF (end-of-file) condition is satisfied.
    // If the user does not enter another command, the program terminates.
         break;
     }
     else if (strcmp(input, "CONSTRUCT") == 0) { // The strcmp() compares two strings character by character. If the strings are equal, the function returns 0.

        char c;
        while ((c = getchar()) != '['); // This loop reads characters from the input until it encounters a '[' character.
        // It skips any leading characters before the opening '[' character.

        while (scanf("%d", &value) == 1) { // Reads integer values from the input. Constructing the binary search tree based on the input provided by the user.

            root = insert(root, value); // It inserts the values into the binary search tree root using the insert function.
            if ((c = getchar()) == ']') // If the character read is ']', that means the end of the input for the "CONSTRUCT" command has been reached, the loop breaks.
                break;
            }
      }
     else if (strcmp(input, "LIST") == 0) { // The strcmp() compares two strings character by character. If the strings are equal, the function returns 0.
            inorder(root); // It performs an inorder traversal (ascending order) of the binary search tree.
            printf("\n");
            fflush(stdout); // Force the buffer to flush
        }
     else if (strcmp(input, "INSERT") == 0) { // The strcmp() compares two strings character by character. If the strings are equal, the function returns 0.
            scanf("%d", &value); // It reads an integer value from the input.
            root = insert(root, value); // Inserting the value into the binary search tree.
            findParent(root, value); // It finds and prints the parent of the inserted value in the binary search tree.
           }
     else if (strcmp(input, "PARENT") == 0) { // The strcmp() compares two strings character by character. If the strings are equal, the function returns 0.
            scanf("%d", &value); // It reads an integer value from the input.
            findParent(root, value); // It finds and prints the parent of the specified value in the binary search tree.

         }
     else if(strcmp(input, "DELETE") == 0){ // The strcmp() compares two strings character by character. If the strings are equal, the function returns 0.

            int temp = root->data; // I keep the first root value in temp so that I can compare the first root and the changed root in case the root changes.

            scanf("%d", &value); // It reads an integer value from the input.
            root = deleteFromTree(root, value); // I am sending the value to be deleted from the tree via deleteFromTree method.
            // This method returns the current root of the tree after the delete operation.
            if( root->data != temp){ // I am comparing the first root with the new root. If the root has changed, I print the new root on the screen.
                printf("Root changed. The new root is %d\n", root->data); // Printing the new root on the screen.
                fflush(stdout); // Force the buffer to flush
            }

          }

      } // End of the first while

    return 0;
}
