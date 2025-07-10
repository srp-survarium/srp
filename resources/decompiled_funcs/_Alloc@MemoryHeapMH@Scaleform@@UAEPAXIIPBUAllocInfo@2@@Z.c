void *__thiscall Scaleform::MemoryHeapMH::Alloc(
        Scaleform::MemoryHeapMH *this,
        unsigned int size,
        unsigned int align,
        const Scaleform::AllocInfo *info)
{
  void *v5; // eax
  void *v6; // esi
  Scaleform::Lock *p_HeapLock; // [esp-8h] [ebp-18h]
  Scaleform::HeapMH::PageInfoMH v9; // [esp+4h] [ebp-Ch] BYREF

  if ( !this->UseLocks )
    return Scaleform::HeapMH::AllocEngineMH::Alloc(this->pEngine, size, align, &v9, 0);
  EnterCriticalSection(&this->HeapLock.cs);
  v5 = Scaleform::HeapMH::AllocEngineMH::Alloc(this->pEngine, size, align, &v9, 0);
  p_HeapLock = &this->HeapLock;
  v6 = v5;
  LeaveCriticalSection(&p_HeapLock->cs);
  return v6;
}
