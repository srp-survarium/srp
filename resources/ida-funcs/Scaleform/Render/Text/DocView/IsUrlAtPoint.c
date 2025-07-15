char __thiscall Scaleform::Render::Text::DocView::IsUrlAtPoint(
        Scaleform::Render::Text::DocView *this,
        float x,
        float y,
        Scaleform::Range *purlPosRange)
{
  Scaleform::Render::Text::LineBuffer::Line *v5; // ebp
  int MemSize; // ecx
  bool v7; // cl
  double v8; // st7
  double v9; // st6
  int v10; // esi
  unsigned int v11; // edi
  int Advance; // eax
  char v13; // cl
  int TextPos; // eax
  Scaleform::Render::Text::DocView::DocumentText *pObject; // ecx
  Scaleform::Render::Text::Paragraph *pPara; // ebp
  const Scaleform::Render::Text::TextFormat *TextFormat; // eax
  unsigned int v18; // esi
  Scaleform::Render::Text::TextFormat *v19; // eax
  Scaleform::Render::Text::Paragraph::FormatRunIterator *v20; // eax
  Scaleform::Render::Text::TextFormat *v21; // eax
  Scaleform::Render::Text::TextFormat *v22; // esi
  unsigned int v24; // [esp-Ch] [ebp-114h]
  char v25; // [esp+Fh] [ebp-F9h]
  unsigned int pindexInParagraph; // [esp+10h] [ebp-F8h] BYREF
  unsigned int yoff; // [esp+14h] [ebp-F4h]
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator v28; // [esp+18h] [ebp-F0h] BYREF
  Scaleform::Render::Text::Paragraph::FormatRunIterator v29; // [esp+20h] [ebp-E8h] BYREF
  Scaleform::Render::Text::LineBuffer::Iterator result; // [esp+44h] [ebp-C4h] BYREF
  Scaleform::Render::Text::TextFormat v31; // [esp+58h] [ebp-B0h] BYREF
  Scaleform::Render::Text::LineBuffer::GlyphIterator v32; // [esp+80h] [ebp-88h] BYREF
  Scaleform::Render::Text::TextFormat v33; // [esp+E0h] [ebp-28h] BYREF
  float v34; // [esp+10Ch] [ebp+4h]
  float v35; // [esp+110h] [ebp+8h]

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  v34 = x - (this->mLineBuffer.Geom.VisibleRect.x1 - this->ViewRect.x1);
  v35 = y - (this->mLineBuffer.Geom.VisibleRect.y1 - this->ViewRect.y1);
  *(float *)&yoff = (double)(unsigned int)Scaleform::Render::Text::LineBuffer::GetVScrollOffsetInFixp(&this->mLineBuffer)
                  + v35;
  Scaleform::Render::Text::LineBuffer::FindLineAtYOffset(&this->mLineBuffer, &result, yoff);
  v25 = 0;
  if ( !result.pLineBuffer
    || result.CurrentPos >= result.pLineBuffer->Lines.Data.Size
    || (result.CurrentPos & 0x80000000) != 0 )
  {
    return 0;
  }
  v5 = result.pLineBuffer->Lines.Data.Data[result.CurrentPos];
  MemSize = v5->MemSize;
  pindexInParagraph = v5->Data32.OffsetX;
  v7 = MemSize < 0;
  *(float *)&yoff = (float)(int)pindexInParagraph;
  v8 = v34;
  v9 = *(float *)&yoff;
  if ( *(float *)&yoff > (double)v34 )
    return 0;
  pindexInParagraph = v7 ? v5->Data8.Width : v5->Data32.Width;
  if ( (double)(int)pindexInParagraph + v9 < v8 )
    return 0;
  *(float *)&yoff = v8 - v9 + (double)this->mLineBuffer.Geom.HScrollOffset;
  v10 = 0;
  Scaleform::Render::Text::LineBuffer::Line::Begin(v5, &v32);
  v11 = 0;
  while ( v32.pGlyphs && v32.pGlyphs < v32.pEndGlyphs )
  {
    Advance = v32.pGlyphs->Advance;
    if ( (v32.pGlyphs->Flags & 0x40) != 0 )
      Advance = -Advance;
    pindexInParagraph = Advance + v10;
    if ( *(float *)&yoff < (double)(unsigned int)(Advance + v10) )
    {
      v13 = LOBYTE(v32.pGlyphs->Flags) >> 7;
      pindexInParagraph = v11;
      v25 = v13;
      if ( v13 && purlPosRange )
      {
        purlPosRange->Index = 0;
        purlPosRange->Length = 0;
        TextPos = v5->Data32.TextPos;
        if ( (v5->MemSize & 0x80000000) != 0 )
        {
          TextPos &= 0xFFFFFFu;
          if ( TextPos == 0xFFFFFF )
            TextPos = -1;
        }
        pObject = this->pDocument.pObject;
        v24 = pindexInParagraph + TextPos;
        yoff = pindexInParagraph + TextPos;
        pindexInParagraph = 0;
        Scaleform::Render::Text::StyledText::GetParagraphByIndex(pObject, &v28, v24, &pindexInParagraph);
        if ( v28.pArray )
        {
          if ( v28.CurIndex >= 0 && v28.CurIndex < (signed int)v28.pArray->Data.Size )
          {
            pPara = v28.pArray->Data.Data[v28.CurIndex].pPara;
            TextFormat = Scaleform::Render::Text::Paragraph::GetTextFormat(
                           pPara,
                           &v33,
                           pindexInParagraph,
                           pindexInParagraph + 1);
            Scaleform::Render::Text::TextFormat::TextFormat(&v31, TextFormat, 0);
            Scaleform::Render::Text::TextFormat::~TextFormat(&v33);
            Scaleform::Render::Text::Paragraph::GetIterator(pPara, &v29);
            while ( v29.CurTextIndex < v29.pText->Size )
            {
              v18 = pPara->StartIndex
                  + Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v29)->PlaceHolder.Index;
              v19 = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v29)->PlaceHolder.pFormat.pObject;
              if ( (v19->PresentMask & 0x100) != 0
                && Scaleform::String::GetLength(&v19->Url)
                && (v20 = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v29),
                    Scaleform::String::operator==(&v20->PlaceHolder.pFormat.pObject->Url, &v31.Url)) )
              {
                if ( purlPosRange->Index + purlPosRange->Length >= v18 )
                {
                  purlPosRange->Length += Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v29)->PlaceHolder.Length;
                }
                else
                {
                  if ( v18 > yoff )
                    break;
                  purlPosRange->Index = v18;
                  purlPosRange->Length = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v29)->PlaceHolder.Length;
                }
              }
              else
              {
                if ( v18 > yoff )
                  break;
                purlPosRange->Index = 0;
                purlPosRange->Length = 0;
              }
              Scaleform::Render::Text::Paragraph::FormatRunIterator::operator++(&v29);
            }
            v21 = v29.PlaceHolder.pFormat.pObject;
            if ( v29.PlaceHolder.pFormat.pObject )
            {
              --v29.PlaceHolder.pFormat.pObject->RefCount;
              v22 = v21;
              if ( !v21->RefCount )
              {
                Scaleform::Render::Text::TextFormat::~TextFormat(v21);
                Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v22);
              }
            }
            Scaleform::Render::Text::TextFormat::~TextFormat(&v31);
          }
        }
      }
      break;
    }
    v11 += v32.pGlyphs->LenAndFontSize >> 12;
    v10 += Advance;
    Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&v32);
  }
  if ( v32.pImage.pObject )
    Scaleform::RefCountNTSImpl::Release(v32.pImage.pObject);
  if ( v32.pFontHandle.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v32.pFontHandle.pObject);
  return v25;
}
