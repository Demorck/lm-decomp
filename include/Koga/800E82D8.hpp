#ifndef KOGA_800E82D8_HPP
#define KOGA_800E82D8_HPP

#include <types.h>
#include <JSystem/JGeometry/JGVec3.hpp>

class EnThought;
class ToolDataRef;

//Some stuff in ToolDataRef split. Most of these args / returns could be wrong.
ToolDataRef fn_800E82D8(u32);
void fn_800E83A0(EnThought*);
s32 fn_800E8438(EnThought*);
ToolDataRef fn_800E84CC(s32);
s32 fn_800E85C8(s32);
void fn_800E87B0(u8*, s32);
void fn_800E8880(u32);
s32 fn_800E8904(void*, JGeometry::TVec3f*, void*);
void fn_800E8C40(JGeometry::TVec3f*, void*);
ToolDataRef fn_800E8D1C(const char *);
void fn_800E8E0C(ToolDataRef*, u8*);
s32 fn_800E8EF4(ToolDataRef*, Vec*, void*);
void fn_800E9174(JGeometry::TVec3f*, f32, f32, f32);
void fn_800E9184(JGeometry::TVec3f*, JGeometry::TVec3f*);
void* fn_800E9548();
s32 fn_800E8E78(ToolDataRef*);


#endif
