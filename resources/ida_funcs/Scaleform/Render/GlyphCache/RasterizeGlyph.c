Scaleform::Render::GlyphNode *__userpurge Scaleform::Render::GlyphCache::RasterizeGlyph@<eax>(
        Scaleform::Render::GlyphCache *this@<ecx>,
        float a2@<ebp>,
        float a3@<edi>,
        Scaleform::Render::GlyphRunData *data,
        Scaleform::Render::GlyphNode *tm,
        Scaleform::Render::GlyphParam *gp)
{
  int LowerCaseTop; // ebx
  double v10; // st7
  unsigned __int16 v11; // ax
  unsigned int HintedNomHeight; // eax
  unsigned int v13; // ebx
  unsigned int v14; // ebp
  unsigned int v15; // edi
  unsigned int v16; // eax
  unsigned int v17; // ecx
  unsigned int v18; // edi
  Scaleform::Render::GlyphNode *Glyph; // eax
  double v20; // st7
  unsigned int v21; // ebp
  unsigned __int8 *v22; // edi
  void (__thiscall *Clear)(struct Scaleform::Render::Rasterizer *); // edx
  unsigned __int8 *v24; // [esp-4h] [ebp-38h]
  float y2b; // [esp+18h] [ebp-1Ch]
  float y2; // [esp+18h] [ebp-1Ch]
  Scaleform::Render::Rasterizer *y2a; // [esp+18h] [ebp-1Ch]
  float stretch; // [esp+1Ch] [ebp-18h]
  float y1b; // [esp+20h] [ebp-14h]
  float y1c; // [esp+20h] [ebp-14h]
  float y1; // [esp+20h] [ebp-14h]
  unsigned int y1a; // [esp+20h] [ebp-14h]
  float scale; // [esp+28h] [ebp-Ch]
  float scalea; // [esp+28h] [ebp-Ch]
  __int16 scaleb; // [esp+28h] [ebp-Ch]
  int upperCaseTop; // [esp+2Ch] [ebp-8h]
  unsigned int upperCaseTopa; // [esp+2Ch] [ebp-8h]
  char autoFit; // [esp+38h] [ebp+4h]
  float autoFitb; // [esp+38h] [ebp+4h]
  float autoFitc; // [esp+38h] [ebp+4h]
  unsigned int autoFita; // [esp+38h] [ebp+4h]
  Scaleform::Render::GlyphNode *node; // [esp+3Ch] [ebp+8h]
  bool filter; // [esp+40h] [ebp+Ch]

  LowerCaseTop = 0;
  if ( this->MaxNumTextures )
  {
    if ( data->RasterSize )
    {
      return Scaleform::Render::GlyphCache::getPrerasterizedGlyph(
               this,
               data,
               (Scaleform::Render::TextMeshProvider *)tm,
               gp);
    }
    else if ( data->pShape )
    {
      upperCaseTop = 0;
      if ( !this->Param.UseAutoFit || (autoFit = 1, (gp->Flags & 2) == 0) )
        autoFit = 0;
      if ( (gp->Flags & 4) != 0 )
        v10 = 2.5;
      else
        v10 = 1.0;
      stretch = v10;
      if ( autoFit )
      {
        LowerCaseTop = (unsigned __int16)Scaleform::Render::Font::GetLowerCaseTop(gp->pFont->pFont, this);
        v11 = Scaleform::Render::Font::GetUpperCaseTop(gp->pFont->pFont, this);
        upperCaseTop = v11;
        if ( !LowerCaseTop || !v11 )
          autoFit = 0;
      }
      HintedNomHeight = data->HintedNomHeight;
      scale = data->NomHeight;
      if ( HintedNomHeight )
      {
        scale = (float)HintedNomHeight;
        autoFit = 0;
      }
      y1b = (double)gp->FontSize * 0.0625;
      scalea = y1b / scale;
      y1c = data->GlyphBounds.y1 * scalea;
      y1 = floor(y1c);
      y2b = data->GlyphBounds.y2 * scalea;
      y2 = ceil(y2b);
      if ( y2 <= (double)y1 )
      {
        y2 = 0.0;
        y1 = 0.0;
      }
      if ( (unsigned int)(__int64)(y2 - y1) + 2 * this->SlotPadding < this->MaxSlotHeight )
      {
        y2a = &this->Ras;
        ((void (*)(void))this->Ras.Clear)();
        if ( autoFit )
        {
          autoFitb = (double)gp->FontSize * 0.0625;
          Scaleform::Render::GlyphCache::addShapeAutoFit(
            this,
            (unsigned int *)LowerCaseTop,
            data->pShape,
            (__int64)data->NomHeight,
            LowerCaseTop,
            upperCaseTop,
            autoFitb,
            stretch);
        }
        else
        {
          autoFitc = scalea * stretch;
          Scaleform::Render::GlyphCache::addShapeToRasterizer(
            this,
            (unsigned int *)LowerCaseTop,
            (float *)gp,
            data->pShape,
            autoFitc,
            scalea,
            a3,
            a2);
        }
        v13 = 0;
        upperCaseTopa = this->SlotPadding;
        v14 = 0;
        v15 = 0;
        scaleb = 0;
        if ( Scaleform::Render::Rasterizer::SortCells(y2a) )
        {
          v16 = this->Ras.MinY - upperCaseTopa;
          v14 = this->Ras.MinX - upperCaseTopa;
          v15 = upperCaseTopa + this->Ras.MaxX;
          scaleb = v16;
          v13 = upperCaseTopa + this->Ras.MaxY;
        }
        else
        {
          v16 = 0;
        }
        v17 = v15 - v14 + 1;
        v18 = v13 - v16 + 1;
        autoFita = v17;
        y1a = v18;
        if ( v18 > this->MaxSlotHeight )
        {
          y1a = this->MaxSlotHeight;
          v18 = y1a;
        }
        Glyph = Scaleform::Render::GlyphCache::allocateGlyph(
                  this,
                  (Scaleform::Render::TextMeshProvider *)tm,
                  gp,
                  v17,
                  v18);
        node = Glyph;
        if ( Glyph )
        {
          Glyph->Scale = 1.0;
          Glyph->Origin.x = 16 * v14;
          Glyph->Origin.y = 16 * scaleb;
          Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
            &this->RasterData,
            autoFita * v18);
          v24 = this->RasterData.Data.Data;
          this->RasterPitch = autoFita;
          memset((int)v24, 0, autoFita * v18);
          v20 = 1.0;
          if ( 1.0 != this->Ras.Gamma1 )
          {
            Scaleform::Render::Rasterizer::SetGamma1(y2a, 1.0);
            v20 = 1.0;
          }
          filter = autoFita >= 5 && v20 < stretch;
          v21 = 0;
          if ( this->Ras.SortedYs.Size )
          {
            while ( upperCaseTopa + v21 < v18 )
            {
              v22 = &this->RasterData.Data.Data[(upperCaseTopa + v21) * this->RasterPitch];
              Scaleform::Render::Rasterizer::SweepScanline(y2a, v21, &v22[upperCaseTopa], 1u, 0);
              if ( filter )
                Scaleform::Render::GlyphCache::filterScanline(this, v22, autoFita);
              if ( ++v21 >= this->Ras.SortedYs.Size )
                break;
              v18 = y1a;
            }
          }
          Scaleform::Render::GlyphCache::updateTextureGlyph(this, node);
          Clear = y2a->Clear;
          ++this->RasterizationCount;
          Clear(y2a);
          return node;
        }
        else
        {
          this->Result = Res_CacheFull;
          Scaleform::Render::GlyphCache::cacheFullWarning(this);
          return 0;
        }
      }
      else
      {
        this->Result = Res_ShapeIsTooBig;
        return 0;
      }
    }
    else
    {
      this->Result = Res_ShapeNotFound;
      return 0;
    }
  }
  else
  {
    this->Result = Res_NoRasterCache;
    return 0;
  }
}
