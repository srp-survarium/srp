void __thiscall Scaleform::Render::GlyphCache::copyImageData(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::ImagePlane *pl,
        const __m128i *data,
        unsigned int pitch,
        unsigned int dstX,
        unsigned int dstY,
        unsigned int w,
        unsigned int h)
{
  unsigned int i; // esi

  for ( i = 0; i < h; ++i )
  {
    memcpy((int)&pl->pData[pl->Pitch * (i + dstY) + dstX], data, w);
    data = (const __m128i *)((char *)data + pitch);
  }
}
