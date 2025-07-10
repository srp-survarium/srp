void __thiscall Scaleform::GFx::MovieImpl::SuspendGC(Scaleform::GFx::MovieImpl *this, BOOL suspend)
{
  this->pASMovieRoot.pObject->SuspendGC(this->pASMovieRoot.pObject, suspend);
}
