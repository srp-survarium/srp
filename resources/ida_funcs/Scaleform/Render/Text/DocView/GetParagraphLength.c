unsigned int __thiscall Scaleform::Render::Text::DocView::GetParagraphLength(
        Scaleform::Render::Text::DocView *this,
        unsigned int charIndex)
{
  Scaleform::Render::Text::DocView::DocumentText *pObject; // ecx
  unsigned int indexInPara; // [esp+4h] [ebp-Ch] BYREF
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator pit; // [esp+8h] [ebp-8h] BYREF

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  pObject = this->pDocument.pObject;
  indexInPara = 0;
  Scaleform::Render::Text::StyledText::GetParagraphByIndex(pObject, &pit, charIndex, &indexInPara);
  if ( pit.pArray && pit.CurIndex >= 0 && pit.CurIndex < (signed int)pit.pArray->Data.Size )
    return Scaleform::Render::Text::Paragraph::GetLength(pit.pArray->Data.Data[pit.CurIndex].pPara);
  else
    return -1;
}
