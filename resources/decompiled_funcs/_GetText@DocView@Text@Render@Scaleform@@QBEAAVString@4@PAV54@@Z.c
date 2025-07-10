Scaleform::String *__thiscall Scaleform::Render::Text::DocView::GetText(
        Scaleform::Render::Text::DocView *this,
        Scaleform::String *retStr)
{
  return Scaleform::Render::Text::StyledText::GetText(this->pDocument.pObject, retStr);
}
