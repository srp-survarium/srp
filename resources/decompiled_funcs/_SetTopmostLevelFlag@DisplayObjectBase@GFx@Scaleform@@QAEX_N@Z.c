void __thiscall Scaleform::GFx::DisplayObjectBase::SetTopmostLevelFlag(Scaleform::GFx::DisplayObjectBase *this, bool v)
{
  if ( v )
    this->Flags |= 2u;
  else
    this->Flags &= ~2u;
}
