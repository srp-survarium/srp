Scaleform::String *__thiscall Scaleform::Render::Text::StyledText::GetText(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::String *retStr)
{
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // edi
  int v4; // esi
  Scaleform::Render::Text::Paragraph *pPara; // eax
  const wchar_t *pText; // ecx
  unsigned int Size; // eax
  unsigned int v8; // edx
  const wchar_t *v9; // edx

  Scaleform::String::operator=(retStr, (char *)&buf);
  p_Paragraphs = &this->Paragraphs;
  v4 = 0;
  while ( p_Paragraphs && v4 >= 0 && v4 < (signed int)p_Paragraphs->Data.Size )
  {
    pPara = p_Paragraphs->Data.Data[v4].pPara;
    pText = pPara->Text.pText;
    Size = pPara->Text.Size;
    if ( Size )
    {
      v8 = Size - 1;
      if ( pText && v8 < Size )
        v9 = &pText[v8];
      else
        v9 = 0;
      if ( !*v9 )
        --Size;
    }
    Scaleform::String::AppendString(retStr, pText, Size);
    if ( v4 < (signed int)p_Paragraphs->Data.Size )
      ++v4;
  }
  return retStr;
}
