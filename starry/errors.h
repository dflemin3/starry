/**
Custom exceptions for starry.

*/

#ifndef _STARRY_ERRORS_H_
#define _STARRY_ERRORS_H_

#include <iostream>
#include <exception>
#include <string>

namespace errors {

    using namespace std;

    class TooManyDerivs : public exception {
        string m_msg;
    public:
        TooManyDerivs(const int& ngrad) :
            m_msg(string("Too many derivatives requested. Either decrease the degree of the map or re-compile starry with compiler flag STARRY_NGRAD >= " + to_string(ngrad) + ".")) { }
        virtual const char* what() const throw() {
            return m_msg.c_str();
        }
    };

    struct Kepler : public exception {
    	const char * what () const throw (){
        	return "The Kepler solver failed to converge when computing the eccentric anomaly.";
        }
    };

    struct Elliptic : public exception {
    	const char * what () const throw (){
        	return "Elliptic integral did not converge.";
        }
    };

    struct BadTaylor : public exception {
        const char * what () const throw (){
            return "Expression order exceeds the order of the tabulated Taylor expansions.";
        }
    };

    struct LargeOccultorsUnstable : public exception {
        const char * what () const throw (){
            return "Expressions for large occultors are numerically unstable for l > 8. Please enable multi-precision.";
        }
    };

    struct BadIndex : public exception {
        const char * what () const throw (){
            return "Invalid index.";
        }
    };

    struct BadLMIndex : public exception {
        const char * what () const throw (){
            return "Invalid (`l`, `m`) index.";
        }
    };

    struct BadSliceLength : public exception {
        const char * what () const throw (){
            return "Mismatch between slice length and array length.";
        }
    };

    struct LimbDark : public exception {
        const char * what () const throw (){
            return "Limb darkening is currently only available up to second order.";
        }
    };

    struct BadSystem : public exception {
        const char * what () const throw (){
            return "The first body (and only the first body) must be a `Star`.";
        }
    };

    struct SparseFail : public exception {
        const char * what () const throw (){
            return "Sparse solve failed for matrix `A`.";
        }
    };

    struct BadLM : public exception {
        const char * what () const throw (){
            return "Invalid value for `l` and/or `m`.";
        }
    };

    struct NoLimbDark : public exception {
        const char * what () const throw (){
            return "The map is not currently limb-darkened.";
        }
    };

    struct Domain : public exception {
        const char * what () const throw (){
            return "Domain error in function computeM().";
        }
    };

    struct NotImplemented : public exception {
        const char * what () const throw (){
            return "Function, method, or attribute not implemented.";
        }
    };

    struct Y00IsUnity : public exception {
        const char * what () const throw (){
            return "The Y_{0,0} coefficient is fixed at unity. You probably want to change the body's luminosity instead.";
        }
    };

}; // namespace errors

#endif
