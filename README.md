<h2>INTRO</h2>
You are going to construct and manipulate with Binary Search Tree (BST). BST is a
rooted binary tree data structure. The nodes in the tree store keys and any internal node in BST has the
following properties:
<br>
<br>
<ul>
  <li>The left subtree of a node contains nodes with keys less than or equal to the node’s key</li>
  <li>The right subtree of a node contains nodes with keys greater than the node’s key</li>
  <li>The left and right subtrees of a node are also BSTs</li>
</ul>
The construction of a BST is based on the rules above. For example, consider that we are given the
following input [31, 65, 3, 10, 5, 100, 3, 12]. The first element will be the root of the tree and the rest will
be placed in correct positions within the tree based on the rules given above. The final BST constructed
for this example is given in Figure 1.
<br>
<br>
<div align="center">
<img src="https://github.com/user-attachments/assets/b3936917-8e8a-47cc-87e3-0514c11d8570" width=600px/><br>
</div>

<h2>Input/Output Specifications</h2>
Your program should accept the set of commands from standard input.
<br>
<br>
<b>1) CONSTRUCT [value1, value2, value3, …, valueN]</b><br><br>
The CONSTRUCT command expects a set of integers in brackets separated by commas. The
command takes the input and constructs a binary tree rooted at the first element of the input.<br>
For example, for the input given below, your program should construct a tree as shown in Figure 1.<br><br>
CONSTRUCT [31, 65, 3, 10, 5, 100, 3, 12] 
<br>
<br>
<b>2) INSERT value</b><br><br>
The INSERT command expects a single integer. It creates a new node and places the node in the
correct position in the tree. For example, INSERT 55, places the value 55 in the correct position as
shown in Figure 2 and outputs:<br><br>
The parent of 55 is 65
<br>
<br>
<b>3) LIST</b>
<br><br>
The LIST command performs inorder traversal on the tree (see Figure 3) and prints the keys of
every visiting node. Observe that inorder traversal of the BST prints sorted list in ascending
order. For example, LIST command that is given after previous two example commands, the
output will be:<br><br>
3 3 5 10 12 31 55 65 100
<br>
<br>
<b>4) PARENT value</b><br><br>
The PARENT command takes the input value, searches it in the tree and prints its parent. For
example:<br><br>
PARENT 12<br>
The parent of 12 is 10<br>
PARENT 31<br>
It is a root node<br><br>

<b>Note:</b> You can assume that there are no errors in the input. Hence, you do not need to explicitly
check for correctness of the provided input.<br><br>
Here are some sample runs:

<pre>
CONSTRUCT [31,65,3,10,5,100,3,12]
INSERT 55
The parent of 55 is 65
LIST
3 3 5 10 12 31 55 65 100
PARENT 12
The parent of 12 is 10
PARENT 31
It is a root node
INSERT 1
The parent of 1 is 3
LIST
1 3 3 5 10 12 31 55 65 100
INSERT 500
The parent of 500 is 100
LIST
1 3 3 5 10 12 31 55 65 100 500
PARENT 5
The parent of 5 is 10
</pre>

<b>5) DELETE value</b><br><br>
The DELETE command expects one integer value. Its purpose is to find the given value in the
tree and delete it. The state of the tree after deletion should still obey the rules specified above.
Also observe that the root of the tree might change after delete operation. You should maintain
the order of the tree and reconnect the parent/child connections. Figure 4 shows three different
scenarios of delete operation: a node has no children, has single child and has two children.

<img src="https://github.com/user-attachments/assets/269c10b9-f370-420d-bb8a-a48d4b85e83e" width=600px/><br>





