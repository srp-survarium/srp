void __thiscall Scaleform::GFx::MouseState::ResetState(Scaleform::GFx::MouseState *this)
{
  *((_BYTE *)this + 52) &= 0xE0u;
  this->LastPosition.y = 0.0;
  this->LastPosition.x = 0.0;
  this->mPresetCursorType = -1;
  this->CursorType = 0;
  this->PrevButtonsState = 0;
  this->CurButtonsState = 0;
  this->WheelDelta = 0;
}
