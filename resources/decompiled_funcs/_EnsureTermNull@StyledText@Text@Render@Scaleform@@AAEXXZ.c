void __thiscall Scaleform::Render::Text::StyledText::EnsureTermNull(Scaleform::Render::Text::StyledText *this)
{
  signed int Size; // ecx
  signed int v3; // eax
  Scaleform::Render::Text::Paragraph *pPara; // eax
  unsigned int v5; // ecx
  unsigned int v6; // esi
  wchar_t *v7; // ecx
  wchar_t v8; // cx

  Size = this->Paragraphs.Data.Size;
  v3 = Size - 1;
  if ( Size - 1 >= 0 && v3 < Size && (pPara = this->Paragraphs.Data.Data[v3].pPara) != 0
    || (pPara = Scaleform::Render::Text::StyledText::AppendNewParagraph(this, 0)) != 0 )
  {
    v5 = pPara->Text.Size;
    if ( !v5
      || ((v6 = v5 - 1, !pPara->Text.pText) || v6 >= v5 ? (v7 = 0) : (v7 = &pPara->Text.pText[v6]),
          (v8 = *v7, v8 != 13) && v8 != 10) )
    {
      Scaleform::Render::Text::Paragraph::AppendTermNull(
        pPara,
        this->pTextAllocator.pObject,
        this->pDefaultTextFormat.pObject);
    }
  }
}
