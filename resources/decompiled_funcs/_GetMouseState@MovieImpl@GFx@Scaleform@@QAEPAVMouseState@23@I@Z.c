Scaleform::GFx::MouseState *__thiscall Scaleform::GFx::MovieImpl::GetMouseState(
        Scaleform::GFx::MovieImpl *this,
        unsigned int mouseIndex)
{
  if ( mouseIndex < 6 )
    return &this->mMouseState[mouseIndex];
  else
    return 0;
}
