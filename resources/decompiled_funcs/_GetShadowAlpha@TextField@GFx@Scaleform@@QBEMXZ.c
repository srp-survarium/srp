double __thiscall Scaleform::GFx::TextField::GetShadowAlpha(Scaleform::GFx::TextField *this)
{
  return (float)((double)this->pDocument.pObject->Filter.ShadowAlpha / 255.0);
}
