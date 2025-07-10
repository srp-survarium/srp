void *__thiscall Scaleform::MemoryHeapPT::Alloc(
        Scaleform::MemoryHeapPT *this,
        unsigned int size,
        const Scaleform::AllocInfo *info)
{
  void *v4; // eax
  void *v5; // edi
  Scaleform::Lock *p_HeapLock; // [esp-8h] [ebp-Ch]

  if ( !this->UseLocks )
    return Scaleform::HeapPT::AllocEngine::Alloc(this->pEngine, size);
  EnterCriticalSection(&this->HeapLock.cs);
  v4 = Scaleform::HeapPT::AllocEngine::Alloc(this->pEngine, size);
  p_HeapLock = &this->HeapLock;
  v5 = v4;
  LeaveCriticalSection(&p_HeapLock->cs);
  return v5;
}
