void __thiscall Scaleform::GFx::TextField::SetFontScaleFactor(Scaleform::GFx::TextField *this, float f)
{
  Scaleform::Render::Text::DocView::SetFontScaleFactor(this->pDocument.pObject, f);
}
