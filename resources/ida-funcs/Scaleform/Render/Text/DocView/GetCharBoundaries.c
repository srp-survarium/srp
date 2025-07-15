bool __thiscall Scaleform::Render::Text::DocView::GetCharBoundaries(
        Scaleform::Render::Text::DocView *this,
        Scaleform::Render::Rect<float> *pCharRect,
        unsigned int indexOfChar)
{
  Scaleform::Render::Text::LineBuffer::Line *v4; // ebp
  int TextPos; // eax
  int v6; // ebx
  int v7; // esi
  int i; // edi
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // eax
  int v10; // eax
  bool v11; // zf
  double v12; // st7
  bool rv; // [esp+Bh] [ebp-81h]
  float v15; // [esp+Ch] [ebp-80h]
  int v16; // [esp+Ch] [ebp-80h]
  int Height; // [esp+Ch] [ebp-80h]
  int OffsetY; // [esp+Ch] [ebp-80h]
  int advance[2]; // [esp+10h] [ebp-7Ch] BYREF
  Scaleform::Render::Text::LineBuffer::Iterator it; // [esp+18h] [ebp-74h] BYREF
  Scaleform::Render::Text::LineBuffer::GlyphIterator git; // [esp+2Ch] [ebp-60h] BYREF

  if ( !pCharRect || indexOfChar >= Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject) )
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
    v4 = it.pLineBuffer->Lines.Data.Data[it.CurrentPos];
    TextPos = v4->Data32.TextPos;
    if ( (v4->MemSize & 0x80000000) != 0 )
    {
      TextPos &= (unsigned int)&vostok::memory::s_CRT_arena[5574199];
      if ( (unsigned __int8 *)TextPos == &vostok::memory::s_CRT_arena[5574199] )
        TextPos = -1;
    }
    v6 = indexOfChar - TextPos;
    Scaleform::Render::Text::LineBuffer::Line::Begin(v4, &git);
    v7 = 0;
    for ( i = 0; ; ++i )
    {
      pGlyphs = git.pGlyphs;
      if ( !git.pGlyphs || git.pGlyphs >= git.pEndGlyphs )
        break;
      if ( i == v6 )
      {
        v11 = (git.pGlyphs->Flags & 0x100) == 0;
        advance[0] = v7;
        if ( v11 )
        {
          pCharRect->x1 = 0.0;
          rv = 1;
          pCharRect->y1 = 0.0;
          v15 = 0.0 + 0.0;
          v12 = v15;
          pCharRect->x2 = v15;
          pCharRect->y2 = v15;
          if ( (pGlyphs->Flags & 0x40) != 0 )
            v16 = -pGlyphs->Advance;
          else
            v16 = pGlyphs->Advance;
          pCharRect->x2 = v12 + (double)v16;
          pCharRect->y1 = 40.0;
          if ( (v4->MemSize & 0x80000000) == 0 )
            Height = v4->Data32.Height;
          else
            Height = v4->Data8.Height;
          pCharRect->y2 = (float)Height;
          OffsetY = v4->Data32.OffsetY;
          *(float *)advance = (double)advance[0] + 40.0;
          *(float *)&advance[1] = (float)OffsetY;
          Scaleform::Render::Rect<float>::operator+=(pCharRect, (const Scaleform::Render::Point<float> *)advance);
        }
        break;
      }
      v10 = git.pGlyphs->Advance;
      if ( (git.pGlyphs->Flags & 0x40) != 0 )
        v10 = -v10;
      v7 += v10;
      Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&git);
    }
    if ( git.pImage.pObject )
      Scaleform::RefCountNTSImpl::Release(git.pImage.pObject);
    if ( git.pFontHandle.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)git.pFontHandle.pObject);
  }
  return rv;
}
