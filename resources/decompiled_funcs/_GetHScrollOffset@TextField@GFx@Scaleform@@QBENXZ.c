double __thiscall Scaleform::GFx::TextField::GetHScrollOffset(Scaleform::GFx::TextField *this)
{
  return (double)Scaleform::Render::Text::DocView::GetHScrollOffset(this->pDocument.pObject) * 0.05;
}
