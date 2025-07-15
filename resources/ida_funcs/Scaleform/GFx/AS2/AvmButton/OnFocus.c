// attributes: thunk
void __thiscall Scaleform::GFx::AS2::AvmButton::OnFocus(
        Scaleform::GFx::AS2::AvmButton *this,
        Scaleform::GFx::InteractiveObject::FocusEventType event,
        Scaleform::GFx::InteractiveObject *oldOrNewFocusCh,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::AS2::AvmCharacter::OnFocus(this, event, oldOrNewFocusCh, controllerIdx, fmt);
}


void __thiscall Scaleform::GFx::AS2::AvmButton::OnFocus(
        char *this,
        Scaleform::GFx::InteractiveObject::FocusEventType a2,
        Scaleform::GFx::InteractiveObject *a3,
        unsigned int a4,
        Scaleform::GFx::FocusMovedType a5)
{
  Scaleform::GFx::AS2::AvmButton::OnFocus((Scaleform::GFx::AS2::AvmButton *)(this - 24), a2, a3, a4, a5);
}
