double __thiscall Scaleform::Render::GlyphCache::SnapShadowSizeToRamp(
        Scaleform::Render::GlyphCache *this,
        float screenSize)
{
  unsigned int v3; // eax
  float screenSizea; // [esp+18h] [ebp+4h]

  screenSizea = floor(screenSize);
  v3 = (__int64)screenSizea;
  if ( v3 > 0xFF )
    return (double)255;
  else
    return (double)FontSizeRamp[this->FontSizeMap[v3] + 1];
}
