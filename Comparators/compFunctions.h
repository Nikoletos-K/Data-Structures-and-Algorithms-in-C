typedef enum sortingColumn {

	sortIds = 1,
	sortFName = 2,
	sortLName = 3,
	sortStreet = 4,
	sortHouseId = 5,
	sortCity = 6,
	sortPC = 7,
	sortAmount = 8,

} sortingColumn;


int compareStrings(void * str1,void * str2);
int compareIntegers(void * int1,void * int2);
int compareLongs(void * long1,void * long2);
int compareFloats(void * float1,void * float2);

int compare(void * rec1,void * rec2,sortingColumn columnid);

void exchange(void ** array,int pos1,int pos2);
