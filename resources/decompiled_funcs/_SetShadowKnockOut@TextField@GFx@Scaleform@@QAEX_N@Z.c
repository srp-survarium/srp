void __thiscall Scaleform::GFx::TextField::SetShadowKnockOut(Scaleform::GFx::TextField *this, bool v)
{
  Scaleform::Render::Text::DocView *pObject; // eax

  pObject = this->pDocument.pObject;
  if ( v )
    pObject->Filter.ShadowFlags |= 0x20u;
  else
    pObject->Filter.ShadowFlags &= ~0x20u;
}
