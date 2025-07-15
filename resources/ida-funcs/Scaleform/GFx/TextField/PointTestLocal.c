bool __thiscall Scaleform::GFx::TextField::PointTestLocal(
        Scaleform::GFx::TextField *this,
        const Scaleform::Render::Point<float> *pt,
        unsigned __int8 hitTestMask)
{
  Scaleform::Render::Rect<float> *ViewRect; // eax

  if ( (this->Scaleform::GFx::InteractiveObject::Flags & 0x800) != 0
    || (hitTestMask & 2) != 0 && !this->GetVisible(this) )
  {
    return 0;
  }
  ViewRect = (Scaleform::Render::Rect<float> *)Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
  return Scaleform::Render::Rect<float>::Contains(ViewRect, pt);
}
