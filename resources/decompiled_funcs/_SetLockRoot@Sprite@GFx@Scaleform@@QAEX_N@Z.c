void __thiscall Scaleform::GFx::Sprite::SetLockRoot(Scaleform::GFx::Sprite *this, bool v)
{
  unsigned __int8 Flags; // al

  Flags = this->Flags;
  if ( v )
    this->Flags = Flags | 0x20;
  else
    this->Flags = Flags & 0xDF;
}
