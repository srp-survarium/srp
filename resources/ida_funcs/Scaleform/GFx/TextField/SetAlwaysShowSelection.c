void __thiscall Scaleform::GFx::TextField::SetAlwaysShowSelection(Scaleform::GFx::TextField *this, bool v)
{
  if ( v )
    this->Flags |= 0x200u;
  else
    this->Flags &= ~0x200u;
}
