void __thiscall Scaleform::GFx::InteractiveObject::SetHitTestDisableFlag(
        Scaleform::GFx::InteractiveObject *this,
        bool v)
{
  if ( v )
    this->Flags |= 0x800u;
  else
    this->Flags &= ~0x800u;
}
