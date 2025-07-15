bool __thiscall Scaleform::Mutex::TryLock(Scaleform::Mutex *this)
{
  Scaleform::MutexImpl *pImpl; // esi
  bool result; // al

  pImpl = this->pImpl;
  if ( WaitForSingleObject(pImpl->hMutexOrSemaphore, 0) )
    return 0;
  result = 1;
  ++pImpl->LockCount;
  return result;
}
