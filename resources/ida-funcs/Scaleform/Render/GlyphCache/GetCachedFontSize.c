double __thiscall Scaleform::Render::GlyphCache::GetCachedFontSize(
        Scaleform::Render::GlyphCache *this,
        const Scaleform::Render::GlyphParam *gp,
        float screenSize,
        bool exactFit)
{
  double v5; // st7
  double result; // st7
  float v7; // [esp+18h] [ebp+Ch]
  float v8; // [esp+18h] [ebp+Ch]
  float v9; // [esp+18h] [ebp+Ch]

  if ( !exactFit )
  {
    if ( (gp->Flags & 1) != 0 )
    {
      v7 = screenSize * 4.0 + 0.5;
      v8 = floor(v7);
      v5 = v8 * 0.25;
    }
    else
    {
      v5 = Scaleform::Render::GlyphCache::SnapFontSizeToRamp(this, screenSize);
    }
    screenSize = v5;
  }
  v9 = (float)(this->MaxSlotHeight - 2 * this->SlotPadding);
  result = screenSize;
  if ( this->Param.MaxRasterScale * v9 >= screenSize )
  {
    if ( v9 >= result )
      return screenSize;
    return v9;
  }
  return result;
}
