Scaleform::Render::Text::Paragraph::CharactersIterator *__thiscall Scaleform::Render::Text::Paragraph::CharactersIterator::operator=(
        Scaleform::Render::Text::Paragraph::CharactersIterator *this,
        const Scaleform::Render::Text::Paragraph::CharactersIterator *__that)
{
  Scaleform::Render::Text::TextFormat *pObject; // ebx

  if ( __that->PlaceHolder.pFormat.pObject )
    ++__that->PlaceHolder.pFormat.pObject->RefCount;
  pObject = this->PlaceHolder.pFormat.pObject;
  if ( this->PlaceHolder.pFormat.pObject )
  {
    if ( pObject->RefCount-- == 1 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  this->PlaceHolder.pFormat.pObject = __that->PlaceHolder.pFormat.pObject;
  this->PlaceHolder.Index = __that->PlaceHolder.Index;
  this->PlaceHolder.Character = __that->PlaceHolder.Character;
  this->pFormatInfo = __that->pFormatInfo;
  this->FormatIterator = __that->FormatIterator;
  this->pText = __that->pText;
  this->CurTextIndex = __that->CurTextIndex;
  return this;
}


Scaleform::Render::Text::Paragraph::CharactersIterator *__thiscall Scaleform::Render::Text::Paragraph::CharactersIterator::operator*(
        Scaleform::Render::Text::Paragraph::CharactersIterator *this)
{
  const Scaleform::Render::Text::Paragraph::TextBuffer *pText; // ecx
  unsigned int v3; // eax
  int Index; // ecx
  const Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *pArray; // edx
  int v6; // ebx
  Scaleform::Render::Text::TextFormat *v7; // edi
  bool v8; // zf
  _DWORD *v10; // eax
  Scaleform::Render::Text::TextFormat *v11; // edi
  Scaleform::Render::Text::TextFormat *pObject; // edi
  Scaleform::Render::Text::TextFormat *v13; // edi
  unsigned int CurTextIndex; // edx

  pText = this->pText;
  if ( pText && (v3 = this->CurTextIndex, v3 < pText->Size) )
  {
    this->PlaceHolder.Character = pText->pText[v3];
    this->PlaceHolder.Index = v3;
    Index = this->FormatIterator.Index;
    if ( Index < 0 || (pArray = this->FormatIterator.pArray, Index >= pArray->Ranges.Data.Size) )
    {
      pObject = this->PlaceHolder.pFormat.pObject;
      if ( this->PlaceHolder.pFormat.pObject )
      {
        v8 = pObject->RefCount-- == 1;
        if ( v8 )
        {
          Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
        }
      }
      this->PlaceHolder.pFormat.pObject = 0;
      return this;
    }
    else
    {
      v6 = (int)&pArray->Ranges.Data.Data[Index];
      if ( v3 >= *(_DWORD *)v6 )
      {
        v10 = *(_DWORD **)(v6 + 8);
        if ( v10 )
          ++*v10;
        v11 = this->PlaceHolder.pFormat.pObject;
        if ( this->PlaceHolder.pFormat.pObject )
        {
          v8 = v11->RefCount-- == 1;
          if ( v8 )
          {
            Scaleform::Render::Text::TextFormat::~TextFormat(v11);
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
          }
        }
        this->PlaceHolder.pFormat.pObject = *(Scaleform::Render::Text::TextFormat **)(v6 + 8);
        return this;
      }
      else
      {
        v7 = this->PlaceHolder.pFormat.pObject;
        if ( this->PlaceHolder.pFormat.pObject )
        {
          v8 = v7->RefCount-- == 1;
          if ( v8 )
          {
            Scaleform::Render::Text::TextFormat::~TextFormat(v7);
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
          }
        }
        this->PlaceHolder.pFormat.pObject = 0;
        return this;
      }
    }
  }
  else
  {
    v13 = this->PlaceHolder.pFormat.pObject;
    CurTextIndex = this->CurTextIndex;
    this->PlaceHolder.Character = 0;
    this->PlaceHolder.Index = CurTextIndex;
    if ( v13 )
    {
      v8 = v13->RefCount-- == 1;
      if ( v8 )
      {
        Scaleform::Render::Text::TextFormat::~TextFormat(v13);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
      }
    }
    this->PlaceHolder.pFormat.pObject = 0;
    return this;
  }
}


void __thiscall Scaleform::Render::Text::Paragraph::CharactersIterator::operator+=(
        Scaleform::Render::Text::Paragraph::CharactersIterator *this,
        unsigned int n)
{
  unsigned int v2; // esi
  const Scaleform::Render::Text::Paragraph::TextBuffer *pText; // edx
  unsigned int CurTextIndex; // eax
  unsigned int v5; // eax
  int Index; // edx
  const Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *pArray; // edi
  int v8; // eax

  if ( n )
  {
    v2 = n;
    do
    {
      pText = this->pText;
      if ( pText && (CurTextIndex = this->CurTextIndex, CurTextIndex < pText->Size) )
      {
        v5 = CurTextIndex + 1;
        this->CurTextIndex = v5;
        Index = this->FormatIterator.Index;
        if ( Index >= 0 )
        {
          pArray = this->FormatIterator.pArray;
          if ( Index < pArray->Ranges.Data.Size
            && v5 >= pArray->Ranges.Data.Data[Index].Index + pArray->Ranges.Data.Data[Index].Length )
          {
            v8 = this->FormatIterator.Index;
            if ( v8 < (signed int)this->FormatIterator.pArray->Ranges.Data.Size )
              this->FormatIterator.Index = v8 + 1;
          }
        }
      }
      else
      {
        this->CurTextIndex = pText->Size;
      }
      --v2;
    }
    while ( v2 );
  }
}
