void __thiscall Scaleform::GFx::MovieImpl::ForceCollectGarbage(Scaleform::GFx::MovieImpl *this, unsigned int gcFlags)
{
  this->pASMovieRoot.pObject->ForceCollect(this->pASMovieRoot.pObject, gcFlags);
}
