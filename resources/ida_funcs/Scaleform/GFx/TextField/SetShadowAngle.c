void __thiscall Scaleform::GFx::TextField::SetShadowAngle(Scaleform::GFx::TextField *this, float v)
{
  Scaleform::Render::Text::DocView *pObject; // eax

  pObject = this->pDocument.pObject;
  pObject->Filter.ShadowAngle = v;
  Scaleform::Render::Text::TextFilter::UpdateShadowOffset(&pObject->Filter);
}
