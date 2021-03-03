
typedef struct BloomFilter{

	char * bitArray;
	unsigned int size;

}BF;

unsigned int size_of_bitArray(unsigned int numOfVoters);

BF * createBF(unsigned int size);

void setBit(BF * bf,int hash);

void insertBF(BF * bf,unsigned int length, char * identity);
int checkBF(BF * bf,unsigned int length, char * identity);

void destroyBF(BF * bf);
