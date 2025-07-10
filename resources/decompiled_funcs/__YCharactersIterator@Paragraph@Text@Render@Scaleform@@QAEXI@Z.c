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
