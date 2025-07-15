void __thiscall Scaleform::GFx::TextField::SetIMEDisabledFlag(Scaleform::GFx::TextField *this, bool v)
{
  if ( v )
    this->Flags |= 0x800u;
  else
    this->Flags &= ~0x800u;
}
