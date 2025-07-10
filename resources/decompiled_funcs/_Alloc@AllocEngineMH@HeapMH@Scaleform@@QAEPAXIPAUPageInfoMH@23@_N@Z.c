char *__thiscall Scaleform::HeapMH::AllocEngineMH::Alloc(
        Scaleform::HeapMH::AllocEngineMH *this,
        unsigned int size,
        Scaleform::HeapMH::PageInfoMH *info,
        Scaleform::LockSafe::Locker globalLocked)
{
  unsigned int MinAlignSize; // eax
  char *result; // eax
  char *v8; // edi
  Scaleform::LockSafe *rl; // [esp+8h] [ebp+4h]

  MinAlignSize = this->MinAlignSize;
  if ( MinAlignSize > 0x10 )
    return Scaleform::HeapMH::AllocEngineMH::Alloc(this, size, MinAlignSize, info, globalLocked);
  if ( size <= 0x200 )
    return (char *)Scaleform::HeapMH::AllocEngineMH::allocFromPage(
                     this,
                     (size + 15) & 0xFFFFFFF0,
                     info,
                     (bool)globalLocked.pLock);
  if ( LOBYTE(globalLocked.pLock) )
  {
    LOBYTE(globalLocked.pLock) = 0;
    do
      result = Scaleform::HeapMH::AllocEngineMH::allocDirect(
                 this,
                 size,
                 this->MinAlignSize,
                 (bool *)&globalLocked,
                 info);
    while ( !result && LOBYTE(globalLocked.pLock) );
  }
  else
  {
    rl = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    LOBYTE(globalLocked.pLock) = 0;
    while ( 1 )
    {
      v8 = Scaleform::HeapMH::AllocEngineMH::allocDirect(this, size, this->MinAlignSize, (bool *)&globalLocked, info);
      if ( v8 )
        break;
      if ( !LOBYTE(globalLocked.pLock) )
      {
        LeaveCriticalSection(&rl->mLock.cs);
        return 0;
      }
    }
    LeaveCriticalSection(&rl->mLock.cs);
    return v8;
  }
  return result;
}
