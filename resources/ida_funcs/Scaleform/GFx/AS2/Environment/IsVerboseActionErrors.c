BOOL __thiscall Scaleform::GFx::AS2::Environment::IsVerboseActionErrors(Scaleform::GFx::AS2::Environment *this)
{
  return (this->Target->pASRoot->pMovieImpl->Flags & 0x40) == 0;
}
