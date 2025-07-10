void __thiscall Scaleform::GFx::MovieImpl::SetActionErrorsSuppress(
        Scaleform::GFx::MovieImpl *this,
        bool suppressActionErrors)
{
  if ( suppressActionErrors )
    this->Flags |= 0x40u;
  else
    this->Flags &= ~0x40u;
}
