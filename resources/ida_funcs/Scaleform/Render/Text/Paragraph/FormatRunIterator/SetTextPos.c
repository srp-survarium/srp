void __thiscall Scaleform::Render::Text::Paragraph::FormatRunIterator::SetTextPos(
        Scaleform::Render::Text::Paragraph::FormatRunIterator *this,
        signed int newTextPos)
{
  int Index; // eax
  const Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *pArray; // edx
  unsigned int CurTextIndex; // ecx
  unsigned int *v6; // eax
  int v7; // eax

  while ( this->CurTextIndex < this->pText->Size )
  {
    if ( Scaleform::Render::Text::Paragraph::FormatRunIterator::operator*(this)->PlaceHolder.Index >= newTextPos )
      break;
    Index = this->FormatIterator.Index;
    if ( Index < 0 || (pArray = this->FormatIterator.pArray, Index >= pArray->Ranges.Data.Size) )
    {
      this->CurTextIndex = this->pText->Size;
    }
    else
    {
      CurTextIndex = this->CurTextIndex;
      v6 = (unsigned int *)&pArray->Ranges.Data.Data[Index];
      if ( CurTextIndex >= *v6 )
      {
        this->CurTextIndex = CurTextIndex + v6[1];
        v7 = this->FormatIterator.Index;
        if ( v7 < (signed int)this->FormatIterator.pArray->Ranges.Data.Size )
          this->FormatIterator.Index = v7 + 1;
      }
      else
      {
        this->CurTextIndex = *v6;
      }
    }
  }
}
