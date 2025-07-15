bool __thiscall Scaleform::Render::Text::DocView::GetExactCharBoundaries(
        Scaleform::Render::Text::DocView *this,
        Scaleform::Render::Rect<float> *pCharRect,
        unsigned int indexOfChar)
{
  unsigned int Length; // eax
  Scaleform::Render::Text::LineBuffer::Line *v5; // ebx
  int TextPos; // eax
  int i; // edi
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // ebp
  int v9; // eax
  Scaleform::Render::Font *pObject; // edi
  double FontSize; // st7
  int v12; // eax
  Scaleform::Render::Text::ImageDesc *v13; // edi
  bool rv; // [esp+Fh] [ebp-8Dh]
  int scale; // [esp+10h] [ebp-8Ch]
  float scaleb; // [esp+10h] [ebp-8Ch]
  float scalea; // [esp+10h] [ebp-8Ch]
  int scalec; // [esp+10h] [ebp-8Ch]
  int scaled; // [esp+10h] [ebp-8Ch]
  unsigned __int16 *p_Flags; // [esp+14h] [ebp-88h]
  float v22; // [esp+14h] [ebp-88h]
  float v23; // [esp+14h] [ebp-88h]
  float v24; // [esp+14h] [ebp-88h]
  Scaleform::Render::Point<float> pt; // [esp+18h] [ebp-84h] BYREF
  int advance; // [esp+20h] [ebp-7Ch]
  float Descent; // [esp+24h] [ebp-78h]
  Scaleform::Render::Text::LineBuffer::Iterator it; // [esp+28h] [ebp-74h] BYREF
  Scaleform::Render::Text::LineBuffer::GlyphIterator git; // [esp+3Ch] [ebp-60h] BYREF

  Length = Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject);
  if ( !pCharRect || indexOfChar > Length )
    return 0;
  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  Scaleform::Render::Text::LineBuffer::FindLineByTextPos(&this->mLineBuffer, &it, indexOfChar);
  rv = 0;
  if ( it.pLineBuffer && it.CurrentPos < it.pLineBuffer->Lines.Data.Size && (it.CurrentPos & 0x80000000) == 0 )
  {
    v5 = it.pLineBuffer->Lines.Data.Data[it.CurrentPos];
    TextPos = v5->Data32.TextPos;
    if ( (v5->MemSize & 0x80000000) != 0 )
    {
      TextPos &= (unsigned int)&vostok::memory::s_CRT_arena[5574199];
      if ( (unsigned __int8 *)TextPos == &vostok::memory::s_CRT_arena[5574199] )
        TextPos = -1;
    }
    scale = indexOfChar - TextPos;
    Scaleform::Render::Text::LineBuffer::Line::Begin(v5, &git);
    advance = 0;
    for ( i = 0; ; ++i )
    {
      pGlyphs = git.pGlyphs;
      if ( !git.pGlyphs || git.pGlyphs >= git.pEndGlyphs )
        goto LABEL_28;
      if ( i == scale )
        break;
      v9 = git.pGlyphs->Advance;
      if ( (git.pGlyphs->Flags & 0x40) != 0 )
        v9 = -v9;
      advance += v9;
      Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&git);
    }
    p_Flags = &git.pGlyphs->Flags;
    rv = 1;
    if ( (git.pGlyphs->Flags & 0x800) == 0 )
    {
      if ( git.pFontHandle.pObject )
        pObject = git.pFontHandle.pObject->pFont.pObject;
      else
        pObject = 0;
      FontSize = Scaleform::Render::Text::LineBuffer::GlyphEntry::GetFontSize(git.pGlyphs);
      LOWORD(v12) = pGlyphs->Index;
      scaleb = FontSize * 20.0;
      scalea = scaleb * 0.0009765625;
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
      pCharRect->x1 = pCharRect->x1 * scalea;
      pCharRect->x2 = scalea * pCharRect->x2;
      v24 = Scaleform::Render::Text::LineBuffer::Line::GetBaseLineOffset(v5) - pObject->Ascent * scalea + 40.0;
      pCharRect->y1 = v24;
      pt.x = scalea * (Descent + pt.x);
      pCharRect->y2 = v24 + pt.x;
      scalec = v5->Data32.OffsetY;
      pt.x = (double)advance + 40.0;
      pt.y = (float)scalec;
      Scaleform::Render::Rect<float>::operator+=(pCharRect, &pt);
LABEL_28:
      v13 = git.pImage.pObject;
      goto LABEL_29;
    }
    v13 = git.pImage.pObject;
    pCharRect->x1 = -git.pImage.pObject->BaseLineX;
    pCharRect->y1 = -v13->BaseLineY;
    pCharRect->x2 = v13->ScreenWidth + pCharRect->x1;
    pCharRect->y2 = v13->ScreenHeight + pCharRect->y1;
    scaled = v5->Data32.OffsetY;
    pt.x = (double)advance + 40.0;
    pt.y = (double)scaled + 40.0;
    Scaleform::Render::Rect<float>::operator+=(pCharRect, &pt);
LABEL_29:
    if ( v13 )
      Scaleform::RefCountNTSImpl::Release(v13);
    if ( git.pFontHandle.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)git.pFontHandle.pObject);
  }
  return rv;
}
