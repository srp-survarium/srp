void __thiscall Scaleform::GFx::AS3::SocketThreadMgr::SendBytes(
        Scaleform::GFx::AS3::SocketThreadMgr *this,
        char *sendValue,
        unsigned int length)
{
  Scaleform::Lock *p_SendingBufferLock; // edi

  p_SendingBufferLock = &this->SendingBufferLock;
  EnterCriticalSection(&this->SendingBufferLock.cs);
  Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH<unsigned char,327>,Scaleform::ArrayConstPolicy<0,4,1>>::Append(
    &this->SendingBuffer.pObject->Data.Data,
    (unsigned __int8 *)sendValue,
    length);
  LeaveCriticalSection(&p_SendingBufferLock->cs);
}
