#include <iostream>
#include <vector>
#include <list>

// template to accept various types
template <class K, class V>
class HashTable
{
private:
    // struct to hold key-value pair
    struct HashNode
    {
        K key;
        V value;
    };

    // actual hash table data structure
    std::vector<std::list<HashNode>> table;
    // capacity of hash table
    int capacity;
    // current size of nodes
    int size;

    // hash function
    int hashFunction(K key) const
    {
        return std::hash<K>{}(key) % capacity;
    }

public:
    // constructor
    HashTable(int cap) : capacity(cap), size(0)
    {
        table.resize(capacity);
    }

    // to insert new key value pair or new value to exist key
    void insert(const K &key, const V &value)
    {
        int index = hashFunction(key);
        for (auto &node : table[index])
        {
            if (node.key == key)
            {
                node.value = value;
                return;
            }
        }
        table[index].push_back({key, value});
        size++;
    }

    // search value based on key
    bool search(const K &key, V &value) const
    {
        int index = hashFunction(key);
        for (auto &node : table[index])
        {
            if (node.key == key)
            {
                value = node.value;
                return true;
            }
        }
        return false;
    }

    // remove node from hash table
    bool remove(const K &key)
    {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); it++)
        {
            if (it->key == key)
            {
                table[index].erase(it);
                size--;
                return true;
            }
        }
        return false;
    }

    // print all nodes
    void display() const
    {
        for (int i = 0; i < capacity; i++)
        {
            std::cout << " Bucket " << i << " : ";
            for (auto &node : table[i])
            {
                std::cout << "{" << node.key << " , " << node.value << "}";
            }
            std::cout << std::endl;
        }
    }

    // get current size of nodes
    int getSize() const
    {
        return size;
    }
};

int main()
{
    // initialize hash table
    HashTable<std::string, std::string> hashtable(7);
    // insert value
    hashtable.insert("hgfgh", "tftft");
    hashtable.insert("ftj", "tftryksft");
    hashtable.insert("ths", "45jsjtjstj");
    hashtable.insert("j,m", ";lyfuksj");
    hashtable.insert("eh", "lr78lek");
    hashtable.insert("a346", "l9lyukufu");

    std::cout << " Before Remove : " << hashtable.getSize() << std::endl;
    hashtable.display();

    // search node
    std::string value;
    if (hashtable.search("a346", value))
    {
        std::cout << "found :" << value << std::endl;
    }
    else
    {
        std::cout << "not found" << std::endl;
    }

    // remove node
    if (hashtable.remove("ths"))
    {
        std::cout << "value removed" << std::endl;
    }
    else
    {
        std::cout << "value not found" << std::endl;
    }

    std::cout << " After remove :" << hashtable.getSize() << std::endl;
    hashtable.display();

    return 0;
}