Scaleform::GFx::ResourceLib::ResourceSlot *__thiscall Scaleform::GFx::ResourceLib::ResourceSlot::`vector deleting destructor'(
        Scaleform::GFx::ResourceLib::ResourceSlot *this,
        char a2)
{
  Scaleform::GFx::ResourceLib::ResourceSlot::~ResourceSlot(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
