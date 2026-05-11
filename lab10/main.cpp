#include <iostream>
#include <exception>
using namespace std;

class IndexOutOfBoundsException : public exception
{
    virtual const char* what() const throw()
    {
        return "Indexul este iafara domeniului!";
    }
};

class NullPointerException : public exception
{
    virtual const char* what() const throw()
    {
        return "Pointer invalid";
    }
};


class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};
template<class T> class Array;
template<class T>
class ArrayIterator
{
private:
    int Current;
    T** Elements;

public:
    ArrayIterator(T** elements = nullptr, int start = 0) : Elements(elements), Current(start) {}

    ArrayIterator& operator++()
    {
        Current++;
        return *this;
    }

    ArrayIterator& operator--()
    {
        Current--;
        return *this;
    }

    bool operator==(ArrayIterator<T>& other)
    {
        return Elements == other.Elements && Current == other.Current;
    }

    bool operator!=(ArrayIterator<T>& other)
    {
        return !(*this == other);
    }

    T* GetElement()
    {
        return Elements[Current];
    }
};

template<class T>
class Array
{
private:
    T** List;
    int Capacity;
    int Size;

    void Resize()
    {
        int newCapacity = (Capacity == 0) ? 1 : Capacity * 2;
        T** newList = new T*[newCapacity];
        for (int i = 0; i < Size; i++)
        {
            newList[i] = List[i];
        }
        delete[] List;
        List = newList;
        Capacity = newCapacity;
    }

public:
    Array() : List(nullptr), Capacity(0), Size(0) {}

    ~Array()
    {
        for (int i = 0; i < Size; i++)
        {
            delete List[i];
        }
        delete[] List;
    }

    Array(int capacity) : Capacity(capacity), Size(0)
    {
        List = new T*[Capacity];
    }

    Array(const Array<T>& otherArray) : Capacity(otherArray.Capacity), Size(otherArray.Size)
    {
        List = new T*[Capacity];
        for (int i = 0; i < Size; i++)
        {
            List[i] = new T(*(otherArray.List[i]));
        }
    }

    T& operator[](int index)
    {
        if (index < 0 || index >= Size)
            throw IndexOutOfBoundsException();
        return *(List[index]);
    }

    const Array<T>& operator+=(const T& newElem)
    {
        if (Size == Capacity) Resize();
        List[Size++] = new T(newElem);
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem)
    {
        if (index < 0 || index > Size)
            throw IndexOutOfBoundsException();

        if (Size == Capacity) Resize();

        for (int i = Size; i > index; i--)
        {
            List[i] = List[i - 1];
        }
        List[index] = new T(newElem);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray)
    {
        if (index < 0 || index > Size)
            throw IndexOutOfBoundsException();

        while (Size + otherArray.Size > Capacity) Resize();

        for (int i = Size - 1; i >= index; i--)
        {
            List[i + otherArray.Size] = List[i];
        }

        for (int i = 0; i < otherArray.Size; i++)
        {
            List[index + i] = new T(*(otherArray.List[i]));
        }
        Size += otherArray.Size;
        return *this;
    }

    const Array<T>& Delete(int index)
    {
        if (index < 0 || index >= Size)
            throw IndexOutOfBoundsException();

        delete List[index];
        for (int i = index; i < Size - 1; i++)
        {
            List[i] = List[i + 1];
        }
        Size--;
        return *this;
    }

    bool operator=(const Array<T>& otherArray)
    {
        if (this == &otherArray) return true;

        for (int i = 0; i < Size; i++) delete List[i];
        delete[] List;

        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T*[Capacity];

        for (int i = 0; i < Size; i++)
        {
            List[i] = new T(*(otherArray.List[i]));
        }
        return true;
    }

    void Sort()
    {
        for (int i = 1; i < Size; i++)
        {
            T* key = List[i];
            int j = i - 1;
            while (j >= 0 && *List[j] > *key)
            {
                List[j + 1] = List[j];
                j = j - 1;
            }
            List[j + 1] = key;
        }
    }

    void Sort(int(*compare)(const T&, const T&))
    {
        for (int i = 1; i < Size; i++)
        {
            T* key = List[i];
            int j = i - 1;
            while (j >= 0 && compare(*List[j], *key) > 0)
            {
                List[j + 1] = List[j];
                j = j - 1;
            }
            List[j + 1] = key;
        }
    }

    void Sort(Compare* comparator)
    {
        if (comparator == nullptr) throw NullPointerException();
        for (int i = 1; i < Size; i++)
        {
            T* key = List[i];
            int j = i - 1;
            while (j >= 0 && comparator->CompareElements(List[j], key) > 0)
            {
                List[j + 1] = List[j];
                j = j - 1;
            }
            List[j + 1] = key;
        }
    }

    int BinarySearch(const T& elem)
    {
        int st = 0, dr = Size - 1;
        while (st <= dr)
        {
            int mid = st + (dr - st) / 2;
            if (*List[mid] == elem) return mid;
            if (*List[mid] < elem) st = mid + 1;
            else dr = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
    {
        int st = 0, dr = Size - 1;
        while (st <= dr)
        {
            int mid = st + (dr - st) / 2;
            int res = compare(*List[mid], elem);
            if (res == 0) return mid;
            if (res < 0) st = mid + 1;
            else dr = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, Compare* comparator)
    {
        if (comparator == nullptr) throw NullPointerException();
        int st = 0, dr = Size - 1;
        while (st <= dr)
        {
            int mid = st + (dr - st) / 2;
            int res = comparator->CompareElements(List[mid], (void*)&elem);
            if (res == 0) return mid;
            if (res < 0) st = mid + 1;
            else dr = mid - 1;
        }
        return -1;
    }
    int Find(const T& elem)
    {
        for (int i = 0; i < Size; i++)
        {
            if (*List[i] == elem) return i;
        }
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&))
    {
        for (int i = 0; i < Size; i++)
        {
            if (compare(*List[i], elem) == 0) return i;
        }
        return -1;
    }

    int Find(const T& elem, Compare* comparator)
    {
        if (comparator == nullptr) throw NullPointerException();
        for (int i = 0; i < Size; i++)
        {
            if (comparator->CompareElements(List[i], (void*)&elem) == 0) return i;
        }
        return -1;
    }

    int GetSize() { return Size; }
    int GetCapacity() { return Capacity; }

    ArrayIterator<T> GetBeginIterator()
    {
        return ArrayIterator<T>(List, 0);
    }

    ArrayIterator<T> GetEndIterator()
    {
        return ArrayIterator<T>(List, Size);
    }
};