BOOL __thiscall Scaleform::GFx::InteractiveObject::IsFocusAllowed(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::GFx::MovieImpl *proot,
        unsigned int controllerIdx)
{
  Scaleform::GFx::InteractiveObject *v3; // edx
  unsigned __int8 v4; // si
  Scaleform::GFx::InteractiveObject *pParent; // ecx
  unsigned __int16 FocusGroupMask; // ax

  v3 = this;
  v4 = proot->FocusGroupIndexes[controllerIdx];
  if ( !this->FocusGroupMask )
  {
    pParent = this->pParent;
    if ( pParent )
    {
      FocusGroupMask = Scaleform::GFx::InteractiveObject::GetFocusGroupMask(pParent);
      v3->FocusGroupMask = FocusGroupMask;
    }
  }
  return (v3->FocusGroupMask & (1 << v4)) != 0;
}
