bool __thiscall Scaleform::GFx::AS2::AvmButton::IsFocusEnabled(
        Scaleform::GFx::AS2::AvmButton *this,
        Scaleform::GFx::FocusMovedType fmt)
{
  return fmt != GFx_FocusMovedByMouse;
}
