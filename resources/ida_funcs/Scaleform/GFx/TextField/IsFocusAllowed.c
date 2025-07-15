bool __thiscall Scaleform::GFx::TextField::IsFocusAllowed(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::MovieImpl *proot,
        unsigned int controllerIdx)
{
  unsigned int FocusedControllerIdx; // eax

  if ( (this->pDef.pObject->Flags & 0x1000) != 0 )
    return 0;
  FocusedControllerIdx = this->FocusedControllerIdx;
  return (FocusedControllerIdx == -1 || FocusedControllerIdx == controllerIdx)
      && Scaleform::GFx::InteractiveObject::IsFocusAllowed(this, proot, controllerIdx);
}


bool __thiscall Scaleform::GFx::TextField::IsFocusAllowed(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::MovieImpl *proot,
        unsigned int controllerIdx)
{
  unsigned int FocusedControllerIdx; // eax

  if ( (this->pDef.pObject->Flags & 0x1000) != 0 )
    return 0;
  FocusedControllerIdx = this->FocusedControllerIdx;
  return (FocusedControllerIdx == -1 || FocusedControllerIdx == controllerIdx)
      && Scaleform::GFx::InteractiveObject::IsFocusAllowed(this, proot, controllerIdx);
}
