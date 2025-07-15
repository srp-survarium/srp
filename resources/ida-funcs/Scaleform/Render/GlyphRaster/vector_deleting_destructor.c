Scaleform::Render::GlyphRaster *__thiscall Scaleform::Render::GlyphRaster::`vector deleting destructor'(
        Scaleform::Render::GlyphRaster *this,
        char a2)
{
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Raster.Data.Data);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
