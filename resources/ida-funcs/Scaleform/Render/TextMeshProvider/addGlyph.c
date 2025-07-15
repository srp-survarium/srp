char __thiscall Scaleform::Render::TextMeshProvider::addGlyph(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::TmpTextStorage *storage,
        Scaleform::Render::GlyphRunData *data,
        unsigned int glyphIndex,
        bool fauxBold,
        bool fauxItalic,
        BOOL snap,
        char meshGenFlags)
{
  const Scaleform::Render::TextureGlyph *v9; // ecx
  Scaleform::Render::VectorGlyphShape *GlyphShape; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // edx
  unsigned __int16 Flags; // ax
  double CachedFontSize; // st7
  unsigned int RasterSize; // eax
  double v18; // st7
  Scaleform::Render::Font *pFont; // ecx
  float (__thiscall *GetNominalGlyphHeight)(Scaleform::Render::Font *); // eax
  double v21; // st7
  Scaleform::Render::GlyphCache *pCache; // ecx
  int MaxSlotHeight; // edx
  double v24; // st6
  unsigned int v25; // eax
  double v26; // st7
  Scaleform::Render::GlyphNode *Glyph; // eax
  Scaleform::Render::GlyphCache *v28; // ecx
  Scaleform::Render::GlyphCache::RasResult v29; // eax
  unsigned int mColor; // edx
  double x1; // st5
  double v32; // st6
  double v33; // st7
  int v34; // ecx
  int v35; // edx
  int v36; // eax
  Scaleform::Render::FontCacheHandle *pFontHandle; // eax
  unsigned __int16 v38; // ax
  __int16 v39; // cx
  unsigned __int16 v40; // cx
  Scaleform::Render::GlyphCache *v41; // ecx
  Scaleform::Render::GlyphNode *v42; // eax
  float stretch; // [esp+14h] [ebp-44h]
  int v44; // [esp+18h] [ebp-40h]
  __int16 v45; // [esp+2Ah] [ebp-2Eh]
  float colora; // [esp+2Ch] [ebp-2Ch]
  unsigned int color; // [esp+2Ch] [ebp-2Ch]
  float v48; // [esp+30h] [ebp-28h]
  float v49; // [esp+30h] [ebp-28h]
  Scaleform::Render::VectorGlyphShape *v50; // [esp+34h] [ebp-24h]
  Scaleform::Render::Rect<float> rect; // [esp+38h] [ebp-20h] BYREF
  Scaleform::Render::GlyphParam gp; // [esp+48h] [ebp-10h] BYREF
  int savedregs; // [esp+58h] [ebp+0h] BYREF

  v48 = data->HeightRatio * data->FontSize;
  v45 = 256;
  v9 = data->pFont->GetTextureGlyph(data->pFont, glyphIndex);
  if ( v9 )
  {
    if ( (data->pFont->Flags & 0x1000) != 0 || this->pCache->Param.MaxRasterScale * data->TexHeight >= v48 )
    {
      if ( v9->pImage.pObject )
      {
        Scaleform::Render::TextMeshProvider::addTextureGlyph(this, (int)this, storage, v9, data, data->mColor, v44);
        return 1;
      }
      return 1;
    }
    v45 = 1;
  }
  if ( (meshGenFlags & 2) != 0 )
    LOBYTE(v45) = 1;
  GlyphShape = Scaleform::Render::GlyphCache::CreateGlyphShape(
                 this->pCache,
                 data,
                 glyphIndex,
                 v48,
                 fauxBold || (data->Param.TextParam.Flags & 8) != 0,
                 fauxItalic || (data->Param.TextParam.Flags & 0x10) != 0,
                 data->Param.TextParam.Flags >> 12,
                 0);
  v11 = *(_DWORD *)&data->Param.TextParam.Flags;
  v50 = GlyphShape;
  v12 = *(_DWORD *)&data->Param.TextParam.GlyphIndex;
  gp.pFont = data->Param.TextParam.pFont;
  v13 = *(_DWORD *)&data->Param.TextParam.BlurY;
  *(_DWORD *)&gp.GlyphIndex = v12;
  gp.pFont = data->pFontHandle;
  Flags = data->Param.TextParam.Flags;
  *(_DWORD *)&gp.BlurY = v13;
  *(_DWORD *)&gp.Flags = v11;
  gp.GlyphIndex = glyphIndex;
  if ( fauxBold || (Flags & 8) != 0 )
    gp.Flags |= 8u;
  else
    gp.Flags &= ~8u;
  if ( fauxItalic || (Flags & 0x10) != 0 )
    gp.Flags |= 0x10u;
  else
    gp.Flags &= ~0x10u;
  CachedFontSize = Scaleform::Render::GlyphCache::GetCachedFontSize(this->pCache, &gp, v48, data->pRaster != 0);
  LODWORD(rect.x1) = (int)floor(CachedFontSize * 16.0);
  gp.FontSize = LOWORD(rect.x1);
  RasterSize = data->RasterSize;
  if ( RasterSize )
    gp.Flags |= 0x200u;
  else
    gp.Flags &= ~0x200u;
  gp.Flags &= ~4u;
  if ( (gp.Flags & 1) != 0
    && (gp.Flags & 0x100) == 0
    && !data->VectorSize
    && !RasterSize
    && (gp.pFont->pFont->Flags & 0x80) == 0 )
  {
    rect.x1 = (double)gp.BlurX * 0.0625;
    if ( 0.0 == rect.x1 )
    {
      rect.x1 = 0.0625 * (double)gp.BlurY;
      if ( rect.x1 == 0.0 )
      {
        v18 = ((double (__thiscall *)(Scaleform::Render::Font *, _DWORD))gp.pFont->pFont->GetGlyphWidth)(
                gp.pFont->pFont,
                gp.GlyphIndex);
        pFont = gp.pFont->pFont;
        GetNominalGlyphHeight = pFont->GetNominalGlyphHeight;
        *(double *)&rect.x1 = v18 * v48;
        v21 = ((double (__thiscall *)(Scaleform::Render::Font *))GetNominalGlyphHeight)(pFont);
        pCache = this->pCache;
        MaxSlotHeight = pCache->Queue.MaxSlotHeight;
        rect.x1 = *(double *)&rect.x1 / v21;
        v24 = (double)(int)pCache->Queue.MaxSlotHeight;
        if ( MaxSlotHeight < 0 )
          v24 = v24 + 4294967300.0;
        if ( v24 > rect.x1 * 3.0 )
          gp.Flags |= 4u;
      }
    }
  }
  if ( this->pCache->GetParams(&this->pCache->Scaleform::Render::GlyphCacheConfig)->UseAutoFit
    && snap
    && (gp.Flags & 0xF000) == 0
    && (gp.Flags & 1) != 0
    && (gp.Flags & 2) != 0
    && v48 > 6.0
    && ((v25 = gp.pFont->pFont->Flags, (v25 & 0x2000) != 0) || (v25 & 0x10) != 0) )
  {
    gp.Flags |= 2u;
  }
  else
  {
    gp.Flags &= ~2u;
  }
  if ( (data->Param.ShadowParam.Flags & 0x20) != 0 )
  {
    if ( !(_BYTE)v45 )
      goto LABEL_66;
    goto LABEL_63;
  }
  if ( (_BYTE)v45 )
    goto LABEL_63;
  if ( (gp.Flags & 4) != 0 )
    v26 = 2.5;
  else
    v26 = 1.0;
  Glyph = Scaleform::Render::GlyphCache::FindGlyph(this->pCache, this, &gp);
  if ( Glyph
    || (gp.BlurX || gp.BlurY
      ? (Glyph = Scaleform::Render::GlyphCache::RasterizeShadow(
                   this->pCache,
                   *(float *)&snap,
                   COERCE_FLOAT(&savedregs),
                   data,
                   this,
                   &gp,
                   v48,
                   data->pRaster))
      : (Glyph = Scaleform::Render::GlyphCache::RasterizeGlyph(
                   this->pCache,
                   *(float *)&snap,
                   COERCE_FLOAT(&savedregs),
                   data,
                   this,
                   &gp)),
        Glyph) )
  {
    colora = v26;
    Scaleform::Render::TextMeshProvider::addRasterGlyph(
      this,
      storage,
      TextLayer_RasterText,
      data,
      data->mColor,
      Glyph,
      v48,
      snap,
      colora);
    goto LABEL_66;
  }
  v28 = this->pCache;
  v29 = v28->Result;
  if ( v29 == Res_ShapeNotFound )
  {
    mColor = data->mColor;
    rect.x1 = data->FontSize * 0.25;
    v49 = data->FontSize * 0.5;
    x1 = rect.x1;
    v32 = 0.5 * rect.x1;
    rect.x1 = data->NewLineX + v32;
    v33 = 0.25 * v49;
    rect.y1 = data->NewLineY - v49 - v33;
    rect.x2 = v32 + x1 + data->NewLineX;
    rect.y2 = data->NewLineY - v33;
    Scaleform::Render::TextMeshProvider::addSelection(this, storage, mColor, &rect);
    goto LABEL_78;
  }
  if ( v29 == Res_ShapeIsEmpty )
    goto LABEL_78;
  if ( v29 != Res_CacheFull )
  {
    if ( v29 != Res_ShapeIsTooBig && v29 != Res_NoRasterCache )
      goto LABEL_66;
    goto LABEL_63;
  }
  if ( v28->GetParams(&v28->Scaleform::Render::GlyphCacheConfig)->UseVectorOnFullCache )
  {
LABEL_63:
    if ( data->pShape && !data->pShape->IsEmpty(data->pShape) )
    {
      Scaleform::Render::TextMeshProvider::addVectorGlyph(
        this,
        storage,
        data->mColor,
        data->pFontHandle,
        glyphIndex,
        gp.Flags,
        data->FontSize,
        data->NewLineX,
        data->NewLineY);
      this->Flags |= 0x40u;
    }
LABEL_66:
    color = data->Param.ShadowColor;
    if ( !color || !HIBYTE(v45) )
      goto LABEL_78;
    v34 = *(_DWORD *)&data->Param.ShadowParam.GlyphIndex;
    v35 = *(_DWORD *)&data->Param.ShadowParam.Flags;
    gp.pFont = data->Param.ShadowParam.pFont;
    v36 = *(_DWORD *)&data->Param.ShadowParam.BlurY;
    *(_DWORD *)&gp.Flags = v35;
    *(_DWORD *)&gp.BlurY = v36;
    pFontHandle = data->pFontHandle;
    *(_DWORD *)&gp.GlyphIndex = v34;
    gp.pFont = pFontHandle;
    v38 = data->Param.TextParam.Flags;
    if ( fauxBold || (v38 & 8) != 0 )
      v39 = v35 & 0xFFF4 | 8;
    else
      v39 = v35 & 0xFFF4;
    if ( fauxItalic || (v38 & 0x10) != 0 )
      v40 = v39 | 0x10;
    else
      v40 = v39 & 0xFFEF;
    gp.Flags = v40;
    stretch = Scaleform::Render::GlyphCache::GetCachedShadowSize(this->pCache, v48, data->pRaster);
    Scaleform::Render::GlyphParam::SetFontSize(&gp, stretch);
    v41 = this->pCache;
    gp.GlyphIndex = glyphIndex;
    v42 = Scaleform::Render::GlyphCache::FindGlyph(v41, this, &gp);
    if ( v42
      || (v42 = Scaleform::Render::GlyphCache::RasterizeShadow(
                  this->pCache,
                  *(float *)&snap,
                  COERCE_FLOAT(&savedregs),
                  data,
                  this,
                  &gp,
                  v48,
                  data->pRaster)) != 0 )
    {
      Scaleform::Render::TextMeshProvider::addRasterGlyph(
        this,
        storage,
        TextLayer_Shadow,
        data,
        color,
        v42,
        v48,
        snap,
        1.0);
    }
    else if ( this->pCache->Result == Res_CacheFull )
    {
      goto LABEL_56;
    }
LABEL_78:
    if ( v50 )
      v50->Release(&v50->Scaleform::Render::MeshProvider);
    return 1;
  }
LABEL_56:
  if ( v50 )
    v50->Release(&v50->Scaleform::Render::MeshProvider);
  return 0;
}
