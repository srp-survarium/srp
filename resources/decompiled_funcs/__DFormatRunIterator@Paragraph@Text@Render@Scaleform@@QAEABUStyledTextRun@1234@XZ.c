Scaleform::Render::Text::Paragraph::FormatRunIterator *__thiscall Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(
        Scaleform::Render::Text::Paragraph::FormatRunIterator *this)
{
  int Index; // eax
  const Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *pArray; // ecx
  int v4; // edx
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *Data; // ecx
  unsigned int v6; // eax
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v7; // edx
  unsigned int v8; // ecx
  const wchar_t *v9; // edx
  Scaleform::Render::Text::Paragraph::FormatRunIterator *result; // eax
  const Scaleform::Render::Text::Paragraph::TextBuffer *pText; // edx
  unsigned int CurTextIndex; // eax
  unsigned int v13; // ecx
  Scaleform::Render::Text::TextFormat *pObject; // edi

  Index = this->FormatIterator.Index;
  if ( Index < 0 || (pArray = this->FormatIterator.pArray, Index >= pArray->Ranges.Data.Size) )
  {
    pText = this->pText;
    CurTextIndex = this->CurTextIndex;
    v13 = pText->Size - CurTextIndex;
    v9 = &pText->pText[CurTextIndex];
    this->PlaceHolder.Index = CurTextIndex;
    this->PlaceHolder.Length = v13;
  }
  else
  {
    v4 = Index;
    Data = pArray->Ranges.Data.Data;
    v6 = Data[Index].Index;
    v7 = &Data[v4];
    v8 = this->CurTextIndex;
    if ( v8 >= v6 )
      return (Scaleform::Render::Text::Paragraph::FormatRunIterator *)Scaleform::Render::Text::Paragraph::StyledTextRun::Set(
                                                                        &this->PlaceHolder,
                                                                        &this->pText->pText[v6],
                                                                        v6,
                                                                        v7->Length,
                                                                        v7->Data.pObject);
    v9 = &this->pText->pText[v8];
    this->PlaceHolder.Index = v8;
    this->PlaceHolder.Length = v6 - v8;
  }
  this->PlaceHolder.pText = v9;
  pObject = this->PlaceHolder.pFormat.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
    {
      Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  result = this;
  this->PlaceHolder.pFormat.pObject = 0;
  return result;
}
