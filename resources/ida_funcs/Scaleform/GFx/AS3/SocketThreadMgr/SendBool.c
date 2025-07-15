void __thiscall Scaleform::GFx::AS3::SocketThreadMgr::SendBool(
        Scaleform::GFx::AS3::SocketThreadMgr *this,
        bool sendValue)
{
  Scaleform::Lock *p_SendingBufferLock; // edi
  Scaleform::GFx::AS3::SocketBuffer *pObject; // ecx
  int (__thiscall *Write)(struct Scaleform::GFx::AS3::SocketBuffer *, const unsigned __int8 *, int); // edx

  p_SendingBufferLock = &this->SendingBufferLock;
  EnterCriticalSection(&this->SendingBufferLock.cs);
  pObject = this->SendingBuffer.pObject;
  Write = pObject->Write;
  sendValue = sendValue;
  Write(pObject, (const unsigned __int8 *)&sendValue, 1);
  LeaveCriticalSection(&p_SendingBufferLock->cs);
}
