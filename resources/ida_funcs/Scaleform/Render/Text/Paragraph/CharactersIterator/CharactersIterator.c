void __thiscall Scaleform::Render::Text::Paragraph::CharactersIterator::CharactersIterator(
        Scaleform::Render::Text::Paragraph::CharactersIterator *this,
        const Scaleform::Render::Text::Paragraph *pparagraph,
        int index)
{
  int NearestRangeIndex; // eax
  unsigned int Size; // edi
  int v6; // eax
  const Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *pArray; // ecx
  Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> > *v8; // eax
  const Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *v9; // edx
  int v10; // eax

  this->PlaceHolder.pFormat.pObject = 0;
  this->PlaceHolder.Index = 0;
  this->PlaceHolder.Character = 0;
  this->pFormatInfo = &pparagraph->FormatInfo;
  NearestRangeIndex = Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::FindNearestRangeIndex(
                        &pparagraph->FormatInfo,
                        index);
  this->FormatIterator.pArray = &pparagraph->FormatInfo;
  this->FormatIterator.Index = 0;
  if ( NearestRangeIndex >= 0 )
  {
    Size = pparagraph->FormatInfo.Ranges.Data.Size;
    if ( NearestRangeIndex < Size )
      this->FormatIterator.Index = NearestRangeIndex;
    else
      this->FormatIterator.Index = Size - 1;
  }
  else
  {
    this->FormatIterator.Index = 0;
  }
  this->pText = (const Scaleform::Render::Text::Paragraph::TextBuffer *)pparagraph;
  this->CurTextIndex = index;
  v6 = this->FormatIterator.Index;
  if ( v6 >= 0 )
  {
    pArray = this->FormatIterator.pArray;
    if ( v6 < pArray->Ranges.Data.Size )
    {
      v8 = &pArray->Ranges.Data.Data[v6];
      if ( index < v8->Index || index > (signed int)(v8->Length + v8->Index - 1) )
      {
        v9 = this->FormatIterator.pArray;
        if ( index > v9->Ranges.Data.Data[this->FormatIterator.Index].Index )
        {
          v10 = this->FormatIterator.Index;
          if ( v10 < (signed int)v9->Ranges.Data.Size )
            this->FormatIterator.Index = v10 + 1;
        }
      }
    }
  }
}
