void __thiscall Scaleform::GFx::MovieImpl::SetNoInvisibleAdvanceFlag(Scaleform::GFx::MovieImpl *this, bool f)
{
  if ( f )
    this->Flags |= 0x800u;
  else
    this->Flags &= ~0x800u;
}
