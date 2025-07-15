unsigned int __thiscall Scaleform::Render::Text::DocView::GetFirstCharInParagraph(
        Scaleform::Render::Text::DocView *this,
        unsigned int indexOfChar)
{
  Scaleform::Render::Text::DocView::DocumentText *pObject; // ecx
  unsigned int pindexInParagraph; // [esp+4h] [ebp-Ch] BYREF
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator result; // [esp+8h] [ebp-8h] BYREF

  pObject = this->pDocument.pObject;
  pindexInParagraph = -1;
  Scaleform::Render::Text::StyledText::GetParagraphByIndex(pObject, &result, indexOfChar, &pindexInParagraph);
  if ( result.pArray && result.CurIndex >= 0 && result.CurIndex < (signed int)result.pArray->Data.Size )
    return indexOfChar - pindexInParagraph;
  else
    return -1;
}
