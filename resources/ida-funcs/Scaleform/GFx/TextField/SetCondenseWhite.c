void __thiscall Scaleform::GFx::TextField::SetCondenseWhite(Scaleform::GFx::TextField *this, bool v)
{
  if ( v )
    this->Flags |= 0x10u;
  else
    this->Flags &= ~0x10u;
}
