unsigned int __thiscall Scaleform::Render::Text::StyledText::GetLength(Scaleform::Render::Text::StyledText *this)
{
  unsigned int result; // eax
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // ebx
  int i; // edi
  Scaleform::Render::Text::Paragraph *pPara; // edx
  unsigned int Size; // ecx
  wchar_t *pText; // edx
  unsigned int v7; // esi
  wchar_t *v8; // edx

  result = 0;
  p_Paragraphs = &this->Paragraphs;
  for ( i = 0; p_Paragraphs && i >= 0 && i < (signed int)p_Paragraphs->Data.Size; ++i )
  {
    pPara = p_Paragraphs->Data.Data[i].pPara;
    Size = pPara->Text.Size;
    if ( Size )
    {
      pText = pPara->Text.pText;
      v7 = Size - 1;
      if ( pText && v7 < Size )
        v8 = &pText[v7];
      else
        v8 = 0;
      if ( !*v8 )
        --Size;
    }
    result += Size;
  }
  return result;
}
