long double __thiscall Scaleform::GFx::TextField::GetTextHeight(Scaleform::GFx::TextField *this)
{
  return (float)(Scaleform::Render::Text::DocView::GetTextHeight(this->pDocument.pObject) * 0.05000000074505806);
}
