Scaleform::GFx::AS3::Classes::UserDefined *__thiscall Scaleform::GFx::AS3::Classes::UserDefined::`vector deleting destructor'(
        Scaleform::GFx::AS3::Classes::UserDefined *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AS3::Classes::UserDefined_vtbl *)&Scaleform::GFx::AS3::Classes::UserDefined::`vftable';
  Scaleform::GFx::AS3::Classes::UDBase::~UDBase(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
