Scaleform::Render::GlyphNode *__thiscall Scaleform::Render::GlyphCache::getPrerasterizedGlyph(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::GlyphRunData *data,
        Scaleform::Render::TextMeshProvider *tm,
        const Scaleform::Render::GlyphParam *gp)
{
  const Scaleform::Render::GlyphRaster *pRaster; // esi
  unsigned int SlotPadding; // eax
  int v8; // ebp
  int v9; // ebx
  Scaleform::Render::GlyphNode *Glyph; // eax
  unsigned int i; // ebx
  unsigned __int8 *v12; // [esp-14h] [ebp-24h]
  unsigned int v13; // [esp+8h] [ebp-8h]
  unsigned int v14; // [esp+Ch] [ebp-4h]
  unsigned int MaxSlotHeight; // [esp+14h] [ebp+4h]
  const Scaleform::Render::GlyphNode *v16; // [esp+1Ch] [ebp+Ch]

  pRaster = data->pRaster;
  if ( pRaster->Height + 2 * this->SlotPadding < this->MaxSlotHeight || data->pShape->IsEmpty(data->pShape) )
  {
    SlotPadding = this->SlotPadding;
    v8 = -(pRaster->OriginX + SlotPadding);
    v9 = -(SlotPadding + pRaster->OriginY);
    v14 = SlotPadding;
    v13 = 2 * SlotPadding + pRaster->Width + 1;
    MaxSlotHeight = pRaster->Height - pRaster->OriginY + SlotPadding + pRaster->OriginY + SlotPadding + 1;
    if ( MaxSlotHeight > this->MaxSlotHeight )
    {
      MaxSlotHeight = this->MaxSlotHeight;
      if ( this->RasterTooBigWarning )
      {
        Scaleform::Render::GlyphCache::LogWarning(
          this,
          "Warning: Raster glyph is too big - increase GlyphCacheParams.MaxSlotHeight");
        this->RasterTooBigWarning = 0;
      }
    }
    Glyph = Scaleform::Render::GlyphCache::allocateGlyph(
              this,
              tm,
              gp,
              (Scaleform::Render::GlyphNode *)v13,
              (Scaleform::Render::GlyphNode *)MaxSlotHeight);
    v16 = Glyph;
    if ( Glyph )
    {
      Glyph->Origin.y = 16 * v9;
      Glyph->Scale = 1.0;
      Glyph->Origin.x = 16 * v8;
      Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
        &this->RasterData,
        v13 * MaxSlotHeight);
      v12 = this->RasterData.Data.Data;
      this->RasterPitch = v13;
      memset((int)v12, 0, v13 * MaxSlotHeight);
      for ( i = 0; i < pRaster->Height; ++i )
      {
        if ( i + v14 >= MaxSlotHeight )
          break;
        memcpy(
          (int)&this->RasterData.Data.Data[(i + v14) * this->RasterPitch + v14],
          (const __m128i *)&pRaster->Raster.Data.Data[i * pRaster->Width],
          pRaster->Width);
      }
      Scaleform::Render::GlyphCache::updateTextureGlyph(this, v16);
      ++this->RasterizationCount;
      return (Scaleform::Render::GlyphNode *)v16;
    }
    else
    {
      this->Result = Res_CacheFull;
      if ( this->RasterCacheWarning )
      {
        Scaleform::Render::GlyphCache::LogWarning(
          this,
          "Warning: Increase raster glyph cache capacity - see GlyphCacheParams");
        this->RasterCacheWarning = 0;
      }
      return 0;
    }
  }
  else
  {
    this->Result = Res_ShapeIsTooBig;
    return 0;
  }
}
