# Project 3 Report

Answer the following questions directly in this file:
* You will have a different grader again, so make sure your report includes information about your dataset.
    * My dataset is a csv of characters from the anime/manga One Piece, with information of the year they first appeared in print, 
      the chapter of first appearance, and episode of first appearance
* How do the depths of the random-ordered integers compare to the depths of the ordered integers for each tree? Why?
    * In the BST of ordered integers, the ints are read in ascending order and each new int becomes a right child of 
      its parent, creating a depth equal to the number of ints in the vector (no siblings or left children). For random order,
      the tree has shallower depth because the shuffled integers have the chance to be right or left children,
      and the tree is more balanced. 
    * In the AVL of ordered integers and random-ordered integers, the depths of each item were different, but
      the general balance of the tree and how deep it goes doesn't change much. The AVL tree is self balancing,
      so it will be balanced this way no matter if the integers are ordered or shuffled.
      * In the Splay trees of ordered and random-ordered integers, the depth of the ordered integers is far greater than the shuffled set of ints.
        The ordered integers have a max depth of 99, whereas the random-ordered has a max depth of 8.
* How do the depths of each custom-data-type tree compare to each other?
    * The depth of the BST is equal to the number of items in the vector (the index), so it has a depth of 1316. The AVL tree
      was considerably less deep, with a max depth of 10. The splay tree had a max depth of 1316 like the BST did, but notably had
      only one node that was that deep. Most of the depths of the Splay tree were concentrated from around 2-9, with a few outliers in 
      the first few nodes being far deeper. 

* Why do the depths of the second custom-data-type Splay Tree make sense?
    * Each first time it finds the depth of the item, it moves it to the top. It follows that the first time a node is visited the depth is a non-1 number,
      and each of the following 4 depths are 1 because the item was moved to the root

* Graph the Binary Search Tree, AVL Tree, and Splay Tree depths for the custom data type trees. Do not use C++ to graph, you can use whatever spreadsheet application or graphical programming language you prefer. You can use whatever graph is most readable to you (e.g. scatter plot, histogram, etc.).
  * Your graphs should have clear labels for both x and y axes.
  * Save your graph files in the graphs folder.
  * You do not need to graph the depths of the integer type trees or the Splay Tree that finds each object 5 times in a row, but you can if you feel it helps you analyze the data.
  * An example graph spreadsheet and an example graph image have been included in the starter code.
  * Here is how you include an image in your Report.md file: ![example graph](graphs/example-graph.png)
  * ![BST Graph](graphs/BST_CustomType_Graph.png)
  * ![AVL Graph](graphs/AVL_CustomType_Graph.png)
  * ![SPLAY Graph](graphs/SPLAY_CustomType_Graph.png)
* ****** NOTE: I did each of the 3 graphs differently (line vs scatter graphs, which axis was which) to better visualize the data for each different tree type and 
                to practice more with excel which I don't often use. 
* Compare and contrast the graphs and explain the differences based on what you know about the structure and behavior of the trees. Justify the time complexity of searching the trees based on the results.
  * The line graph for the BST shows the worst case time complexity of O(N), where the tree is a linked list and each new node is a right child of its parent. 
  * In my scatter plot for the AVL tree, it shows the dispersion of different depth values at the different item indices. I believe the time complexity is O(log N) for the AVL tree,
     because it is self-balancing no matter the order objects are inserted in.
  * In the graph of the Splay tree, nearly all the indexes depths are clustered in the shallowest depths, with a few outliers reaching far deeper. I believe
    this shows a time complexity of O(log N), because the depth starts very high but then drops and plateaus after just a few nodes.
  **Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**
    Used concept from stack overflow https://stackoverflow.com/questions/27847128/using-for-loop-to-add-numbers-to-a-vector
    not sure if we covered push_back in class so I am citing it to be safe :P