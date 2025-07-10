void __thiscall Scaleform::Render::Text::StyledText::SetParagraphFormat(
        Scaleform::Render::Text::StyledText *this,
        const Scaleform::Render::Text::ParagraphFormat *fmt,
        unsigned int startPos,
        unsigned int endPos)
{
  unsigned int v4; // esi
  unsigned int v5; // edi
  int CurIndex; // ebx
  unsigned int v7; // ebp
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *pArray; // edx
  Scaleform::Render::Text::Paragraph *pPara; // esi
  unsigned int Size; // eax
  wchar_t *pText; // esi
  unsigned int v12; // ecx
  wchar_t *v13; // ecx
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator paraIter; // [esp+14h] [ebp-8h] BYREF

  v4 = startPos;
  Scaleform::Render::Text::StyledText::GetParagraphByIndex(this, &paraIter, startPos, &startPos);
  v5 = startPos;
  CurIndex = paraIter.CurIndex;
  v7 = endPos - v4;
  while ( 1 )
  {
    pArray = paraIter.pArray;
    if ( !paraIter.pArray || CurIndex < 0 || CurIndex >= (signed int)paraIter.pArray->Data.Size )
      break;
    pPara = paraIter.pArray->Data.Data[CurIndex].pPara;
    if ( !v5 )
    {
      Scaleform::Render::Text::Paragraph::SetFormat(pPara, this->pTextAllocator.pObject, fmt);
      pArray = paraIter.pArray;
    }
    if ( !v7 )
      break;
    Size = pPara->Text.Size;
    if ( Size )
    {
      pText = pPara->Text.pText;
      v12 = Size - 1;
      if ( pText && v12 < Size )
        v13 = &pText[v12];
      else
        v13 = 0;
      if ( !*v13 )
        --Size;
    }
    if ( v7 <= Size )
      Size = v5 + v7;
    v7 += v5 - Size;
    v5 = 0;
    if ( CurIndex < (signed int)pArray->Data.Size )
      ++CurIndex;
  }
}
