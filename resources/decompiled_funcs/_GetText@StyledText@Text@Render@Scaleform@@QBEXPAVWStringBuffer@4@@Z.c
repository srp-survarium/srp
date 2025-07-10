void __thiscall Scaleform::Render::Text::StyledText::GetText(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::WStringBuffer *pBuffer)
{
  unsigned int Length; // eax
  int v4; // edi
  Scaleform::ArrayLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2,Scaleform::ArrayDefaultPolicy> *p_Paragraphs; // ebx
  int v6; // ebp
  Scaleform::Render::Text::Paragraph *pPara; // eax
  unsigned int Size; // esi
  unsigned __int8 *pText; // ecx
  unsigned int v10; // eax
  unsigned __int8 *v11; // eax

  Length = Scaleform::Render::Text::StyledText::GetLength(this);
  Scaleform::WStringBuffer::Resize(pBuffer, Length + 1);
  v4 = 0;
  p_Paragraphs = &this->Paragraphs;
  v6 = 0;
  while ( p_Paragraphs && v4 >= 0 && v4 < (signed int)p_Paragraphs->Data.Size )
  {
    pPara = p_Paragraphs->Data.Data[v4].pPara;
    Size = pPara->Text.Size;
    pText = (unsigned __int8 *)pPara->Text.pText;
    if ( Size )
    {
      v10 = Size - 1;
      if ( pText && v10 < Size )
        v11 = &pText[2 * v10];
      else
        v11 = 0;
      if ( !*(_WORD *)v11 )
        --Size;
    }
    memcpy((unsigned __int8 *)&pBuffer->pText[v6], pText, 2 * Size);
    v6 += Size;
    if ( v4 < (signed int)p_Paragraphs->Data.Size )
      ++v4;
  }
  pBuffer->pText[v6] = 0;
}
