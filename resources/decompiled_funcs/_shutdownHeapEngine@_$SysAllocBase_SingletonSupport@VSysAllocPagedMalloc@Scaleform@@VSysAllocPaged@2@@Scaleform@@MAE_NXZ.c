bool __thiscall Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocPagedMalloc,Scaleform::SysAllocPaged>::shutdownHeapEngine(
        Scaleform::SysAllocBase_SingletonSupport<Scaleform::SysAllocPagedMalloc,Scaleform::SysAllocPaged> *this)
{
  bool v2; // bl
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
