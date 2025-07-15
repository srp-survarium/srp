Scaleform::GFx::AS3::GASRefCountBase *__thiscall Scaleform::GFx::AS3::GASRefCountBase::`vector deleting destructor'(
        Scaleform::GFx::AS3::GASRefCountBase *this,
        char a2)
{
  Scaleform::GFx::AS3::GASRefCountBase::~GASRefCountBase(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
