bool __thiscall Scaleform::GFx::MovieImpl::IsDragging(Scaleform::GFx::MovieImpl *this, unsigned int mouseIndex)
{
  return this->CurrentDragStates[mouseIndex].pCharacter != 0;
}
