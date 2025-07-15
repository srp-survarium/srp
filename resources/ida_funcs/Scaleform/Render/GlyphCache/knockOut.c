void __thiscall Scaleform::Render::GlyphCache::knockOut(Scaleform::Render::GlyphCache *this, unsigned __int8 *raster)
{
  unsigned __int8 *Data; // esi
  unsigned int i; // edi

  Data = this->KnockOutCopy.Data.Data;
  for ( i = 0; i < this->KnockOutCopy.Data.Size; ++raster )
  {
    *raster = (unsigned __int16)((255 - *Data) * *raster + 255) >> 8;
    ++i;
    ++Data;
  }
}
