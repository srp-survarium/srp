void __thiscall Scaleform::GFx::InteractiveObject::SetFocusRectFlag(Scaleform::GFx::InteractiveObject *this, bool v)
{
  if ( v )
    this->Flags |= 0x180u;
  else
    this->Flags = this->Flags & 0xFFFFFE7F | 0x100;
}
