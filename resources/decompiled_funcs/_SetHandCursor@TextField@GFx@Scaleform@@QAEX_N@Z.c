void __thiscall Scaleform::GFx::TextField::SetHandCursor(Scaleform::GFx::TextField *this, bool v)
{
  if ( v )
    this->Flags |= 0x20u;
  else
    this->Flags &= ~0x20u;
}
