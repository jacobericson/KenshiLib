#pragma once

#include <ogre/OgrePrerequisites.h>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include <kenshi/util/lektor.h>
#include <string>

class RootObject;
class ContextMenuGUI;

class ContextMenu : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    // no_addr void ContextMenu(const class ContextMenu & _a1);// public missing arg names
    ContextMenu();// public RVA = 0x793750
    ContextMenu* _CONSTRUCTOR();// public RVA = 0x793750
    ~ContextMenu();// public RVA = 0x793800
    void _DESTRUCTOR();// public RVA = 0x793800
    void showContextMenu(bool on, RootObject* what);// public RVA = 0x7A5960
    bool isVisible() const;// public RVA = 0x790B60
    void update();// public RVA = 0x8055A0
    bool rightMouseActivated; // 0x0 Member
    lektor<int> orders; // 0x8 Member
    std::string contextMenuName; // 0x20 Member
    ContextMenuGUI* menuGUI; // 0x48 Member
    ContextMenuGUI* menuGUI2; // 0x50 Member
    void _destroyMenuGUICheck();// private RVA = 0x7AB660
    bool delayedDestroyFlag; // 0x58 Member
    // no_addr class ContextMenu & operator=(const class ContextMenu & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};