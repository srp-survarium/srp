void __thiscall Scaleform::GFx::TextField::SetShadowHideObject(Scaleform::GFx::TextField *this, bool v)
{
  Scaleform::Render::Text::DocView *pObject; // eax

  pObject = this->pDocument.pObject;
  if ( v )
    pObject->Filter.ShadowFlags |= 0x40u;
  else
    pObject->Filter.ShadowFlags &= ~0x40u;
}
