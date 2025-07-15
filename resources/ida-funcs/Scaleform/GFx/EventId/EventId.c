void __thiscall Scaleform::GFx::EventId::EventId(Scaleform::GFx::EventId *this, unsigned int id)
{
  this->Id = id;
  this->WcharCode = 0;
  this->KeyCode = 0;
  this->AsciiCode = 0;
  this->RollOverCnt = 0;
  this->KeysState.States = 0;
  this->MouseWheelDelta = 0;
  this->ControllerIndex = -1;
}
