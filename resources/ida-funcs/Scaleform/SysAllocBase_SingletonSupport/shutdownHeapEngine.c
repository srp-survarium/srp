char __thiscall Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocMalloc,Scaleform::SysAlloc>::shutdownHeapEngine(
        Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocMalloc,Scaleform::SysAlloc> *this)
{
  Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocMalloc,Scaleform::SysAlloc>::SysAllocContainer *pContainer; // eax
  char v4; // [esp+7h] [ebp-1h]

  v4 = Scaleform::SysAlloc::shutdownHeapEngine(this);
  pContainer = this->pContainer;
  if ( pContainer )
  {
    pContainer->Initialized = 0;
    ((void (__thiscall *)(Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocMalloc,Scaleform::SysAlloc> *, _DWORD))this->~Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocMalloc,Scaleform::SysAlloc>)(
      this,
      0);
    this->pContainer = 0;
  }
  return v4;
}


char __thiscall Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocPagedMalloc,Scaleform::SysAllocPaged>::shutdownHeapEngine(
        Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocPagedMalloc,Scaleform::SysAllocPaged> *this)
{
  char v2; // bl
  Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocPagedMalloc,Scaleform::SysAllocPaged>::SysAllocContainer *pContainer; // eax

  v2 = Scaleform::SysAllocPaged::shutdownHeapEngine(this);
  pContainer = this->pContainer;
  if ( pContainer )
  {
    pContainer->Initialized = 0;
    ((void (__thiscall *)(Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocPagedMalloc,Scaleform::SysAllocPaged> *, _DWORD))this->~Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocPagedMalloc,Scaleform::SysAllocPaged>)(
      this,
      0);
    this->pContainer = 0;
  }
  return v2;
}


char __thiscall Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocWinAPI,Scaleform::SysAllocPaged>::shutdownHeapEngine(
        Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocWinAPI,Scaleform::SysAllocPaged> *this)
{
  char v2; // bl
  Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocWinAPI,Scaleform::SysAllocPaged>::SysAllocContainer *pContainer; // eax

  v2 = Scaleform::SysAllocPaged::shutdownHeapEngine(this);
  pContainer = this->pContainer;
  if ( pContainer )
  {
    pContainer->Initialized = 0;
    ((void (__thiscall *)(Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocWinAPI,Scaleform::SysAllocPaged> *, _DWORD))this->~Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocWinAPI,Scaleform::SysAllocPaged>)(
      this,
      0);
    this->pContainer = 0;
  }
  return v2;
}
