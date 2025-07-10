void __thiscall Scaleform::GFx::TextField::SetPassword(Scaleform::GFx::TextField *this, bool v)
{
  if ( v )
    this->Flags |= 4u;
  else
    this->Flags &= ~4u;
}
