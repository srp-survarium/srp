void __thiscall Scaleform::Render::Text::StyledText::SetTextFormat(
        Scaleform::Render::Text::StyledText *this,
        const Scaleform::Render::Text::TextFormat *fmt,
        unsigned int startPos,
        unsigned int endPos)
{
  Scaleform::Render::Text::StyledText *v4; // edi
  unsigned int v5; // ebx
  int CurIndex; // ebp
  Scaleform::Render::Text::Paragraph *pPara; // ecx
  unsigned int Size; // eax
  unsigned int v9; // edx
  unsigned int v10; // edi
  wchar_t *v11; // esi
  unsigned int v12; // esi
  unsigned int v13; // edi
  wchar_t *v14; // eax
  unsigned int indexInPara; // [esp+10h] [ebp-10h] BYREF
  Scaleform::Render::Text::StyledText *v16; // [esp+14h] [ebp-Ch]
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator paraIter; // [esp+18h] [ebp-8h] BYREF
  unsigned int runLen; // [esp+28h] [ebp+8h]

  v4 = this;
  v16 = this;
  Scaleform::Render::Text::StyledText::GetParagraphByIndex(this, &paraIter, startPos, &indexInPara);
  v5 = indexInPara;
  CurIndex = paraIter.CurIndex;
  runLen = endPos - startPos;
  while ( paraIter.pArray && CurIndex >= 0 && CurIndex < (signed int)paraIter.pArray->Data.Size )
  {
    pPara = paraIter.pArray->Data.Data[CurIndex].pPara;
    Size = pPara->Text.Size;
    v9 = Size;
    if ( Size )
    {
      v10 = Size - 1;
      if ( pPara->Text.pText && v10 < Size )
        v11 = &pPara->Text.pText[v10];
      else
        v11 = 0;
      if ( !*v11 )
        v9 = Size - 1;
    }
    v12 = v5 + runLen;
    if ( v5 + runLen <= v9 )
    {
      if ( v5 + runLen != v9 )
        goto LABEL_23;
    }
    else
    {
      v12 = v9;
    }
    if ( Size )
    {
      v13 = Size - 1;
      if ( pPara->Text.pText && v13 < Size )
        v14 = &pPara->Text.pText[v13];
      else
        v14 = 0;
      if ( !*v14 )
      {
        ++v12;
        if ( runLen != -1 )
          ++runLen;
      }
    }
LABEL_23:
    v4 = v16;
    Scaleform::Render::Text::Paragraph::SetTextFormat(pPara, v16->pTextAllocator.pObject, fmt, v5, v12);
    runLen += v5 - v12;
    v5 = 0;
    if ( CurIndex < (signed int)paraIter.pArray->Data.Size )
      ++CurIndex;
  }
  if ( (fmt->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&fmt->Url) )
    v4->RTFlags |= 1u;
}
