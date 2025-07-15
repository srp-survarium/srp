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
  unsigned int v12; // edx
  unsigned int v13; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebp
  Scaleform::Render::GlyphNode *v16; // ecx
  Scaleform::Render::GlyphNode *Glyph; // ebp
  double v19; // st7
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_RasterDataSrc; // edi
  unsigned int v21; // ebp
  unsigned int v22; // eax
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *p_RasterData; // ecx
  const Scaleform::Render::GlyphRaster *v24; // ecx
  int v25; // ebp
  int v26; // edx
  int v27; // ebp
  double v28; // st7
  int v29; // eax
  unsigned __int8 *v30; // [esp-4h] [ebp-44h]
  float X; // [esp+0h] [ebp-40h]
  unsigned int v32; // [esp+18h] [ebp-28h]
  float v33; // [esp+1Ch] [ebp-24h]
  float v34; // [esp+20h] [ebp-20h]
  float v35; // [esp+24h] [ebp-1Ch]
  float v36; // [esp+24h] [ebp-1Ch]
  unsigned int v37; // [esp+28h] [ebp-18h]
  float v38; // [esp+2Ch] [ebp-14h]
  float v39; // [esp+2Ch] [ebp-14h]
  float v40; // [esp+30h] [ebp-10h]
  float v41; // [esp+34h] [ebp-Ch]
  unsigned int v42; // [esp+34h] [ebp-Ch]
  const Scaleform::Render::GlyphNode *v43; // [esp+38h] [ebp-8h]
  float hb; // [esp+44h] [ebp+4h]
  float h; // [esp+44h] [ebp+4h]
  unsigned int ha; // [esp+44h] [ebp+4h]
  int v47; // [esp+48h] [ebp+8h]
  float v48; // [esp+50h] [ebp+10h]
  float v49; // [esp+50h] [ebp+10h]
  float v50; // [esp+50h] [ebp+10h]
  float v51; // [esp+50h] [ebp+10h]
  float v52; // [esp+50h] [ebp+10h]
  float v53; // [esp+50h] [ebp+10h]
  float v54; // [esp+50h] [ebp+10h]
  float v55; // [esp+50h] [ebp+10h]
  float v56; // [esp+50h] [ebp+10h]
  float v57; // [esp+50h] [ebp+10h]
  unsigned int MaxSlotHeight; // [esp+50h] [ebp+10h]
  float v59; // [esp+54h] [ebp+14h]

  v41 = (double)gp->FontSize * 0.0625;
  v48 = v41 / screenSize;
  hb = (double)gp->BlurX * 0.0625;
  v8 = v48;
  v34 = hb * v48 * data->HeightRatio;
  v49 = 0.0625 * (double)gp->BlurY;
  v33 = v8 * v49 * data->HeightRatio;
  h = this->ShadowQuality * (double)this->MaxSlotHeight - (double)(2 * this->SlotPadding);
  v35 = 1.0;
  v9 = v33;
  v50 = v9 + v9 + (double)ras->Height;
  if ( h <= (double)v50 )
  {
    v51 = h / v50;
    v34 = v34 * v51;
    v33 = v9 * v51;
    v35 = v51;
  }
  v52 = ceil(v34);
  v10 = (int)v52;
  v53 = ceil(v33);
  SlotPadding = this->SlotPadding;
  v12 = SlotPadding + v10;
  v13 = (int)v53 + SlotPadding;
  v14 = ras->Width + 2 * v12 + 1;
  v42 = v12;
  v15 = ras->Height + 2 * v13 + 1;
  v37 = v13;
  ha = v15;
  v38 = (float)v14;
  v54 = v38 * v35;
  v55 = ceil(v54);
  v32 = (__int64)v55;
  v40 = (float)v15;
  v56 = v40 * v35;
  v57 = ceil(v56);
  v16 = (Scaleform::Render::GlyphNode *)(__int64)v57;
  MaxSlotHeight = (unsigned int)v16;
  if ( (unsigned int)v16 > this->MaxSlotHeight )
  {
    MaxSlotHeight = this->MaxSlotHeight;
    v16 = (Scaleform::Render::GlyphNode *)MaxSlotHeight;
  }
  Glyph = Scaleform::Render::GlyphCache::allocateGlyph(this, tm, gp, (Scaleform::Render::GlyphNode *)v32, v16);
  v43 = Glyph;
  if ( !Glyph )
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
  v36 = (float)v32;
  v19 = v38;
  Glyph->Origin.x = (int)((double)(int)(-16 * (v42 + ras->OriginX)) * v36 / v38);
  v39 = (float)MaxSlotHeight;
  Glyph->Origin.y = (int)((double)(int)(-16 * (v37 + ras->OriginY)) * v39 / v40);
  p_RasterDataSrc = &this->RasterDataSrc;
  Glyph->Scale = (v40 / v39 + v19 / v36) * 0.5;
  v21 = v14 * ha;
  if ( v14 * ha >= this->RasterDataSrc.Data.Size )
  {
    if ( v21 >= this->RasterDataSrc.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->RasterDataSrc,
        &this->RasterDataSrc,
        v21 + (v21 >> 2));
  }
  else if ( v21 < this->RasterDataSrc.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->RasterDataSrc,
      &this->RasterDataSrc,
      v14 * ha);
  }
  v22 = v32 * MaxSlotHeight;
  p_RasterData = &this->RasterData;
  this->RasterDataSrc.Data.Size = v21;
  if ( v32 * MaxSlotHeight >= this->RasterData.Data.Size )
  {
    if ( v22 >= this->RasterData.Data.Policy.Capacity )
    {
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)p_RasterData,
        &this->RasterData,
        v22 + (v22 >> 2));
      goto LABEL_19;
    }
  }
  else if ( v22 < this->RasterData.Data.Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)p_RasterData,
      &this->RasterData,
      v22);
LABEL_19:
    v22 = v32 * MaxSlotHeight;
  }
  this->RasterData.Data.Size = v22;
  v30 = p_RasterDataSrc->Data.Data;
  this->RasterPitch = v32;
  memset((int)v30, 0, v21);
  if ( v14 > 1 && ha > 1 )
  {
    v24 = ras;
    v25 = 0;
    if ( ras->Height )
    {
      v26 = v37 * v14;
      v47 = v37 * v14;
      while ( v25 + v37 < ha )
      {
        memcpy(
          (int)&p_RasterDataSrc->Data.Data[v42 + v26],
          (const __m128i *)&v24->Raster.Data.Data[v25 * v24->Width],
          v24->Width);
        v47 += v14;
        if ( ++v25 >= ras->Height )
          break;
        v26 = v47;
        v24 = ras;
      }
    }
    v27 = 0;
    if ( (gp->Flags & 0x20) != 0 )
      Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
        &this->KnockOutCopy,
        &this->RasterDataSrc);
    if ( v34 > 0.0 )
    {
      v28 = v34;
    }
    else
    {
      v28 = v34;
      if ( v33 <= 0.0 )
        goto LABEL_31;
    }
    X = v28;
    Scaleform::Render::GlyphCache::recursiveBlur(this, p_RasterDataSrc->Data.Data, v14, 0, 0, v14, ha, X, v33);
    v27 = 8;
LABEL_31:
    v59 = (double)gp->BlurStrength * 0.0625;
    if ( v59 > 1.0 )
      v29 = v27;
    else
      v29 = 0;
    Scaleform::Render::GlyphCache::strengthenImage(this, p_RasterDataSrc->Data.Data, v14, 0, 0, v14, ha, v59, v29);
    if ( (gp->Flags & 0x20) != 0 )
      Scaleform::Render::GlyphCache::knockOut(this, p_RasterDataSrc->Data.Data);
  }
  if ( ha == MaxSlotHeight && v14 == v32 )
  {
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
      &this->RasterData,
      &this->RasterDataSrc);
  }
  else
  {
    memset((int)this->RasterData.Data.Data, 0, v32 * MaxSlotHeight);
    Scaleform::Render::ResizeImageBilinear(
      this->RasterData.Data.Data,
      v32,
      MaxSlotHeight,
      v32,
      p_RasterDataSrc->Data.Data,
      v14,
      ha,
      v14,
      ResizeGray);
  }
  Scaleform::Render::GlyphCache::updateTextureGlyph(this, v43);
  ++this->RasterizationCount;
  return (Scaleform::Render::GlyphNode *)v43;
}
