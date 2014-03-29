// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice-E is licensed to you under the terms described in the
// ICEE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice-E version 1.3.0
// Generated from file `Control.ice'

#ifndef __Control_h__
#define __Control_h__

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

namespace Maerklin
{

class Control;

}

}

namespace Maerklin
{

class Control;
bool operator==(const Control&, const Control&);
bool operator<(const Control&, const Control&);

}

namespace IceInternal
{

::Ice::Object* upCast(::Maerklin::Control*);
::IceProxy::Ice::Object* upCast(::IceProxy::Maerklin::Control*);

}

namespace Maerklin
{

typedef ::IceInternal::Handle< ::Maerklin::Control> ControlPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Maerklin::Control> ControlPrx;

void __read(::IceInternal::BasicStream*, ControlPrx&);
void __patch__ControlPtr(void*, ::Ice::ObjectPtr&);

}

namespace Maerklin
{

}

namespace Maerklin
{

class Control : virtual public ::Ice::Object
{
public:

    typedef ControlPrx ProxyType;
    typedef ControlPtr PointerType;
    

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void Locom(::Ice::Int, ::Ice::Int, ::Ice::Int, ::Ice::Int&, const ::Ice::Current& = ::Ice::Current()) = 0;
#ifndef ICEE_PURE_CLIENT
    ::Ice::DispatchStatus ___Locom(::IceInternal::Incoming&, const ::Ice::Current&);
#endif // ICEE_PURE_CLIENT

    virtual void Func(::Ice::Int, ::Ice::Int, ::Ice::Int, ::Ice::Int&, const ::Ice::Current& = ::Ice::Current()) = 0;
#ifndef ICEE_PURE_CLIENT
    ::Ice::DispatchStatus ___Func(::IceInternal::Incoming&, const ::Ice::Current&);
#endif // ICEE_PURE_CLIENT

    virtual void Sole(::Ice::Int, ::Ice::Int, ::Ice::Int&, const ::Ice::Current& = ::Ice::Current()) = 0;
#ifndef ICEE_PURE_CLIENT
    ::Ice::DispatchStatus ___Sole(::IceInternal::Incoming&, const ::Ice::Current&);
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

namespace Maerklin
{

class Control : virtual public ::IceProxy::Ice::Object
{
public:

    void Locom(::Ice::Int idLocom, ::Ice::Int vel, ::Ice::Int dir, ::Ice::Int& ret)
    {
        Locom(idLocom, vel, dir, ret, 0);
    }
    void Locom(::Ice::Int idLocom, ::Ice::Int vel, ::Ice::Int dir, ::Ice::Int& ret, const ::Ice::Context& __ctx)
    {
        Locom(idLocom, vel, dir, ret, &__ctx);
    }
    
private:

    void Locom(::Ice::Int, ::Ice::Int, ::Ice::Int, ::Ice::Int&, const ::Ice::Context*);
    
public:

    void Func(::Ice::Int idLocom, ::Ice::Int fun, ::Ice::Int stat, ::Ice::Int& ret)
    {
        Func(idLocom, fun, stat, ret, 0);
    }
    void Func(::Ice::Int idLocom, ::Ice::Int fun, ::Ice::Int stat, ::Ice::Int& ret, const ::Ice::Context& __ctx)
    {
        Func(idLocom, fun, stat, ret, &__ctx);
    }
    
private:

    void Func(::Ice::Int, ::Ice::Int, ::Ice::Int, ::Ice::Int&, const ::Ice::Context*);
    
public:

    void Sole(::Ice::Int idSole, ::Ice::Int stat, ::Ice::Int& ret)
    {
        Sole(idSole, stat, ret, 0);
    }
    void Sole(::Ice::Int idSole, ::Ice::Int stat, ::Ice::Int& ret, const ::Ice::Context& __ctx)
    {
        Sole(idSole, stat, ret, &__ctx);
    }
    
private:

    void Sole(::Ice::Int, ::Ice::Int, ::Ice::Int&, const ::Ice::Context*);
    
public:
    
    ::IceInternal::ProxyHandle<Control> ice_context(const ::Ice::Context& __context) const
    {
        return dynamic_cast<Control*>(::IceProxy::Ice::Object::ice_context(__context).get());
    }
    
    ::IceInternal::ProxyHandle<Control> ice_secure(bool __secure) const
    {
        return dynamic_cast<Control*>(::IceProxy::Ice::Object::ice_secure(__secure).get());
    }
    
#ifdef ICEE_HAS_ROUTER
    ::IceInternal::ProxyHandle<Control> ice_router(const ::Ice::RouterPrx& __router) const
    {
        return dynamic_cast<Control*>(::IceProxy::Ice::Object::ice_router(__router).get());
    }
#endif // ICEE_HAS_ROUTER
    
#ifdef ICEE_HAS_LOCATOR
    ::IceInternal::ProxyHandle<Control> ice_locator(const ::Ice::LocatorPrx& __locator) const
    {
        return dynamic_cast<Control*>(::IceProxy::Ice::Object::ice_locator(__locator).get());
    }
    
    ::IceInternal::ProxyHandle<Control> ice_adapterId(const std::string& __id) const
    {
        return dynamic_cast<Control*>(::IceProxy::Ice::Object::ice_adapterId(__id).get());
    }
#endif // ICEE_HAS_LOCATOR
    
    ::IceInternal::ProxyHandle<Control> ice_twoway() const
    {
        return dynamic_cast<Control*>(::IceProxy::Ice::Object::ice_twoway().get());
    }
    
    ::IceInternal::ProxyHandle<Control> ice_oneway() const
    {
        return dynamic_cast<Control*>(::IceProxy::Ice::Object::ice_oneway().get());
    }
    
    ::IceInternal::ProxyHandle<Control> ice_batchOneway() const
    {
        return dynamic_cast<Control*>(::IceProxy::Ice::Object::ice_batchOneway().get());
    }
    
    ::IceInternal::ProxyHandle<Control> ice_datagram() const
    {
        return dynamic_cast<Control*>(::IceProxy::Ice::Object::ice_datagram().get());
    }
    
    ::IceInternal::ProxyHandle<Control> ice_batchDatagram() const
    {
        return dynamic_cast<Control*>(::IceProxy::Ice::Object::ice_batchDatagram().get());
    }
    
    ::IceInternal::ProxyHandle<Control> ice_timeout(int __timeout) const
    {
        return dynamic_cast<Control*>(::IceProxy::Ice::Object::ice_timeout(__timeout).get());
    }
    
    static const ::std::string& ice_staticId();
    
private:
    
    virtual ::IceProxy::Ice::Object* __newInstance() const;
};

}

}

#endif
