double __thiscall Scaleform::Render::Text::ParagraphFormatter::GetActualFontSize(
        Scaleform::Render::Text::ParagraphFormatter *this)
{
  Scaleform::Render::Text::FontHandle *pObject; // edx
  Scaleform::Render::Text::DocView *pDocView; // ecx
  float fontSize; // [esp+0h] [ebp-8h]
  float v5; // [esp+4h] [ebp-4h]

  pObject = this->FindFontInfo.pCurrentFont.pObject;
  fontSize = (double)this->FindFontInfo.pCurrentFormat->FontSize * 0.05000000074505806;
  if ( 1.0 != pObject->FontScaleFactor )
    fontSize = pObject->FontScaleFactor * fontSize;
  pDocView = this->pDocView;
  if ( (pDocView->RTFlags & 4) != 0 )
  {
    v5 = 0.05000000074505806 * (double)pDocView->FontScaleFactor;
    return (float)(v5 * fontSize);
  }
  return fontSize;
}
