#pragma once

#include <string>
#include "GameplayOptions.h"

class GameData;

struct SaveInfo
{
    std::string version; // 0x0 Member
    std::string name; // 0x28 Member
    std::string area; // 0x50 Member
    __int64 time; // 0x78 Member
    std::string faction; // 0x80 Member
    int money; // 0xA8 Member
    int size; // 0xAC Member
    int days; // 0xB0 Member
    std::string location; // 0xB8 Member
    GameplayOptions advanced; // 0xE0 Member
    SaveInfo(const SaveInfo& __that);// public RVA = 0x487EE0
    SaveInfo* _CONSTRUCTOR(const SaveInfo& __that);// public RVA = 0x487EE0
    SaveInfo();// public RVA = 0x3824A0
    SaveInfo* _CONSTRUCTOR();// public RVA = 0x3824A0
    ~SaveInfo();// public RVA = 0x382550
    void _DESTRUCTOR();// public RVA = 0x382550
    SaveInfo& operator=(const SaveInfo& __that);// public RVA = 0x488AC0
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};