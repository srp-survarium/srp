void __thiscall Scaleform::GFx::AS3::SocketThreadMgr::SendFloat(
        Scaleform::GFx::AS3::SocketThreadMgr *this,
        float sendValue)
{
  Scaleform::Lock *p_SendingBufferLock; // edi

  p_SendingBufferLock = &this->SendingBufferLock;
  EnterCriticalSection(&this->SendingBufferLock.cs);
  this->SendingBuffer.pObject->Write(this->SendingBuffer.pObject, (const unsigned __int8 *)&sendValue, 4);
  LeaveCriticalSection(&p_SendingBufferLock->cs);
}
