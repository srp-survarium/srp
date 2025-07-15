double __thiscall Scaleform::Render::GlyphCache::GetCachedShadowSize(
        Scaleform::Render::GlyphCache *this,
        float screenSize,
        const Scaleform::Render::GlyphRaster *ras)
{
  float screenSizea; // [esp+Ch] [ebp+4h]
  float rasa; // [esp+10h] [ebp+8h]

  if ( ras )
    return (double)ras->HintedSize;
  screenSizea = Scaleform::Render::GlyphCache::SnapShadowSizeToRamp(this, screenSize);
  rasa = (float)(this->MaxSlotHeight - 2 * this->SlotPadding);
  if ( rasa < (double)screenSizea )
    return rasa;
  else
    return screenSizea;
}
