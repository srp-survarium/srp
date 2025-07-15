void __thiscall Scaleform::GFx::TextField::SetShadowAlpha(Scaleform::GFx::TextField *this, float v)
{
  Scaleform::Render::Text::DocView::SetShadowAlpha(this->pDocument.pObject, v);
}
