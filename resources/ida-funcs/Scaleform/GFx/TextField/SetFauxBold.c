void __thiscall Scaleform::GFx::TextField::SetFauxBold(Scaleform::GFx::TextField *this, bool v)
{
  Scaleform::Render::Text::DocView *pObject; // eax

  pObject = this->pDocument.pObject;
  if ( v )
    pObject->FlagsEx |= 1u;
  else
    pObject->FlagsEx &= ~1u;
}
