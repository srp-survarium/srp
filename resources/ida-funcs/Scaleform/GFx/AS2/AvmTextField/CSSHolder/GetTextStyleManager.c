const Scaleform::GFx::Text::StyleManager *__thiscall Scaleform::GFx::AS2::AvmTextField::CSSHolder::GetTextStyleManager(
        Scaleform::GFx::AS2::AvmTextField::CSSHolder *this)
{
  Scaleform::GFx::AS2::StyleSheetObject *pObject; // eax

  pObject = this->pASStyleSheet.pObject;
  if ( pObject )
    return &pObject->CSS;
  else
    return 0;
}
