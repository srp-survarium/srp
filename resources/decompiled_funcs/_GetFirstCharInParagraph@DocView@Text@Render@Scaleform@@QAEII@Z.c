unsigned int __thiscall Scaleform::Render::Text::DocView::GetFirstCharInParagraph(
        Scaleform::Render::Text::DocView *this,
        unsigned int indexOfChar)
{
  Scaleform::Render::Text::DocView::DocumentText *pObject; // ecx
  unsigned int indexInPara; // [esp+4h] [ebp-Ch] BYREF
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator pit; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pDocument.pObject;
  indexInPara = -1;
  Scaleform::Render::Text::StyledText::GetParagraphByIndex(pObject, &pit, indexOfChar, &indexInPara);
  if ( pit.pArray && pit.CurIndex >= 0 && pit.CurIndex < (signed int)pit.pArray->Data.Size )
    return indexOfChar - indexInPara;
  else
    return -1;
}
