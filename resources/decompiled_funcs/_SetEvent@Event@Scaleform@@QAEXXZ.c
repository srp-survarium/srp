void __thiscall Scaleform::Event::SetEvent(Scaleform::Event *this)
{
  Scaleform::Mutex *p_StateMutex; // edi
  Scaleform::Waitable::HandlerArray *pObject; // esi
  Scaleform::Waitable::CallableHandlers handlers; // [esp+8h] [ebp-4h] BYREF

  p_StateMutex = &this->StateMutex;
  Scaleform::Mutex::DoLock(&this->StateMutex);
  this->State = 1;
  this->Temporary = 0;
  Scaleform::WaitCondition::NotifyAll(&this->StateWaitCondition);
  handlers.pArray.pObject = 0;
  Scaleform::Waitable::GetCallableHandlers(this, &handlers);
  Scaleform::Mutex::Unlock(p_StateMutex);
  pObject = handlers.pArray.pObject;
  if ( handlers.pArray.pObject )
  {
    Scaleform::Waitable::HandlerArray::CallWaitHandlers(handlers.pArray.pObject);
    if ( InterlockedExchangeAdd(&pObject->RefCount.Value, -1) == 1 )
    {
      Scaleform::Lock::~Lock(&pObject->HandlersLock);
      if ( pObject->Handlers.Data.Data )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject->Handlers.Data.Data);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
}
