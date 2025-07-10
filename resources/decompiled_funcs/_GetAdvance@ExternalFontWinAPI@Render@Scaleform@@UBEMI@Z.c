double __thiscall Scaleform::Render::ExternalFontWinAPI::GetAdvance(
        Scaleform::Render::ExternalFontWinAPI *this,
        unsigned int glyphIndex)
{
  Scaleform::Lock *pFontLock; // ebx
  double result; // st7
  float glyphIndexa; // [esp+Ch] [ebp+4h]

  if ( (unsigned __int16)glyphIndex == 0xFFFF )
  {
    this->GetNominalGlyphWidth(this);
  }
  else
  {
    pFontLock = this->pFontLock;
    EnterCriticalSection(&pFontLock->cs);
    glyphIndexa = this->Glyphs.Data.Data[glyphIndex].Advance;
    LeaveCriticalSection(&pFontLock->cs);
    return glyphIndexa;
  }
  return result;
}
