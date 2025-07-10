void *__thiscall Scaleform::MemoryHeapPT::Alloc(
        Scaleform::MemoryHeapPT *this,
        unsigned int size,
        unsigned int align,
        const Scaleform::AllocInfo *info)
{
  void *v5; // eax
  void *v6; // edi
  Scaleform::Lock *p_HeapLock; // [esp-8h] [ebp-Ch]

  if ( !this->UseLocks )
    return Scaleform::HeapPT::AllocEngine::Alloc(this->pEngine, size, align);
  EnterCriticalSection(&this->HeapLock.cs);
  v5 = Scaleform::HeapPT::AllocEngine::Alloc(this->pEngine, size, align);
  p_HeapLock = &this->HeapLock;
  v6 = v5;
  LeaveCriticalSection(&p_HeapLock->cs);
  return v6;
}
