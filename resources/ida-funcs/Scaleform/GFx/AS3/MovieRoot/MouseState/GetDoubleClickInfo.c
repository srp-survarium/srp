Scaleform::GFx::AS3::MovieRoot::MouseState::DoubleClickInfo *__thiscall Scaleform::GFx::AS3::MovieRoot::MouseState::GetDoubleClickInfo(
        Scaleform::GFx::AS3::MovieRoot::MouseState *this,
        unsigned int buttonMask)
{
  float buttonMaska; // [esp+10h] [ebp+4h]

  if ( buttonMask <= 4 )
    return &this->DblClick[ll[buttonMask]];
  buttonMaska = log((double)buttonMask);
  return &this->DblClick[(__int64)buttonMaska];
}
