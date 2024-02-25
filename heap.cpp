#include <iostream>
#include <vector>

template <typename T>
class Heap {
public:
	Heap() = default;
	Heap(std::vector<T>& oth);
	void Insert(T val);
	T getMax();
	void printHeap();
private:
	void MaxHeapify(int i);
	void MaxHeapifyUp(int i);
	void buildMaxHeap();
	int getParent(int i);
	int getLeft(int i);
	int getRight(int i);
	std::vector<T> heap;
	int size = 0;
};

template<typename T>
Heap<T>::Heap(std::vector<T>& oth) 
	: size{oth.size()} {
	for(const auto& value : oth) {
		heap.push_back(value);
	}
	buildMaxHeap();
}

template<typename T>
void Heap<T>::Insert(T val){
	heap.push_back(val);
	++size;
	MaxHeapifyUp(size-1);
}

template<typename T>
T Heap<T>::getMax(){
	return heap[0];
}

template<typename T>
void Heap<T>::MaxHeapify(int i) {
	int largestI;
	int l = getLeft(i);
	int r = getRight(i);
	if (l < size && heap[l] > heap[i]) {
		largestI = l;
	} else {
		largestI = i;
	}
	if (r < size && heap[r] > heap[largestI]) {
		largestI = r;
	}
	if (largestI != i) {
		std::swap(heap[i],heap[largestI]);
		MaxHeapify(largestI);
	}
}

template<typename T>
void Heap<T>::MaxHeapifyUp(int i) {
	int largest = i;
	int p = getParent(i);
	if (i >= 0 && p >= 0 && heap[i] > heap[p]) {
		std::swap(heap[i],heap[p]);
		largest = p;
		MaxHeapifyUp(largest);
	}
}

template<typename T>
void Heap<T>::buildMaxHeap() {
	for (int i = size/2; i >= 0; --i) {
		MaxHeapify(i);
	}
}

template<typename T>
int Heap<T>::getParent(int i) {
	return (i - 1) / 2;
}

template<typename T>
int Heap<T>::getLeft(int i) {
	return (i * 2) + 1;
}

template<typename T>
int Heap<T>::getRight(int i) {
	return (i * 2) + 2;
}

template<typename T>
void Heap<T>::printHeap() {
	for(const auto& value : heap) {
		std::cout << value << " ";
	}
	std::cout << std::endl;
}

int main() { 
	std::vector<int> vec = {1,2,3,4};
	Heap<int> heap(vec);
	heap.Insert(7);
	heap.printHeap();
}

