bool __thiscall Scaleform::Render::Text::DocView::IsUrlAtPoint(
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
  const Scaleform::Render::Text::Paragraph::StyledTextRun *v20; // eax
  Scaleform::Render::Text::TextFormat *v21; // eax
  Scaleform::Render::Text::TextFormat *v22; // esi
  unsigned int v24; // [esp-Ch] [ebp-114h]
  bool rv; // [esp+Fh] [ebp-F9h]
  unsigned int indexInPara; // [esp+10h] [ebp-F8h] BYREF
  unsigned int posInDoc; // [esp+14h] [ebp-F4h]
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator paraIter; // [esp+18h] [ebp-F0h] BYREF
  Scaleform::Render::Text::Paragraph::FormatRunIterator v29; // [esp+20h] [ebp-E8h] BYREF
  Scaleform::Render::Text::LineBuffer::Iterator it; // [esp+44h] [ebp-C4h] BYREF
  Scaleform::Render::Text::TextFormat formatAtThePoint; // [esp+58h] [ebp-B0h] BYREF
  Scaleform::Render::Text::LineBuffer::GlyphIterator git; // [esp+80h] [ebp-88h] BYREF
  Scaleform::Render::Text::TextFormat result; // [esp+E0h] [ebp-28h] BYREF
  float xa; // [esp+10Ch] [ebp+4h]
  float ya; // [esp+110h] [ebp+8h]

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  xa = x - (this->mLineBuffer.Geom.VisibleRect.x1 - this->ViewRect.x1);
  ya = y - (this->mLineBuffer.Geom.VisibleRect.y1 - this->ViewRect.y1);
  *(float *)&posInDoc = (double)Scaleform::Render::Text::LineBuffer::GetVScrollOffsetInFixp(&this->mLineBuffer) + ya;
  Scaleform::Render::Text::LineBuffer::FindLineAtYOffset(&this->mLineBuffer, &it, *(float *)&posInDoc);
  rv = 0;
  if ( !it.pLineBuffer || it.CurrentPos >= it.pLineBuffer->Lines.Data.Size || (it.CurrentPos & 0x80000000) != 0 )
    return 0;
  v5 = it.pLineBuffer->Lines.Data.Data[it.CurrentPos];
  MemSize = v5->MemSize;
  indexInPara = v5->Data32.OffsetX;
  v7 = MemSize < 0;
  *(float *)&posInDoc = (float)(int)indexInPara;
  v8 = xa;
  v9 = *(float *)&posInDoc;
  if ( *(float *)&posInDoc > (double)xa )
    return 0;
  indexInPara = v7 ? v5->Data8.Width : v5->Data32.Width;
  if ( (double)(int)indexInPara + v9 < v8 )
    return 0;
  *(float *)&posInDoc = v8 - v9 + (double)this->mLineBuffer.Geom.HScrollOffset;
  v10 = 0;
  Scaleform::Render::Text::LineBuffer::Line::Begin(v5, &git);
  v11 = 0;
  while ( git.pGlyphs && git.pGlyphs < git.pEndGlyphs )
  {
    Advance = git.pGlyphs->Advance;
    if ( (git.pGlyphs->Flags & 0x40) != 0 )
      Advance = -Advance;
    indexInPara = Advance + v10;
    if ( *(float *)&posInDoc < (double)(unsigned int)(Advance + v10) )
    {
      v13 = LOBYTE(git.pGlyphs->Flags) >> 7;
      indexInPara = v11;
      rv = v13;
      if ( v13 && purlPosRange )
      {
        purlPosRange->Index = 0;
        purlPosRange->Length = 0;
        TextPos = v5->Data32.TextPos;
        if ( (v5->MemSize & 0x80000000) != 0 )
        {
          TextPos &= (unsigned int)&vostok::memory::s_CRT_arena[5574199];
          if ( (unsigned __int8 *)TextPos == &vostok::memory::s_CRT_arena[5574199] )
            TextPos = -1;
        }
        pObject = this->pDocument.pObject;
        v24 = indexInPara + TextPos;
        posInDoc = indexInPara + TextPos;
        indexInPara = 0;
        Scaleform::Render::Text::StyledText::GetParagraphByIndex(pObject, &paraIter, v24, &indexInPara);
        if ( paraIter.pArray )
        {
          if ( paraIter.CurIndex >= 0 && paraIter.CurIndex < (signed int)paraIter.pArray->Data.Size )
          {
            pPara = paraIter.pArray->Data.Data[paraIter.CurIndex].pPara;
            TextFormat = Scaleform::Render::Text::Paragraph::GetTextFormat(pPara, &result, indexInPara, indexInPara + 1);
            Scaleform::Render::Text::TextFormat::TextFormat(&formatAtThePoint, TextFormat, 0);
            Scaleform::Render::Text::TextFormat::~TextFormat(&result);
            Scaleform::Render::Text::Paragraph::GetIterator(pPara, &v29);
            while ( v29.CurTextIndex < v29.pText->Size )
            {
              v18 = pPara->StartIndex + Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v29)->Index;
              v19 = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v29)->pFormat.pObject;
              if ( (v19->PresentMask & 0x100) != 0
                && Scaleform::String::GetLength(&v19->Url)
                && (v20 = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v29),
                    Scaleform::String::operator==(&v20->pFormat.pObject->Url, &formatAtThePoint.Url)) )
              {
                if ( purlPosRange->Index + purlPosRange->Length >= v18 )
                {
                  purlPosRange->Length += Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v29)->Length;
                }
                else
                {
                  if ( v18 > posInDoc )
                    break;
                  purlPosRange->Index = v18;
                  purlPosRange->Length = Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(&v29)->Length;
                }
              }
              else
              {
                if ( v18 > posInDoc )
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
            Scaleform::Render::Text::TextFormat::~TextFormat(&formatAtThePoint);
          }
        }
      }
      break;
    }
    v11 += git.pGlyphs->LenAndFontSize >> 12;
    v10 += Advance;
    Scaleform::Render::Text::LineBuffer::GlyphIterator::operator++(&git);
  }
  if ( git.pImage.pObject )
    Scaleform::RefCountNTSImpl::Release(git.pImage.pObject);
  if ( git.pFontHandle.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)git.pFontHandle.pObject);
  return rv;
}
