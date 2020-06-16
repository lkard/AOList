#pragma once
template <typename T>
class AOList
{

public:
	AOList()
	{
		this->size = 0;
		this->head = nullptr;
	}
	int getSize() {
		return this->size;
	}
	void push_back(T data) {
		if (head == nullptr) {
			head = new AONode<T>(data);
		}
		else {
			AONode<T>* current = this->head;
			while (current->pNext != nullptr) {
				current = current->pNext;
			}
			current->pNext = new AONode<T>(data);
		}
		this->size += 1;

	}
	void push_front(T data) {

		this->head = new AONode<T>(data, head);
		size++;
	}
	void insert(T data, int index) {
		//Необходима проверка
		if (index == 0) {
			push_front(data);
		}
		else if (index < size) {
			AONode<T>* pref = this->head;
			for (int i = 0; i < index - 1; i++) {
				pref = pref->pNext;
			}
			AONode<T>* n = new AONode<T>(data, pref->pNext);
			pref->pNext = n;
			size++;
		}
		else {
			push_back(data);
		}
	}
	T& operator[](const int index) {
		//Необходима проверка
		if (index < size) {
			AONode<T>* current = this->head;
			for (int i = 0; i < index; i++) {
				current = current->pNext;
			}
			return current->data;
		}
	}
	void pop_front() {
		AONode<T>* temp = this->head;
		head = head->pNext;
		delete temp;
		size--;
	}
	void removeAt(int index) {
		//Необходима проверка 
		if (index < size) {
			AONode<T>* pref = getPrefByIndex(index);
			AONode<T>* toDestroid = pref->pNext;
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
	~AOList()
	{
		clear();
	}
private:
	template <typename T>
	class AONode {
	public:
		AONode* pNext;
		T data;
		AONode(T data = T(), AONode* pNext = nullptr) {
			this->pNext = pNext;
			this->data = data;
		}

	};
	AONode<T>* getPrefByIndex(int index) {
		AONode<T>* pref = this->head;

		for (int i = 0; i < index - 1; i++) {
			pref = pref->pNext;

		}
		return pref;
	}
	int size = 0;
	AONode<T>* head = nullptr;
};
