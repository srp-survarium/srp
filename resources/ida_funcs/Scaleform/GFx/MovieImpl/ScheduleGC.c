void __thiscall Scaleform::GFx::MovieImpl::ScheduleGC(Scaleform::GFx::MovieImpl *this, unsigned int gcFlags)
{
  this->pASMovieRoot.pObject->ScheduleGC(this->pASMovieRoot.pObject, gcFlags);
}
