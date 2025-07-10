void __thiscall Scaleform::ThreadList::ThreadList(Scaleform::ThreadList *this)
{
  Scaleform::Lock *v2; // eax
  Scaleform::WaitConditionImpl *v3; // esi

  this->ThreadSet.pTable = 0;
  Scaleform::Mutex::Mutex(&this->ThreadMutex, 1, 0);
  v2 = (Scaleform::Lock *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 36, 0);
  v3 = (Scaleform::WaitConditionImpl *)v2;
  if ( v2 )
  {
    Scaleform::Lock::Lock(v2, 0);
    v3->pFreeEventList = 0;
    v3->pQueueTail = 0;
    v3->pQueueHead = 0;
    this->ThreadsEmpty.pImpl = v3;
  }
  else
  {
    this->ThreadsEmpty.pImpl = 0;
  }
  this->RootThreadId = (void *)GetCurrentThreadId();
}
