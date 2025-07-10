void __thiscall Scaleform::GFx::MovieImpl::SetVerboseAction(Scaleform::GFx::MovieImpl *this, bool verboseAction)
{
  if ( verboseAction )
    this->Flags |= 4u;
  else
    this->Flags &= ~4u;
}
