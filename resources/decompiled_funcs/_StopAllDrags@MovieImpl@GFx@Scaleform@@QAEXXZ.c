void __thiscall Scaleform::GFx::MovieImpl::StopAllDrags(Scaleform::GFx::MovieImpl *this)
{
  this->CurrentDragStates[0].pCharacter = 0;
  this->CurrentDragStates[0].MouseIndex = -1;
  this->CurrentDragStates[1].pCharacter = 0;
  this->CurrentDragStates[1].MouseIndex = -1;
  this->CurrentDragStates[2].pCharacter = 0;
  this->CurrentDragStates[2].MouseIndex = -1;
  this->CurrentDragStates[3].pCharacter = 0;
  this->CurrentDragStates[3].MouseIndex = -1;
  this->CurrentDragStates[4].pCharacter = 0;
  this->CurrentDragStates[4].MouseIndex = -1;
  this->CurrentDragStates[5].pCharacter = 0;
  this->CurrentDragStates[5].MouseIndex = -1;
}
