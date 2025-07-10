char __thiscall Scaleform::Render::ExternalFontWinAPI::IsHintedVectorGlyph(
        Scaleform::Render::ExternalFontWinAPI *this,
        unsigned int glyphIndex,
        unsigned int hintedSize)
{
  Scaleform::Render::Font::NativeHintingRange VectorRange; // eax
  Scaleform::Lock *pFontLock; // ebp
  bool IsCJK; // bl

  if ( (unsigned __int16)glyphIndex == 0xFFFF )
    return 0;
  VectorRange = this->Hinting.VectorRange;
  if ( VectorRange == DontHint || hintedSize > this->Hinting.MaxVectorHintedSize )
    return 0;
  if ( VectorRange == HintAll )
    return 1;
  pFontLock = this->pFontLock;
  EnterCriticalSection(&pFontLock->cs);
  IsCJK = Scaleform::Render::Font::IsCJK(this, this->Glyphs.Data.Data[glyphIndex].Code);
  LeaveCriticalSection(&pFontLock->cs);
  return IsCJK;
}
