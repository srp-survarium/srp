void __thiscall Scaleform::GFx::MovieImpl::StopDragCharacter(
        Scaleform::GFx::MovieImpl *this,
        const Scaleform::GFx::InteractiveObject *ch)
{
  if ( this->CurrentDragStates[0].pCharacter == ch )
  {
    this->CurrentDragStates[0].pCharacter = 0;
    this->CurrentDragStates[0].MouseIndex = -1;
  }
  if ( this->CurrentDragStates[1].pCharacter == ch )
  {
    this->CurrentDragStates[1].pCharacter = 0;
    this->CurrentDragStates[1].MouseIndex = -1;
  }
  if ( this->CurrentDragStates[2].pCharacter == ch )
  {
    this->CurrentDragStates[2].pCharacter = 0;
    this->CurrentDragStates[2].MouseIndex = -1;
  }
  if ( this->CurrentDragStates[3].pCharacter == ch )
  {
    this->CurrentDragStates[3].pCharacter = 0;
    this->CurrentDragStates[3].MouseIndex = -1;
  }
  if ( this->CurrentDragStates[4].pCharacter == ch )
  {
    this->CurrentDragStates[4].pCharacter = 0;
    this->CurrentDragStates[4].MouseIndex = -1;
  }
  if ( this->CurrentDragStates[5].pCharacter == ch )
  {
    this->CurrentDragStates[5].pCharacter = 0;
    this->CurrentDragStates[5].MouseIndex = -1;
  }
}
