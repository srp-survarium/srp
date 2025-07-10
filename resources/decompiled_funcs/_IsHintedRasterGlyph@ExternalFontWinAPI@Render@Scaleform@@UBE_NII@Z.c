char __thiscall Scaleform::Render::ExternalFontWinAPI::IsHintedRasterGlyph(
        Scaleform::Render::ExternalFontWinAPI *this,
        unsigned int glyphIndex,
        unsigned int hintedSize)
{
  Scaleform::Render::Font::NativeHintingRange RasterRange; // eax
  Scaleform::Lock *pFontLock; // ebp
  bool IsCJK; // bl

  if ( (unsigned __int16)glyphIndex == 0xFFFF )
    return 0;
  RasterRange = this->Hinting.RasterRange;
  if ( RasterRange == DontHint || hintedSize > this->Hinting.MaxRasterHintedSize )
    return 0;
  if ( RasterRange == HintAll )
    return 1;
  pFontLock = this->pFontLock;
  EnterCriticalSection(&pFontLock->cs);
  IsCJK = Scaleform::Render::Font::IsCJK(this, this->Glyphs.Data.Data[glyphIndex].Code);
  LeaveCriticalSection(&pFontLock->cs);
  return IsCJK;
}
