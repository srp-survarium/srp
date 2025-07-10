Scaleform::String *__thiscall Scaleform::Render::Text::DocView::GetText(
        Scaleform::Render::Text::DocView *this,
        Scaleform::String *result)
{
  Scaleform::Render::Text::StyledText::GetText(this->pDocument.pObject, result);
  return result;
}
