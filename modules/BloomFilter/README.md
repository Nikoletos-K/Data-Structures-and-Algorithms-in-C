# Bloom filter
A Bloom filter is a space-efficient probabilistic data structure, conceived by Burton Howard Bloom in 1970, that is used to test whether an element is a member of a set. False positive matches are possible, but false negatives are not – in other words, a query returns either "possibly in set" or "definitely not in set". Elements can be added to the set, but not removed (though this can be addressed with the counting Bloom filter variant); the more items added, the larger the probability of false positives.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/a/ac/Bloom_filter.svg/360px-Bloom_filter.svg.png)

## Functionality
With this data structure

![](https://upload.wikimedia.org/wikipedia/commons/thumb/c/c4/Bloom_filter_speed.svg/360px-Bloom_filter_speed.svg.png)


## Time and space complexity
While risking false positives, Bloom filters have a substantial space advantage over other data structures for representing sets, such as self-balancing binary search trees, tries, hash tables, or simple arrays or linked lists of the entries. Most of these require storing at least the data items themselves, which can require anywhere from a small number of bits, for small integers, to an arbitrary number of bits, such as for strings (tries are an exception since they can share storage between elements with equal prefixes). However, Bloom filters do not store the data items at all, and a separate solution must be provided for the actual storage. A bloom filter is extremely efficient in both time and space usage. These features are so important that it gives up accuracy to maintain them.

### Time

If we are using a bloom filter with mm bits and kk hash function, insertion and search will both take O(k)O(k) time. In both cases, we just need to run the input through all of the hash functions. Then we just check the output bits.

| Operation | Complexity |
| --- | --- |
| Insertion |	O(k) |
| Search | 	O(k) |

Note that this is one of the few data structures whose time complexity does not at all depend on the number of elements in it. This is because the elements never really enter the structure, only their hashes.

### Space

To truly understand the space complexity of the bloom filter, you have to first choose your parameters. You could make a bloom filter with k = 1k=1 and it would just be a hash table that ignores collisions. However, you would have a very large mm if you wanted to keep your false positive rate low. The space of the actual data structure (what holds the data) is simply O(m)O(m).

| | Complexity |
| --- | --- |
| Space | O(m) |

