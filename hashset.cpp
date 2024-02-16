#include <iostream>
#include <type_traits>
#include <functional>
#include <stdexcept>

const int MAXSIZE = 50;

template <typename T>
class ListNode {
private:
    T getPlaceholder() {
        if constexpr (std::is_same<T, std::string>::value)
        {
            return "";
        }

        else
        {
            return 0;
        }
    }

public:
    T data;
    ListNode<T>* next;

    ListNode()
    {
        this->data = getPlaceholder();
        this->next = nullptr;
    }

    ListNode(T data, ListNode<T>* next)
    {
        this->data = data;
        this->next = next;
    }
};


template <typename T>
class LinkedList {
private:
    ListNode<T>* head;
public:
    LinkedList()
    {
        this->head = nullptr;
    }

    LinkedList(ListNode<T>* head) {
        this->head = head;
    }

    void add(T value) {
        ListNode<T>* newNode = new ListNode<T>(value, nullptr);

        if (!(this->head)) {
            this->head = newNode;
            return;
        }

        ListNode<T>* tail = this->head;

        while (tail->next) {
            tail = tail->next;
        }

        tail->next = newNode;
    }


    bool remove(T value) {
        if (!this->head) {
            return false;
        }

        ListNode<T>* tail = this->head;
        ListNode<T>* prev = nullptr;


        while (tail) {
            if (tail->data == value) {
                if (prev) {
                    prev->next = tail->next;
                }

                else
                {
                    this->head = this->head->next;
                }
                return true;
            }

            else
            {
                prev = tail;
            }

            tail = tail->next;
        }

        return false;
    }

    bool contains(T value) {
        if (!(this->head)) {
            return false;
        }

        ListNode<T>* tail = this->head;

        while (tail) {
            if (tail->data == value) {
                return true;
            }

            tail = tail->next;
        }

        return false;

    }

    friend std::ostream& operator << (std::ostream& outputStream, const LinkedList* linkedlist) {
        if (!(linkedlist->head)) {
            return outputStream;
        }

        ListNode<T>* tail = linkedlist->head;

        while (tail->next) {
            std::cout << tail->data << ", ";
            tail = tail->next;
        }

        std::cout << tail->data;

        return outputStream;
    }

    ListNode<T>* getHead()
    {
        return this->head;
    }

};


template <typename T>
class HashSet {
private:
    LinkedList<T>* objectList[MAXSIZE];
    int listSize;

    void validate() {
         if (!(std::is_same<T, int>::value ||
                std::is_same<T, float>::value ||
                std::is_same<T, double>::value ||
                std::is_same<T, char>::value ||
                std::is_same<T, std::string>::value))
            {
               throw std::invalid_argument("Unhashable type for HashSet");
            }
    }

    int getHash(T item) {
        return std::hash<T>{}(item) % MAXSIZE;
    }

public:
    HashSet()
    {
        validate();

        for (int i = 0; i < MAXSIZE; i++) {
            this->objectList[i] = nullptr;
        }

        this->listSize = 0;
    }

    HashSet(T* array) : HashSet()
    {

        int size = sizeof(array) / sizeof(array[0]);

        for (int i = 0; i < size; i++)
        {
            int key = this->getHash(array[i]);

            if (this->objectList[key] == nullptr) {
                this->objectList[key] = new LinkedList<T>();
            }

            this->add(array[i]);
        }

    }

    T getItem(T item) {
       int key = this->hashKey(item);
       return this->objectList[key];
    }

    void add(T item) {
        int key = this->getHash(item);

        if (this->objectList[key] == nullptr) {
            this->objectList[key] = new LinkedList<T>();
        }

        if (!(this->objectList[key]->contains(item))){
            this->objectList[key]->add(item);
            this->listSize += 1;
        }

    }

    void remove(T item) {
        if (this->listSize < 1) {
            std::cout << "Cannot remove from an empty set" << std::endl;
            return;
        }

        int key = this->getHash(item);

        if (this->objectList[key] == nullptr) {
            std::cout << "Element not in set" << std::endl;
            return;
        }

        if (this->objectList[key]->remove(item)) {
            this->listSize -= 1;
        }

        else {
            std::cout << "Element not in set" << std::endl;
            return;
        }
    }

    bool contains(T item) {
        if (this->listSize < 1) {
            return false;
        }

        int key = this->getHash(item);

        if (this->objectList[key] == nullptr) {
            return false;
        }

        if (!(this->objectList[key]->contains(item))) {
            return false;
        }

        return true;
    }

    int getSize() const
    {
        return listSize;
    }

    friend std::ostream& operator << (std::ostream& outputStream, const HashSet& hashset) {
        int n = hashset.listSize;

        bool displayed = false;

        if (n < 1) {
            std::cout << "set()" << std::endl;
        }

        else
        {
            outputStream << "{";

            for (int i = 0; i < MAXSIZE; i++) {
                if (hashset.objectList[i] && hashset.objectList[i]->getHead() && !(displayed)) {
                    outputStream << hashset.objectList[i];
                    displayed = true;
                }

                else if (hashset.objectList[i] && hashset.objectList[i]->getHead()){
                    outputStream << ", " << hashset.objectList[i];
                }
            }

            outputStream << "}" << std::endl;
        }

        return outputStream;
    }

};
