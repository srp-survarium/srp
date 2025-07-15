char __thiscall Scaleform::Render::Text::ParagraphFormatter::HandleCustomWordWrap(
        Scaleform::Render::Text::ParagraphFormatter *this)
{
  Scaleform::Render::Text::FontHandle *pObject; // ecx
  int Pass; // eax
  const Scaleform::Render::Text::Paragraph::TextBuffer *pText; // eax
  double LineWidth; // st7
  Scaleform::Render::Font *v6; // edi
  unsigned int NumChars; // ebx
  unsigned int TextBufLen; // edx
  Scaleform::Render::Text::LineBuffer::Line *pTempLine; // eax
  int MemSize; // ecx
  int TextPos; // eax
  const Scaleform::Render::Text::ParagraphFormat *pParaFormat; // ecx
  int v13; // eax
  Scaleform::Render::Text::Allocator *Allocator; // eax
  unsigned int GlyphIndex; // ecx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pGlyphs; // ebx
  unsigned int v17; // edx
  unsigned __int16 *p_Advance; // edi
  int v19; // eax
  int v20; // eax
  unsigned __int16 *v21; // edi
  float *v22; // ecx
  int v23; // edx
  double v24; // st6
  unsigned int v25; // edx
  int v26; // eax
  bool v27; // zf
  Scaleform::Render::Text::DocView *pDocView; // eax
  unsigned int v29; // ecx
  const Scaleform::Render::Text::Paragraph::TextBuffer *v30; // eax
  const Scaleform::Render::Text::Paragraph::TextBuffer *v31; // eax
  unsigned int v32; // ecx
  Scaleform::Render::Text::DocView::DocumentText *v33; // ebx
  Scaleform::MemoryHeap *v34; // edi
  Scaleform::Render::Text::Allocator *v35; // eax
  Scaleform::Render::Text::Allocator *v36; // eax
  Scaleform::Render::Text::Allocator *v37; // edi
  Scaleform::RefCountNTSImpl *v38; // ecx
  const Scaleform::Render::Text::GFxLineCursor *v39; // eax
  const Scaleform::Render::Text::GFxLineCursor *v40; // eax
  Scaleform::Render::Text::TextFormat *v41; // eax
  Scaleform::Render::Text::TextFormat *v42; // edi
  Scaleform::Render::Text::TextFormat *v43; // eax
  Scaleform::Render::Text::TextFormat *v44; // edi
  const Scaleform::Render::Text::GFxLineCursor *v46; // eax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v47; // ebx
  double LastAdvance; // st7
  double v49; // st7
  int v50; // eax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pPrevGrec; // ecx
  int v52; // eax
  unsigned int v53; // edi
  Scaleform::Render::Text::FontHandle *v54; // eax
  double v55; // st7
  Scaleform::Render::Font *pFont; // ecx
  double v57; // st7
  double v58; // st7
  double v59; // st7
  int v60; // ecx
  unsigned int v61; // eax
  float v62; // [esp+4016h] [ebp-510h]
  float v63; // [esp+4016h] [ebp-510h]
  float v64; // [esp+4016h] [ebp-510h]
  unsigned int v65; // [esp+401Ah] [ebp-50Ch]
  float v66; // [esp+401Ah] [ebp-50Ch]
  float v67; // [esp+401Ah] [ebp-50Ch]
  unsigned int v68; // [esp+401Eh] [ebp-508h]
  bool v69; // [esp+4025h] [ebp-501h]
  _BYTE *v70; // [esp+4026h] [ebp-500h]
  unsigned int v71; // [esp+402Ah] [ebp-4FCh]
  float v72; // [esp+402Ah] [ebp-4FCh]
  unsigned __int16 *v73; // [esp+402Eh] [ebp-4F8h]
  int v74; // [esp+4032h] [ebp-4F4h]
  _DWORD v75[4]; // [esp+4036h] [ebp-4F0h] BYREF
  unsigned int v76; // [esp+4046h] [ebp-4E0h]
  float TextRectWidth; // [esp+404Ah] [ebp-4DCh]
  float v78; // [esp+404Eh] [ebp-4D8h]
  float v79; // [esp+4052h] [ebp-4D4h]
  float v80; // [esp+4056h] [ebp-4D0h]
  char v81; // [esp+405Ah] [ebp-4CCh]
  int v82; // [esp+405Eh] [ebp-4C8h]
  float v83; // [esp+4062h] [ebp-4C4h]
  float v84[5]; // [esp+4066h] [ebp-4C0h] BYREF
  Scaleform::Render::Text::GFxLineCursor v85; // [esp+407Ah] [ebp-4ACh] BYREF
  _BYTE v86[1024]; // [esp+4126h] [ebp-400h] BYREF

  pObject = this->LineCursor.pLastFont.pObject;
  if ( pObject )
  {
    Pass = this->Pass;
    if ( Pass == 1 && this->HasLineFormatHandler )
    {
      pText = this->WordWrapPoint.CharIter.pText;
      if ( pText && this->WordWrapPoint.CharIter.CurTextIndex < pText->Size )
      {
        LineWidth = (double)this->WordWrapPoint.LineWidth;
        v6 = this->WordWrapPoint.pLastFont.pObject->pFont.pObject;
        NumChars = this->WordWrapPoint.NumChars;
      }
      else
      {
        LineWidth = (double)this->LineCursor.LineWidth;
        v6 = pObject->pFont.pObject;
        NumChars = this->LineCursor.NumChars;
      }
      TextBufLen = this->TextBufLen;
      pTempLine = this->pTempLine;
      v75[0] = this->pTextBufForCustomFormat;
      v75[1] = TextBufLen;
      MemSize = pTempLine->MemSize;
      TextPos = pTempLine->Data32.TextPos;
      v65 = NumChars;
      if ( MemSize < 0 )
      {
        TextPos &= (unsigned int)&vostok::memory::s_CRT_arena[5574199];
        if ( (unsigned __int8 *)TextPos == &vostok::memory::s_CRT_arena[5574199] )
          TextPos = -1;
      }
      pParaFormat = this->pParaFormat;
      v75[3] = TextPos - this->pParagraph->StartIndex;
      v76 = this->LineCursor.NumChars;
      switch ( (pParaFormat->PresentMask >> 9) & 3 )
      {
        case 0:
          v81 = 0;
          break;
        case 1:
          v81 = 1;
          break;
        case 2:
          v81 = 3;
          break;
        case 3:
          v81 = 2;
          break;
        default:
          break;
      }
      TextRectWidth = this->TextRectWidth;
      v78 = (float)this->LineCursor.LineWidth;
      v62 = LineWidth;
      v79 = v62;
      v13 = v6->GetGlyphIndex(v6, 45u);
      if ( v13 > 0 )
        v80 = v6->GetGlyphWidth(v6, v13);
      v82 = NumChars;
      v70 = v86;
      if ( v76 + 1 > 0x100 )
      {
        Allocator = Scaleform::Render::Text::StyledText::GetAllocator(this->pDocView->pDocument.pObject);
        v70 = Allocator->pHeap->Alloc(Allocator->pHeap, 4 * v76 + 4, 0);
      }
      GlyphIndex = this->LineCursor.GlyphIns.GlyphIndex;
      pGlyphs = this->LineCursor.GlyphIns.pGlyphs;
      v63 = 0.0;
      v17 = 0;
      if ( GlyphIndex )
      {
        p_Advance = &pGlyphs->Advance;
        do
        {
          if ( (p_Advance[1] & 0xF000) != 0 )
            break;
          v19 = *p_Advance;
          if ( (p_Advance[2] & 0x40) != 0 )
            v19 = -v19;
          ++v17;
          p_Advance += 4;
          v63 = (double)v19 + v63;
        }
        while ( v17 < GlyphIndex );
      }
      v75[2] = v70;
      v20 = 0;
      v74 = 0;
      TextRectWidth = TextRectWidth - v63;
      v78 = v78 - v63;
      v79 = v79 - v63;
      v64 = 0.0;
      if ( v17 < GlyphIndex )
      {
        v21 = &pGlyphs[v17].Advance;
        v73 = v21;
        v71 = GlyphIndex - v17;
        do
        {
          v22 = (float *)&v70[4 * v20];
          *v22 = v64;
          v23 = *v21;
          if ( (v21[2] & 0x40) != 0 )
            v23 = -v23;
          v24 = v64 + (double)v23;
          v25 = v21[1] >> 12;
          v68 = v25;
          v64 = v24;
          if ( v25 > 1 )
          {
            v26 = v20;
            do
            {
              this->pTextBufForCustomFormat[v26] = 160;
              *v22 = 0.0;
              ++v26;
              ++v22;
              --v25;
            }
            while ( v25 );
            v21 = v73;
            v25 = v68;
            v20 = v74;
          }
          v20 += v25;
          v21 += 4;
          v27 = v71-- == 1;
          v74 = v20;
          v73 = v21;
        }
        while ( !v27 );
      }
      *(float *)&v70[4 * v20] = v64;
      pDocView = this->pDocView;
      LOBYTE(v83) = 0;
      v69 = pDocView->pDocumentListener.pObject->View_OnLineFormat(
              pDocView->pDocumentListener.pObject,
              pDocView,
              (Scaleform::Render::Text::DocView::LineFormatDesc *)v75);
      if ( v69 )
      {
        this->HyphenationRequested = LOBYTE(v83);
        v29 = v82;
        if ( !v82 )
        {
          v29 = 1;
          v82 = 1;
        }
        if ( v29 != v65 )
        {
          v30 = this->WordWrapPoint.CharIter.pText;
          if ( v30 && this->WordWrapPoint.CharIter.CurTextIndex < v30->Size && v29 > this->WordWrapPoint.NumChars )
          {
            Scaleform::Render::Text::LineBuffer::GlyphInserter::ResetTo(
              &this->LineCursor.GlyphIns,
              &this->WordWrapPoint.GlyphIns);
            Scaleform::Render::Text::GFxLineCursor::operator=(&this->LineCursor, &this->WordWrapPoint);
          }
          else
          {
            v31 = this->HalfPoint.CharIter.pText;
            if ( v31 && this->HalfPoint.CharIter.CurTextIndex < v31->Size && v29 > this->HalfPoint.NumChars )
            {
              Scaleform::Render::Text::LineBuffer::GlyphInserter::ResetTo(
                &this->LineCursor.GlyphIns,
                &this->HalfPoint.GlyphIns);
              Scaleform::Render::Text::GFxLineCursor::operator=(&this->LineCursor, &this->HalfPoint);
            }
            else
            {
              Scaleform::Render::Text::LineBuffer::GlyphInserter::ResetTo(
                &this->LineCursor.GlyphIns,
                &this->StartPoint.GlyphIns);
              Scaleform::Render::Text::GFxLineCursor::operator=(&this->LineCursor, &this->StartPoint);
            }
          }
          v32 = v82;
          this->Pass = 2;
          this->RequestedWordWrapPos = v32;
          this->DeltaText = 0;
        }
      }
      if ( v70 != v86 )
      {
        v33 = this->pDocView->pDocument.pObject;
        if ( !v33->pTextAllocator.pObject )
        {
          v34 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(
                  Scaleform::Memory::pGlobalHeap,
                  this->pDocView->pDocument.pObject);
          v35 = (Scaleform::Render::Text::Allocator *)v34->Alloc(v34, 76u, 0);
          if ( v35 )
          {
            Scaleform::Render::Text::Allocator::Allocator(v35, v34, 0);
            v37 = v36;
          }
          else
          {
            v37 = 0;
          }
          v38 = v33->pTextAllocator.pObject;
          if ( v38 )
            Scaleform::RefCountNTSImpl::Release(v38);
          v33->pTextAllocator.pObject = v37;
        }
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v70);
      }
      Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(&v85);
      v40 = Scaleform::Render::Text::GFxLineCursor::operator=(&this->HalfPoint, v39);
      Scaleform::Render::Text::GFxLineCursor::operator=(&this->StartPoint, v40);
      v41 = v85.CharInfoHolder.pFormat.pObject;
      if ( v85.CharInfoHolder.pFormat.pObject )
      {
        --v85.CharInfoHolder.pFormat.pObject->RefCount;
        v42 = v41;
        if ( !v41->RefCount )
        {
          Scaleform::Render::Text::TextFormat::~TextFormat(v41);
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v42);
        }
      }
      v43 = v85.CharIter.PlaceHolder.pFormat.pObject;
      if ( v85.CharIter.PlaceHolder.pFormat.pObject )
      {
        --v85.CharIter.PlaceHolder.pFormat.pObject->RefCount;
        v44 = v43;
        if ( !v43->RefCount )
        {
          Scaleform::Render::Text::TextFormat::~TextFormat(v43);
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v44);
        }
      }
      if ( v85.pComposStr.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v85.pComposStr.pObject);
      if ( v85.pLastFont.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v85.pLastFont.pObject);
      if ( v69 && this->Pass == 2 )
        return 1;
    }
    else if ( Pass == 2 )
    {
      Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(&v85);
      Scaleform::Render::Text::GFxLineCursor::operator=(&this->WordWrapPoint, v46);
      Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor(&v85);
      this->Pass = 1;
    }
    if ( this->HyphenationRequested )
    {
      v47 = &this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex];
      v47->Flags = 0;
      v47->LenAndFontSize = 0;
      LastAdvance = this->LineCursor.LastAdvance;
      if ( LastAdvance <= 0.0 )
        v49 = LastAdvance - 0.5;
      else
        v49 = LastAdvance + 0.5;
      v50 = (int)v49;
      pPrevGrec = this->LineCursor.pPrevGrec;
      if ( pPrevGrec )
      {
        if ( v50 < 0 )
        {
          v50 = -v50;
          pPrevGrec->Flags |= 0x40u;
        }
        else
        {
          pPrevGrec->Flags &= ~0x40u;
        }
        pPrevGrec->Advance = v50;
      }
      v52 = this->LineCursor.pLastFont.pObject->pFont.pObject->GetGlyphIndex(
              this->LineCursor.pLastFont.pObject->pFont.pObject,
              45u);
      v47->LenAndFontSize &= 0xFFFu;
      v53 = v52;
      v47->Index = v52;
      Scaleform::Render::Text::LineBuffer::GlyphEntry::SetFontSize(v47, this->FontSize);
      v54 = this->LineCursor.pLastFont.pObject;
      this->LineCursor.LineWidth = this->NewLineWidth;
      v55 = ((double (__thiscall *)(Scaleform::Render::Font *, unsigned int))v54->pFont.pObject->GetAdvance)(
              v54->pFont.pObject,
              v53);
      pFont = this->pFont;
      v66 = v55 * this->Scale;
      v84[0] = 0.0;
      v84[1] = 0.0;
      v84[2] = 0.0;
      v84[3] = 0.0;
      v72 = pFont->GetGlyphBounds(pFont, v53, (Scaleform::Render::Rect<float> *)v84)->x2 * this->Scale + 20.0;
      v57 = v66;
      if ( v72 > (double)v66 )
        v57 = v72;
      v67 = v57;
      v58 = v67;
      if ( v67 <= 0.0 )
        v59 = v58 - 0.5;
      else
        v59 = v58 + 0.5;
      this->LineCursor.pLastFont.pObject->pFont.pObject->GetGlyphWidth(
        this->LineCursor.pLastFont.pObject->pFont.pObject,
        v53);
      v60 = (int)v59 + this->NewLineWidth;
      this->LineCursor.LastAdvance = (float)(int)v59;
      this->LineCursor.LastGlyphWidth = (int)v59;
      this->LineCursor.LastGlyphIndex = v53;
      this->LineCursor.NumOfTrailingSpaces = 0;
      this->LineCursor.LineWidthWithoutTrailingSpaces = v60;
      this->HyphenationRequested = 0;
      this->LineCursor.pPrevGrec = v47;
      if ( this->LineCursor.GlyphIns.pGlyphs )
      {
        v61 = this->LineCursor.GlyphIns.GlyphIndex;
        if ( v61 < this->LineCursor.GlyphIns.GlyphsCount )
          this->LineCursor.GlyphIns.GlyphIndex = v61 + 1;
      }
    }
  }
  return 0;
}
