void __thiscall Scaleform::Render::Text::StyledText::GetText(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::WStringBuffer *pBuffer,
        unsigned int startPos,
        unsigned int endPos)
{
  unsigned int Length; // eax
  unsigned int v6; // edi
  unsigned int v7; // esi
  unsigned int v8; // ebp
  unsigned int v9; // ebx
  int CurIndex; // edi
  Scaleform::Render::Text::Paragraph *pPara; // eax
  unsigned int Size; // esi
  unsigned int v13; // edx
  wchar_t *v14; // ecx
  unsigned int v15; // esi
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator paraIter; // [esp+10h] [ebp-8h] BYREF

  Length = endPos;
  if ( endPos == -1 )
    Length = Scaleform::Render::Text::StyledText::GetLength(this);
  v6 = startPos;
  v7 = Length - startPos;
  Scaleform::WStringBuffer::Resize(pBuffer, Length - startPos + 1);
  startPos = 0;
  v8 = v7;
  Scaleform::Render::Text::StyledText::GetParagraphByIndex(this, &paraIter, v6, &startPos);
  v9 = startPos;
  CurIndex = paraIter.CurIndex;
  endPos = 0;
  while ( paraIter.pArray && CurIndex >= 0 && CurIndex < (signed int)paraIter.pArray->Data.Size && v8 )
  {
    pPara = paraIter.pArray->Data.Data[CurIndex].pPara;
    Size = pPara->Text.Size;
    if ( Size )
    {
      v13 = Size - 1;
      if ( pPara->Text.pText && v13 < Size )
        v14 = &pPara->Text.pText[v13];
      else
        v14 = 0;
      if ( !*v14 )
        --Size;
    }
    v15 = Size - v9;
    if ( v15 > v8 )
      v15 = v8;
    memcpy((unsigned __int8 *)&pBuffer->pText[endPos], (unsigned __int8 *)&pPara->Text.pText[v9], 2 * v15);
    endPos += v15;
    v9 = 0;
    v8 -= v15;
    if ( CurIndex < (signed int)paraIter.pArray->Data.Size )
      ++CurIndex;
  }
  pBuffer->pText[endPos] = 0;
}
