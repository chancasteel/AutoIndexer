template <typename T>
class myVector
{
    /// @brief capacity is the size of the array
    /// size is the amount of elements in the array
    /// data is the array
    int capacity;
    int size;
    T* data;

public:
    /// @brief Constructs vector setting data to a templated array
    /// @param cap defaults to 10, but can be set to any
    myVector(const int cap = 10) : capacity(cap), data(new T [capacity]), size(0){};
    ~myVector() {delete[] data;}
    /// @brief Copy constructor
    /// @param arg vector to copy
    myVector(const myVector& arg) : capacity(arg.capacity), size(arg.size), data(new T[arg.capacity]) {
        for (int i = 0; i < size; i++)
            data[i] = arg.data[i];
    }
    /// @brief Copy assignment operator
    /// @param arg vector to copy
    /// @return copied vector
    myVector& operator= (const myVector& arg) {
        if (&arg != this) {
            delete[] data;
            size = arg.size;
            capacity = arg.capacity;
            data = new T[capacity];
            for (int i = 0; i < size; i++)
                data[i] = arg.data[i];
            return *this;
        }
        return *this;
    }
    /// @brief gettters and setters for size and capacity
    /// @return size or capacity for getters
    int getSize() {return size;}
    int getCapacity() {return capacity;}
    void setSize(int arg) {size = arg};
    void setCapacity(int arg) {capacity = arg};
    /// @brief Adds item to the end of vector
    /// @param arg item to be added
    void push_back(const T arg) {
        if (size == capacity) {
            T* temp = data;
            data = new T[capacity * 2];
            for (int i = 0; i < size; i++)
                data[i] = temp[i];
            delete[] temp;
        }
        data[size] = arg;
        size += 1;
    }
    /// @brief Removes item from vector
    /// @param arg index to remove item at
    void remove(int arg) {
        if (size != 0)
        size--;
    }

    /// @brief Inserts the item at the index given
    /// @param argc item to be inserted
    /// @param argv index to be inserted at
    void insert(const T argc, int argv) {
        if (argv < size) {
            if (size == capacity) {
                T* temp = data;
                data = new T[capacity * 2]
                for (int i = 0; i < size; i++) {
                    data[i] = temp[i];
                }
                data[argv] = argc;
                size++;
            }
        }
    }
    /// @brief Finds the index of a given item
    /// @param arg item to search for
    /// @return index where found or -1 if not found
    int search(T arg) {
        for (int i = 0; i < size; i++)
            if (arg == data[i])
                return i;
        return -1;
    }
    /// @brief Grabs item at index
    /// @param arg index to retrieve from
    /// @return item at index
    T& operator[](int arg) {
        if (arg <= size) {
            return data[arg];
        }
        return;
    }
    /// @brief iterator class to iterate over array
    struct iterator {
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        private:
            T* ptr;
        public:
            iterator() : ptr(nullptr){}
            explicit iterator(T* point) : ptr(point){}
            reference operator*() const {return *ptr;}
            pointer operator->(){return ptr;}
            iterator& operator++() {
                ptr++;
                return *this;
            }
            iterator operator++(int) {
                iterator temp = *this;
                ++(*this);
                return temp;
            }
            friend bool operator== (const iterator& a, const iterator& b) {return a.ptr == b.ptr;}
            friend bool operator!= (const iterator& a, const iterator& b) {return a.ptr != b.ptr;}
    };
    iterator begin() const {return iterator(&data[0]);}
    iterator end() const {return iterator(&data[size]);}
};