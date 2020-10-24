//
//  main.cpp
//  Serial_xml
//
//  Created by SZC on 2020/6/24.
//  Copyright © 2020 SZC. All rights reserved.
//

#include <cassert>
#include "Serialization.h"
#include "serialize_xml.h"


using namespace tinyxml2;
using std::string;
using std::cout;
using std::endl;

const string filename = "../c.xml";
const string filename_1 = "../a.data";

/********************* Here is the test class of XML and struct definition*************/
// For each struct, we need to implement an insertXMLNode function and an get XMLNode Function
// Then we construct a class
// The class has two functions, serialize and deserialize, users just copy and paste them
//
//
struct test: public xmls::Serializable<test>{
    int a;
    string b;
    vector<float> c;
};

void insertXMLNode(XMLDocument* doc,XMLElement* Node,test& ex,string label = "example"){
    XMLElement*userNode = doc->NewElement(label.c_str());
    Node->InsertFirstChild(userNode);
    ex.userNode = userNode;
    xmls::insertXMLNode(doc, userNode,ex.a,"INT");
    xmls::insertXMLNode(doc, userNode,ex.b,"String");
    xmls::insertXMLNode(doc, userNode,ex.c,"Vector");
}

void getXMLNode(XMLElement* userNode,test &ex){
    userNode = userNode->FirstChildElement();
    xmls::getXMLNode(userNode, ex.a);
    userNode = userNode->NextSiblingElement("String");
    xmls::getXMLNode(userNode, ex.b);
    userNode = userNode->NextSiblingElement("Vector");
    xmls::getXMLNode(userNode, ex.c);
}

class example: public test{
public:
    void serialize(const char* xmlPath,const char* name,example ex){
        tofile(xmlPath,name,ex);
        insertXMLNode(doc,Node,ex);
        doc->SaveFile(xmlPath);
    }
    void deserialize(const char* xmlPath,const char* name,example &ex){
         readfile(xmlPath, name, ex);
         getXMLNode(userNode,ex);
     }
};

/********************* Class of XML Definition Done *********************************/
//
//
//
//


/********************* Test Function of XML *******************************/
// We test all the basic types, such as int, double, float, char,bool
// We test std::string
// We test vector, map, list, pair, set ...
// All of the containers support basic type and user-defined type
// We use user-defined type for vector and list here
// all the others(pair, set,...) are tested and is true
// We test the user-defined types


template<typename T>
void testOne_XML(const T &data) {
    T ans;
    xmls::serialize(filename.c_str(),"test",data);
    xmls::deserialize(filename.c_str(),"test",ans);
    assert(data == ans);
}

void testBaseTypes_XML() {
    int a = 123456;
    double b = 123.45;
    float c = 234.56;
    char d = 'd';
    bool e = true;
    string f = "123456";
    testOne_XML(a);
    testOne_XML(b);
    testOne_XML(c);
    testOne_XML(d);
    testOne_XML(e);
    testOne_XML(f);
    
    cout<<"XML Basic Type test complete, it passed." <<endl;
}

void testVector_XML(){
    vector<int> a{1, 2, 3, 4, 5}, b;
    xmls::serialize(filename.c_str(),"test",a);
    xmls::deserialize(filename.c_str(),"test",b);
    assert(a.size() == b.size());
    for (int i = 0; i < a.size(); i++) {
        assert(a[i] == b[i]);
    }
    
    vector<example> v1,v2;
    example m1;
    m1.a = 1;
    m1.b = "string";
    m1.c = {2.1,3.1,4.2};
    v1.push_back(m1);
    xmls::serialize(filename.c_str(),"test",v1);
    xmls::deserialize(filename.c_str(),"test",v2);
    assert(v1.size() == v2.size());
    assert(v1[0].a == v2[0].a);
    assert(v1[0].b == v2[0].b);
    for(int i=0;i<v1[0].c.size();i++){
        assert(v1[0].c[i] == v2[0].c[i]);
    }
    cout<<"XML Vector test complete, it passed." <<endl;
}

void testList_XML(){
    list<int> a{1, 2, 3, 4, 5}, b;
        xmls::serialize(filename.c_str(),"test",a);
        xmls::deserialize(filename.c_str(),"test",b);
        assert(a.size() == b.size());
        auto ita = a.begin(), itb = b.begin();
        while (ita != a.end()) {
            assert(*ita == *itb);
            ++ita;
            ++itb;
        }
    
    list<example> v1,v2;
    example m1;
    m1.a = 1;
    m1.b = "string";
    m1.c = {2.1,3.1,4.2};
    v1.push_back(m1);
    xmls::serialize(filename.c_str(),"test",v1);
    xmls::deserialize(filename.c_str(),"test",v2);
    assert(v1.size() == v2.size());
    
    auto it2 = v1.begin(), it3 = v2.begin();
    while (it2 != v1.end()) {
        example e = *it2;
        example f = *it3;
        assert(e.a == f.a);
        assert(e.b == f.b);
        ++it2;
        ++it3;
    }
    cout<<"XML List test complete, it passed." <<endl;
    }


void testPair_XML() {
    pair<int, float> a = {123, 0.45}, b;
    xmls::serialize(filename.c_str(),"test",a);
    xmls::deserialize(filename.c_str(),"test",b);
    assert(a.first == b.first);
    assert(a.second == b.second);
    cout<<"XML Pair test complete, it passed." <<endl;
}


void testMap_XML() {
    map<string, int> a = {
            {"key1", 1},
            {"key2", 2},
            {"key3", 3}
    }, b;
    xmls::serialize(filename.c_str(),"test",a);
    xmls::deserialize(filename.c_str(),"test",b);
    assert(a.size() == b.size());
    auto ita = a.begin(), itb = b.begin();
    //map<string, int>::iterator ita = a.begin(), itb = b.begin();
    while (ita != a.end()) {
        assert(ita->first == itb->first);
        assert(ita->second == itb->second);
        ++ita;
        ++itb;
    }
    cout<<"XML Map test complete, it passed." <<endl;
}

void testSet_XML() {
    set<int> a{1, 2, 3, 4, 5}, b;
    xmls::serialize(filename.c_str(),"test",a);
    xmls::deserialize(filename.c_str(),"test",b);
    assert(a.size() == b.size());
    auto ita = a.begin(), itb = b.begin();
    //set<int>::iterator ita = a.begin(), itb = b.begin();

    while (ita != a.end()) {
        assert(*ita == *itb);
        ++ita;
        ++itb;
    }
    cout<<"XML Set test complete, it passed." <<endl;
}

void testClass_XML(){
    example m1,m2;
    m1.a = 1;
    m1.b = "string";
    m1.c = {1.2,2.3,3.4};
    
    m1.serialize(filename.c_str(),"example",m1);
    m2.deserialize(filename.c_str(),"example",m2);
    
    assert(m1.a == m2.a);
    assert(m1.b == m2.b);
    
    assert(m1.c.size() == m2.c.size());
    for (int i = 0; i < m1.c.size(); i++) {
        assert(m1.c[i] == m2.c[i]);
    }
    
    cout<<"XML Self-Defined Class test complete, it passed." <<endl;
    
}



/********************* Test Function of Binary *******************************/

/**
@brief Test a constant to see if it is the same before and after serialization.
@param data The tested serializable object.
*/
template<typename T>
void testOne_Binary(const T &data) {
    T ans;
    binary::serialize(data, filename_1);
    binary::deserialize(ans, filename_1);
    assert(data == ans);
}

/**
@brief Test binary serialiaztion on basic forms, including int, double, float, char, bool, string.
*/
void testBaseTypes_Binary() {
    int a = 123456;
    double b = 123.45;
    float c = 234.56;
    char d = 'd';
    bool e = true;
    string f = "123456";
    testOne_Binary(a);
    testOne_Binary(b);
    testOne_Binary(c);
    testOne_Binary(d);
    testOne_Binary(e);
    testOne_Binary(f);
    
    cout<<"Binary Basic Type test complete, it passed." <<endl;
}

/**
@brief Test binary serialiaztion on vector.
*/
void testVector_Binary() {
    vector<int> a{1, 2, 3, 4, 5}, b;
    binary::serialize(a, filename_1);
    binary::deserialize(b, filename_1);
    assert(a.size() == b.size());
    for (int i = 0; i < a.size(); i++) {
        assert(a[i] == b[i]);
    }
    cout<<"Binary Vector test complete, it passed." <<endl;
}

/**
@brief Test binary serialiaztion on list.
*/
void testList_Binary() {
    list<int> a{1, 2, 3, 4, 5}, b;
    binary::serialize(a, filename_1);
    binary::deserialize(b, filename_1);
    assert(a.size() == b.size());
    auto ita = a.begin(), itb = b.begin();
    //list<int>::iterator ita = a.begin(), itb = b.begin();
    while (ita != a.end()) {
        assert(*ita == *itb);
        ++ita;
        ++itb;
    }
    cout<<"Binary List test complete, it passed." <<endl;
}

/**
@brief Test binary serialiaztion on pair.
*/
void testPair_Binary() {
    pair<int, float> a = {123, 0.45}, b;
    binary::serialize(a, filename_1);
    binary::deserialize(b, filename_1);
    assert(a.first == b.first);
    assert(a.second == b.second);
    cout<<"Binary Pair test complete, it passed." <<endl;
}

/**
@brief Test binary serialiaztion on set.
*/
void testSet_Binary() {
    set<int> a{1, 2, 3, 4, 5}, b;
    binary::serialize(a, filename_1);
    binary::deserialize(b, filename_1);
    assert(a.size() == b.size());
    auto ita = a.begin(), itb = b.begin();
    //set<int>::iterator ita = a.begin(), itb = b.begin();

    while (ita != a.end()) {
        assert(*ita == *itb);
        ++ita;
        ++itb;
    }
    
    cout<<"Binary Set test complete, it passed." <<endl;
}

/**
@brief Test binary serialiaztion on map.
*/
void testMap_Binary() {
    map<string, int> a = {
            {"key1", 1},
            {"key2", 2},
            {"key3", 3}
    }, b;
    binary::serialize(a, filename_1);
    binary::deserialize(b, filename_1);
    assert(a.size() == b.size());
    auto ita = a.begin(), itb = b.begin();
    //map<string, int>::iterator ita = a.begin(), itb = b.begin();
    while (ita != a.end()) {
        assert(ita->first == itb->first);
        assert(ita->second == itb->second);
        ++ita;
        ++itb;
    }
    cout<<"Binary Map test complete, it passed." <<endl;
}

struct test_2{
    int a;
    string b;
    vector<float> c;
};

class structtest: public binary::Serializable<structtest>,public test_2{
public:
    void serialize(structtest &m,const string &filename){
        ofstream output(filename, ios::binary);
        binary::serialize(m.a, output);
        binary::serialize(m.b, output);
        binary::serialize(m.c, output);
    }
    void deserialize(structtest &m,const string &filename){
        ifstream input(filename, ios::binary);
        binary::deserialize(m.a, input);
        binary::deserialize(m.b, input);
        binary::deserialize(m.c, input);
    }
};

void testStruct_Binary(){
    structtest m,m1;
    m.a = 1;
    m.b = "wow";
    m.c = {1.2,2.3,3.4};
    m.serialize(m, filename_1);
    m1.deserialize(m1, filename_1);
    
    assert(m.a == m1.a);
    assert(m.b == m1.b);
    
    assert(m.c.size() == m1.c.size());
    for (int i = 0; i < m.c.size(); i++) {
        assert(m.c[i] == m1.c[i]);
    }
    cout<<"Binary Self-Defined Class test complete, it passed." <<endl;
}



int main(int argc, const char * argv[]) {

    
    testBaseTypes_XML();
    testVector_XML();
    testList_XML();
    testPair_XML();
    testMap_XML();
    testSet_XML();
    testClass_XML();
    
    testBaseTypes_Binary();
    testVector_Binary();
    testList_Binary();
    testPair_Binary();
    testSet_Binary();
    testMap_Binary();
    testStruct_Binary();
    return 0;
    
     
}
