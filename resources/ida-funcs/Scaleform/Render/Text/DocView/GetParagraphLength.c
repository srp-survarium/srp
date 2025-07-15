unsigned int __thiscall Scaleform::Render::Text::DocView::GetParagraphLength(
        Scaleform::Render::Text::DocView *this,
        unsigned int charIndex)
{
  Scaleform::Render::Text::DocView::DocumentText *pObject; // ecx
  unsigned int pindexInParagraph; // [esp+4h] [ebp-Ch] BYREF
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator result; // [esp+8h] [ebp-8h] BYREF

  if ( (this->RTFlags & 3) != 0 )
  {
    Scaleform::Render::Text::DocView::Format(this);
    this->RTFlags &= 0xFCu;
  }
  pObject = this->pDocument.pObject;
  pindexInParagraph = 0;
  Scaleform::Render::Text::StyledText::GetParagraphByIndex(pObject, &result, charIndex, &pindexInParagraph);
  if ( result.pArray && result.CurIndex >= 0 && result.CurIndex < (signed int)result.pArray->Data.Size )
    return Scaleform::Render::Text::Paragraph::GetLength(result.pArray->Data.Data[result.CurIndex].pPara);
  else
    return -1;
}
