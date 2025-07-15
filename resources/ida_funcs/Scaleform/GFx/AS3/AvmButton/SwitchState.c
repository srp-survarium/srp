void __thiscall Scaleform::GFx::AS3::AvmButton::SwitchState(
        Scaleform::GFx::AS3::AvmButton *this,
        Scaleform::GFx::ButtonRecord::MouseState mouseState)
{
  const char *pClassName; // ecx
  Scaleform::GFx::Button::ButtonState ButtonState; // eax

  pClassName = this[-1].pClassName;
  if ( (*((_WORD *)pClassName + 31) & 0x10) == 0
    && (*((_WORD *)pClassName + 31) & 0x1000) == 0
    && *((int *)pClassName + 6) >= -1 )
  {
    ButtonState = Scaleform::GFx::Button::GetButtonState(mouseState);
    Scaleform::GFx::AS3::AvmButton::SwitchStateIntl((Scaleform::GFx::AS3::AvmButton *)((char *)this - 36), ButtonState);
  }
}
