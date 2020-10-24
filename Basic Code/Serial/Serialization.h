//
//  Serialization.h
//  serial
//
//  Created by SZC on 2020/6/21.
//  Copyright © 2020 SZC. All rights reserved.
//
// This is the binary version of serialization

#ifndef Serialization_h
#define Serialization_h

#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <set>
#include <map>


using std::ifstream;
using std::ofstream;
using std::ios;
using std::string;
using std::vector;
using std::list;
using std::pair;
using std::set;
using std::map;

namespace binary {

/// vector serialization declaration
template<class T>
void serialize(vector<T> vec, ofstream &output);

template<class T>
void deserialize(vector<T> &vec, ifstream &input);

/// list serialization declaration
template<class T>
void serialize(list<T> lst, ofstream &output);

template<class T>
void deserialize(list<T> &lst, ifstream &input);

/// pair  serialization declaration
template<class T1, class T2>
void serialize(pair<T1, T2> p, ofstream &output);

template<class T1, class T2>
void deserialize(pair<T1, T2> &p, ifstream &input);

///set  serialization declaration
template<class T>
void serialize(set<T> st, ofstream &output);

template<class T>
void deserialize(set<T> &st, ifstream &input);

/// map  serialization declaration
template<class K, class V>
void serialize(map<K, V> mp, ofstream &output);

template<class K, class V>
void deserialize(map<K, V> &mp, ifstream &input);

/// string serialization
void serialize(const string &a, ofstream &output);
void deserialize(std::string &a, ifstream &input);

/// base type serialization
#define A_SERIALIZE(Type) \
    void serialize(const Type& c,ofstream& output) \
    { \
        output.write ((const char *)&c,sizeof(c));\
    }

#define A_DESERIALIZE(Type) \
    void deserialize(Type& c,ifstream& input)\
    { \
        input.read((char *)& c , sizeof(c));\
    }

A_SERIALIZE(int);

A_DESERIALIZE(int);

A_SERIALIZE(double);

A_DESERIALIZE(double);

A_SERIALIZE(float);

A_DESERIALIZE(float);

A_SERIALIZE(char);

A_DESERIALIZE(char);

A_SERIALIZE(bool);

A_DESERIALIZE(bool);


/// string serialization
/**
@brief Serialize a string term, to transform a string term into binary form.
@param a The serializable object.
*/
inline void serialize(const string &a, ofstream &output) {
    int len = a.size();
    serialize(len, output);

    output.write(a.c_str(), len);//因为记录了长度,所以不必写入末尾的\0
}

/**
@brief Deserialize a string term, to transform a binary form back to a string term.
@param a The deserializable object.
*/
inline void deserialize(std::string &a, ifstream &input) {
    int len;
    deserialize(len, input);

    char *str = new char[len + 1];
    input.read(str, len);
    str[len] = '\0';
    a = str;
    delete[] str;
}


/// vector serialization
/**
@brief Serialize a vector, to transform it into binary form.
@param vec The serializable object.
*/
template<class T>
void serialize(const vector<T> vec, ofstream &output) {
    //前面写了整个vector的长度，也写了vector中包含的数据
    int size = vec.size();
    serialize(size, output);
    for (const T &e : vec) {
        serialize(e, output);
    }
}

/**
@brief Deserialize a vector, to transform its binary form back to original form.
@param vec The deserializable object.
*/
template<class T>
void deserialize(vector<T> &vec, ifstream &input) {
    int len;
    deserialize(len, input);
    vec.resize(len);
    for (T &e : vec) {
        deserialize(e, input);
    }
}

/// list serialization
/**
@brief Serialize a list, to transform it into binary form.
@param lst The serializable object.
*/
template<class T>
void serialize(const list<T> lst, ofstream &output) {
    int size = lst.size();
    serialize(size, output);
    for (const T &e : lst) {
        serialize(e, output);
    }
}

/**
@brief Deserialize a list, to transform its binary form back to original form.
@param lst The deserializable object.
*/
template<class T>
void deserialize(list<T> &lst, ifstream &input) {
    int len;
    deserialize(len, input);
    lst.resize(len);
    for (T &e : lst) {
        deserialize(e, input);
    }
}

/// pair  serialization
/**
@brief Serialize a pair, to transform it into binary form.
@param p The serializable object.
@param T1 The type of first element in this pair.
@param T2 The type of second element in this pair.
*/
template<class T1, class T2>
void serialize(const pair<T1, T2> p, ofstream &output) {
    serialize(p.first, output);
    serialize(p.second, output);
}

/**
@brief Deserialize a pair, to transform its binary form back to original form.
@param p The deserializable object.
*/
template<class T1, class T2>
void deserialize(pair<T1, T2> &p, ifstream &input) {
    deserialize(p.first, input);
    deserialize(p.second, input);
}

///set  serialization
/**
@brief Serialize a set, to transform it into binary form.
@param st The serializable object.
@param T The type of elements in this set.
*/
template<class T>
void serialize(const set<T> st, ofstream &output) {
    int size = st.size();
    serialize(size, output);
    for (const T &e : st) {
        serialize(e, output);
    }
}

/**
@brief Deserialize a set, to transform its binary form back to original form.
@param st The deserializable object.
*/
template<class T>
void deserialize(set<T> &st, ifstream &input) {
    int len;
    deserialize(len, input);
    for (int i = 0; i < len; i++) {
        T e;
        deserialize(e, input);
        st.insert(e);
    }
}

/// map  serialization
/**
@brief Serialize a map, to transform it into binary form.
@param mp The serializable object.
@param K The type of first element in this map.
@param V The type of second element in this map.
*/
template<class K, class V>
void serialize(const map<K, V> mp, ofstream &output) {
    int size = mp.size();
    serialize(size, output);
    for (const pair<K, V> e : mp) {
        serialize(e, output);
    }
}

/**
@brief Deserialize a map, to transform its binary form back to original form.
@param mp The deserializable object.
*/
template<class K, class V>
void deserialize(map<K, V> &mp, ifstream &input) {
    int len;
    deserialize(len, input);
    for (int i = 0; i < len; i++) {
        pair<K, V> e;
        deserialize(e, input);
        mp.insert(e);
    }
}


// Common
/**
@brief Serialize a common type, to transform it into binary form.
@param a The serializable object.
*/
template<typename T>
void serialize(const T &a, const string &filename) {
    ofstream output(filename, std::ios::binary);
    serialize(a, output);
}

/**
@brief Deserialize a common type, to transform its binary form back to original form.
@param a The deserializable object.
*/
template<typename T>
void deserialize(T &a, const string &filename) {
    ifstream input(filename, ios::binary);
    deserialize(a, input);
}

template<typename SerializableType>
class Serializable
{
public:
    void deserialize(SerializableType& a, std::string _address);
    void serialize(SerializableType& a, std::string _address);
};


}

#endif /* Serialization_h */

