Scaleform::GFx::FontGlyphPacker *__thiscall Scaleform::GFx::FontGlyphPacker::`vector deleting destructor'(
        Scaleform::GFx::FontGlyphPacker *this,
        char a2)
{
  Scaleform::GFx::FontGlyphPacker::~FontGlyphPacker(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
