Scaleform::Render::GlyphNode *__userpurge Scaleform::Render::GlyphCache::RasterizeShadow@<eax>(
        Scaleform::Render::GlyphCache *this@<ecx>,
        float a2@<ebp>,
        float a3@<edi>,
        Scaleform::Render::GlyphRunData *data,
        Scaleform::Render::TextMeshProvider *tm,
        const Scaleform::Render::GlyphParam *gp,
        float screenSize,
        const Scaleform::Render::GlyphRaster *ras)
{
  Scaleform::Render::GlyphNode *result; // eax
  double v11; // st6
  double v12; // st4
  double v13; // st7
  unsigned int HintedNomHeight; // eax
  double NomHeight; // st6
  double v16; // st7
  double v17; // st5
  double v18; // st6
  double v19; // st7
  unsigned int *v20; // ebx
  unsigned int SlotPadding; // eax
  int v22; // ebx
  int v23; // ebp
  int v24; // edi
  int v25; // eax
  unsigned int v26; // ecx
  unsigned int MaxSlotHeight; // edi
  Scaleform::Render::GlyphNode *Glyph; // eax
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_RasterData; // ebx
  unsigned int i; // ebp
  int v31; // ebp
  double v32; // st7
  int v33; // eax
  void (__thiscall *Clear)(struct Scaleform::Render::Rasterizer *); // edx
  unsigned __int8 *v35; // [esp-4h] [ebp-34h]
  float screenSizea; // [esp+0h] [ebp-30h]
  float y1; // [esp+18h] [ebp-18h]
  Scaleform::Render::Rasterizer *y1a; // [esp+18h] [ebp-18h]
  float vectorScale; // [esp+1Ch] [ebp-14h]
  __int16 vectorScalea; // [esp+1Ch] [ebp-14h]
  float rasterScale; // [esp+20h] [ebp-10h]
  int padY; // [esp+24h] [ebp-Ch]
  int padX; // [esp+28h] [ebp-8h]
  int padXa; // [esp+28h] [ebp-8h]
  Scaleform::Render::GlyphNode *node; // [esp+2Ch] [ebp-4h]
  float blurX; // [esp+34h] [ebp+4h]
  float gamma; // [esp+38h] [ebp+8h]
  float blurYb; // [esp+40h] [ebp+10h]
  float blurYc; // [esp+40h] [ebp+10h]
  float blurY; // [esp+40h] [ebp+10h]
  float blurYd; // [esp+40h] [ebp+10h]
  float blurYa; // [esp+40h] [ebp+10h]
  float hc; // [esp+44h] [ebp+14h]
  float hd; // [esp+44h] [ebp+14h]
  float he; // [esp+44h] [ebp+14h]
  float h; // [esp+44h] [ebp+14h]
  float hf; // [esp+44h] [ebp+14h]
  float hg; // [esp+44h] [ebp+14h]
  float ha; // [esp+44h] [ebp+14h]
  float hh; // [esp+44h] [ebp+14h]
  float hi; // [esp+44h] [ebp+14h]
  unsigned int hb; // [esp+44h] [ebp+14h]

  if ( !this->MaxNumTextures )
  {
    this->Result = Res_NoRasterCache;
    return 0;
  }
  if ( !ras
    || (result = Scaleform::Render::GlyphCache::createShadowFromRaster(this, data, tm, gp, screenSize, ras)) == 0 )
  {
    if ( !data->pShape )
    {
      this->Result = Res_ShapeNotFound;
      return 0;
    }
    hc = (double)gp->FontSize * 0.0625;
    v11 = hc;
    blurYb = hc / screenSize;
    hd = (double)gp->BlurX * 0.0625;
    v12 = blurYb;
    blurX = hd * blurYb * data->HeightRatio;
    blurYc = 0.0625 * (double)gp->BlurY;
    v13 = v11;
    blurY = v12 * blurYc * data->HeightRatio;
    HintedNomHeight = data->HintedNomHeight;
    *(float *)&padX = this->ShadowQuality * (double)this->MaxSlotHeight - (double)(2 * this->SlotPadding);
    rasterScale = 1.0;
    if ( HintedNomHeight )
      NomHeight = (double)HintedNomHeight;
    else
      NomHeight = data->NomHeight;
    he = NomHeight;
    vectorScale = v13 / he;
    y1 = data->GlyphBounds.y1;
    h = data->GlyphBounds.y2;
    if ( h <= (double)y1 )
    {
      h = 0.0;
      y1 = 0.0;
    }
    v16 = blurY;
    hf = h * vectorScale + blurY;
    v17 = hf;
    hg = y1 * vectorScale - blurY;
    ha = v17 - hg;
    if ( *(float *)&padX <= (double)ha )
    {
      blurYd = *(float *)&padX / ha;
      vectorScale = vectorScale * blurYd;
      blurX = blurX * blurYd;
      v18 = v16 * blurYd;
      v19 = blurYd;
      blurY = v18;
      rasterScale = 1.0 / v19;
    }
    hh = ceil(blurX);
    v20 = (unsigned int *)(int)hh;
    hi = ceil(blurY);
    y1a = &this->Ras;
    ((void (*)(void))this->Ras.Clear)();
    Scaleform::Render::GlyphCache::addShapeToRasterizer(
      this,
      v20,
      (float *)data,
      data->pShape,
      vectorScale,
      vectorScale,
      a2,
      a3);
    SlotPadding = this->SlotPadding;
    padXa = (int)v20 + SlotPadding;
    v22 = 0;
    padY = (int)hi + SlotPadding;
    v23 = 0;
    v24 = 0;
    vectorScalea = 0;
    if ( Scaleform::Render::Rasterizer::SortCells(&this->Ras) )
    {
      v23 = this->Ras.MinX - padXa;
      v24 = padXa + this->Ras.MaxX;
      v25 = this->Ras.MinY - padY;
      vectorScalea = v25;
      v22 = padY + this->Ras.MaxY;
    }
    else
    {
      v25 = 0;
    }
    v26 = v24 - v23 + 1;
    MaxSlotHeight = v22 - v25 + 1;
    hb = v26;
    if ( MaxSlotHeight > this->MaxSlotHeight )
      MaxSlotHeight = this->MaxSlotHeight;
    Glyph = Scaleform::Render::GlyphCache::allocateGlyph(this, tm, gp, v26, MaxSlotHeight);
    node = Glyph;
    if ( !Glyph )
    {
      this->Result = Res_CacheFull;
      Scaleform::Render::GlyphCache::cacheFullWarning(this);
      return 0;
    }
    Glyph->Scale = rasterScale;
    Glyph->Origin.x = 16 * v23;
    Glyph->Origin.y = 16 * vectorScalea;
    p_RasterData = &this->RasterData;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
      &this->RasterData,
      hb * MaxSlotHeight);
    v35 = this->RasterData.Data.Data;
    this->RasterPitch = hb;
    memset((int)v35, 0, hb * MaxSlotHeight);
    if ( hb <= 1 || MaxSlotHeight <= 1 )
      goto LABEL_42;
    gamma = 1.0;
    if ( gp->BlurX || gp->BlurY )
      gamma = 0.40000001;
    if ( this->Ras.Gamma2 != gamma )
      Scaleform::Render::Rasterizer::SetGamma2(y1a, gamma);
    for ( i = 0; i < this->Ras.SortedYs.Size; ++i )
    {
      if ( i + padY >= MaxSlotHeight )
        break;
      Scaleform::Render::Rasterizer::SweepScanline(
        y1a,
        i,
        &p_RasterData->Data.Data[(i + padY) * this->RasterPitch + padXa],
        1u,
        1);
    }
    v31 = 0;
    if ( (gp->Flags & 0x20) != 0 )
      Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
        &this->KnockOutCopy,
        &this->RasterData);
    if ( blurX > 0.0 )
    {
      v32 = blurX;
    }
    else
    {
      v32 = blurX;
      if ( blurY <= 0.0 )
      {
LABEL_35:
        blurYa = (double)gp->BlurStrength * 0.0625;
        if ( blurYa > 1.0 )
          v33 = v31;
        else
          v33 = 0;
        Scaleform::Render::GlyphCache::strengthenImage(
          this,
          p_RasterData->Data.Data,
          this->RasterPitch,
          0,
          0,
          hb,
          MaxSlotHeight,
          blurYa,
          v33);
        if ( (gp->Flags & 0x20) != 0 )
          Scaleform::Render::GlyphCache::knockOut(this, p_RasterData->Data.Data);
LABEL_42:
        Scaleform::Render::GlyphCache::updateTextureGlyph(this, node);
        Clear = y1a->Clear;
        ++this->RasterizationCount;
        Clear(y1a);
        return node;
      }
    }
    screenSizea = v32;
    Scaleform::Render::GlyphCache::recursiveBlur(
      this,
      p_RasterData->Data.Data,
      this->RasterPitch,
      0,
      0,
      hb,
      MaxSlotHeight,
      screenSizea,
      blurY);
    v31 = 8;
    goto LABEL_35;
  }
  return result;
}
