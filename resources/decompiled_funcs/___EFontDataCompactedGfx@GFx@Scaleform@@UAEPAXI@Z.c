Scaleform::GFx::FontDataCompactedGfx *__thiscall Scaleform::GFx::FontDataCompactedGfx::`vector deleting destructor'(
        Scaleform::GFx::FontDataCompactedGfx *this,
        char a2)
{
  Scaleform::GFx::FontDataCompactedGfx::~FontDataCompactedGfx(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
