Scaleform::GFx::AS3::XMLSupport *__thiscall Scaleform::GFx::AS3::XMLSupport::`vector deleting destructor'(
        Scaleform::GFx::AS3::XMLSupport *this,
        char a2)
{
  this->__vftable = (Scaleform::GFx::AS3::XMLSupport_vtbl *)&Scaleform::GFx::AS3::XMLSupport::`vftable';
  Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
