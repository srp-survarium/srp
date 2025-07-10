Scaleform::GFx::AS3::Classes::ClassClass *__thiscall Scaleform::GFx::AS3::Classes::ClassClass::`vector deleting destructor'(
        Scaleform::GFx::AS3::Classes::ClassClass *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AS3::Classes::ClassClass_vtbl *)&Scaleform::GFx::AS3::Classes::ClassClass::`vftable';
  Scaleform::GFx::AS3::Class::~Class(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
