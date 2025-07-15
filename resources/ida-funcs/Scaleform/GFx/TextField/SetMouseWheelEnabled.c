void __thiscall Scaleform::GFx::TextField::SetMouseWheelEnabled(Scaleform::GFx::TextField *this, bool v)
{
  if ( v )
    this->Flags |= 0x80u;
  else
    this->Flags &= ~0x80u;
}
