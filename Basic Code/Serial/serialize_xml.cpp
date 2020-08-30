//
//  serialize_xml.cpp
//  Serial_xml
//
//  Created by SZC&JXBR on 2020/7/2.
//  Copyright © 2020 SZC&JXBR. All rights reserved.
//

#include "serialize_xml.h"


void xmls::insertXMLNode(XMLDocument* doc,XMLElement* Node,int a, string label)
{
    XMLElement* userNode = doc->NewElement(label.c_str());
    userNode->SetAttribute("val",std::to_string(a).c_str());
    Node->InsertEndChild(userNode);
}

void xmls::insertXMLNode(XMLDocument* doc,XMLElement* Node,bool a, string label)
{
    XMLElement* userNode = doc->NewElement(label.c_str());
    userNode->SetAttribute("val",std::to_string(a).c_str());
    Node->InsertEndChild(userNode);
}

void xmls::insertXMLNode(XMLDocument* doc,XMLElement* Node,float a, string label)
{
    XMLElement* userNode = doc->NewElement(label.c_str());
    userNode->SetAttribute("val",std::to_string(a).c_str());
    Node->InsertEndChild(userNode);
}

void xmls::insertXMLNode(XMLDocument* doc,XMLElement* Node,double a, string label)
{
    XMLElement* userNode = doc->NewElement(label.c_str());
    userNode->SetAttribute("val",std::to_string(a).c_str());
    Node->InsertEndChild(userNode);
}


void xmls::insertXMLNode(XMLDocument* doc,XMLElement* Node,string a,string label)
{
    XMLElement* userNode = doc->NewElement(label.c_str());
    userNode->SetAttribute("val",a.c_str());
    Node->InsertEndChild(userNode);
}


void xmls::insertXMLNode(XMLDocument* doc,XMLElement* Node,char a,string label)
{
    XMLElement* userNode = doc->NewElement(label.c_str());
    userNode->SetAttribute("val",(char *)&a);
    Node->InsertEndChild(userNode);
}

void xmls::getXMLNode(XMLElement* Node, int &a){
    std::string b = Node->Attribute("val");
    a = stoi(b);
}

void xmls::getXMLNode(XMLElement* Node, double &a){
    std::string b = Node->Attribute("val");
    a = stod(b);
}

void xmls::getXMLNode(XMLElement* Node, bool &a){
    std::string b = Node->Attribute("val");
    a = stoi(b);
}

void xmls::getXMLNode(XMLElement* Node, float &a){
    std::string b = Node->Attribute("val");
    a = stof(b);
}

void xmls::getXMLNode(XMLElement* Node,char &a){
    std::string b = Node->Attribute("val");
    a =  *b.data();
}

void xmls::getXMLNode(XMLElement* Node, string &a){
    a = Node->Attribute("val");
}


