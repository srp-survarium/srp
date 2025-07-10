unsigned int __thiscall Scaleform::GFx::DisplayObjectBase::IsVerboseAction(Scaleform::GFx::DisplayObjectBase *this)
{
  if ( !this )
    return (MEMORY[0x3F74] >> 2) & 1;
  while ( SLOBYTE(this->Flags) >= 0 )
  {
    this = this->pParent;
    if ( !this )
      return (MEMORY[0x3F74] >> 2) & 1;
  }
  return (this->pASRoot->pMovieImpl->Flags >> 2) & 1;
}
