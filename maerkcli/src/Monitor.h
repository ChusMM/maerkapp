// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice-E is licensed to you under the terms described in the
// ICEE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice-E version 1.3.0
// Generated from file `Monitor.ice'

#ifndef __Monitor_h__
#define __Monitor_h__

#include <IceE/ProxyF.h>
#include <IceE/ObjectF.h>
#include <IceE/Exception.h>
#include <IceE/ScopedArray.h>
#include <IceE/Proxy.h>
#include <IceE/Object.h>
#ifndef ICEE_PURE_CLIENT
#  include <IceE/Incoming.h>
#endif
#include <IceE/Outgoing.h>
#include <IceE/UndefSysMacros.h>

#ifndef ICEE_IGNORE_VERSION
#   if ICEE_INT_VERSION / 100 != 103
#       error IceE version mismatch!
#   endif
#   if ICEE_INT_VERSION % 100 < 0
#       error IceE patch level mismatch!
#   endif
#endif

namespace IceProxy
{

namespace Loconet
{

class Monitor;

}

}

namespace Loconet
{

class Monitor;
bool operator==(const Monitor&, const Monitor&);
bool operator<(const Monitor&, const Monitor&);

}

namespace IceInternal
{

::Ice::Object* upCast(::Loconet::Monitor*);
::IceProxy::Ice::Object* upCast(::IceProxy::Loconet::Monitor*);

}

namespace Loconet
{

typedef ::IceInternal::Handle< ::Loconet::Monitor> MonitorPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Loconet::Monitor> MonitorPrx;

void __read(::IceInternal::BasicStream*, MonitorPrx&);
void __patch__MonitorPtr(void*, ::Ice::ObjectPtr&);

}

namespace Loconet
{

}

namespace Loconet
{

class Monitor : virtual public ::Ice::Object
{
public:

    typedef MonitorPrx ProxyType;
    typedef MonitorPtr PointerType;
    

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void Register(::Ice::Int, ::Ice::Int, const ::Ice::Current& = ::Ice::Current()) = 0;
#ifndef ICEE_PURE_CLIENT
    ::Ice::DispatchStatus ___Register(::IceInternal::Incoming&, const ::Ice::Current&);
#endif // ICEE_PURE_CLIENT

#ifndef ICEE_PURE_CLIENT
    virtual ::Ice::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);
#endif // ICEE_PURE_CLIENT

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
};

}

namespace IceProxy
{

namespace Loconet
{

class Monitor : virtual public ::IceProxy::Ice::Object
{
public:

    void Register(::Ice::Int idLocom, ::Ice::Int idSen)
    {
        Register(idLocom, idSen, 0);
    }
    void Register(::Ice::Int idLocom, ::Ice::Int idSen, const ::Ice::Context& __ctx)
    {
        Register(idLocom, idSen, &__ctx);
    }
    
private:

    void Register(::Ice::Int, ::Ice::Int, const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<Monitor> ice_context(const ::Ice::Context& __context) const
    {
        return dynamic_cast<Monitor*>(::IceProxy::Ice::Object::ice_context(__context).get());
    }
    
    ::IceInternal::ProxyHandle<Monitor> ice_secure(bool __secure) const
    {
        return dynamic_cast<Monitor*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    }
    
#ifdef ICEE_HAS_ROUTER
    ::IceInternal::ProxyHandle<Monitor> ice_router(const ::Ice::RouterPrx& __router) const
    {
        return dynamic_cast<Monitor*>(::IceProxy::Ice::Object::ice_router(__router).get());
    }
#endif // ICEE_HAS_ROUTER
    
#ifdef ICEE_HAS_LOCATOR
    ::IceInternal::ProxyHandle<Monitor> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
        return dynamic_cast<Monitor*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    }
    
    ::IceInternal::ProxyHandle<Monitor> ice_adapterId(const std::string& __id) const
    {
        return dynamic_cast<Monitor*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    }
#endif // ICEE_HAS_LOCATOR
    
    ::IceInternal::ProxyHandle<Monitor> ice_twoway() const
    {
        return dynamic_cast<Monitor*>(::IceProxy::Ice::Object::ice_twoway().get());
    }
    
    ::IceInternal::ProxyHandle<Monitor> ice_oneway() const
    {
        return dynamic_cast<Monitor*>(::IceProxy::Ice::Object::ice_oneway().get());
    }
    
    ::IceInternal::ProxyHandle<Monitor> ice_batchOneway() const
    {
        return dynamic_cast<Monitor*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    }
    
    ::IceInternal::ProxyHandle<Monitor> ice_datagram() const
    {
        return dynamic_cast<Monitor*>(::IceProxy::Ice::Object::ice_datagram().get());
    }
    
    ::IceInternal::ProxyHandle<Monitor> ice_batchDatagram() const
    {
        return dynamic_cast<Monitor*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    }
    
    ::IceInternal::ProxyHandle<Monitor> ice_timeout(int __timeout) const
    {
        return dynamic_cast<Monitor*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    }
    
    static const ::std::string& ice_staticId();
    
private:
    
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

}

}

#endif
