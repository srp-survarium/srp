void __thiscall Scaleform::GFx::TextField::SetFauxItalic(Scaleform::GFx::TextField *this, bool v)
{
  Scaleform::Render::Text::DocView *pObject; // eax

  pObject = this->pDocument.pObject;
  if ( v )
    pObject->FlagsEx |= 2u;
  else
    pObject->FlagsEx &= ~2u;
}
