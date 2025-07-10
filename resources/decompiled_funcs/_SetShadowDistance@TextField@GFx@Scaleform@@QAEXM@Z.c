void __thiscall Scaleform::GFx::TextField::SetShadowDistance(Scaleform::GFx::TextField *this, float v)
{
  Scaleform::Render::Text::DocView *pObject; // eax

  pObject = this->pDocument.pObject;
  pObject->Filter.ShadowDistance = v;
  Scaleform::Render::Text::TextFilter::UpdateShadowOffset(&pObject->Filter);
}
