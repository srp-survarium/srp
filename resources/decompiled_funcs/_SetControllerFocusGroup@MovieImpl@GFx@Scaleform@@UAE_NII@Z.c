char __thiscall Scaleform::GFx::MovieImpl::SetControllerFocusGroup(
        Scaleform::GFx::MovieImpl *this,
        unsigned int controllerIdx,
        unsigned int focusGroupIndex)
{
  if ( controllerIdx >= 0x10 || focusGroupIndex >= 0x10 )
    return 0;
  this->FocusGroupIndexes[controllerIdx] = focusGroupIndex;
  if ( focusGroupIndex >= this->FocusGroupsCnt )
    this->FocusGroupsCnt = focusGroupIndex + 1;
  return 1;
}
