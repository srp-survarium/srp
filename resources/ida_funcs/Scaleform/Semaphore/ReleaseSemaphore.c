char __thiscall Scaleform::Semaphore::ReleaseSemaphore(
        Scaleform::Semaphore *this,
        Scaleform::Waitable::HandlerArray *count)
{
  Scaleform::Waitable::HandlerArray *v2; // edi
  Scaleform::WaitCondition *p_ValueWaitCondition; // ecx
  int v5; // esi

  v2 = count;
  if ( count )
  {
    Scaleform::Mutex::DoLock(&this->ValueMutex);
    if ( this->Value - (int)v2 < 0 )
      this->Value = 0;
    else
      this->Value -= (volatile int)v2;
    p_ValueWaitCondition = &this->ValueWaitCondition;
    if ( v2 == (Scaleform::Waitable::HandlerArray *)1 )
      Scaleform::WaitCondition::Notify(p_ValueWaitCondition);
    else
      Scaleform::WaitCondition::NotifyAll(p_ValueWaitCondition);
    count = 0;
    Scaleform::Waitable::GetCallableHandlers(this, (Scaleform::Waitable::CallableHandlers *)&count);
    Scaleform::Mutex::Unlock(&this->ValueMutex);
    v5 = (int)count;
    if ( count )
    {
      Scaleform::Waitable::HandlerArray::CallWaitHandlers(count);
      if ( InterlockedExchangeAdd((volatile LONG *)v5, -1) == 1 )
      {
        Scaleform::Lock::~Lock((Scaleform::Lock *)(v5 + 16));
        if ( *(_DWORD *)(v5 + 4) )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *(void **)(v5 + 4));
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v5);
      }
    }
  }
  return 1;
}
