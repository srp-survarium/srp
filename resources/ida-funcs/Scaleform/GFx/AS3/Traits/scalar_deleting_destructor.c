Scaleform::GFx::AS3::Traits *__thiscall Scaleform::GFx::AS3::Traits::`scalar deleting destructor'(
        Scaleform::GFx::AS3::Traits *this,
        char a2)
{
  Scaleform::GFx::AS3::Traits::~Traits(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)this);
  return this;
}
