void __thiscall Scaleform::GFx::TextField::SetNoAutoSelection(Scaleform::GFx::TextField *this, bool v)
{
  if ( v )
    this->Flags |= 0x400u;
  else
    this->Flags &= ~0x400u;
}
