# Project 4 Report

Answer the following prompts directly in this file:

* Information about your dataset (you will be assigned a different grader for this project).
  * My Dataset is about the manga/anime One Piece, and has columns representing numbers(1-1317), character names, and the chapter, episode, and year the character was first introduced.

* Analyze the data. Graph the number of reads and allocations for each sorting algorithm and look at how the number of reads and allocations grows when the size of the data set grows. Compare and contrast the different sorting algorithms and draw conclusions about which sorting algorithms are more efficient. Discuss complexities and their effects.
  * The first noticeable thing in graphing my output was the similar constant values for Allocations represented in 3 of my sorting algorithms, those being Bubble, Heap, and Selection sort. This
  makes sense, as all 3 have an auxliary complexity of O(1), and therefore the size of the vector does not affect the amount of memory used. On the other hand, Merge sort with an auxilary complexity
  of O(N), shows a linear decline in the amount of allocations per iteration, as well as having a significantly higher amount of allocations, at even the last iteration (smallest vector), 
  than the other 3 sorting algorithms did. As far as the number of reads, Merge sort graphs as linear again, opposed to the other 3 algorithms which show curves. The graphs for bubble heap and selection sort appear similar, the
  actual values vary but the general shape of the graphs are similar. Heap sort has a time complexity of O(nLog(n)), while Selection and Bubble sort have O(n^2). I think the reason that the graph for Heap sort appears 
  similar to the other two as far as the shape of the curve is because Heap sort has a smaller amount of reads relative to the other two, so the scope of the graph presents differently, whereas if they were all graphed together
  on the same scale the difference in the steepness would be more apparent. I would conclude that Merge sort would be the best algorithm to use in this case, as it is stable and efficient, with the time declining logarithmically and 
  the algorithm allocating memory at a O(n) complexity.


* Look at the output from the stabilityTest function and answer the following questions:
  * How are the names sorted by default?
    * They are default sorted alphabetically by first name.
  
  * How is the output from the two stable sorting algorithms different from the two unstable ones? Be specific in your answer, and use what you know about how each sorting algorithm works to justify your observations.
    * These algorithms are sorting by last name instead of first name, and the stable and unstable algorithms present different results. In the stable algorithms, those with the same last name maintain the original order of first names from the default sorting. 
    * In the unstable algorithms, this first name ordering is not preserved. For example, in the default ordering, Blake Black came before both Jordan and Sam Black. However, in heap sort the order goes Jordan, Sam, Blake. In the default ordering, Alex White was 
    the first on the list, whereas in Selection sort he appears below both Red and Robin White. This shows the instability of these algorithms, and how the way they sort does not preserve default ordering of duplicate items.

* Answers to the following questions: 
  * If you need to sort a contacts list on a mobile app, which sorting algorithm(s) would you use and why?
    * I would choose either the stable version of Quick sort, or use Merge sort. A list of contacts is likely not too large of a dataset,
    and you would want to use a stable algorithm to ensure contacts with the same name or information stay in the right order. 
  
  * What about if you need to sort a database of 20 million client files that are stored in a datacenter in the cloud?
    * For a large database like this, I think that Merge sort would work well, as it is stable and is ideal for the use case of a very large dataset.
    Merge sort does have a slightly higher time complexity of Nlog(N), it is relatively efficient for a dataset this size. Depending on the data type, a Radix sort could also
    work, but would need the data to have a known maximum.

**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**