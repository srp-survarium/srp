char __thiscall Scaleform::Mutex::TryAcquireCancel(Scaleform::Mutex *this)
{
  Scaleform::MutexImpl::Unlock(
    *((Scaleform::MutexImpl **)&this[-1].pHandlers + 4),
    (Scaleform::Mutex *)((char *)this - 12));
  return 1;
}
