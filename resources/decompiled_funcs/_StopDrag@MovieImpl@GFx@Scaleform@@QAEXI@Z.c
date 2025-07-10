void __thiscall Scaleform::GFx::MovieImpl::StopDrag(Scaleform::GFx::MovieImpl *this, unsigned int mouseIndex)
{
  this->CurrentDragStates[mouseIndex].pCharacter = 0;
  this->CurrentDragStates[mouseIndex].MouseIndex = -1;
}
