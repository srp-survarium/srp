Scaleform::Render::Text::TextFormat *__thiscall Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
        Scaleform::Render::Text::StyledText *this,
        Scaleform::Render::Text::TextFormat **ppdestTextFmt,
        Scaleform::Render::Text::ParagraphFormat **ppdestParaFmt,
        unsigned int pos)
{
  Scaleform::Render::Text::ParagraphFormat *v5; // esi
  Scaleform::Render::Text::TextFormat *result; // eax
  Scaleform::Render::Text::Paragraph *pPara; // esi
  Scaleform::Render::Text::TextFormat *pObject; // ecx
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,Scaleform::AllocatorLH<Scaleform::Render::Text::StyledText::ParagraphPtrWrapper,2>,Scaleform::ArrayDefaultPolicy> >::Iterator paraIter; // [esp+8h] [ebp-8h] BYREF

  result = (Scaleform::Render::Text::TextFormat *)Scaleform::Render::Text::StyledText::GetParagraphByIndex(
                                                    this,
                                                    &paraIter,
                                                    pos,
                                                    &pos);
  v5 = 0;
  LOBYTE(result) = 0;
  if ( !paraIter.pArray
    || paraIter.CurIndex < 0
    || paraIter.CurIndex >= (signed int)paraIter.pArray->Data.Size
    || (pPara = paraIter.pArray->Data.Data[paraIter.CurIndex].pPara,
        result = Scaleform::Render::Text::Paragraph::GetTextFormatPtr(pPara, pos),
        v5 = pPara->pFormat.pObject,
        pObject = result,
        LOBYTE(result) = 1,
        !pObject) )
  {
    pObject = this->pDefaultTextFormat.pObject;
  }
  if ( !v5 )
    v5 = this->pDefaultParagraphFormat.pObject;
  if ( ppdestTextFmt )
    *ppdestTextFmt = pObject;
  if ( ppdestParaFmt )
    *ppdestParaFmt = v5;
  return result;
}
