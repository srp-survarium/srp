Scaleform::String *__thiscall Scaleform::Render::Text::DocView::GetHtml(
        Scaleform::Render::Text::DocView *this,
        Scaleform::String *result)
{
  Scaleform::Render::Text::StyledText::GetHtml(this->pDocument.pObject, result);
  return result;
}
