void __thiscall Scaleform::Render::Text::ParagraphFormatter::Format(
        Scaleform::Render::Text::ParagraphFormatter *this,
        const Scaleform::Render::Text::Paragraph *paragraph)
{
  const Scaleform::Render::Text::ParagraphFormat *pParaFormat; // eax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v4; // ebx
  Scaleform::Render::Text::TextFormat *pObject; // eax
  Scaleform::GFx::Resource *Font; // eax
  unsigned __int16 v7; // ax
  double ActualFontSize; // st7
  unsigned int ColorV; // ebx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v10; // eax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v11; // eax
  unsigned int GlyphIndex; // eax
  Scaleform::RefCountVImpl *v13; // ecx
  Scaleform::Render::Text::ParagraphFormat *v14; // ecx
  const Scaleform::Render::Text::Paragraph::TextBuffer *pText; // eax
  const Scaleform::Render::Text::Paragraph::CharacterInfo *v16; // ebx
  bool v17; // zf
  const wchar_t *RemainingTextPtr; // eax
  Scaleform::Render::Text::ImageDesc *ImageDesc; // eax
  Scaleform::Render::Text::TextFormat *v20; // ecx
  Scaleform::Render::Text::HTMLImageTagDesc *v21; // eax
  Scaleform::Render::Text::FontHandle *v22; // edi
  bool v23; // al
  wchar_t Character; // cx
  bool v25; // al
  Scaleform::GFx::Resource *v26; // ecx
  Scaleform::RefCountVImpl *v27; // ecx
  Scaleform::GFx::Resource *v28; // eax
  Scaleform::Render::Text::FontHandle *v29; // edi
  Scaleform::RefCountVImpl *v30; // ecx
  double v31; // st7
  Scaleform::Render::Text::DocView *pDocView; // ecx
  wchar_t v33; // ax
  int v34; // eax
  Scaleform::Render::Text::TextFormat *pCurrentFormat; // edi
  unsigned __int16 PresentMask; // bx
  unsigned __int8 FormatFlags; // al
  Scaleform::StringDH *FontList; // eax
  Scaleform::Render::Text::DocView::DocumentListener *v39; // ecx
  const Scaleform::String *v40; // eax
  unsigned int v41; // ebx
  unsigned int v42; // edi
  unsigned int v43; // ebx
  Scaleform::StringDH *v44; // eax
  double v45; // st7
  double v46; // st6
  int v47; // eax
  Scaleform::Render::Font *v48; // ecx
  double v49; // rt2
  double v50; // st6
  double v51; // st7
  double v52; // st5
  int v53; // eax
  double v54; // st5
  double v55; // st5
  double v56; // rt0
  double GlyphAdvance; // st5
  bool v58; // c0
  bool v59; // c3
  double v60; // st6
  double v61; // st7
  double v62; // st6
  double v63; // st5
  double v64; // st6
  int v65; // edi
  double v66; // st5
  double v67; // st5
  double v68; // st7
  double v69; // st7
  Scaleform::Render::Text::LineBuffer::GlyphEntry *pPrevGrec; // eax
  int LastAdvance; // ecx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v72; // edi
  Scaleform::Render::Text::CompositionStringBase *v73; // ecx
  unsigned int v74; // ebx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v75; // eax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v76; // eax
  double v77; // st7
  double v78; // st6
  double v79; // st7
  int NewLineWidth; // eax
  int v81; // eax
  const Scaleform::Render::Text::TextFormat *v82; // eax
  Scaleform::RefCountVImpl *v83; // ebx
  Scaleform::GFx::Resource *v84; // ecx
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v85; // eax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v86; // eax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v87; // eax
  Scaleform::Render::Text::LineBuffer::GlyphEntry *v88; // eax
  wchar_t v89; // ax
  int v90; // edx
  Scaleform::Render::Font *v91; // ecx
  bool IsEmpty; // al
  const Scaleform::Render::Text::TextFormat *v93; // eax
  Scaleform::GFx::Resource *v94; // ecx
  Scaleform::RefCountVImpl *v95; // ecx
  const Scaleform::Render::Text::TextFormat *v96; // edx
  unsigned int TabStopsIndex; // ecx
  int v98; // eax
  int v99; // ecx
  int v100; // eax
  double v101; // st7
  unsigned int LenAndFontSize; // eax
  int v103; // edx
  double v104; // st7
  unsigned int v105; // eax
  unsigned int v106; // ecx
  const Scaleform::Render::Text::TextFormat *v107; // eax
  unsigned int v108; // eax
  wchar_t *pTextBufForCustomFormat; // eax
  float scale_4; // [esp+5C8h] [ebp-94h]
  Scaleform::GFx::Resource *pfont; // [esp+5E0h] [ebp-7Ch]
  Scaleform::Render::Text::FontHandle *pfonta; // [esp+5E0h] [ebp-7Ch]
  unsigned int v113; // [esp+5E4h] [ebp-78h]
  const Scaleform::Render::Text::Paragraph::CharacterInfo *v114; // [esp+5E8h] [ebp-74h]
  char *pData; // [esp+5ECh] [ebp-70h]
  float v116; // [esp+5ECh] [ebp-70h]
  Scaleform::String v117; // [esp+5F0h] [ebp-6Ch] BYREF
  Scaleform::String v118; // [esp+5F4h] [ebp-68h] BYREF
  Scaleform::RefCountVImpl *TextRectWidth_low; // [esp+5F8h] [ebp-64h]
  unsigned int plen; // [esp+5FCh] [ebp-60h] BYREF
  unsigned int ptextLen; // [esp+600h] [ebp-5Ch] BYREF
  bool v122[4]; // [esp+604h] [ebp-58h]
  bool device[4]; // [esp+608h] [ebp-54h]
  bool italic[4]; // [esp+60Ch] [ebp-50h]
  bool bold[4]; // [esp+610h] [ebp-4Ch]
  Scaleform::String v126; // [esp+614h] [ebp-48h] BYREF
  Scaleform::String v127; // [esp+618h] [ebp-44h] BYREF
  float FontScaleFactor; // [esp+61Ch] [ebp-40h]
  unsigned int *TabStops; // [esp+620h] [ebp-3Ch]
  float v130; // [esp+628h] [ebp-34h]
  Scaleform::Render::Rect<float> v131; // [esp+62Ch] [ebp-30h] BYREF
  Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo v132; // [esp+640h] [ebp-1Ch] BYREF

  v113 = 0;
  Scaleform::Render::Text::ParagraphFormatter::InitParagraph(this, paragraph);
  pParaFormat = this->pParaFormat;
  this->LineCursor.LeftMargin = 0;
  if ( (pParaFormat->PresentMask & 0x80u) != 0 && (pParaFormat->PresentMask & 0x8000) != 0 )
  {
    v4 = &this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex];
    v4->LenAndFontSize = 0;
    v4->Flags = 0;
    pObject = Scaleform::Render::Text::GFxLineCursor::operator*(&this->LineCursor)->pFormat.pObject;
    this->FindFontInfo.pCurrentFormat = pObject;
    if ( pObject )
    {
      Font = (Scaleform::GFx::Resource *)Scaleform::Render::Text::DocView::FindFont(
                                           this->pDocView,
                                           &this->FindFontInfo,
                                           0);
      pfont = Font;
      if ( Font )
        Scaleform::RefCountImpl::AddRef(Font);
      v7 = (*((int (__thiscall **)(Scaleform::GFx::Resource_vtbl *, int))pfont[2].~Scaleform::GFx::Resource + 2))(
             pfont[2].__vftable,
             8226);
      v4->Flags &= ~0x40u;
      v4->Index = v7;
      v4->Advance = 300;
      ActualFontSize = Scaleform::Render::Text::ParagraphFormatter::GetActualFontSize(this);
      *(float *)&TextRectWidth_low = (ActualFontSize + ActualFontSize) / 3.0;
      Scaleform::Render::Text::LineBuffer::GlyphEntry::SetFontSize(v4, *(float *)&TextRectWidth_low);
      v4->LenAndFontSize &= 0xFFFu;
      ColorV = this->FindFontInfo.pCurrentFormat->ColorV;
      Scaleform::Render::Text::LineBuffer::GlyphInserter::AddFont(&this->LineCursor.GlyphIns, pfont);
      v10 = &this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex];
      v10->Flags |= 0x4000u;
      v11 = &this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex];
      v11->Flags |= 0x1000u;
      this->LineCursor.GlyphIns.pNextFormatData[this->LineCursor.GlyphIns.FormatDataIndex++].ColorV = ColorV;
      if ( this->LineCursor.GlyphIns.pGlyphs )
      {
        GlyphIndex = this->LineCursor.GlyphIns.GlyphIndex;
        if ( GlyphIndex < this->LineCursor.GlyphIns.GlyphsCount )
          this->LineCursor.GlyphIns.GlyphIndex = GlyphIndex + 1;
      }
      Scaleform::RefCountImpl::AddRef(pfont);
      v13 = (Scaleform::RefCountVImpl *)this->LineCursor.pLastFont.pObject;
      if ( v13 )
        Scaleform::RefCountImpl::Release(v13);
      this->LineCursor.pLastFont.pObject = (Scaleform::Render::Text::FontHandle *)pfont;
      this->LineCursor.LastColor = ColorV;
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pfont);
    }
    this->LineCursor.LeftMargin = 700;
    this->LineCursor.LineWidth = 700;
    this->LineCursor.Indent = -300;
  }
  else
  {
    this->LineCursor.Indent = 20 * pParaFormat->Indent;
  }
  v14 = (Scaleform::Render::Text::ParagraphFormat *)this->pParaFormat;
  this->LineCursor.LeftMargin += 20 * (v14->BlockIndent + v14->LeftMargin);
  this->LineCursor.RightMargin = 20 * v14->RightMargin;
  TabStops = Scaleform::Render::Text::ParagraphFormat::GetTabStops(v14, &this->TabStopsNum);
  pfonta = 0;
  while ( 1 )
  {
    pText = this->LineCursor.CharIter.pText;
    if ( !pText || this->LineCursor.CharIter.CurTextIndex >= pText->Size )
      break;
    v16 = Scaleform::Render::Text::GFxLineCursor::operator*(&this->LineCursor);
    v114 = v16;
    if ( this->Pass == 1 )
    {
      if ( (this->pDocView->Flags & 8) != 0
        && !pfonta
        && Scaleform::Render::Text::WordWrapHelper::IsLineBreakOpportunityAt(
             7u,
             this->LineCursor.LastCharCode,
             v16->Character) )
      {
        Scaleform::Render::Text::GFxLineCursor::operator=(&this->WordWrapPoint, &this->LineCursor);
      }
      if ( this->Pass == 1 && this->HasLineFormatHandler )
      {
        v17 = this->LineCursor.LineWidth == 0;
        TextRectWidth_low = (Scaleform::RefCountVImpl *)LODWORD(this->TextRectWidth);
        if ( v17 && !this->StartPoint.pDocView )
          Scaleform::Render::Text::GFxLineCursor::operator=(&this->StartPoint, &this->LineCursor);
        if ( *(float *)&TextRectWidth_low * 0.5 < (double)this->LineCursor.LineWidth && !this->HalfPoint.pDocView )
          Scaleform::Render::Text::GFxLineCursor::operator=(&this->HalfPoint, &this->LineCursor);
      }
    }
    this->DeltaText = 1;
    if ( pfonta )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)pfonta);
    pfonta = 0;
    if ( !this->pDocView->pImageSubstitutor )
      goto LABEL_37;
    RemainingTextPtr = Scaleform::Render::Text::Paragraph::CharactersIterator::GetRemainingTextPtr(
                         &this->LineCursor.CharIter,
                         &plen);
    ImageDesc = Scaleform::Render::Text::DocView::ImageSubstitutor::FindImageDesc(
                  this->pDocView->pImageSubstitutor,
                  RemainingTextPtr,
                  plen,
                  &ptextLen);
    if ( ImageDesc )
      ++ImageDesc->RefCount;
    pfonta = (Scaleform::Render::Text::FontHandle *)ImageDesc;
    if ( ImageDesc )
    {
      this->DeltaText = ptextLen;
    }
    else
    {
LABEL_37:
      v20 = v16->pFormat.pObject;
      if ( v16->pFormat.pObject && (v20->PresentMask & 0x200) != 0 && v16->Character )
      {
        v21 = Scaleform::Render::Text::TextFormat::GetImageDesc(v20);
        v22 = (Scaleform::Render::Text::FontHandle *)v21;
        if ( v21 )
          ++v21->RefCount;
        if ( pfonta )
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)pfonta);
        pfonta = v22;
      }
    }
    this->Scale = 1.0;
    this->pFont = 0;
    this->FontSize = -1.0;
    if ( pfonta )
    {
      this->FindFontInfo.pCurrentFormat = v16->pFormat.pObject;
      FontScaleFactor = pfonta->FontScaleFactor;
      v62 = FontScaleFactor;
      if ( FontScaleFactor <= 0.0 )
      {
        v66 = v62 - 0.5;
        v64 = 0.5;
        v65 = (int)v66;
        TextRectWidth_low = (Scaleform::RefCountVImpl *)(int)v66;
      }
      else
      {
        v63 = v62 + 0.5;
        v64 = 0.5;
        v65 = (int)v63;
        TextRectWidth_low = (Scaleform::RefCountVImpl *)(int)v63;
      }
      v67 = (double)(int)TextRectWidth_low;
      this->GlyphWidth = v65;
      this->GlyphAdvance = v67 + 40.0;
      FontScaleFactor = this->LineCursor.LastAdvance;
      v68 = FontScaleFactor;
      if ( FontScaleFactor <= 0.0 )
        v69 = v68 - v64;
      else
        v69 = v68 + v64;
      this->LastAdvance = (int)v69;
      this->AdjLineWidth = v65;
      this->GlyphIndex = -1;
      this->isSpace = 0;
      this->isNbsp = 0;
      goto LABEL_114;
    }
    v23 = v16->Character == 160;
    this->isNbsp = v23;
    Character = v16->Character;
    v25 = !Character || !v23 && (Character == 9 || Character == 13 || Character == 32 || Character == 12288);
    v17 = this->FindFontInfo.pCurrentFont.pObject == 0;
    this->isSpace = v25;
    if ( !v17 && this->FindFontInfo.pCurrentFormat == v16->pFormat.pObject )
    {
      v26 = (Scaleform::GFx::Resource *)this->FindFontInfo.pCurrentFont.pObject;
      if ( v26 )
        Scaleform::RefCountImpl::AddRef(v26);
      v27 = (Scaleform::RefCountVImpl *)this->pFontHandle.pObject;
      if ( v27 )
        Scaleform::RefCountImpl::Release(v27);
      this->pFontHandle.pObject = this->FindFontInfo.pCurrentFont.pObject;
LABEL_66:
      this->pFont = this->pFontHandle.pObject->pFont.pObject;
      *(float *)&TextRectWidth_low = Scaleform::Render::Text::ParagraphFormatter::GetActualFontSize(this);
      v31 = *(float *)&TextRectWidth_low;
      pDocView = this->pDocView;
      this->FontSize = *(float *)&TextRectWidth_low;
      *(float *)&TextRectWidth_low = v31 * 20.0;
      this->Scale = *(float *)&TextRectWidth_low * 0.0009765625;
      v33 = v16->Character;
      if ( v33 == (unsigned __int8)((pDocView->pDocument.pObject->RTFlags & 2) != 0 ? 13 : 10) || !v33 )
      {
        v47 = this->pFont->GetGlyphIndex(this->pFont, 32u);
        v48 = this->pFont;
        this->GlyphIndex = v47;
        this->GlyphAdvance = ((double (__thiscall *)(Scaleform::Render::Font *, int))v48->GetAdvance)(v48, v47)
                           * 0.5
                           * this->Scale;
        v46 = 0.5;
        v45 = 0.0;
      }
      else if ( v33 == 9 )
      {
        v45 = 0.0;
        this->GlyphIndex = -1;
        this->GlyphAdvance = 0.0;
        v46 = 0.5;
      }
      else
      {
        v34 = this->pFont->GetGlyphIndex(this->pFont, v16->Character);
        this->GlyphIndex = v34;
        if ( v34 == -1 )
        {
          if ( this->isNbsp )
            this->GlyphIndex = this->pFont->GetGlyphIndex(this->pFont, 32u);
          if ( this->GlyphIndex == -1 && this->pLog && (this->pDocView->RTFlags & 0x10) == 0 )
          {
            Scaleform::Render::Text::FontManagerBase::FontSearchPathInfo::FontSearchPathInfo(&v132, 1);
            pCurrentFormat = (Scaleform::Render::Text::TextFormat *)this->FindFontInfo.pCurrentFormat;
            PresentMask = pCurrentFormat->PresentMask;
            device[0] = (this->pDocView->Flags & 0x20) != 0;
            FormatFlags = pCurrentFormat->FormatFlags;
            italic[0] = (FormatFlags & 2) != 0;
            bold[0] = FormatFlags & 1;
            FontList = Scaleform::Render::Text::TextFormat::GetFontList(pCurrentFormat);
            *(float *)&TextRectWidth_low = COERCE_FLOAT(
                                             Scaleform::Render::Text::FontManagerBase::CreateFontHandle(
                                               this->pDocView->pFontManager.pObject,
                                               (const char *)((FontList->HeapTypeBits & 0xFFFFFFFC) + 8),
                                               bold[0],
                                               italic[0],
                                               device[0],
                                               (PresentMask & 0x1000) == 0,
                                               &v132));
            v39 = this->pDocView->pDocumentListener.pObject;
            if ( v39 )
            {
              v113 |= 1u;
              v40 = v39->GetCharacterPath(v39, &v127);
            }
            else
            {
              v113 |= 2u;
              Scaleform::String::String(&v126);
            }
            Scaleform::String::String(&v118, v40);
            v41 = v113;
            if ( (v113 & 2) != 0 )
            {
              v41 = v113 & 0xFFFFFFFD;
              v113 &= ~2u;
              Scaleform::String::~String(&v126);
            }
            if ( (v41 & 1) != 0 )
            {
              v113 = v41 & 0xFFFFFFFE;
              Scaleform::String::~String(&v127);
            }
            this->pFont->GetCharRanges(this->pFont, &v117);
            FontScaleFactor = COERCE_FLOAT(this->pFont->GetGlyphShapeCount(this->pFont));
            pData = v132.Info.pData;
            if ( !v132.Info.pData )
              pData = (char *)&buf;
            v42 = v117.HeapTypeBits & 0xFFFFFFFC;
            v43 = v118.HeapTypeBits & 0xFFFFFFFC;
            v44 = Scaleform::Render::Text::TextFormat::GetFontList((Scaleform::Render::Text::TextFormat *)this->FindFontInfo.pCurrentFormat);
            Scaleform::Log::LogError(
              this->pLog,
              "Missing \"%s\" glyph '%c' (0x%x) in \"%s\".\nFont has %u glyphs, ranges %s.\nSearch log: \n%s",
              (const char *)((v44->HeapTypeBits & 0xFFFFFFFC) + 8),
              SLOBYTE(v114->Character),
              v114->Character,
              (const char *)(v43 + 8),
              FontScaleFactor,
              (const char *)(v42 + 8),
              pData);
            this->pDocView->RTFlags |= 0x10u;
            Scaleform::String::~String(&v117);
            Scaleform::String::~String(&v118);
            if ( *(float *)&TextRectWidth_low != 0.0 )
              Scaleform::RefCountImpl::Release(TextRectWidth_low);
            Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&v132.Info);
            v16 = v114;
          }
        }
        this->GlyphAdvance = ((double (__thiscall *)(Scaleform::Render::Font *, int))this->pFont->GetAdvance)(
                               this->pFont,
                               this->GlyphIndex)
                           * this->Scale;
        v45 = 0.0;
        v46 = 0.5;
      }
      if ( this->LineCursor.pPrevGrec )
      {
        v17 = !this->LineCursor.LastKerning;
        v49 = v46;
        v50 = v45;
        v51 = v49;
        *(float *)&TextRectWidth_low = v50;
        if ( !v17 )
        {
          if ( this->LineCursor.pPrevGrec )
          {
            *(float *)&TextRectWidth_low = this->LineCursor.pLastFont.pObject->pFont.pObject->GetKerningAdjustment(
                                             this->LineCursor.pLastFont.pObject->pFont.pObject,
                                             this->LineCursor.LastCharCode,
                                             v16->Character);
            v50 = 0.0;
            v51 = 0.5;
          }
          else
          {
            *(float *)&TextRectWidth_low = v50;
          }
          *(float *)&TextRectWidth_low = *(float *)&TextRectWidth_low * this->Scale;
        }
        FontScaleFactor = this->LineCursor.LastAdvance + *(float *)&TextRectWidth_low;
        v52 = FontScaleFactor;
        if ( FontScaleFactor <= v50 )
          v53 = (int)(v52 - v51);
        else
          v53 = (int)(v52 + v51);
      }
      else
      {
        FontScaleFactor = this->LineCursor.LastAdvance;
        v54 = FontScaleFactor;
        if ( FontScaleFactor <= v45 )
          v55 = v54 - v46;
        else
          v55 = v54 + v46;
        v53 = (int)v55;
        v56 = v46;
        v50 = v45;
        v51 = v56;
      }
      GlyphAdvance = this->GlyphAdvance;
      this->LastAdvance = v53;
      FontScaleFactor = GlyphAdvance;
      v58 = FontScaleFactor < v50;
      v59 = FontScaleFactor == v50;
      v60 = FontScaleFactor;
      if ( v58 || v59 )
        v61 = v60 - v51;
      else
        v61 = v51 + v60;
      v17 = !this->isSpace;
      this->GlyphWidth = (int)v61;
      this->AdjLineWidth = !v17 ? 0 : (int)v61;
LABEL_114:
      this->NewLineWidth = this->LastAdvance + this->LineCursor.LineWidth;
      if ( Scaleform::Render::Text::ParagraphFormatter::CheckWordWrap(this) )
        goto LABEL_179;
      pPrevGrec = this->LineCursor.pPrevGrec;
      if ( pPrevGrec )
      {
        LastAdvance = this->LastAdvance;
        if ( LastAdvance < 0 )
        {
          pPrevGrec->Flags |= 0x40u;
          pPrevGrec->Advance = -(__int16)LastAdvance;
        }
        else
        {
          pPrevGrec->Advance = LastAdvance;
          pPrevGrec->Flags &= ~0x40u;
        }
      }
      v72 = &this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex];
      v72->LenAndFontSize = 0;
      v72->Flags = 0;
      v72->Index = this->GlyphIndex;
      v73 = this->LineCursor.pComposStr.pObject;
      if ( v73 )
      {
        if ( v73->GetLength(v73) )
        {
          v74 = Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(&this->LineCursor.CharIter)->Index
              + this->LineCursor.pParagraph->StartIndex;
          if ( v74 >= this->LineCursor.pComposStr.pObject->GetPosition(this->LineCursor.pComposStr.pObject)
            && this->LineCursor.ComposStrCurPos < this->LineCursor.pComposStr.pObject->GetLength(this->LineCursor.pComposStr.pObject) )
          {
            v72->Flags |= 4u;
          }
        }
      }
      if ( pfonta )
      {
        v75 = &this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex];
        v75->Flags |= 0x4000u;
        v76 = &this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex];
        v76->Flags |= 0x800u;
        this->LineCursor.GlyphIns.pNextFormatData[this->LineCursor.GlyphIns.FormatDataIndex++].ColorV = (unsigned int)pfonta;
        ++pfonta->RefCount;
        v72->LenAndFontSize = v72->LenAndFontSize & 0xFFF | (LOWORD(this->DeltaText) << 12);
        this->LineCursor.LastKerning = 0;
        v130 = *(float *)&pfonta[1].pFont.pObject * 0.0
             + 0.0 * pfonta[1].FontScaleFactor
             + *(float *)&pfonta[2].RefCount;
        TextRectWidth_low = (Scaleform::RefCountVImpl *)LODWORD(this->LineCursor.MaxFontAscent);
        FontScaleFactor = -v130;
        v77 = FontScaleFactor;
        v78 = FontScaleFactor;
        if ( *(float *)&TextRectWidth_low > (double)FontScaleFactor )
          v78 = *(float *)&TextRectWidth_low;
        *(float *)&TextRectWidth_low = v78;
        this->LineCursor.MaxFontAscent = *(float *)&TextRectWidth_low;
        TextRectWidth_low = (Scaleform::RefCountVImpl *)LODWORD(this->LineCursor.MaxFontDescent);
        FontScaleFactor = *(float *)&pfonta->pFont.pObject - v77;
        v79 = FontScaleFactor;
        if ( *(float *)&TextRectWidth_low > (double)FontScaleFactor )
          v79 = *(float *)&TextRectWidth_low;
        NewLineWidth = this->NewLineWidth;
        *(float *)&TextRectWidth_low = v79;
        v81 = this->AdjLineWidth + NewLineWidth;
        this->LineCursor.MaxFontDescent = *(float *)&TextRectWidth_low;
        this->LineCursor.LineWidthWithoutTrailingSpaces = v81;
        v82 = this->FindFontInfo.pCurrentFormat;
        this->LineCursor.NumOfTrailingSpaces = 0;
        if ( (v82->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&v82->Url) )
          v72->Flags |= 0x80u;
        else
          v72->Flags &= ~0x80u;
        goto LABEL_168;
      }
      v83 = (Scaleform::RefCountVImpl *)this->FindFontInfo.pCurrentFormat->ColorV;
      scale_4 = this->FontSize;
      TextRectWidth_low = v83;
      Scaleform::Render::Text::LineBuffer::GlyphEntry::SetFontSize(v72, scale_4);
      v84 = (Scaleform::GFx::Resource *)this->pFontHandle.pObject;
      if ( v84 != (Scaleform::GFx::Resource *)this->LineCursor.pLastFont.pObject )
      {
        v85 = &this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex];
        v85->Flags |= 0x4000u;
        v86 = &this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex];
        v86->Flags |= 0x2000u;
        this->LineCursor.GlyphIns.pNextFormatData[this->LineCursor.GlyphIns.FormatDataIndex++].ColorV = (unsigned int)v84;
        Scaleform::RefCountImpl::AddRef(v84);
      }
      if ( v83 != (Scaleform::RefCountVImpl *)this->LineCursor.LastColor )
      {
        v87 = &this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex];
        v87->Flags |= 0x4000u;
        v88 = &this->LineCursor.GlyphIns.pGlyphs[this->LineCursor.GlyphIns.GlyphIndex];
        v88->Flags |= 0x1000u;
        this->LineCursor.GlyphIns.pNextFormatData[this->LineCursor.GlyphIns.FormatDataIndex++].ColorV = (unsigned int)v83;
      }
      v89 = v114->Character;
      if ( v89 == (unsigned __int8)((this->pDocView->pDocument.pObject->RTFlags & 2) != 0 ? 13 : 10) )
      {
        if ( !v89 )
          goto LABEL_152;
        v72->LenAndFontSize = v72->LenAndFontSize & 0xFFF | 0x1000;
      }
      else
      {
        if ( v89 )
        {
          if ( !this->isSpace && !this->isNbsp )
          {
            this->LineCursor.LineWidthWithoutTrailingSpaces = this->AdjLineWidth + this->NewLineWidth;
            goto LABEL_149;
          }
          v72->Flags |= 2u;
          v90 = this->GlyphIndex;
          if ( v90 >= 0 )
          {
            v91 = this->pFont;
            v131.x1 = 0.0;
            v131.y1 = 0.0;
            v131.x2 = 0.0;
            v131.y2 = 0.0;
            v91->GetGlyphBounds(v91, v90, &v131);
            IsEmpty = Scaleform::Render::Rect<float>::IsEmpty(&v131);
            v83 = TextRectWidth_low;
            if ( IsEmpty )
              v72->Flags |= 0x200u;
          }
          else
          {
            v72->Flags |= 0x200u;
          }
          ++this->LineCursor.NumOfSpaces;
          if ( this->isSpace )
          {
            ++this->LineCursor.NumOfTrailingSpaces;
          }
          else
          {
            this->LineCursor.LineWidthWithoutTrailingSpaces = this->AdjLineWidth + this->NewLineWidth;
LABEL_149:
            this->LineCursor.NumOfTrailingSpaces = 0;
          }
          v72->LenAndFontSize = v72->LenAndFontSize & 0xFFF | 0x1000;
          Scaleform::Render::Text::GFxLineCursor::TrackFontParams(&this->LineCursor, this->pFont, this->Scale);
LABEL_156:
          if ( (this->FindFontInfo.pCurrentFormat->FormatFlags & 4) != 0 )
            v72->Flags |= 0x400u;
          else
            v72->Flags &= ~0x400u;
          v93 = this->FindFontInfo.pCurrentFormat;
          if ( (v93->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&v93->Url) )
            v72->Flags |= 0x80u;
          else
            v72->Flags &= ~0x80u;
          v94 = (Scaleform::GFx::Resource *)this->pFontHandle.pObject;
          if ( v94 )
            Scaleform::RefCountImpl::AddRef(v94);
          v95 = (Scaleform::RefCountVImpl *)this->LineCursor.pLastFont.pObject;
          if ( v95 )
            Scaleform::RefCountImpl::Release(v95);
          this->LineCursor.pLastFont.pObject = this->pFontHandle.pObject;
          v96 = this->FindFontInfo.pCurrentFormat;
          this->LineCursor.LastColor = (unsigned int)v83;
          this->LineCursor.LastKerning = (v96->FormatFlags & 8) != 0;
LABEL_168:
          if ( v114->Character == 9 )
          {
            TabStopsIndex = this->TabStopsIndex;
            if ( TabStopsIndex >= this->TabStopsNum )
            {
              FontScaleFactor = (this->FontSize + this->FontSize + 8.0) * 0.125;
              FontScaleFactor = floor(FontScaleFactor);
              FontScaleFactor = FontScaleFactor * 8.0;
              *(float *)&TextRectWidth_low = FontScaleFactor * 20.0;
              v116 = (float)this->NewLineWidth;
              FontScaleFactor = (v116 + *(float *)&TextRectWidth_low) / *(float *)&TextRectWidth_low;
              FontScaleFactor = floor(FontScaleFactor);
              FontScaleFactor = FontScaleFactor * *(float *)&TextRectWidth_low;
              v101 = FontScaleFactor - v116;
LABEL_173:
              this->GlyphAdvance = v101;
            }
            else
            {
              v98 = 5 * TabStops[TabStopsIndex];
              this->TabStopsIndex = TabStopsIndex + 1;
              v99 = this->NewLineWidth;
              v100 = 4 * v98;
              if ( v100 > v99 )
              {
                LODWORD(FontScaleFactor) = v100 - v99;
                v101 = (double)(v100 - v99);
                goto LABEL_173;
              }
            }
          }
          LenAndFontSize = v72->LenAndFontSize;
          v103 = this->NewLineWidth;
          FontScaleFactor = this->GlyphAdvance;
          v104 = FontScaleFactor;
          this->LineCursor.LineLength += LenAndFontSize >> 12;
          v105 = this->GlyphIndex;
          this->LineCursor.pPrevGrec = v72;
          v106 = v114->Character;
          this->LineCursor.LastAdvance = v104;
          this->LineCursor.LastGlyphIndex = v105;
          v107 = this->FindFontInfo.pCurrentFormat;
          this->LineCursor.LastCharCode = v106;
          this->LineCursor.LineWidth = v103;
          if ( (v107->PresentMask & 2) != 0 )
          {
            FontScaleFactor = (double)(v107->LetterSpacing / 20) * 20.0;
            this->LineCursor.LastAdvance = v104 + FontScaleFactor;
          }
          this->LineCursor.LastGlyphWidth = this->GlyphWidth;
          if ( this->LineCursor.GlyphIns.pGlyphs )
          {
            v108 = this->LineCursor.GlyphIns.GlyphIndex;
            if ( v108 < this->LineCursor.GlyphIns.GlyphsCount )
              this->LineCursor.GlyphIns.GlyphIndex = v108 + 1;
          }
          goto LABEL_179;
        }
LABEL_152:
        v72->LenAndFontSize &= 0xFFFu;
      }
      v72->Flags |= 0x300u;
      this->GlyphWidth = 0;
      this->LineCursor.LineHasNewLine = 1;
      if ( !v114->Index )
        Scaleform::Render::Text::GFxLineCursor::TrackFontParams(&this->LineCursor, this->pFont, this->Scale);
      goto LABEL_156;
    }
    this->FindFontInfo.pCurrentFormat = v16->pFormat.pObject;
    v122[0] = v16->Character == 0;
    v28 = (Scaleform::GFx::Resource *)Scaleform::Render::Text::DocView::FindFont(
                                        this->pDocView,
                                        &this->FindFontInfo,
                                        *(Scaleform::String *)v122);
    v29 = (Scaleform::Render::Text::FontHandle *)v28;
    if ( v28 )
      Scaleform::RefCountImpl::AddRef(v28);
    v30 = (Scaleform::RefCountVImpl *)this->pFontHandle.pObject;
    if ( v30 )
      Scaleform::RefCountImpl::Release(v30);
    this->pFontHandle.pObject = v29;
    if ( v29 )
      goto LABEL_66;
LABEL_179:
    Scaleform::Render::Text::GFxLineCursor::operator+=(&this->LineCursor, this->DeltaText);
  }
  if ( this->pTempLine )
    Scaleform::Render::Text::ParagraphFormatter::FinalizeLine(this);
  pTextBufForCustomFormat = this->pTextBufForCustomFormat;
  if ( pTextBufForCustomFormat && pTextBufForCustomFormat != this->TextBufForCustomFormat )
  {
    Scaleform::Render::Text::StyledText::GetAllocator(this->pDocView->pDocument.pObject);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pTextBufForCustomFormat);
  }
  if ( pfonta )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)pfonta);
}
