Scaleform::GFx::KeyboardState *__thiscall Scaleform::GFx::MovieImpl::GetKeyboardState(
        Scaleform::GFx::MovieImpl *this,
        unsigned int keyboardIndex)
{
  if ( keyboardIndex >= 6 )
    return 0;
  else
    return &this->KeyboardStates[keyboardIndex];
}
