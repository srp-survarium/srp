bool __thiscall Scaleform::Render::ExternalFontWinAPI::GetGlyphRaster(
        Scaleform::Render::ExternalFontWinAPI *this,
        unsigned int glyphIndex,
        unsigned int hintedSize,
        Scaleform::Render::GlyphRaster *raster)
{
  bool result; // al
  Scaleform::Render::ExternalFontWinAPI::GlyphType *v7; // edi
  HDC__ *WinHDC; // ebx
  HGDIOBJ v9; // eax
  Scaleform::Render::FontSysDataWinAPI *pSysData; // ecx
  Scaleform::Render::FontSysDataWinAPI *v11; // eax
  signed int GlyphOutlineW; // eax
  Scaleform::Render::FontSysDataWinAPI *v13; // ecx
  DWORD v14; // eax
  void *g1_4; // [esp+Ch] [ebp-28h]
  _MAT2 im; // [esp+10h] [ebp-24h] BYREF
  _GLYPHMETRICS gm; // [esp+20h] [ebp-14h] BYREF
  Scaleform::Lock *locker; // [esp+38h] [ebp+4h]

  if ( (unsigned __int16)glyphIndex == 0xFFFF )
    return 0;
  result = this->IsHintedRasterGlyph(this, glyphIndex, hintedSize);
  if ( result )
  {
    locker = this->pFontLock;
    EnterCriticalSection(&locker->cs);
    v7 = &this->Glyphs.Data.Data[glyphIndex];
    if ( hintedSize != this->LastHintedFontSize )
    {
      if ( this->HintedFont )
        DeleteObject(this->HintedFont);
      this->HintedFont = CreateFontW(
                           -hintedSize,
                           0,
                           0,
                           0,
                           (this->Flags & 2) != 0 ? 700 : 400,
                           this->Flags & 1,
                           0,
                           0,
                           1u,
                           0,
                           0,
                           4u,
                           0,
                           this->NameW.Data.Data);
      this->LastHintedFontSize = hintedSize;
    }
    WinHDC = this->pSysData->WinHDC;
    v9 = SelectObject(WinHDC, this->HintedFont);
    pSysData = this->pSysData;
    g1_4 = v9;
    if ( !pSysData->GlyphBuffer.Data.Size )
      Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
        &pSysData->GlyphBuffer,
        0x3F8u);
    im.eM11.value = 1;
    memset(&im.eM12, 0, 10);
    im.eM22.value = 1;
    v11 = this->pSysData;
    im.eM11.fract = 0;
    GlyphOutlineW = GetGlyphOutlineW(
                      v11->WinHDC,
                      v7->Code,
                      1u,
                      &gm,
                      v11->GlyphBuffer.Data.Size,
                      v11->GlyphBuffer.Data.Data,
                      &im);
    if ( (GlyphOutlineW == -1 || (v13 = this->pSysData, GlyphOutlineW > (signed int)v13->GlyphBuffer.Data.Size))
      && ((v14 = GetGlyphOutlineW(this->pSysData->WinHDC, v7->Code, 1u, &gm, 0, 0, &im), v14 == -1)
       || (Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
             &this->pSysData->GlyphBuffer,
             v14 + 1016),
           GlyphOutlineW = GetGlyphOutlineW(
                             this->pSysData->WinHDC,
                             v7->Code,
                             1u,
                             &gm,
                             this->pSysData->GlyphBuffer.Data.Size,
                             this->pSysData->GlyphBuffer.Data.Data,
                             &im),
           GlyphOutlineW == -1)
       || (v13 = this->pSysData, GlyphOutlineW > (signed int)v13->GlyphBuffer.Data.Size)) )
    {
      SelectObject(WinHDC, g1_4);
      LeaveCriticalSection(&locker->cs);
      return 0;
    }
    else
    {
      if ( GlyphOutlineW )
      {
        Scaleform::Render::ExternalFontWinAPI::decomposeGlyphBitmap(
          this,
          v13->GlyphBuffer.Data.Data,
          gm.gmBlackBoxX,
          gm.gmBlackBoxY,
          gm.gmptGlyphOrigin.x,
          gm.gmptGlyphOrigin.y,
          raster);
      }
      else
      {
        raster->Width = 1;
        raster->Height = 1;
        Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
          &raster->Raster,
          1u);
        *raster->Raster.Data.Data = 0;
      }
      SelectObject(WinHDC, g1_4);
      LeaveCriticalSection(&locker->cs);
      return 1;
    }
  }
  return result;
}
