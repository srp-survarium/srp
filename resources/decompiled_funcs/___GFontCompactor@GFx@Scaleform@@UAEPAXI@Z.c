Scaleform::GFx::FontCompactor *__thiscall Scaleform::GFx::FontCompactor::`scalar deleting destructor'(
        Scaleform::GFx::FontCompactor *this,
        char a2)
{
  Scaleform::GFx::FontCompactor::~FontCompactor(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
