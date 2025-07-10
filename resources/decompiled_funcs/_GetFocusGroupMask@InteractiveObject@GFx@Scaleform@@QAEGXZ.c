unsigned __int16 __thiscall Scaleform::GFx::InteractiveObject::GetFocusGroupMask(
        Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::InteractiveObject *pParent; // ecx

  if ( !this->FocusGroupMask )
  {
    pParent = this->pParent;
    if ( pParent )
      this->FocusGroupMask = Scaleform::GFx::InteractiveObject::GetFocusGroupMask(pParent);
  }
  return this->FocusGroupMask;
}
