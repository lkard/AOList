#include <iostream>
#include "AOList.h"
using namespace std;

int main()
{
	if (true) {


		AOList<int> lst;
		
		lst.push_back(10);
		lst.push_back(11);
		lst.push_front(5);
		lst.push_back(22);

		cout << "count of element = " << lst.getSize() << endl;
		for (int i = 0; i < lst.getSize();i++) {
			cout << "Element #" << i << "=" << lst[i] << endl;
		}
		lst.push_front(555);

		cout << endl << "count of element = " << lst.getSize() << endl;
		for (int i = 0; i < lst.getSize();i++) {
			cout << "Element #" << i << "=" << lst[i] << endl;
		}
		lst.removeAt(3);

		cout << endl << "count of element = " << lst.getSize() << endl;
		for (int i = 0; i < lst.getSize();i++) {
			cout << "Element #" << i << "=" << lst[i] << endl;
		}
		lst.insert(99, 2);

		cout << endl << "count of element = " << lst.getSize() << endl;
		for (int i = 0; i < lst.getSize();i++) {
			cout << "Element #" << i << "=" << lst[i] << endl;
		}

		lst.removeAt(2);

		cout << endl << "count of element = " << lst.getSize() << endl;
		for (int i = 0; i < lst.getSize();i++) {
			cout << "Element #" << i << "=" << lst[i] << endl;
		}

		lst.clear();
		cout << endl << "count of element = " << lst.getSize() << endl;
	}
	cout << "Complited" << endl;
}