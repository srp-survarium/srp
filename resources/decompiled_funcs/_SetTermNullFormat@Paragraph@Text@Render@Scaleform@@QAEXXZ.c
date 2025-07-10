void __thiscall Scaleform::Render::Text::Paragraph::SetTermNullFormat(Scaleform::Render::Text::Paragraph *this)
{
  unsigned int Size; // eax
  wchar_t *pText; // edx
  unsigned int v3; // esi
  wchar_t *v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // esi
  wchar_t *v7; // eax
  Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat> >,2,Scaleform::ArrayDefaultPolicy> > *p_FormatInfo; // esi

  Size = this->Text.Size;
  if ( Size )
  {
    pText = this->Text.pText;
    v3 = Size - 1;
    if ( this->Text.pText && v3 < Size )
      v4 = &pText[v3];
    else
      v4 = 0;
    if ( !*v4 )
    {
      v5 = this->Text.Size;
      v6 = Size - 1;
      if ( pText && v6 < Size )
        v7 = &pText[v6];
      else
        v7 = 0;
      if ( !*v7 )
        --v5;
      p_FormatInfo = &this->FormatInfo;
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::ExpandRange(
        &this->FormatInfo,
        v5,
        1u);
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::RemoveRange(
        p_FormatInfo,
        v5 + 1,
        1u);
    }
  }
}
