#pragma once

#include <iostream>
#include <ostream>

template <typename Key, typename Value>
class Map
{
    struct Object
    {
        Key key;
        Value value;
        Object() {};
        Object(Key key, Value value) : key(key), value(value) {};
    };

    size_t size;
    Object *collection;

private:
    int findKey(Key key)
    {
        for (size_t i = 0; i < this->size; i++)
        {
            if (this->collection[i].key == key)
            {
                return i;
            }
        }
        return -1;
    }

    void increaseCapacity()
    {
        if (this->size == 0)
        {
            this->size = 1;
            this->collection = new Object[1];
            return;
        }

        Object *newListOfObjects = new Object[this->size + 1];

        for (size_t i = 0; i < this->size; i++)
        {
            newListOfObjects[i] = this->collection[i];
        }

        this->size++;
        delete[] this->collection;
        this->collection = newListOfObjects;        
    }

    void copyData(const Map &otherMap)
    {
        this->collection = new Object[this->size];
        for (size_t i = 0; i < this->size; i++)
        {
            this->collection[i] = otherMap.collection[i];
        }
    }
public:
    Map()
    {
        this->size = 0;
    }

    Map(const Map &otherMap) : size(otherMap.size)
    {
        copyData(otherMap);
    }

    Value *find(Key key)
    {
        int index = this->findKey(key);
        if (index == -1)
        {
            return nullptr;
        }
        return &this->collection[index].value;
    }

    void add(Key key, Value value)
    {
        if (this->findKey(key) != -1)
        {
            throw KeyAlreadyExistsInMap();
        }
        this->increaseCapacity();
        this->collection[this->size - 1] = Object(key, value);
    }

    ~Map()
    {
        delete[] this->collection;
    }

    friend std::ostream &operator<<(std::ostream &os, const Map<Key, Value> &map)
    {
        for (size_t i = 0; i < map.size; i++)
        {
            os << map.collection[i].key << ": " << map.collection[i].value << std::endl;
        }
        return os;
    }

    Map &operator=(Map otherMap)
    {
        delete[] this->collection;
        this->size = otherMap.size;
        copyData(otherMap);
        return *this;
    }

    class KeyAlreadyExistsInMap {};
};