Scaleform::Render::GlyphNode *__thiscall Scaleform::Render::GlyphCache::createShadowFromRaster(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::GlyphRunData *data,
        Scaleform::Render::TextMeshProvider *tm,
        const Scaleform::Render::GlyphParam *gp,
        float screenSize,
        const Scaleform::Render::GlyphRaster *ras)
{
  double v8; // st5
  double v9; // st7
  int v10; // esi
  unsigned int SlotPadding; // ecx
  int v12; // edx
  unsigned int v13; // esi
  unsigned int v14; // eax
  Scaleform::Render::GlyphNode *Glyph; // eax
  Scaleform::Render::GlyphNode *v16; // edi
  Scaleform::Render::TextNotifier *Notifier; // eax
  double v18; // st7
  unsigned int v19; // ebp
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_RasterDataSrc; // edi
  bool v21; // zf
  unsigned int v23; // eax
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_RasterData; // ecx
  const Scaleform::Render::GlyphRaster *v25; // ecx
  int v26; // ebp
  int v27; // edx
  int v28; // ebp
  double v29; // st7
  int v30; // eax
  const unsigned __int8 *v31; // [esp-4h] [ebp-44h]
  float X; // [esp+0h] [ebp-40h]
  unsigned int imgWs; // [esp+18h] [ebp-28h]
  float blurY; // [esp+1Ch] [ebp-24h]
  float blurX; // [esp+20h] [ebp-20h]
  float rasterScale; // [esp+24h] [ebp-1Ch]
  float rasterScalea; // [esp+24h] [ebp-1Ch]
  int padY; // [esp+28h] [ebp-18h]
  float v39; // [esp+2Ch] [ebp-14h]
  float v40; // [esp+2Ch] [ebp-14h]
  float v41; // [esp+30h] [ebp-10h]
  float padXa; // [esp+34h] [ebp-Ch]
  int padX; // [esp+34h] [ebp-Ch]
  const Scaleform::Render::GlyphNode *node; // [esp+38h] [ebp-8h]
  float imgHb; // [esp+44h] [ebp+4h]
  float imgH; // [esp+44h] [ebp+4h]
  unsigned int imgHa; // [esp+44h] [ebp+4h]
  int tma; // [esp+48h] [ebp+8h]
  float hb; // [esp+50h] [ebp+10h]
  float hc; // [esp+50h] [ebp+10h]
  float h; // [esp+50h] [ebp+10h]
  float hd; // [esp+50h] [ebp+10h]
  float he; // [esp+50h] [ebp+10h]
  float hf; // [esp+50h] [ebp+10h]
  float hg; // [esp+50h] [ebp+10h]
  float hh; // [esp+50h] [ebp+10h]
  float hi; // [esp+50h] [ebp+10h]
  float hj; // [esp+50h] [ebp+10h]
  unsigned int ha; // [esp+50h] [ebp+10h]
  float rasa; // [esp+54h] [ebp+14h]

  padXa = (double)gp->FontSize * 0.0625;
  hb = padXa / screenSize;
  imgHb = (double)gp->BlurX * 0.0625;
  v8 = hb;
  blurX = imgHb * hb * data->HeightRatio;
  hc = 0.0625 * (double)gp->BlurY;
  blurY = v8 * hc * data->HeightRatio;
  imgH = this->ShadowQuality * (double)this->MaxSlotHeight - (double)(2 * this->SlotPadding);
  rasterScale = 1.0;
  v9 = blurY;
  h = v9 + v9 + (double)ras->Height;
  if ( imgH <= (double)h )
  {
    hd = imgH / h;
    blurX = blurX * hd;
    blurY = v9 * hd;
    rasterScale = hd;
  }
  he = ceil(blurX);
  v10 = (int)he;
  hf = ceil(blurY);
  SlotPadding = this->SlotPadding;
  v12 = SlotPadding + v10;
  v13 = ras->Width + 2 * (SlotPadding + v10) + 1;
  padX = v12;
  padY = SlotPadding + (int)hf;
  imgHa = ras->Height + 2 * padY + 1;
  v39 = (float)v13;
  hg = v39 * rasterScale;
  hh = ceil(hg);
  imgWs = (__int64)hh;
  v41 = (float)imgHa;
  hi = v41 * rasterScale;
  hj = ceil(hi);
  v14 = (__int64)hj;
  ha = v14;
  if ( v14 > this->MaxSlotHeight )
  {
    ha = this->MaxSlotHeight;
    v14 = ha;
  }
  Glyph = Scaleform::Render::GlyphQueue::AllocateGlyph(&this->Queue, gp, imgWs, v14);
  v16 = Glyph;
  node = Glyph;
  if ( Glyph )
  {
    Notifier = Scaleform::Render::GlyphQueue::CreateNotifier(&this->Queue, Glyph, tm);
    Scaleform::Render::TextMeshProvider::AddNotifier(tm, Notifier);
    rasterScalea = (float)imgWs;
    v18 = v39;
    v16->Origin.x = (int)((double)(-16 * (padX + ras->OriginX)) * rasterScalea / v39);
    v40 = (float)ha;
    v16->Origin.y = (int)((double)(-16 * (padY + ras->OriginY)) * v40 / v41);
    v19 = v13 * imgHa;
    v16->Scale = (v41 / v40 + v18 / rasterScalea) * 0.5;
    p_RasterDataSrc = &this->RasterDataSrc;
    if ( v13 * imgHa >= this->RasterDataSrc.Data.Size )
    {
      if ( v19 >= this->RasterDataSrc.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->RasterDataSrc,
          &this->RasterDataSrc,
          v19 + (v19 >> 2));
    }
    else if ( v19 < this->RasterDataSrc.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->RasterDataSrc,
        &this->RasterDataSrc,
        v19);
    }
    v23 = imgWs * ha;
    p_RasterData = &this->RasterData;
    this->RasterDataSrc.Data.Size = v19;
    if ( imgWs * ha >= this->RasterData.Data.Size )
    {
      if ( v23 >= this->RasterData.Data.Policy.Capacity )
      {
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)p_RasterData,
          &this->RasterData,
          v23 + (v23 >> 2));
        goto LABEL_19;
      }
    }
    else if ( v23 < this->RasterData.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)p_RasterData,
        &this->RasterData,
        v23);
LABEL_19:
      v23 = imgWs * ha;
    }
    this->RasterData.Data.Size = v23;
    v31 = p_RasterDataSrc->Data.Data;
    this->RasterPitch = imgWs;
    memset((int)v31, 0, v19);
    if ( v13 <= 1 || imgHa <= 1 )
    {
LABEL_38:
      if ( imgHa == ha && v13 == imgWs )
      {
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
          &this->RasterData,
          &this->RasterDataSrc);
      }
      else
      {
        memset((int)this->RasterData.Data.Data, 0, imgWs * ha);
        Scaleform::Render::ResizeImageBilinear(
          this->RasterData.Data.Data,
          imgWs,
          ha,
          imgWs,
          p_RasterDataSrc->Data.Data,
          v13,
          imgHa,
          v13,
          ResizeGray);
      }
      Scaleform::Render::GlyphCache::updateTextureGlyph(this, node);
      ++this->RasterizationCount;
      return (Scaleform::Render::GlyphNode *)node;
    }
    v25 = ras;
    v26 = 0;
    if ( ras->Height )
    {
      v27 = padY * v13;
      tma = padY * v13;
      while ( v26 + padY < imgHa )
      {
        memcpy(&p_RasterDataSrc->Data.Data[v27 + padX], &v25->Raster.Data.Data[v26 * v25->Width], v25->Width);
        tma += v13;
        if ( ++v26 >= ras->Height )
          break;
        v27 = tma;
        v25 = ras;
      }
    }
    v28 = 0;
    if ( (gp->Flags & 0x20) != 0 )
      Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
        &this->KnockOutCopy,
        &this->RasterDataSrc);
    if ( blurX > 0.0 )
    {
      v29 = blurX;
    }
    else
    {
      v29 = blurX;
      if ( blurY <= 0.0 )
        goto LABEL_31;
    }
    X = v29;
    Scaleform::Render::GlyphCache::recursiveBlur(this, p_RasterDataSrc->Data.Data, v13, 0, 0, v13, imgHa, X, blurY);
    v28 = 8;
LABEL_31:
    rasa = (double)gp->BlurStrength * 0.0625;
    if ( rasa > 1.0 )
      v30 = v28;
    else
      v30 = 0;
    Scaleform::Render::GlyphCache::strengthenImage(this, p_RasterDataSrc->Data.Data, v13, 0, 0, v13, imgHa, rasa, v30);
    if ( (gp->Flags & 0x20) != 0 )
      Scaleform::Render::GlyphCache::knockOut(this, p_RasterDataSrc->Data.Data);
    goto LABEL_38;
  }
  v21 = !this->RasterCacheWarning;
  this->Result = Res_CacheFull;
  if ( !v21 )
  {
    Scaleform::Render::GlyphCache::LogWarning(
      this,
      "Warning: Increase raster glyph cache capacity - see GlyphCacheParams");
    this->RasterCacheWarning = 0;
  }
  return 0;
}
