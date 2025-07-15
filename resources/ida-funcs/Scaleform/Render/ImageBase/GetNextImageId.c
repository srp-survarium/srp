unsigned int __stdcall Scaleform::Render::ImageBase::GetNextImageId()
{
  unsigned int v0; // esi

  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    Scaleform::Lock::Lock(&staticLock, 0);
    atexit(Scaleform::Render::ImageBase::GetNextImageId_::_2_::_dynamic_atexit_destructor_for__staticLock__);
  }
  EnterCriticalSection(&staticLock.cs);
  v0 = ++nextImageId;
  LeaveCriticalSection(&staticLock.cs);
  return v0;
}
