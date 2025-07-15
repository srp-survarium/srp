Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::ExternalFontWinAPI::GetGlyphBounds(
        Scaleform::Render::ExternalFontWinAPI *this,
        unsigned int glyphIndex,
        Scaleform::Render::Rect<float> *prect)
{
  Scaleform::Render::Rect<float> *result; // eax
  Scaleform::Lock *pFontLock; // ebx
  Scaleform::Render::ExternalFontWinAPI::GlyphType *Data; // ecx
  unsigned int v7; // edi
  float v8; // [esp+8h] [ebp-8h]
  float x2; // [esp+8h] [ebp-8h]
  float y2; // [esp+Ch] [ebp-4h]
  float glyphIndexa; // [esp+14h] [ebp+4h]
  float glyphIndexb; // [esp+14h] [ebp+4h]

  if ( (unsigned __int16)glyphIndex == 0xFFFF )
  {
    glyphIndexa = this->GetNominalGlyphWidth(this);
    v8 = this->GetNominalGlyphHeight(this);
    result = prect;
    prect->x1 = 0.0;
    prect->y1 = 0.0;
    prect->x2 = glyphIndexa;
    prect->y2 = v8;
  }
  else
  {
    pFontLock = this->pFontLock;
    EnterCriticalSection(&pFontLock->cs);
    Data = this->Glyphs.Data.Data;
    v7 = glyphIndex;
    glyphIndexb = Data[glyphIndex].Bounds.y1;
    x2 = Data[v7].Bounds.x2;
    y2 = Data[v7].Bounds.y2;
    prect->x1 = Data[v7].Bounds.x1;
    prect->y1 = glyphIndexb;
    prect->x2 = x2;
    prect->y2 = y2;
    LeaveCriticalSection(&pFontLock->cs);
    return prect;
  }
  return result;
}
