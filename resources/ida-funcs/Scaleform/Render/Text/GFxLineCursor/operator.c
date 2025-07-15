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


const Scaleform::Render::Text::Paragraph::CharacterInfo *__thiscall Scaleform::Render::Text::GFxLineCursor::operator*(
        Scaleform::Render::Text::GFxLineCursor *this)
{
  Scaleform::Render::Text::Paragraph::CharactersIterator *p_CharIter; // ebx
  Scaleform::Render::Text::Paragraph::CharacterInfo *v3; // eax
  Scaleform::Render::Text::CompositionStringBase *pObject; // ecx
  unsigned int v5; // edi
  const wchar_t *v6; // eax
  Scaleform::Render::Text::CompositionStringBase *v7; // edi
  Scaleform::Render::Text::TextFormat *v8; // ebx
  const Scaleform::Render::Text::TextFormat *v9; // eax
  Scaleform::Render::Text::TextFormat *v10; // eax
  Scaleform::Render::Text::Allocator *v11; // eax
  Scaleform::Render::Text::TextFormat *TextFormat; // eax
  Scaleform::Render::Text::Paragraph::CharacterInfo *p_CharInfoHolder; // edi
  Scaleform::Render::Text::TextFormat *v14; // esi
  Scaleform::Render::Text::TextFormat *v15; // ebx
  bool v16; // zf
  const Scaleform::Render::Text::Paragraph::CharacterInfo *v17; // eax
  Scaleform::Render::Text::CompositionStringBase *v18; // edi
  Scaleform::Render::Text::Paragraph::CharacterInfo *v19; // ebp
  Scaleform::Render::Text::Paragraph::CharacterInfo *v20; // ebp
  Scaleform::Render::Text::TextFormat *v21; // eax
  Scaleform::Render::Text::Paragraph::CharacterInfo *RefCount; // ecx
  Scaleform::Render::Text::TextFormat *v23; // edi
  wchar_t Character; // dx
  const Scaleform::Render::Text::TextFormat *ComposStrCurPos; // [esp-4h] [ebp-40h]
  Scaleform::Render::Text::TextFormat result; // [esp+10h] [ebp-2Ch] BYREF

  p_CharIter = &this->CharIter;
  v3 = Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(&this->CharIter);
  pObject = this->pComposStr.pObject;
  this->CharInfoHolder.Index = v3->Index;
  if ( pObject )
  {
    if ( pObject->GetLength(pObject) )
    {
      v5 = this->CharInfoHolder.Index + this->pParagraph->StartIndex;
      if ( v5 >= this->pComposStr.pObject->GetPosition(this->pComposStr.pObject) )
      {
        if ( v5 == this->pComposStr.pObject->GetPosition(this->pComposStr.pObject)
          && this->ComposStrCurPos < this->pComposStr.pObject->GetLength(this->pComposStr.pObject) )
        {
          this->CharInfoHolder.Index = this->ComposStrCurPos
                                     + Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(p_CharIter)->Index;
          v6 = this->pComposStr.pObject->GetText(this->pComposStr.pObject);
          v7 = this->pComposStr.pObject;
          this->CharInfoHolder.Character = v6[this->ComposStrCurPos];
          v8 = Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(p_CharIter)->pFormat.pObject;
          ComposStrCurPos = (const Scaleform::Render::Text::TextFormat *)this->ComposStrCurPos;
          v9 = (const Scaleform::Render::Text::TextFormat *)((int (__thiscall *)(Scaleform::Render::Text::CompositionStringBase *))v7->GetTextFormat)(v7);
          v10 = Scaleform::Render::Text::TextFormat::Merge(v8, &result, v9);
          v11 = (Scaleform::Render::Text::Allocator *)((int (__thiscall *)(Scaleform::Render::Text::CompositionStringBase *, Scaleform::Render::Text::TextFormat *))v7->GetAllocator)(
                                                        v7,
                                                        v10);
          TextFormat = Scaleform::Render::Text::Allocator::AllocateTextFormat(v11, ComposStrCurPos);
          p_CharInfoHolder = &this->CharInfoHolder;
          v14 = this->CharInfoHolder.pFormat.pObject;
          v15 = TextFormat;
          if ( v14 )
          {
            v16 = v14->RefCount-- == 1;
            if ( v16 )
            {
              Scaleform::Render::Text::TextFormat::~TextFormat(v14);
              Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
            }
          }
          p_CharInfoHolder->pFormat.pObject = v15;
          Scaleform::Render::Text::TextFormat::~TextFormat((Scaleform::Render::Text::TextFormat *)&result.FontList);
          return p_CharInfoHolder;
        }
        v18 = this->pComposStr.pObject;
        v19 = Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(p_CharIter);
        this->CharInfoHolder.Index = v19->Index + v18->GetLength(v18);
      }
    }
  }
  v20 = Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(p_CharIter);
  v21 = v20->pFormat.pObject;
  RefCount = &this->CharInfoHolder;
  result.RefCount = (unsigned int)&this->CharInfoHolder;
  if ( v21 )
    ++v21->RefCount;
  v23 = RefCount->pFormat.pObject;
  if ( RefCount->pFormat.pObject )
  {
    v16 = v23->RefCount-- == 1;
    if ( v16 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(v23);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v23);
      RefCount = (Scaleform::Render::Text::Paragraph::CharacterInfo *)result.RefCount;
    }
  }
  RefCount->pFormat.pObject = v20->pFormat.pObject;
  if ( (this->pDocView->Flags & 0x10) != 0
    && Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(p_CharIter)->Character )
  {
    v17 = (const Scaleform::Render::Text::Paragraph::CharacterInfo *)result.RefCount;
    this->CharInfoHolder.Character = 42;
  }
  else
  {
    Character = Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(p_CharIter)->Character;
    v17 = (const Scaleform::Render::Text::Paragraph::CharacterInfo *)result.RefCount;
    this->CharInfoHolder.Character = Character;
  }
  return v17;
}


void __thiscall Scaleform::Render::Text::GFxLineCursor::operator+=(
        Scaleform::Render::Text::GFxLineCursor *this,
        unsigned int n)
{
  Scaleform::Render::Text::CompositionStringBase *pObject; // ecx
  unsigned int v4; // ebx
  unsigned int v5; // edi
  unsigned int v6; // ebx
  unsigned int v7; // ebp
  unsigned int v8; // eax

  pObject = this->pComposStr.pObject;
  if ( pObject
    && pObject->GetLength(pObject)
    && (v4 = this->CharIter.CurTextIndex + this->pParagraph->StartIndex,
        v4 <= this->pComposStr.pObject->GetPosition(this->pComposStr.pObject)) )
  {
    v5 = n;
    if ( v4 + n >= this->pComposStr.pObject->GetPosition(this->pComposStr.pObject) )
    {
      v6 = this->pComposStr.pObject->GetPosition(this->pComposStr.pObject) - v4;
      if ( v6 >= n )
        v6 = n;
      v7 = this->ComposStrCurPos - v6 + n;
      if ( v7 <= this->pComposStr.pObject->GetLength(this->pComposStr.pObject) )
      {
        this->NumChars += n - v6;
        this->ComposStrCurPos = v7;
      }
      else
      {
        v6 = n + this->ComposStrCurPos - this->pComposStr.pObject->GetLength(this->pComposStr.pObject);
        v8 = this->pComposStr.pObject->GetLength(this->pComposStr.pObject);
        this->NumChars += v8;
        this->ComposStrCurPos = v8;
      }
      v5 = v6;
    }
  }
  else
  {
    v5 = n;
  }
  if ( v5 )
  {
    Scaleform::Render::Text::Paragraph::CharactersIterator::operator+=(&this->CharIter, v5);
    this->NumChars += v5;
  }
}
