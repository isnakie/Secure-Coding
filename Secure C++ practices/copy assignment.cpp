/* 
Example of copying assignment bad and better coding
*/

class IntArray{

private:
	int* array = nullptr;
	size_t nElems = 0;
	
	IntArray(const IntArray& rhs) {
		nElems = rhs.nElems;
		if (nElems){
			array = new int[nElems];
			std::memcpy(array, rhs.array, nElems * sizeof(int));
		}
	}
	/*
	First example deletes existing array. 
	If the 'new int[nElems]' allocation fails, the original array has already been deleted
	Should comment out...
	*/

	IntArray& operator=(const IntArray &rhs){
		if (this != &rhs) {
			delete[] array;
			array = nullptr;
			nElems = rhs.nElems;
			if (nElems) {
				array = new int[nElems];
				std::memcpy(array, rhs.array, nElems * sizeof(*array));
			}
		}
		return *this;
	}

	/* 
	Should allocate elements before deleting the old array
	*/

	IntArray& operator=(const IntArray &rhs){
		int *tmp = nullptr;
		if(rhs.nElems){
			tmp = new int[rhs.nElems];
			std::memcpy(tmp, rhs.array, rhs.nElems * sizeof(*array));
		}
		delete[] array;
		array = tmp;
		nElems = rhs.nElems;
		return *this;
	}
	
}