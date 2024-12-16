# Project 5 Report

Answer the following prompts directly in this file:
* Information about your dataset. You will be assigned a different grader for this project.
    My dataset is of characters from the anime/manga One Piece, it contains columns for id#, character name, and then year, chapter, and episode the character first appeared.
* Create graphs for the number of collisions for inserting your dataset into all 20 hash tables.
  * Clearly label the graph titles and axes.
  * Set up the graph in a way that makes the most sense to you. Here are some options I have seen before:
    * Using a line graph to track the *individual* collision counts as each insertion is made. High-valued blips happen in open addressing when rehashes occur.
    * Using a line graph to track the *cumulative* collision count as each insertion is made. Vertical jumps happen in open addressing when rehashes occur.
    * Using a line graph to track the *average* number of collisions per insertion, where each hash table has one value and you can see the trends as the initial table size grows.
* Using the graphs, analyze why the collision counts are different for the different size hash tables. Use what you know about your keys and the hash tables to justify why the collision counts make sense.
  * The collision counts are different for different size hash tables for a few reasons. Some hash tables using Open Addressing, due to the size of my vector, need to rehash at some point. This increases the collision count and the 
  table size. In Separate Chaining, larger tables have fewer collisions, because there are more open spaces for the inputs to go. More Unique keys, like key2 in my code, result in fewer collisions for each table size. 
* Determine which global function works best as the key for your dataset objects based on the collision counts.
  * It appears that getKey2, or the concatenated character name and chapter worked the best. While the difference wasn't drastic, the collision count appeared lower for the tables using this key.
  This is likely due to the fact that a longer and more complex input makes for a more unique hash value, so the collision count lowers.
* Draw conclusions about which hash collision detection method works best on your dataset (separate chaining or open addressing).
  Separate Chaining seems to work best on my dataset, with a pretty consistently lower collision count. Separate Chaining has the benefit of not having the vertical spike in collisions when
  the table is rehashed. The Separate chaining graphs show a gradual increase, but without any of those rehashing vertical jumps. I see a similar shape in open addressing tables 5 and 10, which were the 
  only oen addressing tables that didn't need to rehash. Because of my vector size and the table sizes I chose, Separate Chaining is the better method for my data. 
**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**