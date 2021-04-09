/*
 * author:  Alexander Grill
 * file:    masterserver.h
 * project: mapreduce
 * date:    27.02.2021
*/

#ifndef MASTERSERVER_H
#define MASTERSERVER_H

#include <map>
#include <string>
#include <list>
#include <mutex>

class MasterServer{
private:
    int clientcounter{0};
    unsigned short serverport;
    std::map<std::string, int> resultmap;
    std::list<std::map<std::string, int>> *maplist;
    std::mutex &mxms;
    MasterServer(unsigned short pr, std::mutex &mx) : serverport{pr}, mxms{mx}{
        maplist = new std::list<std::map<std::string, int>>();
    }
    int FindElementinDataMap(std::string value);

public:
    ~MasterServer(){
        delete maplist;
    }
    static MasterServer* GetMasterServer(std::string port, std::mutex &mx);
    unsigned short GetServerPort();
    std::map<std::string, int>* GetMap();
    int GetListLength();
    int GetClientCounter();
    void SetClientCounter();
    void AddList(std::map<std::string, int>* mapdic);
    void InsertElementinMap(std::string value, int valuecnt);
    void WriteIntoFile(std::string jsonfile);
    void Reduce();
};

#endif