Scaleform::GFx::MovieImpl *__thiscall Scaleform::GFx::DisplayObjectBase::FindMovieImpl(
        Scaleform::GFx::DisplayObjectBase *this)
{
  if ( !this )
    return 0;
  while ( SLOBYTE(this->Flags) >= 0 )
  {
    this = this->pParent;
    if ( !this )
      return 0;
  }
  return this->pASRoot->pMovieImpl;
}
