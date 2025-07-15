void __thiscall Scaleform::GFx::AS3::SocketThreadMgr::SendByte(
        Scaleform::GFx::AS3::SocketThreadMgr *this,
        char sendValue)
{
  Scaleform::Lock *p_SendingBufferLock; // edi

  p_SendingBufferLock = &this->SendingBufferLock;
  EnterCriticalSection(&this->SendingBufferLock.cs);
  this->SendingBuffer.pObject->Write(this->SendingBuffer.pObject, (const unsigned __int8 *)&sendValue, 1);
  LeaveCriticalSection(&p_SendingBufferLock->cs);
}
