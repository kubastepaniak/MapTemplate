#pragma once
#include <iostream>

template<class TKey, class TValue> class Map {
private:	
	struct node {
		node *next;
		TKey key;
		TValue *value;
	};
	node* head;
	node* current;
	void swap(Map& m) {
		node *t = head;
		head = m.head;
		head = t;
	}

public:
	Map() {
		head = NULL;
		current = NULL;
	}

	Map(const Map& m) {
		node *source, **destination;
		head = NULL;
		current = NULL;
		source = m.head;
		destination = &head;
		while (source) {
			*destination = new node;
			(*destination)->key = source->key;
			(*destination)->value = source->value;
			(*destination)->next = NULL;
			if(source == m.current)
				current = *destination;
			source = source->next;
			destination = &((*destination)->next);
		}
	}

	~Map() {
		while (head) {
			node *t = head->next;
			delete head;
			head = t;
		}
	}
	
	void add(TKey k, TValue v) {
		if(!(find(k))) {
			node *t = new node;
			t->next = head;
			head = t;
			head->key = k;
			head->value = &v;
			current = head;
		} else {
			std::cout << "Entry with a key \" " << k << " \" already exists.\n";
		}
	}

	TValue* find(TKey k) {
		while (current) {
			if(current->key == k) {
				TValue* t = current->value;
				current = head;
				return t;
			}
			current = current->next;
		}
		current = head;
		return NULL;
	}

	Map& operator=(const Map& m) {
		if(&m == this)
			return *this;
		Map t(m);
		swap(t);
		return *this;
	}

	friend std::ostream& operator<< (std::ostream& out, Map& m) {
		while(m.current) {
			out << m.current->key << " \t" << *(m.current->value) << std::endl;
			m.current = m.current->next;
		}
		m.current = m.head;
		return out;
	}
};