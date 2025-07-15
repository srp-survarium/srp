double __thiscall Scaleform::Render::GlyphCache::SnapShadowSizeToRamp(
        Scaleform::Render::GlyphCache *this,
        float screenSize)
{
  unsigned int v3; // eax
  float v6; // [esp+18h] [ebp+4h]

  v6 = floor(screenSize);
  v3 = (__int64)v6;
  if ( v3 > 0xFF )
    return (double)255;
  else
    return (double)FontSizeRamp[this->FontSizeMap[v3] + 1];
}
