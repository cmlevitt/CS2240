# Project 2 Report

Answer the following prompts directly in this file:
* Information about your dataset (you will be assigned a different grader for this project)
    * My dataset is a list of all characters from the manga/anime "One Piece". It includes numbering, 
      character name, chapter the character first appeared in, episode the character first appeared in, 
      and the year the character first showed up. 
* The time complexities of each method in the Stack and Queue classes
     * Method Complexities:
     * O(1) - push(), pop(), enqueue(), dequeue()
     * O(n) - search(), print()
* Justify your use of pointers in the Queue (i.e. the direction of the arrows between the Nodes) as it relates to the complexity of the enqueue and dequeue methods
     *   The front pointer references the first node, and the back pointer the last node in the queue.
         When a new node is enqueued, the next pointer of the last node then points to the new node,
         which becomes the new last node in the queue.
* An explanation of when and why the 10 objects in the main function changed their order
     *  The 10 items changed order when they were dequeued from the Queue and pushed to the stack.
        This was because the first number being dequeued was number 1, which was then made the bottom of
        the stack, and so on. The queue was FIFO, and the stack LIFO, changing the order of items. 

**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**