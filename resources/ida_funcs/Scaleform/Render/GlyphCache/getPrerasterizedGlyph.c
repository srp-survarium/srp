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
  Scaleform::Render::TextNotifier *Notifier; // eax
  unsigned int i; // ebx
  bool v13; // zf
  unsigned __int8 *v14; // [esp-14h] [ebp-24h]
  int imgW; // [esp+8h] [ebp-8h]
  unsigned int v16; // [esp+Ch] [ebp-4h]
  unsigned int imgH; // [esp+14h] [ebp+4h]
  const Scaleform::Render::GlyphNode *gpa; // [esp+1Ch] [ebp+Ch]

  pRaster = data->pRaster;
  if ( pRaster->Height + 2 * this->SlotPadding < this->MaxSlotHeight || data->pShape->IsEmpty(data->pShape) )
  {
    SlotPadding = this->SlotPadding;
    v8 = -(pRaster->OriginX + SlotPadding);
    v9 = -(SlotPadding + pRaster->OriginY);
    v16 = SlotPadding;
    imgW = 2 * SlotPadding + pRaster->Width + 1;
    imgH = pRaster->Height - pRaster->OriginY + SlotPadding + pRaster->OriginY + SlotPadding + 1;
    if ( imgH > this->MaxSlotHeight )
    {
      imgH = this->MaxSlotHeight;
      if ( this->RasterTooBigWarning )
      {
        Scaleform::Render::GlyphCache::LogWarning(
          this,
          "Warning: Raster glyph is too big - increase GlyphCacheParams.MaxSlotHeight");
        this->RasterTooBigWarning = 0;
      }
    }
    Glyph = Scaleform::Render::GlyphQueue::AllocateGlyph(&this->Queue, gp, imgW, imgH);
    gpa = Glyph;
    if ( Glyph )
    {
      Notifier = Scaleform::Render::GlyphQueue::CreateNotifier(&this->Queue, Glyph, tm);
      Scaleform::Render::TextMeshProvider::AddNotifier(tm, Notifier);
      gpa->Scale = 1.0;
      gpa->Origin.y = 16 * v9;
      gpa->Origin.x = 16 * v8;
      Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
        &this->RasterData,
        imgW * imgH);
      v14 = this->RasterData.Data.Data;
      this->RasterPitch = imgW;
      memset((int)v14, 0, imgW * imgH);
      for ( i = 0; i < pRaster->Height; ++i )
      {
        if ( i + v16 >= imgH )
          break;
        memcpy(
          &this->RasterData.Data.Data[v16 + (i + v16) * this->RasterPitch],
          &pRaster->Raster.Data.Data[i * pRaster->Width],
          pRaster->Width);
      }
      Scaleform::Render::GlyphCache::updateTextureGlyph(this, gpa);
      ++this->RasterizationCount;
      return (Scaleform::Render::GlyphNode *)gpa;
    }
    else
    {
      v13 = !this->RasterCacheWarning;
      this->Result = Res_CacheFull;
      if ( !v13 )
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
