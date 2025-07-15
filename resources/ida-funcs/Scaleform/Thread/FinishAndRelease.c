void __thiscall Scaleform::Thread::FinishAndRelease(Scaleform::Thread *this)
{
  Scaleform::Waitable::HandlerArray *pHandlers; // edi
  Scaleform::Waitable::HandlerArray *v3; // ebx

  pHandlers = this->pHandlers;
  v3 = 0;
  if ( pHandlers )
  {
    InterlockedExchangeAdd(&pHandlers->RefCount.Value, 1);
    v3 = pHandlers;
  }
  Scaleform::AtomicInt<unsigned long>::operator&=(&this->ThreadFlags, 0xFFFFFFFE);
  Scaleform::AtomicInt<unsigned long>::operator|=(&this->ThreadFlags, 2u);
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)this);
  if ( v3 )
  {
    Scaleform::Waitable::HandlerArray::CallWaitHandlers(v3);
    Scaleform::Waitable::HandlerArray::Release(v3);
  }
}
