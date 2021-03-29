#include <iostream>
using namespace std;

template<typename T>
class MaxHeap
{
public:
	bool insert(T val);
	bool remove(T data);
	void print();
	T getTop();
	bool createMaxHeap(T a[], int size);

	MaxHeap(int cap = 10);
	~MaxHeap();

private:
	int capacity;
	int size;
	T* heap;

	void filterUp(int index);
	void filterDown(int current, int end);
};

template<typename T>
bool MaxHeap<T>::insert(T val)
{
	if (size == capacity) return false;
	heap[size] = val;
	filterUp(size);
	size++;
	return true;
}

template<typename T>
bool MaxHeap<T>::remove(T data)
{
	if (size == 0) return false;
	int index;
	for (index = 0; index < size; index++) {
		if (heap[index] == data) {
			break;
		}
	}
	if (index == size) return false;
	heap[index] = heap[size - 1];

	filterDown(index, size--);
	return true;
}

template<typename T>
void MaxHeap<T>::print()
{
	for (int i = 0; i < size; i++) {
		cout << heap[i] << " ";
	}
}

template<typename T>
inline T MaxHeap<T>::getTop()
{
	if (size != 0) return heap[0];
}

template<typename T>
bool MaxHeap<T>::createMaxHeap(T a[], int size)
{
	if (size > capacity) return false;
	for (int i = 0; i < size; i++) {
		insert(a[i]);
	}
	return true;
}

template<typename T>
inline MaxHeap<T>::MaxHeap(int cap):capacity(cap), size(0), heap(nullptr)
{
	heap = new T[capacity];
}

template<typename T>
MaxHeap<T> :: ~MaxHeap()
{
	delete[]heap;
}

template<typename T>
void MaxHeap<T>::filterUp(int index)
{
	T value = heap[index];
	while (index > 0) {
		int indexParent = (index - 1) / 2;
		if (value < heap[indexParent])
			break;
		else {
			heap[index] = heap[indexParent];
			index = indexParent;
		}
	}
	heap[index] = value;
}

template<typename T>
void MaxHeap<T>::filterDown(int current, int end)
{
	int child = current * 2 + 1;
	T value = heap[current];
	while (child < end) {
		if (child < end && heap[child] < heap[child + 1]) child++;
		if (value > heap[child]) break;
		else {
			heap[current] = heap[child];
			current = child;
			child = child * 2 + 1;
		}
	}
	heap[current] = value;
}
