/*
 * author:  Alexander Grill
 * file:    slaveserver.h
 * project: mapreduce
 * date:    27.02.2021
*/

#ifndef SLAVESERVER_H
#define SLAVESERVER_H

#include <map>
#include <iostream>
#include <list>

class Slaveserver{
private:
    unsigned short port;
    std::map<std::string, int> resultmapdic;
    std::list<std::map<std::string, int>> mapdiclist;
    Slaveserver(){}
    Slaveserver(unsigned short pr):port{pr}{}
public:
    static Slaveserver* GetSlaveServer(std::string pr);
    int GetLengthList();
    void AddList(std::map<std::string, int>& mapdic);
    void Shuffle();
};

#endif