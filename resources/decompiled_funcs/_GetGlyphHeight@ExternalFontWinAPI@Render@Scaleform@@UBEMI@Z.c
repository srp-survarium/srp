double __thiscall Scaleform::Render::ExternalFontWinAPI::GetGlyphHeight(
        Scaleform::Render::ExternalFontWinAPI *this,
        unsigned int glyphIndex)
{
  Scaleform::Lock *pFontLock; // edi
  double result; // st7
  float glyphIndexa; // [esp+Ch] [ebp+4h]

  if ( (unsigned __int16)glyphIndex == 0xFFFF )
  {
    this->GetNominalGlyphHeight(this);
  }
  else
  {
    pFontLock = this->pFontLock;
    EnterCriticalSection(&pFontLock->cs);
    glyphIndexa = this->Glyphs.Data.Data[glyphIndex].Bounds.y2 - this->Glyphs.Data.Data[glyphIndex].Bounds.y1;
    LeaveCriticalSection(&pFontLock->cs);
    return glyphIndexa;
  }
  return result;
}
