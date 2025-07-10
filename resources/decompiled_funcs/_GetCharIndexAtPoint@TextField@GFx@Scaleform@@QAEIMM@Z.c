int __thiscall Scaleform::GFx::TextField::GetCharIndexAtPoint(Scaleform::GFx::TextField *this, float x, float y)
{
  return Scaleform::Render::Text::DocView::GetCharIndexAtPoint(this->pDocument.pObject, x, y);
}
