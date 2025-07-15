void __thiscall Scaleform::GFx::InteractiveObject::SetEnabledFlag(Scaleform::GFx::InteractiveObject *this, bool v)
{
  if ( v )
    this->Flags |= 0x10u;
  else
    this->Flags &= ~0x10u;
}
