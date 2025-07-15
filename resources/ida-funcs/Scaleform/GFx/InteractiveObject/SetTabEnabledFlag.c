void __thiscall Scaleform::GFx::InteractiveObject::SetTabEnabledFlag(Scaleform::GFx::InteractiveObject *this, bool v)
{
  if ( v )
    this->Flags |= 0x60u;
  else
    this->Flags = this->Flags & 0xFFFFFF9F | 0x40;
}
