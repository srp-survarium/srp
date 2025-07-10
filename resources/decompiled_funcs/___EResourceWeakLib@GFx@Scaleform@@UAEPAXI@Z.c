Scaleform::GFx::ResourceWeakLib *__thiscall Scaleform::GFx::ResourceWeakLib::`vector deleting destructor'(
        Scaleform::GFx::ResourceWeakLib *this,
        char a2)
{
  Scaleform::GFx::ResourceWeakLib::~ResourceWeakLib(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
