void __thiscall Scaleform::GFx::InteractiveObject::SetTrackAsMenuFlag(Scaleform::GFx::InteractiveObject *this, bool v)
{
  if ( v )
    this->Flags |= 0x4000u;
  else
    this->Flags &= ~0x4000u;
}
