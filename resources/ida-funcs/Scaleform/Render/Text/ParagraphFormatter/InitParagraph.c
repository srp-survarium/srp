void __thiscall Scaleform::Render::Text::ParagraphFormatter::InitParagraph(
        Scaleform::Render::Text::ParagraphFormatter *this,
        const Scaleform::Render::Text::Paragraph *paragraph)
{
  Scaleform::Render::Text::DocView *pDocView; // ecx
  const Scaleform::Render::Text::GFxLineCursor *v4; // eax
  const Scaleform::Render::Text::GFxLineCursor *v5; // eax
  const Scaleform::Render::Text::GFxLineCursor *v6; // eax
  const Scaleform::Render::Text::GFxLineCursor *v7; // eax
  Scaleform::Render::Text::DocView *v8; // eax
  Scaleform::Render::Text::EditorKitBase *pObject; // eax
  Scaleform::GFx::Resource *v10; // eax
  Scaleform::Render::Text::CompositionStringBase *v11; // edi
  Scaleform::RefCountVImpl *v12; // ecx
  unsigned int v13; // eax
  Scaleform::Render::Text::CompositionStringBase *v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // edi
  Scaleform::Render::Text::LineBuffer::Line *TempLineBuff; // eax
  Scaleform::Render::Text::LineBuffer::Line *pDynLine; // eax
  Scaleform::Render::Text::LineBuffer::Line *v19; // eax
  Scaleform::Render::Text::LineBuffer::Line *pTempLine; // eax
  Scaleform::Render::Text::LineBuffer::Line *v21; // eax
  Scaleform::Render::Text::EditorKitBase *v22; // ecx
  unsigned int StartIndex; // edi
  Scaleform::Render::Text::LineBuffer::Line *v24; // ecx
  Scaleform::Render::Text::LineBuffer::Line *v25; // ecx
  unsigned int GlyphsCount; // ebp
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v27; // edi
  Scaleform::Render::Text::DocView *v28; // eax
  double v29; // st7
  unsigned int v30; // [esp+10h] [ebp-B0h]
  Scaleform::Render::Text::GFxLineCursor v31; // [esp+14h] [ebp-ACh] BYREF

  pDocView = this->pDocView;
  this->pParagraph = paragraph;
  this->pParaFormat = paragraph->pFormat.pObject;
  Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(&v31, pDocView, paragraph);
  Scaleform::Render::Text::GFxLineCursor::operator=(&this->LineCursor, v4);
  Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor(&v31);
  Scaleform::Render::Text::GFxLineCursor::GFxLineCursor(&v31);
  v6 = Scaleform::Render::Text::GFxLineCursor::operator=(&this->WordWrapPoint, v5);
  v7 = Scaleform::Render::Text::GFxLineCursor::operator=(&this->HalfPoint, v6);
  Scaleform::Render::Text::GFxLineCursor::operator=(&this->StartPoint, v7);
  Scaleform::Render::Text::GFxLineCursor::~GFxLineCursor(&v31);
  v8 = this->pDocView;
  this->LineCursor.FontScaleFactor = (double)this->pDocView->FontScaleFactor * 0.05000000074505806;
  pObject = v8->pEditorKit.pObject;
  if ( pObject && pObject->HasCompositionString(pObject) )
  {
    v10 = (Scaleform::GFx::Resource *)this->pDocView->pEditorKit.pObject->GetCompositionString(this->pDocView->pEditorKit.pObject);
    v11 = (Scaleform::Render::Text::CompositionStringBase *)v10;
    if ( v10 )
      Scaleform::RefCountImpl::AddRef(v10);
    v12 = (Scaleform::RefCountVImpl *)this->LineCursor.pComposStr.pObject;
    if ( v12 )
      Scaleform::RefCountImpl::Release(v12);
    this->LineCursor.pComposStr.pObject = v11;
    v13 = v11->GetPosition(v11);
    v14 = this->LineCursor.pComposStr.pObject;
    this->LineCursor.ComposStrPosition = v13;
    this->LineCursor.ComposStrLength = v14->GetLength(v14);
  }
  Scaleform::Render::Text::ParagraphFormatter::InitCustomWordWrapping(this);
  v15 = paragraph->Text.Size + this->LineCursor.ComposStrLength;
  v30 = v15;
  if ( (this->pParaFormat->PresentMask & 0x80u) != 0 && (this->pParaFormat->PresentMask & 0x8000) != 0 )
    v30 = ++v15;
  v16 = Scaleform::Render::Text::LineBuffer::CalcLineSize(v15, 2 * v15, Line32);
  if ( v16 >= 0x400 )
  {
    pDynLine = this->pDynLine;
    if ( pDynLine )
    {
      if ( v16 >= (pDynLine->MemSize & 0xFFFFFFF) )
      {
        Scaleform::Render::Text::LineBuffer::TextLineAllocator::FreeLine(
          &this->pDocView->mLineBuffer.LineAllocator,
          this->pDynLine);
        this->pDynLine = Scaleform::Render::Text::LineBuffer::TextLineAllocator::AllocLine(
                           &this->pDocView->mLineBuffer.LineAllocator,
                           v16 + 100,
                           Line32);
      }
      this->pTempLine = this->pDynLine;
    }
    else
    {
      v19 = Scaleform::Render::Text::LineBuffer::TextLineAllocator::AllocLine(
              &this->pDocView->mLineBuffer.LineAllocator,
              v16 + 100,
              Line32);
      this->pDynLine = v19;
      this->pTempLine = v19;
    }
  }
  else
  {
    TempLineBuff = (Scaleform::Render::Text::LineBuffer::Line *)this->TempLineBuff;
    if ( this == (Scaleform::Render::Text::ParagraphFormatter *)-1328 )
    {
      MEMORY[0xFFFFFADC] = 0;
      MEMORY[0] ^= (v16 ^ MEMORY[0]) & 0xFFFFFFF;
    }
    else
    {
      TempLineBuff->MemSize = 0;
      this->pTempLine = TempLineBuff;
      TempLineBuff->MemSize ^= (v16 ^ TempLineBuff->MemSize) & 0xFFFFFFF;
    }
  }
  pTempLine = this->pTempLine;
  pTempLine->MemSize = pTempLine->MemSize & 0xFFFFFFF | 0x40000000;
  pTempLine->Data32.BaseLineOffset = 0;
  pTempLine->Data32.GlyphsCount = 0;
  pTempLine->Data32.TextPos = 0;
  pTempLine->Data32.Leading = 0;
  pTempLine->Data32.OffsetY = 0;
  pTempLine->Data32.OffsetX = 0;
  pTempLine->Data32.Height = 0;
  pTempLine->Data32.Width = 0;
  pTempLine->Data32.TextLength = 0;
  this->pTempLine->MemSize &= ~0x40000000u;
  v21 = this->pTempLine;
  if ( (v21->MemSize & 0x80000000) == 0 )
    v21->Data32.GlyphsCount = v30;
  else
    v21->Data8.GlyphsCount = v30;
  v22 = this->pDocView->pEditorKit.pObject;
  if ( v22 )
    StartIndex = v22->TextPos2GlyphOffset(v22, paragraph->StartIndex);
  else
    StartIndex = paragraph->StartIndex;
  v24 = this->pTempLine;
  if ( (v24->MemSize & 0x80000000) == 0 )
    v24->Data32.TextPos = StartIndex;
  else
    v24->Data32.TextPos ^= (StartIndex ^ v24->Data32.TextPos) & 0xFFFFFF;
  v25 = this->pTempLine;
  if ( (v25->MemSize & 0x80000000) == 0 )
    GlyphsCount = v25->Data32.GlyphsCount;
  else
    GlyphsCount = v25->Data8.GlyphsCount;
  v27 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)(&v25->Data8.Leading + 1);
  if ( (v25->MemSize & 0x80000000) == 0 )
    v27 = (Scaleform::Render::Text::LineBuffer::GlyphEntry *)((char *)&v25->Data8 + 38);
  this->LineCursor.GlyphIns.pNextFormatData = Scaleform::Render::Text::LineBuffer::Line::GetFormatData(v25);
  this->LineCursor.GlyphIns.pGlyphs = v27;
  this->LineCursor.GlyphIns.GlyphIndex = 0;
  this->LineCursor.GlyphIns.GlyphsCount = GlyphsCount;
  this->LineCursor.GlyphIns.FormatDataIndex = 0;
  this->DeltaText = 1;
  this->Pass = 1;
  v28 = this->pDocView;
  this->ParaWidth = 0;
  this->ParaHeight = 0;
  this->ParaLines = 0;
  this->HyphenationRequested = 0;
  this->RequestedWordWrapPos = 0;
  this->isSpace = 0;
  v29 = v28->mLineBuffer.Geom.VisibleRect.x2 - v28->mLineBuffer.Geom.VisibleRect.x1;
  this->TabStopsNum = 0;
  this->TabStopsIndex = 0;
  this->TextRectWidth = v29;
}
