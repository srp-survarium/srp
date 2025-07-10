double __thiscall Scaleform::GFx::TextField::GetMaxHScroll(Scaleform::GFx::TextField *this)
{
  return (double)Scaleform::Render::Text::DocView::GetMaxHScroll(this->pDocument.pObject) * 0.05;
}
