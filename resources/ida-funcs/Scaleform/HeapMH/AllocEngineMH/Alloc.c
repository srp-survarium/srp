char *__thiscall Scaleform::HeapMH::AllocEngineMH::Alloc(
        Scaleform::HeapMH::AllocEngineMH *this,
        unsigned int size,
        unsigned int alignSize,
        Scaleform::HeapMH::PageInfoMH *info,
        Scaleform::LockSafe::Locker globalLocked)
{
  unsigned int v5; // eax
  unsigned int v7; // ecx
  char *result; // eax
  unsigned int v9; // ebp
  unsigned int v10; // esi
  Scaleform::HeapMH::PageInfoMH *v11; // edi
  char *v12; // edi

  v5 = size;
  if ( size > 0x200 )
  {
    v9 = alignSize;
    if ( alignSize < 4 )
      v9 = 4;
    if ( size < v9 )
      v5 = v9;
    v10 = (v5 + 3) & 0xFFFFFFFC;
    if ( LOBYTE(globalLocked.pLock) )
    {
      v11 = info;
      LOBYTE(alignSize) = 0;
      do
        result = Scaleform::HeapMH::AllocEngineMH::allocDirect(this, v10, v9, (bool *)&alignSize, v11);
      while ( !result && (_BYTE)alignSize );
    }
    else
    {
      globalLocked.pLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      EnterCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      LOBYTE(alignSize) = 0;
      while ( 1 )
      {
        v12 = Scaleform::HeapMH::AllocEngineMH::allocDirect(this, v10, v9, (bool *)&alignSize, info);
        if ( v12 )
          break;
        if ( !(_BYTE)alignSize )
        {
          LeaveCriticalSection(&globalLocked.pLock->mLock.cs);
          return 0;
        }
      }
      LeaveCriticalSection(&globalLocked.pLock->mLock.cs);
      return v12;
    }
  }
  else
  {
    v7 = alignSize;
    if ( alignSize < 0x10 )
      v7 = 16;
    return (char *)Scaleform::HeapMH::AllocEngineMH::allocFromPage(
                     this,
                     (size + 15) & 0xFFFFFFF0,
                     v7,
                     info,
                     (bool)globalLocked.pLock);
  }
  return result;
}


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
