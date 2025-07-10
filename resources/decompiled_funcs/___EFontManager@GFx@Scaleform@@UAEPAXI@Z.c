Scaleform::GFx::FontManager *__thiscall Scaleform::GFx::FontManager::`vector deleting destructor'(
        Scaleform::GFx::FontManager *this,
        char a2)
{
  Scaleform::GFx::FontManager::~FontManager(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
