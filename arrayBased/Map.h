#pragma once
#include <iostream>

template<class TKey, class TValue> class Map {
private:
	TKey* keys;
	TValue* values;
	int size;

	void swap(Map& m) {
		TKey *tk = keys;
		TValue *tv = values;
		
		keys = m.keys;
		values = m.values;

		m.keys = tk;
		m.values = tv;
	}

public:
	Map() {
		size = 0;
		keys = NULL;
		values = NULL;
	}

	Map(const Map& m) {
		keys = NULL;
		values = NULL;

		TKey *newKeys = new TKey[m.size]();
		TValue *newValues = new TValue[m.size]();
		for (int i = 0; i < m.size; i++) {
			newKeys[i] = m.keys[i];
			newValues[i] = m.values[i];
		}
		size = m.size;

		if (keys)
			delete [] keys;
		if (values)
			delete [] values;
		keys = newKeys;
		values = newValues;	
	}

	~Map() {
		if (keys)
			delete [] keys;
		if (values)
			delete [] values;
	}
	
	void add(TKey k, TValue v) {
		if(!(find(k))) {
			TKey *newKeys = new TKey[size + 1]();
			TValue *newValues = new TValue[size + 1]();
			for (int i = 0; i < size; i++) {
				newKeys[i] = keys[i];
				newValues[i] = values[i];
			}
			size++;
			newKeys[size - 1] = k;
			newValues[size - 1] = v;

			delete [] keys;
			delete [] values;
			keys = newKeys;
			values = newValues;
		}
	}

	TValue* find(TKey k) {
		for (int i = 0; i < size; i++) {
			if(keys[i] == k) {
				return &values[i];
			}
		}
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
		for (int i = 0; i < m.size; i++) {
			out << m.keys[i] << " \t" << m.values[i] << std::endl;
		}
		return out;
	}
};