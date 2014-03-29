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

#include <Monitor.h>
#include <IceE/LocalException.h>
#include <IceE/ObjectFactory.h>
#include <IceE/BasicStream.h>
#include <IceE/Iterator.h>

#ifndef ICEE_IGNORE_VERSION
#   if ICEE_INT_VERSION / 100 != 103
#       error IceE version mismatch!
#   endif
#   if ICEE_INT_VERSION % 100 < 0
#       error IceE patch level mismatch!
#   endif
#endif

static const ::std::string __Loconet__Monitor__Register_name = "Register";

::Ice::Object* IceInternal::upCast(::Loconet::Monitor* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::Loconet::Monitor* p) { return p; }

void
Loconet::__read(::IceInternal::BasicStream* __is, ::Loconet::MonitorPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Loconet::Monitor;
        v->__copyFrom(proxy);
    }
}

static const ::std::string __Loconet__Monitor_ids[2] =
{
    "::Ice::Object",
    "::Loconet::Monitor"
};

bool
Loconet::Monitor::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Loconet__Monitor_ids, __Loconet__Monitor_ids + 2, _s);
}

::std::vector< ::std::string>
Loconet::Monitor::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Loconet__Monitor_ids[0], &__Loconet__Monitor_ids[2]);
}

const ::std::string&
Loconet::Monitor::ice_id(const ::Ice::Current&) const
{
    return __Loconet__Monitor_ids[1];
}

const ::std::string&
Loconet::Monitor::ice_staticId()
{
    return __Loconet__Monitor_ids[1];
}

#ifndef ICEE_PURE_CLIENT
::Ice::DispatchStatus
Loconet::Monitor::___Register(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int idLocom;
    ::Ice::Int idSen;
    __is->read(idLocom);
    __is->read(idSen);
    Register(idLocom, idSen, __current);
    return ::Ice::DispatchOK;
}
#endif // ICEE_PURE_CLIENT

#ifndef ICEE_PURE_CLIENT
static ::std::string __Loconet__Monitor_all[] =
{
    "Register",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping"
};

::Ice::DispatchStatus
Loconet::Monitor::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__Loconet__Monitor_all, __Loconet__Monitor_all + 5, current.operation);
    if(r.first == r.second)
    {
        throw Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __Loconet__Monitor_all)
    {
        case 0:
        {
            return ___Register(in, current);
        }
        case 1:
        {
            return ___ice_id(in, current);
        }
        case 2:
        {
            return ___ice_ids(in, current);
        }
        case 3:
        {
            return ___ice_isA(in, current);
        }
        case 4:
        {
            return ___ice_ping(in, current);
        }
    }

    assert(false);
    throw Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}
#endif // ICEE_PURE_CLIENT

void
Loconet::Monitor::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
    ::Ice::Object::__write(__os);
}

void
Loconet::Monitor::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
    ::Ice::Object::__read(__is, true);
}


bool
Loconet::operator==(const ::Loconet::Monitor& l, const ::Loconet::Monitor& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
Loconet::operator<(const ::Loconet::Monitor& l, const ::Loconet::Monitor& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

void 
Loconet::__patch__MonitorPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::Loconet::MonitorPtr* p = static_cast< ::Loconet::MonitorPtr*>(__addr);
    assert(p);
    *p = ::Loconet::MonitorPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::Loconet::Monitor::ice_staticId(), v->ice_id());
    }
}

void
IceProxy::Loconet::Monitor::Register(::Ice::Int idLocom, ::Ice::Int idSen, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::RequestHandlerPtr __handler;
        try
        {
            __handler = __getRequestHandler();
            ::IceInternal::Outgoing __outS(__handler.get(), _reference.get(), __Loconet__Monitor__Register_name, ::Ice::Normal, __ctx);
            try
            {
                ::IceInternal::BasicStream* __os = __outS.os();
                __os->write(idLocom);
                __os->write(idSen);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                __outS.abort(__ex);
            }
            bool __ok = __outS.invoke();
            try
            {
                if(!__ok)
                {
                    __outS.is()->throwUnknownUserException();
                }
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
#if defined(_MSC_VER) && defined(_M_ARM) // ARM bug.
            catch(...)
            {
                throw;
            }
#endif
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__handler, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__handler, __ex, __cnt);
        }
#if defined(_MSC_VER) && defined(_M_ARM) // ARM bug.
        catch(...)
        {
            throw;
        }
#endif
    }
}

const ::std::string&
IceProxy::Loconet::Monitor::ice_staticId()
{
    return __Loconet__Monitor_ids[1];
}

::IceProxy::Ice::Object*
IceProxy::Loconet::Monitor::__newInstance() const
{
    return new Monitor;
}
