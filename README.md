DataStructures
==============

Collection of self-made data structures I'm making for myself as a thought experiment.  The purpose is so I can better understand the different kinds of data structures at my disposal as a programmer, as well as know the pros and cons of each.

The implementation of each data structure is based off what I am reading in the book "Data Structures & Algorithm Analysis in C++" by Clifford A. Shaffer.  While much of the code does come from the book, I put my own twist on things and add some stuff of my own.


Data structures included so far:
--------------------------------
<ul>
<li>Array-based List</li>
<li>Singly Linked List</li>
<li>Doubly Linked List</li>
<li>Array-based Stack</li>
<li>Linked Stack</li>
<li>Array-based Queue</li>
<li>Linked Queue</li>
<li>Unsorted array-based Dictionary</li>
<li>Sorted array-based Dictionary</li>
</ul>

A note about the Dictionary implementations: while what I have is adequate for showing how a Dictionary data structure works, I did not include a robust way of comparing Keys.  It will work if your Key is of type integer or float etc, but not with something like a string where the comparison is more ambiguous.  A separate comparator class would have to be created in order to accomodate for this.
