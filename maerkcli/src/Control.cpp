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

#include <Control.h>
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

static const ::std::string __Maerklin__Control__Locom_name = "Locom";

static const ::std::string __Maerklin__Control__Func_name = "Func";

static const ::std::string __Maerklin__Control__Sole_name = "Sole";

::Ice::Object* IceInternal::upCast(::Maerklin::Control* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::Maerklin::Control* p) { return p; }

void
Maerklin::__read(::IceInternal::BasicStream* __is, ::Maerklin::ControlPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Maerklin::Control;
        v->__copyFrom(proxy);
    }
}

static const ::std::string __Maerklin__Control_ids[2] =
{
    "::Ice::Object",
    "::Maerklin::Control"
};

bool
Maerklin::Control::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Maerklin__Control_ids, __Maerklin__Control_ids + 2, _s);
}

::std::vector< ::std::string>
Maerklin::Control::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Maerklin__Control_ids[0], &__Maerklin__Control_ids[2]);
}

const ::std::string&
Maerklin::Control::ice_id(const ::Ice::Current&) const
{
    return __Maerklin__Control_ids[1];
}

const ::std::string&
Maerklin::Control::ice_staticId()
{
    return __Maerklin__Control_ids[1];
}

#ifndef ICEE_PURE_CLIENT
::Ice::DispatchStatus
Maerklin::Control::___Locom(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int idLocom;
    ::Ice::Int vel;
    ::Ice::Int dir;
    __is->read(idLocom);
    __is->read(vel);
    __is->read(dir);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int ret;
    Locom(idLocom, vel, dir, ret, __current);
    __os->write(ret);
    return ::Ice::DispatchOK;
}
#endif // ICEE_PURE_CLIENT

#ifndef ICEE_PURE_CLIENT
::Ice::DispatchStatus
Maerklin::Control::___Func(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int idLocom;
    ::Ice::Int fun;
    ::Ice::Int stat;
    __is->read(idLocom);
    __is->read(fun);
    __is->read(stat);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int ret;
    Func(idLocom, fun, stat, ret, __current);
    __os->write(ret);
    return ::Ice::DispatchOK;
}
#endif // ICEE_PURE_CLIENT

#ifndef ICEE_PURE_CLIENT
::Ice::DispatchStatus
Maerklin::Control::___Sole(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::Ice::Int idSole;
    ::Ice::Int stat;
    __is->read(idSole);
    __is->read(stat);
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int ret;
    Sole(idSole, stat, ret, __current);
    __os->write(ret);
    return ::Ice::DispatchOK;
}
#endif // ICEE_PURE_CLIENT

#ifndef ICEE_PURE_CLIENT
static ::std::string __Maerklin__Control_all[] =
{
    "Func",
    "Locom",
    "Sole",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping"
};

::Ice::DispatchStatus
Maerklin::Control::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__Maerklin__Control_all, __Maerklin__Control_all + 7, current.operation);
    if(r.first == r.second)
    {
        throw Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __Maerklin__Control_all)
    {
        case 0:
        {
            return ___Func(in, current);
        }
        case 1:
        {
            return ___Locom(in, current);
        }
        case 2:
        {
            return ___Sole(in, current);
        }
        case 3:
        {
            return ___ice_id(in, current);
        }
        case 4:
        {
            return ___ice_ids(in, current);
        }
        case 5:
        {
            return ___ice_isA(in, current);
        }
        case 6:
        {
            return ___ice_ping(in, current);
        }
    }

    assert(false);
    throw Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}
#endif // ICEE_PURE_CLIENT

void
Maerklin::Control::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
    ::Ice::Object::__write(__os);
}

void
Maerklin::Control::__read(::IceInternal::BasicStream* __is, bool __rid)
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
Maerklin::operator==(const ::Maerklin::Control& l, const ::Maerklin::Control& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
Maerklin::operator<(const ::Maerklin::Control& l, const ::Maerklin::Control& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

void 
Maerklin::__patch__ControlPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::Maerklin::ControlPtr* p = static_cast< ::Maerklin::ControlPtr*>(__addr);
    assert(p);
    *p = ::Maerklin::ControlPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::Maerklin::Control::ice_staticId(), v->ice_id());
    }
}

void
IceProxy::Maerklin::Control::Locom(::Ice::Int idLocom, ::Ice::Int vel, ::Ice::Int dir, ::Ice::Int& ret, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::RequestHandlerPtr __handler;
        try
        {
            __checkTwowayOnly(__Maerklin__Control__Locom_name);
            __handler = __getRequestHandler();
            ::IceInternal::Outgoing __outS(__handler.get(), _reference.get(), __Maerklin__Control__Locom_name, ::Ice::Normal, __ctx);
            try
            {
                ::IceInternal::BasicStream* __os = __outS.os();
                __os->write(idLocom);
                __os->write(vel);
                __os->write(dir);
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
                ::IceInternal::BasicStream* __is = __outS.is();
                __is->read(ret);
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

void
IceProxy::Maerklin::Control::Func(::Ice::Int idLocom, ::Ice::Int fun, ::Ice::Int stat, ::Ice::Int& ret, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::RequestHandlerPtr __handler;
        try
        {
            __checkTwowayOnly(__Maerklin__Control__Func_name);
            __handler = __getRequestHandler();
            ::IceInternal::Outgoing __outS(__handler.get(), _reference.get(), __Maerklin__Control__Func_name, ::Ice::Normal, __ctx);
            try
            {
                ::IceInternal::BasicStream* __os = __outS.os();
                __os->write(idLocom);
                __os->write(fun);
                __os->write(stat);
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
                ::IceInternal::BasicStream* __is = __outS.is();
                __is->read(ret);
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

void
IceProxy::Maerklin::Control::Sole(::Ice::Int idSole, ::Ice::Int stat, ::Ice::Int& ret, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::RequestHandlerPtr __handler;
        try
        {
            __checkTwowayOnly(__Maerklin__Control__Sole_name);
            __handler = __getRequestHandler();
            ::IceInternal::Outgoing __outS(__handler.get(), _reference.get(), __Maerklin__Control__Sole_name, ::Ice::Normal, __ctx);
            try
            {
                ::IceInternal::BasicStream* __os = __outS.os();
                __os->write(idSole);
                __os->write(stat);
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
                ::IceInternal::BasicStream* __is = __outS.is();
                __is->read(ret);
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
IceProxy::Maerklin::Control::ice_staticId()
{
    return __Maerklin__Control_ids[1];
}

::IceProxy::Ice::Object*
IceProxy::Maerklin::Control::__newInstance() const
{
    return new Control;
}
