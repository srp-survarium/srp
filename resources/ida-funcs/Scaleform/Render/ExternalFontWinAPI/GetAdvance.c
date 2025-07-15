double __thiscall Scaleform::Render::ExternalFontWinAPI::GetAdvance(
        Scaleform::Render::ExternalFontWinAPI *this,
        unsigned int glyphIndex)
{
  Scaleform::Lock *pFontLock; // ebx
  double result; // st7
  float Advance; // [esp+Ch] [ebp+4h]

  if ( (unsigned __int16)glyphIndex == 0xFFFF )
  {
    this->GetNominalGlyphWidth(this);
  }
  else
  {
    pFontLock = this->pFontLock;
    EnterCriticalSection(&pFontLock->cs);
    Advance = this->Glyphs.Data.Data[glyphIndex].Advance;
    LeaveCriticalSection(&pFontLock->cs);
    return Advance;
  }
  return result;
}
