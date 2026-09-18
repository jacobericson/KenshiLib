#pragma once

#include <ogre/OgreMemoryAllocatorConfig.h>
#include <ogre/OgreVector3.h>
#include <ogre/OgreQuaternion.h>
#include <kenshi/Enums.h>
#include <kenshi/util/lektor.h>
#include <kenshi/Weather.h>

class GameData;
class hand;
class SimplePhysXEntity;

enum BuildingRotation
{
    ROTATION_NONE,
    ROTATION_CONSTANT,
    ROTATION_OUTPUT_BASED,
    ROTATION_WIND_SPEED,
    ROTATION_FACE_WIND_DIRECTION,
    ROTATION_TARGET,
    ROTATION_MATCH_PARENT
};

class PhysicalEntity : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x8, length = 0x1
    // VTable         : (none)
    // no_addr void PhysicalEntity(const class PhysicalEntity & _a1);// public missing arg names
    PhysicalEntity(Ogre::MovableObject* entity, char floor, GameData* _mat, GameData* part, bool instanced);// public RVA = 0x4CD570
    PhysicalEntity* _CONSTRUCTOR(Ogre::MovableObject* entity, char floor, GameData* _mat, GameData* part, bool instanced);// public RVA = 0x4CD570
    virtual ~PhysicalEntity();// public RVA = 0x4CB300 vtable offset = 0x0
    void _DESTRUCTOR();// public RVA = 0x4CB300 vtable offset = 0x0
    Ogre::MovableObject* ent; // 0x8 Member
    PhysicalEntity* parent; // 0x10 Member
    char floorNumber; // 0x18 Member
    GameData* mat; // 0x20 Member
    GameData* partData; // 0x28 Member
    bool instanced; // 0x30 Member
    bool isShell; // 0x31 Member
    bool isEmissive; // 0x32 Member
    // no_addr class PhysicalEntity & operator=(const class PhysicalEntity & _a1);// public missing arg names
    // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
};

class WeatherInstance;
class AreaBiomeGroup;
class Season;
class EffectGroup;
// TODO move
class PhysicsCollection : public Ogre::GeneralAllocatedObject
{
public:
    // Ogre::AllocatedObject<Ogre::CategorisedAllocPolicy<0> > offset = 0x0, length = 0x1
    ~PhysicsCollection();// public RVA = 0x4CBB00
    void _DESTRUCTOR();// public RVA = 0x4CBB00
    class StaticEnt : public PhysicalEntity
    {
    public:
        // PhysicalEntity offset = 0x0, length = 0x38
        // no_addr void StaticEnt(const class PhysicsCollection::StaticEnt & _a1);// public missing arg names
        StaticEnt(Ogre::MovableObject* entity, int floor, GameData* _mat, GameData* part);// public RVA = 0x546690
        StaticEnt* _CONSTRUCTOR(Ogre::MovableObject* entity, int floor, GameData* _mat, GameData* part);// public RVA = 0x546690
        virtual void update(float spd);// public RVA = 0x569D50 vtable offset = 0x8
        void _NV_update(float spd);// public RVA = 0x569D50 vtable offset = 0x8
        virtual float updateAim(float rotSpeed, const Ogre::Vector3& target);// public RVA = 0x569D60 vtable offset = 0x10
        float _NV_updateAim(float rotSpeed, const Ogre::Vector3& target);// public RVA = 0x569D60 vtable offset = 0x10
        virtual bool isRotatingEnt() const;// public RVA = 0x569D70 vtable offset = 0x18
        bool _NV_isRotatingEnt() const;// public RVA = 0x569D70 vtable offset = 0x18
        virtual ~StaticEnt();// public RVA = 0x569D80 vtable offset = 0x0
        void _DESTRUCTOR();// public RVA = 0x569D80 vtable offset = 0x0
        // no_addr class PhysicsCollection::StaticEnt & operator=(const class PhysicsCollection::StaticEnt & _a1);// public missing arg names
        // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
    };
    class RotatingEnt : public PhysicsCollection::StaticEnt, public WeatherRegion::Listener
    {
    public:
        // PhysicsCollection::StaticEnt offset = 0x0, length = 0x38
        // WeatherRegion::Listener offset = 0x38, length = 0x8
        // no_addr void RotatingEnt(const class PhysicsCollection::RotatingEnt & _a1);// public missing arg names
        RotatingEnt(Ogre::MovableObject* entity, int floor, GameData* _mat, GameData* part);// public RVA = 0x555AD0
        RotatingEnt* _CONSTRUCTOR(Ogre::MovableObject* entity, int floor, GameData* _mat, GameData* part);// public RVA = 0x555AD0
        virtual ~RotatingEnt();// public RVA = 0x547470 vtable offset = 0x0
        void _DESTRUCTOR();// public RVA = 0x547470 vtable offset = 0x0
        virtual void update(float productionSpeed) override;// public RVA = 0x547520 vtable offset = 0x0
        void _NV_update(float productionSpeed);// public RVA = 0x547520 vtable offset = 0x0
        virtual float updateAim(float speed, const Ogre::Vector3& target) override;// public RVA = 0x549310 vtable offset = 0x0
        float _NV_updateAim(float speed, const Ogre::Vector3& target);// public RVA = 0x549310 vtable offset = 0x0
        virtual bool isRotatingEnt() const override;// public RVA = 0x569DD0 vtable offset = 0x0
        bool _NV_isRotatingEnt() const;// public RVA = 0x569DD0 vtable offset = 0x0
        float getRotationPower() const;// public RVA = 0x4CB0C0
        virtual void weatherUpdated(WeatherInstance* weather, bool newWeather) override;// public RVA = 0x5494E0 vtable offset = 0x0
        void _NV_weatherUpdated(WeatherInstance* weather, bool newWeather);// public RVA = 0x5494E0 vtable offset = 0x0
        Ogre::Vector3 rotAxis; // 0x40 Member
        Ogre::Radian rotAngle; // 0x4C Member
        float rotationSpeed; // 0x50 Member
        float rotationPower; // 0x54 Member
        float speedMin; // 0x58 Member
        float speedMax; // 0x5C Member
        BuildingRotation rotationFunction; // 0x60 Member
        Ogre::Quaternion rotationBase; // 0x64 Member
        bool isRotating; // 0x74 Member
        Ogre::Quaternion rotationSrc; // 0x78 Member
        Ogre::Quaternion rotationDst; // 0x88 Member
        float rotatingTime; // 0x98 Member
        float rotationDuration; // 0x9C Member
        float windSpeedRotationMin; // 0xA0 Member
        float windSpeedRotationMax; // 0xA4 Member
        float windSpeedRotationDanger; // 0xA8 Member
        // no_addr class PhysicsCollection::RotatingEnt & operator=(const class PhysicsCollection::RotatingEnt & _a1);// public missing arg names
        // virtual void * __vecDelDtor(unsigned int _a1) = 0;// public vtable offset = 0x0 missing arg names
    };
    class LightEnt
    {
    public:
        LightEnt(GameData* data, bool indoors, Ogre::SceneNode* parentNode);// public RVA = 0x553460
        LightEnt* _CONSTRUCTOR(GameData* data, bool indoors, Ogre::SceneNode* parentNode);// public RVA = 0x553460
        ~LightEnt();// public RVA = 0x4CB2D0
        void _DESTRUCTOR();// public RVA = 0x4CB2D0
        Ogre::Light* light; // 0x0 Member
        float brightness; // 0x8 Member
        float range; // 0xC Member
        void setEnergyLevel(float level);// public RVA = 0x5464C0
        void setFloor(int floor);// public RVA = 0x5464E0
        // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
    };
    PhysicsCollection::RotatingEnt* findRotatingEnt(GameData* part) const;// public RVA = 0x4CB590
    float getWindRotationPower() const;// public RVA = 0x4CB610
    PhysicsCollection::RotatingEnt* getWindMillPart() const;// public RVA = 0x4CB690
    bool isLoaded();// public RVA = 0x4CB700
    void setVisible(bool on);// public RVA = 0x4CB770
    void handleChanged(const hand& h);// public RVA = 0x4CB870
    void update(float speed);// public RVA = 0x4CB8E0
    float updateAimingType(float speed, const Ogre::Vector3& rotTarget);// public RVA = 0x4CB950
    lektor<PhysicsCollection::StaticEnt*> staticEnts; // 0x0 Member
    lektor<SimplePhysXEntity*> parts; // 0x18 Member
    lektor<PhysicsCollection::LightEnt*> lights; // 0x30 Member
    // no_addr void PhysicsCollection(const class PhysicsCollection & _a1);// public missing arg names
    PhysicsCollection();// public RVA = 0x56EC00
    PhysicsCollection* _CONSTRUCTOR();// public RVA = 0x56EC00
    // no_addr class PhysicsCollection & operator=(const class PhysicsCollection & _a1);// public missing arg names
    // no_addr void * __vecDelDtor(unsigned int _a1);// public missing arg names
};