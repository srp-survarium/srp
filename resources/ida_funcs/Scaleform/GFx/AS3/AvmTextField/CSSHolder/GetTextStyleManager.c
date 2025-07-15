const Scaleform::GFx::Text::StyleManager *__thiscall Scaleform::GFx::AS3::AvmTextField::CSSHolder::GetTextStyleManager(
        Scaleform::GFx::AS3::AvmTextField::CSSHolder *this)
{
  Scaleform::GFx::AS3::Instances::fl_text::StyleSheet *pObject; // eax

  pObject = this->pASStyleSheet.pObject;
  if ( pObject )
    return &pObject->CSS;
  else
    return 0;
}
