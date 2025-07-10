void __thiscall Scaleform::GFx::MovieImpl::SetContinueAnimationFlag(Scaleform::GFx::MovieImpl *this, bool f)
{
  if ( f )
    this->Flags |= 0x2000u;
  else
    this->Flags &= ~0x2000u;
}
