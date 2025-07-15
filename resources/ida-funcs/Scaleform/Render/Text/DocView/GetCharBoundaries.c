char __thiscall Scaleform::Render::Text::DocView::GetCharBoundaries(
        Scaleform::Render::Text::DocView *this,
        Scaleform::Render::Rect<float> *pCharRect,
        unsigned int indexOfChar)
{
  Scaleform::Render::Text::LineBuffer::Line *v4; // ebp
  int TextPos; // eax
  int v6; // ebx
  float v7; // esi
  int i; // edi
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // eax
  int v10; // eax
  bool v11; // zf
  double v12; // st7
  char v14; // [esp+Bh] [ebp-81h]
  float v15; // [esp+Ch] [ebp-80h]
  int Advance; // [esp+Ch] [ebp-80h]
  int Height; // [esp+Ch] [ebp-80h]
  int OffsetY; // [esp+Ch] [ebp-80h]
  Scaleform::Render::Point<float> pt; // [esp+10h] [ebp-7Ch] BYREF
  Scaleform::Render::Text::LineBuffer::Iterator result; // [esp+18h] [ebp-74h] BYREF
  Scaleform::Render::Text::LineBuffer::GlyphIterator v21; // [esp+2Ch] [ebp-60h] BYREF

  if ( !pCharRect || indexOfChar >= Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject) )
    return 0;
  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  Scaleform::Render::Text::LineBuffer::FindLineByTextPos(&this->mLineBuffer, &result, indexOfChar);
  v14 = 0;
  if ( result.pLineBuffer
    && result.CurrentPos < result.pLineBuffer->Lines.Data.Size
    && (result.CurrentPos & 0x80000000) == 0 )
  {
    v4 = result.pLineBuffer->Lines.Data.Data[result.CurrentPos];
    TextPos = v4->Data32.TextPos;
    if ( (v4->MemSize & 0x80000000) != 0 )
    {
      TextPos &= 0xFFFFFFu;
      if ( TextPos == 0xFFFFFF )
        TextPos = -1;
    }
    v6 = indexOfChar - TextPos;
    Scaleform::Render::Text::LineBuffer::Line::Begin(v4, &v21);
    v7 = 0.0;
    for ( i = 0; ; ++i )
    {
      pGlyphs = v21.pGlyphs;
      if ( !v21.pGlyphs || v21.pGlyphs >= v21.pEndGlyphs )
        break;
      if ( i == v6 )
      {
        v11 = (v21.pGlyphs->Flags & 0x100) == 0;
        pt.x = v7;
        if ( v11 )
        {
          pCharRect->x1 = 0.0;
          v14 = 1;
          pCharRect->y1 = 0.0;
          v15 = 0.0 + 0.0;
          v12 = v15;
          pCharRect->x2 = v15;
          pCharRect->y2 = v15;
          if ( (pGlyphs->Flags & 0x40) != 0 )
            Advance = -pGlyphs->Advance;
          else
            Advance = pGlyphs->Advance;
          pCharRect->x2 = v12 + (double)Advance;
          pCharRect->y1 = 40.0;
          if ( (v4->MemSize & 0x80000000) == 0 )
            Height = v4->Data32.Height;
          else
            Height = v4->Data8.Height;
          pCharRect->y2 = (float)Height;
          OffsetY = v4->Data32.OffsetY;
          pt.x = (double)SLODWORD(pt.x) + 40.0;
          pt.y = (float)OffsetY;
          Scaleform::Render::Rect<float>::operator+=(pCharRect, &pt);
        }
        break;
      }
      v10 = v21.pGlyphs->Advance;
      if ( (v21.pGlyphs->Flags & 0x40) != 0 )
        v10 = -v10;
      LODWORD(v7) += v10;
      Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&v21);
    }
    if ( v21.pImage.pObject )
      Scaleform::RefCountNTSImpl::Release(v21.pImage.pObject);
    if ( v21.pFontHandle.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v21.pFontHandle.pObject);
  }
  return v14;
}
