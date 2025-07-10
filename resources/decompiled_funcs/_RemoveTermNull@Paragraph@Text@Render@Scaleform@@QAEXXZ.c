void __thiscall Scaleform::Render::Text::Paragraph::RemoveTermNull(Scaleform::Render::Text::Paragraph *this)
{
  unsigned int Size; // eax
  wchar_t *pText; // ecx
  unsigned int v4; // edx
  wchar_t *v5; // edx
  unsigned int v6; // edx
  wchar_t *v7; // ecx
  unsigned int v8; // eax

  Size = this->Text.Size;
  if ( Size )
  {
    pText = this->Text.pText;
    v4 = Size - 1;
    if ( this->Text.pText && v4 < Size )
      v5 = &pText[v4];
    else
      v5 = 0;
    if ( !*v5 )
    {
      v6 = Size - 1;
      if ( pText && v6 < Size )
        v7 = &pText[v6];
      else
        v7 = 0;
      if ( !*v7 )
        --Size;
      Scaleform::RangeDataArray<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>,Scaleform::ArrayLH<Scaleform::RangeData<Scaleform::Ptr<Scaleform::Render::Text::TextFormat>>,2,Scaleform::ArrayDefaultPolicy>>::RemoveRange(
        &this->FormatInfo,
        Size,
        1u);
      v8 = this->Text.Size;
      if ( v8 )
      {
        if ( !this->Text.pText[v8 - 1] )
          this->Text.Size = v8 - 1;
      }
    }
  }
}
