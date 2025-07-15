void __thiscall Scaleform::Event::SetEvent(Scaleform::Event *this)
{
  Scaleform::Mutex *p_StateMutex; // edi
  Scaleform::Waitable::HandlerArray *pObject; // esi
  Scaleform::Waitable::CallableHandlers ph; // [esp+8h] [ebp-4h] BYREF

  p_StateMutex = &this->StateMutex;
  Scaleform::Mutex::DoLock(&this->StateMutex);
  this->State = 1;
  this->Temporary = 0;
  Scaleform::WaitCondition::NotifyAll(&this->StateWaitCondition);
  ph.pArray.pObject = 0;
  Scaleform::Waitable::GetCallableHandlers(this, &ph);
  Scaleform::Mutex::Unlock(p_StateMutex);
  pObject = ph.pArray.pObject;
  if ( ph.pArray.pObject )
  {
    Scaleform::Waitable::HandlerArray::CallWaitHandlers(ph.pArray.pObject);
    if ( InterlockedExchangeAdd(&pObject->RefCount.Value, -1) == 1 )
    {
      Scaleform::Lock::~Lock(&pObject->HandlersLock);
      if ( pObject->Handlers.Data.Data )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject->Handlers.Data.Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
}
