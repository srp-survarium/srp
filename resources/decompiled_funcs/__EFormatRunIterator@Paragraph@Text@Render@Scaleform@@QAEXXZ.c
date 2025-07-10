void __thiscall Scaleform::Render::Text::Paragraph::FormatRunIterator::operator++(
        Scaleform::Render::Text::Paragraph::FormatRunIterator *this)
{
  int Index; // eax
  const Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *pArray; // edx
  unsigned int *v3; // eax
  unsigned int CurTextIndex; // edx
  int v5; // eax

  Index = this->FormatIterator.Index;
  if ( Index < 0 || (pArray = this->FormatIterator.pArray, Index >= pArray->Ranges.Data.Size) )
  {
    this->CurTextIndex = this->pText->Size;
  }
  else
  {
    v3 = (unsigned int *)&pArray->Ranges.Data.Data[Index];
    CurTextIndex = this->CurTextIndex;
    if ( CurTextIndex >= *v3 )
    {
      this->CurTextIndex = CurTextIndex + v3[1];
      v5 = this->FormatIterator.Index;
      if ( v5 < (signed int)this->FormatIterator.pArray->Ranges.Data.Size )
        this->FormatIterator.Index = v5 + 1;
    }
    else
    {
      this->CurTextIndex = *v3;
    }
  }
}
