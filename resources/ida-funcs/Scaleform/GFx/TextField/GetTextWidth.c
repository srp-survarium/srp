long double __thiscall Scaleform::GFx::TextField::GetTextWidth(Scaleform::GFx::TextField *this)
{
  return (float)(Scaleform::Render::Text::DocView::GetTextWidth(this->pDocument.pObject) * 0.05000000074505806);
}
