void __thiscall Scaleform::GFx::MovieImpl::SetStageAutoOrients(Scaleform::GFx::MovieImpl *this, bool v)
{
  if ( v )
    this->Flags |= 0x4000u;
  else
    this->Flags &= ~0x4000u;
}
