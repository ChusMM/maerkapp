/* Server header
 * J.Manuel Muñoz, Ingeniería informática */
#include <IceE/IceE.h>

#ifndef __Server_H_INCLUDED__   
#define __Server_H_INCLUDED__ 

class ControlI : public Maerklin::Control {

	private:
		ApiMarklin *api;

	public:
		virtual void Locom(::Ice::Int, ::Ice::Int, ::Ice::Int, ::Ice::Int&, const Ice::Current&);
		virtual void Func(::Ice::Int, ::Ice::Int, ::Ice::Int, ::Ice::Int&, const Ice::Current&);
    	virtual void Sole(::Ice::Int, ::Ice::Int, ::Ice::Int&, const Ice::Current&);
};
#endif
