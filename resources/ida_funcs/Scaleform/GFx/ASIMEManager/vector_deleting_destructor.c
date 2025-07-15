Scaleform::GFx::ASIMEManager *__thiscall Scaleform::GFx::ASIMEManager::`vector deleting destructor'(
        Scaleform::GFx::ASIMEManager *this,
        char a2)
{
  Scaleform::GFx::ASIMEManager::~ASIMEManager(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
