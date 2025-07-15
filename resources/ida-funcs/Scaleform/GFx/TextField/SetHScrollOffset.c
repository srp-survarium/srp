void __thiscall Scaleform::GFx::TextField::SetHScrollOffset(Scaleform::GFx::TextField *this, long double hs)
{
  Scaleform::Render::Text::DocView::SetHScrollOffset(this->pDocument.pObject, (__int64)(hs * 20.0));
}
