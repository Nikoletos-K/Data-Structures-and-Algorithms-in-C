# Comparator functions

Comparators used for generic data structures and algorithms

## Main functionality
I'e created functions that return:
- 0: if the two values are equal 
- \>0: if value a > value b
- <0: if value a > value b

__Integers comparison:__
```
int compare_ints(const void * a, const void * b);
```

__String comparison:__
```
int compare_str(const void * a,const void * b);
```

__Longs comparison:__
```
int compare_longs(const void * a,const void * b);
```

__Float comparison:__
```
int compare_floats(const void * a,const void * b);
```

__Date comparison:__ only for the format:  dd-mm-yyyy
```
int compare_dates(const  void * a,const void * b); 
```
