#include <iostream>
#include <vector>
#include <list>

template <class K, class V>
class HashTable
{

private:
    struct HashNode
    {
        K key;
        V value;
    };

    std::vector<std::list<HashNode>> table;

    int capacity;

    int size;

    int hashFunction( K key) const
    {
        return std::hash<K>{}(key) % capacity;
    }

public:
    HashTable(int cap) : capacity(cap), size(0)
    {
        table.resize(capacity);
    }

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

    void display() const
    {
        for (int i = 0; i < capacity; i++)
        {
            std::cout << "Bucket " << i << ":";
            for (auto &node : table[i])
            {
                std::cout << " {" << node.key << ", " << node.value << "}";
            }
            std::cout << std::endl;
        }
    }

    int getSize() const
    {
        return size;
    }
};

int main()
{

    HashTable<std::string, std::string> table(10);

    table.insert("hfthf", "hdfhdh");
    table.insert("rhe", "ttj");
    table.insert("etjkrk", "dtjrxrn");
    table.insert("wrhzet", "tk7ltmx");
    table.insert("jxryjz", "fyk7jxj");

    std::cout << "size : " << table.getSize() << std::endl;

    table.display();

    std::string value;
    if (table.search("wrhzet", value))
    {
        std::cout << "value found : " << value << std::endl;
    }
    else
    {
        std::cout << "value not found" << std::endl;
    }

    if (table.remove("jxryjz"))
    {
        std::cout << "value removed" << std::endl;
    }
    else
    {
        std::cout << "value not found" << std::endl;
    }
    
    std::cout << "size : " << table.getSize() << std::endl;

    table.display();

    return 0;
}