Scaleform::GFx::AS3::VMAppDomain *__thiscall Scaleform::GFx::AS3::VMAppDomain::`vector deleting destructor'(
        Scaleform::GFx::AS3::VMAppDomain *this,
        char a2)
{
  Scaleform::GFx::AS3::VMAppDomain::~VMAppDomain(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
