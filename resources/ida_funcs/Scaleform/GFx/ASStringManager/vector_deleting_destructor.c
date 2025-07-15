Scaleform::GFx::ASStringManager *__thiscall Scaleform::GFx::ASStringManager::`vector deleting destructor'(
        Scaleform::GFx::ASStringManager *this,
        char a2)
{
  Scaleform::GFx::ASStringManager::~ASStringManager(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
