double __thiscall Scaleform::Render::GlyphCache::GetCachedFontSize(
        Scaleform::Render::GlyphCache *this,
        const Scaleform::Render::GlyphParam *gp,
        float screenSize,
        bool exactFit)
{
  double v5; // st7
  double result; // st7
  float maxHeighta; // [esp+18h] [ebp+Ch]
  float maxHeightb; // [esp+18h] [ebp+Ch]
  float maxHeight; // [esp+18h] [ebp+Ch]

  if ( !exactFit )
  {
    if ( (gp->Flags & 1) != 0 )
    {
      maxHeighta = screenSize * 4.0 + 0.5;
      maxHeightb = floor(maxHeighta);
      v5 = maxHeightb * 0.25;
    }
    else
    {
      v5 = Scaleform::Render::GlyphCache::SnapFontSizeToRamp(this, screenSize);
    }
    screenSize = v5;
  }
  maxHeight = (float)(this->MaxSlotHeight - 2 * this->SlotPadding);
  result = screenSize;
  if ( this->Param.MaxRasterScale * maxHeight >= screenSize )
  {
    if ( maxHeight >= result )
      return screenSize;
    return maxHeight;
  }
  return result;
}
