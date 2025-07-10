void __thiscall Scaleform::GFx::TextField::SetShadowQuality(Scaleform::GFx::TextField *this, unsigned int v)
{
  Scaleform::Render::Text::DocView *pObject; // eax

  pObject = this->pDocument.pObject;
  if ( v <= 1 )
    pObject->Filter.ShadowFlags &= ~0x80u;
  else
    pObject->Filter.ShadowFlags |= 0x80u;
}
