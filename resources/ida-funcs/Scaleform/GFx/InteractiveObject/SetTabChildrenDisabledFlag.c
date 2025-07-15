void __thiscall Scaleform::GFx::InteractiveObject::SetTabChildrenDisabledFlag(
        Scaleform::GFx::InteractiveObject *this,
        bool v)
{
  if ( v )
    this->Flags |= 0x8000u;
  else
    this->Flags &= ~0x8000u;
}
