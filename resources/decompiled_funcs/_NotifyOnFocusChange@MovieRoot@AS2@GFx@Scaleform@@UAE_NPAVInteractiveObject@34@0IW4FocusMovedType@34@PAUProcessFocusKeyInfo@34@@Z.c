bool __thiscall Scaleform::GFx::AS2::MovieRoot::NotifyOnFocusChange(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::InteractiveObject *curFocused,
        Scaleform::GFx::InteractiveObject *newFocus,
        unsigned int __formal,
        Scaleform::GFx::FocusMovedType fmt,
        Scaleform::GFx::ProcessFocusKeyInfo *a6)
{
  return fmt != GFx_FocusMovedByMouse
      || curFocused && curFocused->IsFocusEnabled(curFocused, GFx_FocusMovedByMouse)
      || newFocus && newFocus->IsFocusEnabled(newFocus, GFx_FocusMovedByMouse);
}
