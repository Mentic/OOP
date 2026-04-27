#include <iostream>

template <typename K, typename V>
class Map {
private:
    struct Element {
        K key;
        V value;
        int index;
    };

    Element* elements;
    int count;
    int capacity;

    void resize() {
        capacity *= 2;
        Element* newElements = new Element[capacity];
        for (int i = 0; i < count; i++) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }

public:
    Map() {
        capacity = 10;
        count = 0;
        elements = new Element[capacity];
    }

    ~Map() {
        delete[] elements;
    }

    Element* begin() const { return elements; }
    Element* end() const { return elements + count; }

    V& operator[](const K& key) {
        for (int i = 0; i < count; i++) {
            if (elements[i].key == key) {
                return elements[i].value;
            }
        }
        if (count == capacity) {
            resize();
        }
        elements[count].key = key;
        elements[count].index = count;
        count++;
        return elements[count - 1].value;
    }
    void Set(const K& key, const V& value) {
        (*this)[key] = value;
    }

    bool Get(const K& key, V& value) const {
        for (int i = 0; i < count; i++) {
            if (elements[i].key == key) {
                value = elements[i].value;
                return true;
            }
        }
        return false;
    }

    int Count() const {
        return count;
    }
    void Clear() {
        count = 0;
    }
    bool Delete(const K& key) {
        for (int i = 0; i < count; i++) {
            if (elements[i].key == key) {
                for (int j = i; j < count - 1; j++) {
                    elements[j] = elements[j + 1];
                    elements[j].index = j;
                }
                count--;
                return true;
            }
        }
        return false;
    }
    bool Includes(const Map<K, V>& other) const {
        for (int i = 0; i < other.count; i++) {
            bool found = false;
            for (int j = 0; j < count; j++) {
                if (elements[j].key == other.elements[i].key) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }
};