void __thiscall Scaleform::Render::GlyphCache::copyImageData(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::ImagePlane *pl,
        unsigned __int8 *data,
        unsigned int pitch,
        unsigned int dstX,
        unsigned int dstY,
        unsigned int w,
        unsigned int h)
{
  unsigned int i; // esi

  for ( i = 0; i < h; ++i )
  {
    memcpy(&pl->pData[pl->Pitch * (i + dstY) + dstX], data, w);
    data += pitch;
  }
}
