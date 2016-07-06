int FirstNotRepeatingChar(char * str) {
        if (str == NULL)
        {
        	return '\0'
        }

        const int tableSize = 256;
        unsigned int hashTable[tableSize];
        for (int i = 0; i < tableSize; ++i)
        {
        	hashTable[i] = 0;
        }

        char *hashKey = str;

        while(hashKey != '\0'){
        	hashTable[hashKey]++;
        	hashKey++;
        }

        hashKey = str;

        while(hashKey != '\0'){
        	if (hashTable[hashKey] == 1)
        	{
        		return *hashKey;
        	}else {
        		hashKey++;
        	}
        }
    }