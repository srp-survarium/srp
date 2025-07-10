const Scaleform::GFx::AS3::MovieRoot::MouseState *__thiscall Scaleform::GFx::AS3::MovieRoot::GetAS3MouseState(
        Scaleform::GFx::AS3::MovieRoot *this,
        unsigned int mouseIndex)
{
  if ( mouseIndex < 6 )
    return &this->mMouseState[mouseIndex];
  else
    return 0;
}
