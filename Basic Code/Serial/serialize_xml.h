//
//  serialize.h
//  Serial_xml
//
//  Created by SZC on 2020/6/24.
//  Copyright © 2020 SZC. All rights reserved.
//

#ifndef serialize_xml_h
#define serialize_xml_h

#include "tinyxml2.h"
#include <string>
# include <stdio.h>
# include <stdlib.h>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>


using namespace tinyxml2;
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::set;
using std::pair;
using std::map;

namespace xmls {


/********************* insertXMLNode Function *******************************/
/**
 @brief insert a node into the xmldocument
        This node include the serializable part
 @param doc The whole xml document pointer
 @param Node The node where we want to insert into
 @param a  The serializable object
 @param label The xml node name we want to give
 */

void insertXMLNode(XMLDocument* doc,XMLElement* Node,int a, string label="value");
void insertXMLNode(XMLDocument* doc,XMLElement* Node,double a, string label="value");
void insertXMLNode(XMLDocument* doc,XMLElement* Node,float a, string label="value");
void insertXMLNode(XMLDocument* doc,XMLElement* Node,bool a, string label="value");
void insertXMLNode(XMLDocument* doc,XMLElement* Node,string a,string label="value");
void insertXMLNode(XMLDocument* doc,XMLElement* Node,char a,string label="value");


template<class T>
void insertXMLNode(XMLDocument* doc,XMLElement* Node,vector<T> vec,string label="size"){
    XMLElement* userNode = doc->NewElement(label.c_str());
    Node->InsertEndChild(userNode);
    userNode->SetAttribute("val",std::to_string(vec.size()).c_str());
    int i = 0;
    for (T e : vec) {
        i++;
        string s = "element"+std::to_string(i);
        insertXMLNode(doc, userNode,e,s.c_str());
    }
}

template<class T>
void insertXMLNode(XMLDocument* doc,XMLElement* Node,list<T> vec,string label="size"){
    XMLElement* userNode = doc->NewElement(label.c_str());
    Node->InsertEndChild(userNode);
    userNode->SetAttribute("val",std::to_string(vec.size()).c_str());
    int i = 0;
    for (T e : vec) {
        i++;
        string s = "element"+std::to_string(i);
        insertXMLNode(doc, userNode,e,s.c_str());
    }
}

template<class T1,class T2>
void insertXMLNode(XMLDocument* doc,XMLElement* Node,std::pair<T1, T2> p){
    insertXMLNode(doc, Node,p.first,"first");
    insertXMLNode(doc, Node,p.second,"second");
}

template<class T>
void insertXMLNode(XMLDocument* doc,XMLElement* Node,set<T> s,string label="size"){
    XMLElement* userNode = doc->NewElement(label.c_str());
    Node->InsertEndChild(userNode);
    userNode->SetAttribute("val",std::to_string(s.size()).c_str());
    int i = 0;
    for (T e : s) {
        i++;
        string s = "element"+std::to_string(i);
        insertXMLNode(doc, userNode,e,s.c_str());
    }
}

template<class K, class V>
void insertXMLNode(XMLDocument* doc,XMLElement* Node,const map<K, V> mp,string label="size") {
    XMLElement* userNode = doc->NewElement(label.c_str());
    Node->InsertEndChild(userNode);
    userNode->SetAttribute("val",std::to_string(mp.size()).c_str());
    int i = 0;
    for (const pair<K, V> e : mp) {
        i++;
        string s = "element"+std::to_string(i);
        XMLElement* userNode2 = doc->NewElement(s.c_str());
        userNode->InsertEndChild(userNode2);
        insertXMLNode(doc, userNode2,e);
    }
}

/********************* getXMLNode Function *******************************/
/**
 @brief pull an object from a node 
 @param Node The node where we want to pull the object out
 @param a  The object we want to give value to
 */
void getXMLNode(XMLElement* Node, int &a);

void getXMLNode(XMLElement* Node, double &a);

void getXMLNode(XMLElement* Node, bool &a);

void getXMLNode(XMLElement* Node, float &a);

void getXMLNode(XMLElement* Node,char &a);

void getXMLNode(XMLElement* Node, string &a);


template<class T1,class T2>
void getXMLNode(XMLElement* Node,std::pair<T1, T2>& p){
    getXMLNode(Node, p.first);
    Node = Node->NextSiblingElement("second");
    getXMLNode(Node, p.second);
}

template<class T>
void getXMLNode(XMLElement* Node, vector<T>& a){
    int size;
    getXMLNode(Node,size);
    a.resize(size);
    XMLElement* userNode = Node->FirstChildElement();
    int i = 0;
    while(userNode){
        getXMLNode(userNode,a[i]);
        i++;
        userNode = userNode->NextSiblingElement();
    }
}

template<class T>
void getXMLNode(XMLElement* Node, list<T>& a){
    XMLElement* userNode = Node->FirstChildElement();
    while(userNode){
        T x;
        getXMLNode(userNode,x);
        a.push_back(x);
        userNode = userNode->NextSiblingElement();
    }
}

template<class T>
void getXMLNode(XMLElement* Node, set<T>& s){
    XMLElement* userNode = Node->FirstChildElement();
    while(userNode){
        T x;
        getXMLNode(userNode,x);
        s.insert(x);
        userNode = userNode->NextSiblingElement();
    }
}

template<class T,class V>
void getXMLNode(XMLElement* Node, map<T,V>& mp){
    XMLElement* userNode = Node->FirstChildElement();
    while(userNode){
        pair<T, V> x;
        XMLElement* userNode2 = userNode->FirstChildElement();
        getXMLNode(userNode2,x);
        mp.insert(x);
        userNode = userNode->NextSiblingElement();
    }
}


template<typename T>
void serialize(const char* xmlPath,const char* name,T a){
    const char* declaration ="<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>";
    XMLDocument* doc = new tinyxml2::XMLDocument();
    doc->Parse(declaration);
    XMLElement* root=doc->NewElement("serialization");
    doc->InsertEndChild(root);
    XMLElement* Node = doc->NewElement(name);
    root->InsertEndChild(Node);
    
    insertXMLNode(doc,Node,a);
    
    doc->SaveFile(xmlPath);
    doc->Clear();

}

template<class T>
void deserialize(const char* xmlPath,const char* name,T& a){
    XMLDocument* doc = new XMLDocument();
    doc->LoadFile(xmlPath);
    XMLElement* root = doc->RootElement();
    XMLElement* Node = root->FirstChildElement();
    XMLElement* userNode = Node->FirstChildElement();
    
    getXMLNode(userNode,a);

}

template<typename SerializableType>
class Serializable
{
public:
    XMLDocument* doc;
    XMLElement* root;
    XMLElement* Node;
    XMLElement* userNode;
    
    void tofile(const char* xmlPath,const char* name,Serializable& ex){
        const char* declaration ="<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>";
        doc = new tinyxml2::XMLDocument();
        doc->Parse(declaration);
        root=doc->NewElement("serialization");
        doc->InsertEndChild(root);
        Node = doc->NewElement(name);
        root->InsertEndChild(Node);
        userNode = doc->NewElement("example");
        Node->InsertEndChild(userNode);
        ex.doc = doc;
        ex.Node = Node;
        ex.userNode = userNode;
    }


    void readfile(const char* xmlPath,const char* name,Serializable& ex){
        doc = new tinyxml2::XMLDocument();
        doc->LoadFile(xmlPath);
        root = doc->RootElement();
        Node = root->FirstChildElement();
        userNode = Node->FirstChildElement();
        ex.doc = doc;
        ex.Node = Node;
        ex.userNode = userNode;
    }

};

}


#endif /* serialize_h */
