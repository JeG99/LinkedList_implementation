//José Elías Garza Vázquez
//A00824494 
#include "Node.h"

template <class T>
class LinkedList{
public:
	LinkedList();//Constructor
	LinkedList(const LinkedList<T> &linkedList);//Copy constructor
	~LinkedList();//Destructor

	bool isEmpty() const;
	int getSize() const;

	void addFirst(T data);
	void addLast(T data);
	bool add(T data, int pos);

	void deleteFirst();
	void deleteLast();
	void del(int pos);
	int deleteAll();

	T get(int pos);
	T set(int pos, T data);

	bool change(int pos1, int pos2);

	void print();

	void reverse();

	bool operator==(const LinkedList<T> &linkedList);
	void operator+=(T data);
	void operator+=(const LinkedList<T> &linkedList);

	void shift(int casillas);

private:
	Node<T>* head;
	int size;

	void deleteHelper();
};

template <class T>
LinkedList<T>::LinkedList() {
	head = NULL;
	size = 0;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &linkedList) {
	head = NULL;
	size = 0;
	Node<T>* curr = linkedList.head;
	if(!linkedList.isEmpty()) {	
		while(curr != NULL) {
			addLast(curr->getData());
			curr = curr->getNext();
		}
	}
}

template <class T>
LinkedList<T>::~LinkedList() {
	deleteHelper();
}

template <class T>
bool LinkedList<T>::isEmpty() const {
	return(head == NULL);
	//return(size == 0);
}

template <class T>
int LinkedList<T>::getSize() const {
	return size;
}

template <class T>
void LinkedList<T>::addFirst(T data) {
	head = new Node<T>(data, head);
	size++;
}

template <class T>
void LinkedList<T>::deleteFirst() {
	if(!isEmpty()) {
		Node<T>* curr = head;
		curr = head->getNext();
		delete curr;
		size--;
	}
}

template <class T>
void LinkedList<T>::addLast(T data) {
	if(isEmpty()) {
		addFirst(data);
	}
	else {
		Node<T>* curr = head;
		while(curr->getNext() != NULL) {
			curr = curr->getNext();
		}
		curr->setNext(new Node<T>(data));
		size++;
	}
}

template <class T>
void LinkedList<T>::deleteLast() {
	if(size<=1) {
		deleteFirst();
	}
	else {
		Node<T>* curr = head;
		while(curr->getNext()->getNext() != NULL) {
			curr = curr->getNext();
		}
		delete curr->getNext();
		curr->setNext(NULL);
		size--;
	}
}

template <class T>
bool LinkedList<T>::add(T data, int pos) {
	if(pos > size) {
		return false;
	}
	if(pos == 0) {
		addFirst(data);
	}
	else if(pos == size) {
		addLast(data);
	}
	else {
		Node<T>* curr = head;
		for(int i = 0; i < pos - 1; i++) {
			curr = curr->getNext();
		}
		curr->setNext(new Node<T>(data, curr->getNext()));
		size++;
	}
	return true;
}

template <class T>
void LinkedList<T>::del(int pos) {
	if(pos < size) {
		if(pos == 0) {
			deleteFirst();
		}
		else if(pos == size - 1) {
			deleteLast();
		}
		else {
			Node<T> *curr = head;
			for(int i = 0; i < pos - 1; i++) {
				curr = curr->getNext();
			}
			Node<T>* temp = curr->getNext();
			curr->setNext(temp->getNext());
			delete temp;
			size--;
		}	
	}
}

template <class T>
T LinkedList<T>::get(int pos) {
	Node<T>* curr = head;
	for(int i = 0; i < pos; i++) {
		curr = curr->getNext();
	} 
	return curr->getData();
}

template <class T>
T LinkedList<T>::set(int pos, T data) {
	Node<T>* curr = head;
	for(int i = 0; i < pos; i++) {
		curr = curr->getNext();
	}
	T temp = curr->getData();
	curr->setData(data);
	return temp;
}

template <class T>
bool LinkedList<T>::change(int pos1, int pos2) {
	if(pos1 == pos2) {
		return true;
	}

	int posMen = (pos1 < pos2 ? pos1 : pos2);
	int posMay = (pos1 > pos2 ? pos1 : pos2);

	Node<T>* curr = head;
	for(int i = 0; i < posMen; i++) {
		curr = curr->getNext();
	}
	Node<T>* curr2 = curr;
	for(int i = posMen; i < posMay; i++) {
		curr2 = curr2->getNext();
	}

	T temp = curr->getData();
	curr->setData(curr2->getData());
	curr->setData(temp);

	return true;
}

template <class T>
int LinkedList<T>::deleteAll() {
	int cant = size;
	deleteHelper();
	size = 0;
	return cant;
}

template<class T>
void LinkedList<T>::deleteHelper() {
	Node<T>* curr = head;
	while(!isEmpty()) {
		head = head->getNext();
		delete curr;
		curr = head;
	}
}

template <class T>
void LinkedList<T>::print() {
	Node<T>* curr = head;
	while(curr != NULL) {
		std::cout << curr->getData() << ' ';
		curr = curr->getNext(); 
	}
	std::cout << '\n';
}

template <class T>
void LinkedList<T>::reverse() {
	if(!isEmpty()) {	
		Node<T>* curr = head;
		int offset = 0;
		for(int i = 0; i < size - offset; i++) {
			offset++;
			addFirst(curr->getData());
			curr = curr->getNext();
		}
		for(int i = 0; i < size; i++) {
			deleteLast();
		}
	}
}

template<class T>
bool LinkedList<T>::operator==(const LinkedList<T> &linkedList) {
	if(getSize() != linkedList.getSize()) {
		return false;
	}
	else {
		Node<T>* curr1 = head;
		Node<T>* curr2 = linkedList.head;
		for(int i = 0; i < getSize(); i++) {
			if(curr1->getData() != curr2->getData()) {
				return false;
			}
			curr1 = curr1->getNext();
			curr2 = curr2->getNext();				
		}
		return true;	
	}
}

template <class T>
void LinkedList<T>::operator+=(T data) {
	addLast(data);
} //addLast

template <class T>
void LinkedList<T>::operator+=(const LinkedList<T> &linkedList) {
	Node<T>* curr1 = head, *curr2 = linkedList.head;
	if(!isEmpty()) {
		while(curr1->getNext() != NULL) {
			curr1 = curr1->getNext();
		}
	}
	if(!linkedList.isEmpty()) {	
		while(curr2 != NULL) {
			addLast(curr2->getData());
			curr2 = curr2->getNext();
		}
	}
} //milista1 += milista2

template <class T>
void LinkedList<T>::shift(int casillas) {
	if(size > 0) {
		Node<T>* tail = head;
		while(tail->getNext() != NULL) {
			tail = tail->getNext();
		}
		tail->setNext(head);
		for(int i = 0; i < size - casillas; i++) {
			head = head->getNext();
			tail = tail->getNext();
		}
	
		tail->setNext(NULL);
	}
} //carrusel