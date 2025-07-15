double __thiscall Scaleform::Render::GlyphCache::GetCachedShadowSize(
        Scaleform::Render::GlyphCache *this,
        float screenSize,
        const Scaleform::Render::GlyphRaster *ras)
{
  float v5; // [esp+Ch] [ebp+4h]
  float v6; // [esp+10h] [ebp+8h]

  if ( ras )
    return (double)ras->HintedSize;
  v5 = Scaleform::Render::GlyphCache::SnapShadowSizeToRamp(this, screenSize);
  v6 = (float)(this->MaxSlotHeight - 2 * this->SlotPadding);
  if ( v6 < (double)v5 )
    return v6;
  else
    return v5;
}
