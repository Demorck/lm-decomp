#ifndef PARAM_INST_HPP
#define PARAM_INST_HPP

#include <JSystem/JGeometry/JGVec3.hpp>
#include "Koga/BaseParam.hpp"

template <typename T> class TParamT : public TBaseParam {
public:
	TParamT(TParams* params, T defaultValue, const char* paramName, u16 code)
	    : TBaseParam(params, paramName, code)
	    , value(defaultValue)
	{
	}

	virtual void load(JSUMemoryInputStream& stream);

	// fabricated
	const T& get() const { return value; }

	T value;
};

/*
class TParamVec : public TParamT<JGeometry::TVec3<f32> > {
public:
	// fabricated AND wrong
	TParamVec(TParams* parent, JGeometry::TVec3<f32> defaultValue, u16 keycode,
	          const char* name)
	    : TParamT<JGeometry::TVec3<f32> >(parent, defaultValue, keycode, name)
	{
	}
};
*/

#define PARAM_INIT(member, defaultValue)                                       \
	member(&mParams, defaultValue, #member, member.calcKeyCode(#member))

#endif
