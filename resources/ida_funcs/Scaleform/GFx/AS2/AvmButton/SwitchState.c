void __thiscall Scaleform::GFx::AS2::AvmButton::SwitchState(
        Scaleform::GFx::AS2::AvmButton *this,
        Scaleform::GFx::ButtonRecord::MouseState mouseState)
{
  Scaleform::GFx::AS2::AvmButton::RecreateCharacters((Scaleform::GFx::AS2::AvmButton *)((char *)this - 24), mouseState);
}
