BOOL __thiscall Scaleform::GFx::MovieImpl::HasLooped(Scaleform::GFx::MovieImpl *this)
{
  return this->pMainMovie && this->pMainMovie->HasLooped(this->pMainMovie);
}
