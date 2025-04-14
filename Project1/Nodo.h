#ifndef NODO_H
#define NODO_H
template <class T>
class Nodo {
private:
	T* data;
	Nodo<T>* next;
public:
	Nodo(T* data) {
		this->data = data;
		this->next = nullptr;
	}

	Nodo(T data, Nodo<T>* next) {
		this->data = data;
		this->next = next;
	}

	~Nodo() {
		if (data != nullptr) {
			delete data;
			data = nullptr;
		}
	}

	T* getData() {
		return data;
	}

	Nodo<T>* getNext() {
		return next;
	}

	void setData(T* data) {
		this->data = data;
	}

	void setNext(Nodo<T>* next) {
		this->next = next;
	}
};
#endif //NODO_H
