Scaleform::Render::GlyphCache *__thiscall Scaleform::Render::GlyphCache::`vector deleting destructor'(
        Scaleform::Render::GlyphCache *this,
        char a2)
{
  Scaleform::Render::GlyphCache::~GlyphCache(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}


Scaleform::Render::GlyphCache *__thiscall Scaleform::Render::GlyphCache::`vector deleting destructor'(
        char *this,
        char a2)
{
  return Scaleform::Render::GlyphCache::`vector deleting destructor'((Scaleform::Render::GlyphCache *)(this - 8), a2);
}


Scaleform::Render::GlyphCache *__thiscall Scaleform::Render::GlyphCache::`vector deleting destructor'(
        char *this,
        char a2)
{
  return Scaleform::Render::GlyphCache::`vector deleting destructor'((Scaleform::Render::GlyphCache *)(this - 12), a2);
}
