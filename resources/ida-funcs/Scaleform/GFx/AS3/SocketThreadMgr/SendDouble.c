void __thiscall Scaleform::GFx::AS3::SocketThreadMgr::SendDouble(
        Scaleform::GFx::AS3::SocketThreadMgr *this,
        long double sendValue)
{
  Scaleform::Lock *p_SendingBufferLock; // edi

  p_SendingBufferLock = &this->SendingBufferLock;
  EnterCriticalSection(&this->SendingBufferLock.cs);
  this->SendingBuffer.pObject->Write(this->SendingBuffer.pObject, (const unsigned __int8 *)&sendValue, 8);
  LeaveCriticalSection(&p_SendingBufferLock->cs);
}
