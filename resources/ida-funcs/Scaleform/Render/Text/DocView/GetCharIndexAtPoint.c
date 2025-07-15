int __thiscall Scaleform::Render::Text::DocView::GetCharIndexAtPoint(
        Scaleform::Render::Text::DocView *this,
        float x,
        float y)
{
  Scaleform::Render::Text::LineBuffer *p_mLineBuffer; // esi
  Scaleform::Render::Text::LineBuffer::Line *v5; // esi
  double v6; // st7
  double v7; // st6
  int v8; // ebx
  int v9; // edi
  int Advance; // eax
  int TextPos; // eax
  int v12; // esi
  int yoff; // [esp+8h] [ebp-7Ch]
  float OffsetX; // [esp+8h] [ebp-7Ch]
  int v16; // [esp+8h] [ebp-7Ch]
  float v17; // [esp+Ch] [ebp-78h]
  Scaleform::Render::Text::LineBuffer::Iterator result; // [esp+10h] [ebp-74h] BYREF
  Scaleform::Render::Text::LineBuffer::GlyphIterator v19; // [esp+24h] [ebp-60h] BYREF
  float v20; // [esp+88h] [ebp+4h]
  float v21; // [esp+8Ch] [ebp+8h]

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  p_mLineBuffer = &this->mLineBuffer;
  v20 = x - (p_mLineBuffer->Geom.VisibleRect.x1 - *(float *)&p_mLineBuffer[1].Lines.Data.Data);
  v21 = y - (p_mLineBuffer->Geom.VisibleRect.y1 - *(float *)&p_mLineBuffer[1].Lines.Data.Size);
  *(float *)&yoff = (double)(unsigned int)Scaleform::Render::Text::LineBuffer::GetVScrollOffsetInFixp(p_mLineBuffer)
                  + v21;
  Scaleform::Render::Text::LineBuffer::FindLineAtYOffset(p_mLineBuffer, &result, yoff);
  if ( !result.pLineBuffer )
    return -1;
  if ( result.CurrentPos >= result.pLineBuffer->Lines.Data.Size )
    return -1;
  if ( (result.CurrentPos & 0x80000000) != 0 )
    return -1;
  v5 = result.pLineBuffer->Lines.Data.Data[result.CurrentPos];
  OffsetX = (float)v5->Data32.OffsetX;
  v6 = v20;
  v7 = OffsetX;
  if ( OffsetX > (double)v20 )
    return -1;
  v16 = (v5->MemSize & 0x80000000) == 0 ? v5->Data32.Width : v5->Data8.Width;
  if ( (double)v16 + v7 < v6 )
    return -1;
  v8 = 0;
  Scaleform::Render::Text::LineBuffer::Line::Begin(v5, &v19);
  v9 = 0;
  while ( v19.pGlyphs && v19.pGlyphs < v19.pEndGlyphs )
  {
    Advance = v19.pGlyphs->Advance;
    if ( (v19.pGlyphs->Flags & 0x40) != 0 )
      Advance = -Advance;
    v8 += Advance;
    v17 = v6 - v7;
    if ( v17 < (double)v8 )
      break;
    v9 += v19.pGlyphs->LenAndFontSize >> 12;
    Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&v19);
  }
  TextPos = v5->Data32.TextPos;
  if ( (v5->MemSize & 0x80000000) != 0 )
  {
    TextPos &= 0xFFFFFFu;
    if ( TextPos == 0xFFFFFF )
      TextPos = -1;
  }
  v12 = TextPos + v9;
  if ( v19.pImage.pObject )
    Scaleform::RefCountNTSImpl::Release(v19.pImage.pObject);
  if ( v19.pFontHandle.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v19.pFontHandle.pObject);
  return v12;
}
