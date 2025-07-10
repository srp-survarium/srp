char __thiscall Scaleform::Render::ExternalFontWinAPI::GetTemporaryGlyphShape(
        Scaleform::Render::ExternalFontWinAPI *this,
        unsigned int glyphIndex,
        unsigned int hintedSize,
        Scaleform::Render::GlyphShape *shape)
{
  unsigned int v6; // ebp
  HFONT__ *MasterFont; // eax
  Scaleform::Render::ExternalFontWinAPI::GlyphType *v8; // edi
  HGDIOBJ v9; // eax
  Scaleform::Render::FontSysDataWinAPI *pSysData; // ecx
  Scaleform::Render::FontSysDataWinAPI *v11; // eax
  signed int GlyphOutlineW; // eax
  Scaleform::Render::FontSysDataWinAPI *v13; // ecx
  DWORD v14; // eax
  Scaleform::Lock *locker; // [esp+8h] [ebp-30h]
  void *g1_4; // [esp+10h] [ebp-28h]
  _MAT2 im; // [esp+14h] [ebp-24h] BYREF
  _GLYPHMETRICS gm; // [esp+24h] [ebp-14h] BYREF
  HDC__ *glyphIndexa; // [esp+3Ch] [ebp+4h]

  if ( (unsigned __int16)glyphIndex == 0xFFFF )
    return 0;
  v6 = hintedSize;
  if ( !this->IsHintedVectorGlyph(this, glyphIndex, hintedSize) )
  {
    v6 = 0;
    hintedSize = 0;
  }
  locker = this->pFontLock;
  EnterCriticalSection(&locker->cs);
  MasterFont = this->MasterFont;
  v8 = &this->Glyphs.Data.Data[glyphIndex];
  if ( v6 )
  {
    if ( v6 != this->LastHintedFontSize )
    {
      if ( this->HintedFont )
        DeleteObject(this->HintedFont);
      this->HintedFont = CreateFontW(
                           -v6,
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
      this->LastHintedFontSize = v6;
    }
    MasterFont = this->HintedFont;
  }
  glyphIndexa = this->pSysData->WinHDC;
  v9 = SelectObject(glyphIndexa, MasterFont);
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
                    v8->Code,
                    2u,
                    &gm,
                    v11->GlyphBuffer.Data.Size,
                    v11->GlyphBuffer.Data.Data,
                    &im);
  if ( GlyphOutlineW == -1 || (v13 = this->pSysData, GlyphOutlineW > (signed int)v13->GlyphBuffer.Data.Size) )
  {
    v14 = GetGlyphOutlineW(this->pSysData->WinHDC, v8->Code, 2u, &gm, 0, 0, &im);
    if ( v14 == -1 )
      goto LABEL_22;
    Scaleform::ArrayBase<Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>>::Resize(
      &this->pSysData->GlyphBuffer,
      v14 + 1016);
    GlyphOutlineW = GetGlyphOutlineW(
                      this->pSysData->WinHDC,
                      v8->Code,
                      2u,
                      &gm,
                      this->pSysData->GlyphBuffer.Data.Size,
                      this->pSysData->GlyphBuffer.Data.Data,
                      &im);
    if ( GlyphOutlineW == -1 )
      goto LABEL_22;
    v13 = this->pSysData;
    if ( GlyphOutlineW > (signed int)v13->GlyphBuffer.Data.Size )
      goto LABEL_22;
    v6 = hintedSize;
  }
  if ( !GlyphOutlineW
    || Scaleform::Render::ExternalFontWinAPI::decomposeGlyphOutline(
         this,
         v13->GlyphBuffer.Data.Data,
         GlyphOutlineW,
         shape,
         v6) )
  {
    SelectObject(glyphIndexa, g1_4);
    LeaveCriticalSection(&locker->cs);
    return 1;
  }
LABEL_22:
  SelectObject(glyphIndexa, g1_4);
  LeaveCriticalSection(&locker->cs);
  return 0;
}
