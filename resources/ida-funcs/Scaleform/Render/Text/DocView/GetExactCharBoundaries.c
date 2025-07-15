char __thiscall Scaleform::Render::Text::DocView::GetExactCharBoundaries(
        Scaleform::Render::Text::DocView *this,
        Scaleform::Render::Rect<float> *pCharRect,
        unsigned int indexOfChar)
{
  unsigned int Length; // eax
  Scaleform::Render::Text::LineBuffer::Line *v5; // ebx
  int TextPos; // eax
  int i; // edi
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // ebp
  int Advance; // eax
  Scaleform::Render::Font *pObject; // edi
  double FontSize; // st7
  int v12; // eax
  Scaleform::Render::Text::ImageDesc *v13; // edi
  char v15; // [esp+Fh] [ebp-8Dh]
  int v16; // [esp+10h] [ebp-8Ch]
  float v17; // [esp+10h] [ebp-8Ch]
  float v18; // [esp+10h] [ebp-8Ch]
  int OffsetY; // [esp+10h] [ebp-8Ch]
  int v20; // [esp+10h] [ebp-8Ch]
  unsigned __int16 *p_Flags; // [esp+14h] [ebp-88h]
  float v22; // [esp+14h] [ebp-88h]
  float v23; // [esp+14h] [ebp-88h]
  float v24; // [esp+14h] [ebp-88h]
  Scaleform::Render::Point<float> pt; // [esp+18h] [ebp-84h] BYREF
  int v26; // [esp+20h] [ebp-7Ch]
  float Descent; // [esp+24h] [ebp-78h]
  Scaleform::Render::Text::LineBuffer::Iterator result; // [esp+28h] [ebp-74h] BYREF
  Scaleform::Render::Text::LineBuffer::GlyphIterator v29; // [esp+3Ch] [ebp-60h] BYREF

  Length = Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject);
  if ( !pCharRect || indexOfChar > Length )
    return 0;
  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  Scaleform::Render::Text::LineBuffer::FindLineByTextPos(&this->mLineBuffer, &result, indexOfChar);
  v15 = 0;
  if ( result.pLineBuffer
    && result.CurrentPos < result.pLineBuffer->Lines.Data.Size
    && (result.CurrentPos & 0x80000000) == 0 )
  {
    v5 = result.pLineBuffer->Lines.Data.Data[result.CurrentPos];
    TextPos = v5->Data32.TextPos;
    if ( (v5->MemSize & 0x80000000) != 0 )
    {
      TextPos &= 0xFFFFFFu;
      if ( TextPos == 0xFFFFFF )
        TextPos = -1;
    }
    v16 = indexOfChar - TextPos;
    Scaleform::Render::Text::LineBuffer::Line::Begin(v5, &v29);
    v26 = 0;
    for ( i = 0; ; ++i )
    {
      pGlyphs = v29.pGlyphs;
      if ( !v29.pGlyphs || v29.pGlyphs >= v29.pEndGlyphs )
        goto LABEL_28;
      if ( i == v16 )
        break;
      Advance = v29.pGlyphs->Advance;
      if ( (v29.pGlyphs->Flags & 0x40) != 0 )
        Advance = -Advance;
      v26 += Advance;
      Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&v29);
    }
    p_Flags = &v29.pGlyphs->Flags;
    v15 = 1;
    if ( (v29.pGlyphs->Flags & 0x800) == 0 )
    {
      if ( v29.pFontHandle.pObject )
        pObject = v29.pFontHandle.pObject->pFont.pObject;
      else
        pObject = 0;
      FontSize = Scaleform::Render::Text::LineBuffer::GlyphEntry::GetFontSize(v29.pGlyphs);
      LOWORD(v12) = pGlyphs->Index;
      v17 = FontSize * 20.0;
      v18 = v17 * 0.0009765625;
      if ( pGlyphs->Index == 0xFFFF )
        v12 = -1;
      else
        v12 = (unsigned __int16)v12;
      pObject->GetGlyphBounds(pObject, v12, pCharRect);
      if ( (*((_BYTE *)p_Flags + 1) & 1) != 0 )
      {
        v22 = pCharRect->x2 - pCharRect->x1;
        v23 = v22 / 3.0;
        pCharRect->x2 = v23 + pCharRect->x1;
      }
      pt.x = pObject->Ascent;
      Descent = pObject->Descent;
      pCharRect->x1 = pCharRect->x1 * v18;
      pCharRect->x2 = v18 * pCharRect->x2;
      v24 = Scaleform::Render::Text::LineBuffer::Line::GetBaseLineOffset(v5) - pObject->Ascent * v18 + 40.0;
      pCharRect->y1 = v24;
      pt.x = v18 * (Descent + pt.x);
      pCharRect->y2 = v24 + pt.x;
      OffsetY = v5->Data32.OffsetY;
      pt.x = (double)v26 + 40.0;
      pt.y = (float)OffsetY;
      Scaleform::Render::Rect<float>::operator+=(pCharRect, &pt);
LABEL_28:
      v13 = v29.pImage.pObject;
      goto LABEL_29;
    }
    v13 = v29.pImage.pObject;
    pCharRect->x1 = -v29.pImage.pObject->BaseLineX;
    pCharRect->y1 = -v13->BaseLineY;
    pCharRect->x2 = v13->ScreenWidth + pCharRect->x1;
    pCharRect->y2 = v13->ScreenHeight + pCharRect->y1;
    v20 = v5->Data32.OffsetY;
    pt.x = (double)v26 + 40.0;
    pt.y = (double)v20 + 40.0;
    Scaleform::Render::Rect<float>::operator+=(pCharRect, &pt);
LABEL_29:
    if ( v13 )
      Scaleform::RefCountNTSImpl::Release(v13);
    if ( v29.pFontHandle.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v29.pFontHandle.pObject);
  }
  return v15;
}
