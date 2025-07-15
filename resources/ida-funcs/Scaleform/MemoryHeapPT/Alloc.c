unsigned __int8 *__thiscall Scaleform::MemoryHeapPT::Alloc(
        Scaleform::MemoryHeapPT *this,
        unsigned int size,
        unsigned int align,
        const Scaleform::AllocInfo *info)
{
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // edi
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


unsigned __int8 *__thiscall Scaleform::MemoryHeapPT::Alloc(
        Scaleform::MemoryHeapPT *this,
        unsigned int size,
        const Scaleform::AllocInfo *info)
{
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // edi
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
