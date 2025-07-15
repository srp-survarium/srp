wchar_t *__thiscall Scaleform::Render::Text::DocView::GetLineText(
        Scaleform::Render::Text::DocView *this,
        unsigned int lineIndex,
        unsigned int plen)
{
  unsigned int *v3; // ebp
  Scaleform::Render::Text::LineBuffer *p_mLineBuffer; // esi
  Scaleform::Render::Text::LineBuffer::Line *v7; // eax
  int MemSize; // ecx
  unsigned int TextPos; // eax
  Scaleform::Render::Text::DocView::DocumentText *pObject; // ecx
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> > *pArray; // ecx
  int CurIndex; // edi
  Scaleform::Render::Text::LineBuffer::Line *v13; // eax
  unsigned int TextLength; // eax
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator result; // [esp+8h] [ebp-8h] BYREF

  v3 = (unsigned int *)plen;
  if ( !plen )
    return 0;
  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  p_mLineBuffer = &this->mLineBuffer;
  if ( this == (Scaleform::Render::Text::DocView *)-48
    || lineIndex >= this->mLineBuffer.Lines.Data.Size
    || (lineIndex & 0x80000000) != 0 )
  {
    return 0;
  }
  v7 = p_mLineBuffer->Lines.Data.Data[lineIndex];
  MemSize = v7->MemSize;
  TextPos = v7->Data32.TextPos;
  if ( MemSize < 0 )
  {
    TextPos &= 0xFFFFFFu;
    if ( TextPos == 0xFFFFFF )
      TextPos = -1;
  }
  pObject = this->pDocument.pObject;
  plen = 0;
  Scaleform::Render::Text::StyledText::GetParagraphByIndex(pObject, &result, TextPos, &plen);
  pArray = result.pArray;
  if ( !result.pArray )
    return 0;
  CurIndex = result.CurIndex;
  if ( result.CurIndex < 0 || result.CurIndex >= (signed int)result.pArray->Data.Size )
    return 0;
  v13 = p_mLineBuffer->Lines.Data.Data[lineIndex];
  if ( (v13->MemSize & 0x80000000) == 0 )
    TextLength = v13->Data32.TextLength;
  else
    TextLength = HIBYTE(v13->Data8.TextPosAndLength);
  *v3 = TextLength;
  return &pArray->Data.Data[CurIndex].pPara->Text.pText[plen];
}
