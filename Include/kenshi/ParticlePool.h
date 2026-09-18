#pragma once

#include <ogre/OgrePrerequisites.h>
#include <ogre/OgreMemoryAllocatorConfig.h>
#include <ogre/OgreVector3.h>
#include <ogre/OgreQuaternion.h>

class GameData;
class ParticleSystemHandler;

class ParticlePool : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    struct ParticleData
    {
        ParticleData();// public RVA = 0x409300
        ParticleData* _CONSTRUCTOR();// public RVA = 0x409300
        ParticleSystemHandler* particle; // 0x0 Member
        GameData* effectData; // 0x8 Member
        Ogre::SceneNode* node; // 0x10 Member
    };
    ParticlePool(int limit, float ttl);// public RVA = 0x409650
    ParticlePool* _CONSTRUCTOR(int limit, float ttl);// public RVA = 0x409650
    ~ParticlePool();// public RVA = 0x40B810
    void _DESTRUCTOR();// public RVA = 0x40B810
    void init();// public RVA = 0x409320
    void destroy();// public RVA = 0x40B460
    int getSize() const;// public RVA = 0x4093A0
    bool addParticle(GameData* data, const Ogre::Vector3& position, const Ogre::Quaternion& rotation, Ogre::SceneNode* parentNode);// public RVA = 0x40B540
    void update();// public RVA = 0x40B680
    void shiftParticles(const Ogre::Vector3& shift);// public RVA = 0x4093B0
    unsigned int limit; // 0x0 Member
    unsigned int lastIndex; // 0x4 Member
    ParticlePool::ParticleData* particles; // 0x8 Member
    float maxTTL; // 0x10 Member
    // no_addr void __dflt_ctor_closure();// public
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};
