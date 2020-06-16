#pragma once

template <typename T>
class AAList
{
public:
	AAList()
	{
		this->size = 0;
		this->head = nullptr;
	}
	void push_back(T data) {
		if (head == nullptr) {
			head = new AANode<T>(data);
		}
		else {
			AANode<T>* current = this->head;
			while (current->pNext != nullptr) {
				current = current->pNext;
			}
			current->pNext = new AANode<T>(data);
		}
		this->size += 1;

	}
	void push_front(T data) {

		this->head = new AANode<T>(data, head);
		size++;
	}
	void insert(T data, int index) {
		//Необходима проверка
		if (index == 0) {
			push_front(data);
		}
		else if (index < size) {
			AANode<T>* pref = this->head;
			for (int i = 0; i < index - 1; i++) {
				pref = pref->pNext;
			}
			AANode<T>* n = new AANode<T>(data, pref->pNext);
			pref->pNext = n;
			size++;
		}
		else {
			push_back(data);
		}
	}
	int getSize() {
		return this->size;
	}
	T& operator[](const int index) {
		//Необходима проверка
		if (index < size) {
			AANode<T>* current = this->head;
			for (int i = 0; i < index; i++) {
				current = current->pNext;
			}
			return current->data;
		}
	}
	void pop_front() {
		AANode<T>* temp = this->head;
		head = head->pNext;
		delete temp;
		size--;
	}
	void removeAt(int index) {
		//Необходима проверка 
		if (index < size) {
			AANode<T>* pref = getPrefByIndex(index);
			AANode<T>* toDestroid = pref->pNext;
			pref->pNext = toDestroid->pNext;
			delete toDestroid;
			size--;
		}
	}
	void clear() {
		while (size)
		{
			pop_front();
		}
	}
	~AAList()
	{
		clear();
	}
private:
	template <typename T>
	class AANode {
	public:
		AANode* pNext;
		T data;
		AANode(T data = T(), AANode* pNext = nullptr) {
			this->pNext = pNext;
			this->data = data;
		}

	};
	AANode<T>* getPrefByIndex(int index) {
		AANode<T>* pref = this->head;

		for (int i = 0; i < index - 1; i++) {
			pref = pref->pNext;

		}
		return pref;
	}
	int size = 0;
	AANode<T>* head = nullptr;
};
