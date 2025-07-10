void __thiscall Scaleform::GFx::InteractiveObject::SetUseHandCursorFlag(
        Scaleform::GFx::InteractiveObject *this,
        bool v)
{
  if ( v )
    this->Flags |= 0x600u;
  else
    this->Flags = this->Flags & 0xFFFFF9FF | 0x400;
}
