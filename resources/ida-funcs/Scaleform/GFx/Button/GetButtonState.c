int __cdecl Scaleform::GFx::Button::GetButtonState(Scaleform::GFx::ButtonRecord::MouseState mouseState)
{
  if ( mouseState == Unknown )
    return 0;
  if ( mouseState == MouseMove )
    return 2;
  return mouseState == MouseDown;
}
