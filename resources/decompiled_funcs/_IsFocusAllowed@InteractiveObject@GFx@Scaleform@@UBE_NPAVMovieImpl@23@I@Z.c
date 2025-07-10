BOOL __thiscall Scaleform::GFx::InteractiveObject::IsFocusAllowed(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::GFx::MovieImpl *proot,
        unsigned int controllerIdx)
{
  unsigned __int8 v3; // si
  Scaleform::GFx::InteractiveObject *pParent; // edx
  Scaleform::GFx::InteractiveObject *v5; // ecx
  unsigned __int16 v6; // ax
  unsigned __int16 FocusGroupMask; // dx

  v3 = proot->FocusGroupIndexes[controllerIdx];
  if ( this->FocusGroupMask )
  {
    FocusGroupMask = this->FocusGroupMask;
  }
  else
  {
    pParent = this->pParent;
    if ( !pParent->FocusGroupMask )
    {
      v5 = pParent->pParent;
      if ( v5 )
      {
        v6 = Scaleform::GFx::InteractiveObject::GetFocusGroupMask(v5);
        pParent->FocusGroupMask = v6;
      }
    }
    FocusGroupMask = pParent->FocusGroupMask;
  }
  return (FocusGroupMask & (1 << v3)) != 0;
}
