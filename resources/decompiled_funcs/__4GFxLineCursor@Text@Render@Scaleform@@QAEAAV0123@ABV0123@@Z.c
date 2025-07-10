Scaleform::Render::Text::GFxLineCursor *__thiscall Scaleform::Render::Text::GFxLineCursor::operator=(
        Scaleform::Render::Text::GFxLineCursor *this,
        const Scaleform::Render::Text::GFxLineCursor *__that)
{
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::GFx::Resource *v5; // ecx
  Scaleform::RefCountVImpl *v6; // ecx
  Scaleform::Render::Text::TextFormat *v7; // eax
  Scaleform::Render::Text::TextFormat *v8; // ebx

  this->pPrevGrec = __that->pPrevGrec;
  pObject = (Scaleform::GFx::Resource *)__that->pLastFont.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::AddRef(pObject);
  v4 = (Scaleform::RefCountVImpl *)this->pLastFont.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  this->pLastFont.pObject = __that->pLastFont.pObject;
  this->LastCharCode = __that->LastCharCode;
  this->LastGlyphIndex = __that->LastGlyphIndex;
  this->LastAdvance = __that->LastAdvance;
  this->LastGlyphWidth = __that->LastGlyphWidth;
  this->LastColor = __that->LastColor;
  v5 = (Scaleform::GFx::Resource *)__that->pComposStr.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::AddRef(v5);
  v6 = (Scaleform::RefCountVImpl *)this->pComposStr.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  this->pComposStr.pObject = __that->pComposStr.pObject;
  this->ComposStrPosition = __that->ComposStrPosition;
  this->ComposStrLength = __that->ComposStrLength;
  this->ComposStrCurPos = __that->ComposStrCurPos;
  this->pDocView = __that->pDocView;
  this->pParagraph = __that->pParagraph;
  this->LineWidth = __that->LineWidth;
  this->LineWidthWithoutTrailingSpaces = __that->LineWidthWithoutTrailingSpaces;
  this->LineLength = __that->LineLength;
  this->MaxFontAscent = __that->MaxFontAscent;
  this->MaxFontDescent = __that->MaxFontDescent;
  this->MaxFontLeading = __that->MaxFontLeading;
  Scaleform::Render::Text::Paragraph::CharactersIterator::operator=(&this->CharIter, &__that->CharIter);
  v7 = __that->CharInfoHolder.pFormat.pObject;
  if ( v7 )
    ++v7->RefCount;
  v8 = this->CharInfoHolder.pFormat.pObject;
  if ( v8 )
  {
    if ( v8->RefCount-- == 1 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v8);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
    }
  }
  this->CharInfoHolder = __that->CharInfoHolder;
  this->Indent = __that->Indent;
  this->LeftMargin = __that->LeftMargin;
  this->RightMargin = __that->RightMargin;
  this->GlyphIns = __that->GlyphIns;
  this->NumOfSpaces = __that->NumOfSpaces;
  this->NumOfTrailingSpaces = __that->NumOfTrailingSpaces;
  this->FontScaleFactor = __that->FontScaleFactor;
  this->LastKerning = __that->LastKerning;
  this->LineHasNewLine = __that->LineHasNewLine;
  this->NumChars = __that->NumChars;
  return this;
}
