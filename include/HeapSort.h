void exchange(void ** array,int pos1,int pos2);
int getLeft(int i);
int getRight(int i);
int getParent(int i);
void maxHeapify(void ** array,int heapSize,int i);
void heapsort(void ** array,int heapSize);

/* --- Comparators ----- */
int compareStrings(void * str1,void * str2);
int compareIntegers(void * int1,void * int2);
int compareLongs(void * long1,void * long2);
int compareFloats(void * float1,void * float2);