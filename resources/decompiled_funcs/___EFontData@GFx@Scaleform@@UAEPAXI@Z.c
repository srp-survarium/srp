Scaleform::GFx::FontData *__thiscall Scaleform::GFx::FontData::`vector deleting destructor'(
        Scaleform::GFx::FontData *this,
        char a2)
{
  Scaleform::GFx::FontData::~FontData(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
