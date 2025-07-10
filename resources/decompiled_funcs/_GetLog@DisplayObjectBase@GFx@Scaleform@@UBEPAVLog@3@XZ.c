Scaleform::Log *__thiscall Scaleform::GFx::DisplayObjectBase::GetLog(Scaleform::GFx::DisplayObjectBase *this)
{
  if ( !this )
    return Scaleform::GFx::MovieImpl::GetCachedLog(0);
  while ( SLOBYTE(this->Flags) >= 0 )
  {
    this = this->pParent;
    if ( !this )
      return Scaleform::GFx::MovieImpl::GetCachedLog(0);
  }
  return Scaleform::GFx::MovieImpl::GetCachedLog(this->pASRoot->pMovieImpl);
}
