// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME logicle_rflx

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "logicle.hpp"

// Header files passed via #pragma extra_include

namespace {
  void TriggerDictionaryInitialization_logicle_rflx_Impl() {
    static const char* headers[] = {
0    };
    static const char* includePaths[] = {
"/home/max/Git/pylogicle/env/lib/python3.7/site-packages/cppyy_backend/include",
"/home/max/Git/pylogicle/src/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "logicle_rflx dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "logicle_rflx dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#ifndef LOGICLE_H
#define LOGICLE_H
extern "C" {
	struct logicle_params
	{
		double T, W, M, A;

		double a, b, c, d, f;
		double w, x0, x1, x2;

		double xTaylor;
		double *taylor;

		double *lookup;
		int bins;
	};

	struct sfun_info{
		double b,w;
	};
	double logicle_fn(double x,void*info);
}

class Logicle
{
public:
	static const double DEFAULT_DECADES;

	class Exception
	{
	public:
		Exception (const Exception & e);

		virtual ~Exception ();

		const char * message () const;

	protected:
		char * buffer;

		Exception ();
		Exception (const char * const message);

	private:
		Exception & operator= (const Exception & e);

		friend class Logicle;
	};

	class IllegalArgument : public Exception
	{
	private:
		IllegalArgument (double value);
		IllegalArgument (int value);

		friend class Logicle;
		friend class FastLogicle;
	};

	class IllegalParameter : public Exception
	{
	private:
		IllegalParameter (const char * const message);

		friend class Logicle;
	};

	class DidNotConverge : public Exception
	{
	private:
		DidNotConverge (const char * const message);

		friend class Logicle;
	};

	Logicle (double T, double W, double M = DEFAULT_DECADES, double A = 0);
	Logicle (const Logicle & logicle);

	virtual ~Logicle ();

	inline double T() const { return p->T; };
	inline double W() const { return p->W; };
	inline double M() const { return p->M; };
	inline double A() const { return p->A; };

	inline double a() const { return p->a; };
	inline double b() const { return p->b; };
	inline double c() const { return p->c; };
	inline double d() const { return p->d; };
	inline double f() const { return p->f; };

	inline double w() const { return p->w; };
	inline double x0() const { return p->x0; };
	inline double x1() const { return p->x1; };
	inline double x2() const { return p->x2; };

	virtual double scale (double value) const;
	virtual double inverse (double scale) const;
	double dynamicRange () const;
	static double  R_zeroin(double ax, double bx, double (*f)(double, void *), void *info, double *Tol, int *Maxit);
	static double R_zeroin2(double ax,double bx,double fa, double fb,double (*f)(double x, void *info),void *info,double *Tol,int *Maxit);
	static double solve (double b, double w);
protected:
	static const double LN_10;
	static const double EPSILON;
	static const double NaN;
	static const int TAYLOR_LENGTH;

	logicle_params * p;

	Logicle (double T, double W, double M, double A, int bins);


	double slope (double scale) const;
	double seriesBiexponential (double scale) const;

private:
	Logicle & operator= (const Logicle & logicle);

	void initialize (double T, double W, double M, double A, int bins);

	friend class TestLogicle;
};

class FastLogicle : public Logicle
{
public:
	static const int DEFAULT_BINS;

	FastLogicle (double T, double W, double M, double A, int bins);
	FastLogicle (double T, double W, double M, int bins);
	FastLogicle (double T, double W, int bins);

	FastLogicle (double T, double W, double M, double A);
	FastLogicle (double T, double W, double M);
	FastLogicle (double T, double W);

	FastLogicle (const FastLogicle & logicle);

	virtual ~FastLogicle ();

	virtual double scale (double value) const;
	virtual double inverse (double scale) const;

	inline int bins () const { return p->bins; };

	int intScale (double value) const;
	double inverse (int scale) const;

private:
	void initialize (int bins);

	friend class TestLogicle;
};

int PullInMyLibrary ();

#endif

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("logicle_rflx",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_logicle_rflx_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_logicle_rflx_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_logicle_rflx() {
  TriggerDictionaryInitialization_logicle_rflx_Impl();
}
