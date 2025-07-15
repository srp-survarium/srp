void __thiscall Scaleform::Mutex::DoLock(Scaleform::Mutex *this)
{
  Scaleform::MutexImpl *pImpl; // esi

  pImpl = this->pImpl;
  if ( !WaitForSingleObject(pImpl->hMutexOrSemaphore, 0xFFFFFFFF) )
    ++pImpl->LockCount;
}
