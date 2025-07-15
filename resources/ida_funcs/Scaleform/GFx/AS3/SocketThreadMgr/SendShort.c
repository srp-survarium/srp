void __thiscall Scaleform::GFx::AS3::SocketThreadMgr::SendShort(
        Scaleform::GFx::AS3::SocketThreadMgr *this,
        int sendValue)
{
  Scaleform::Lock *p_SendingBufferLock; // edi
  Scaleform::GFx::AS3::SocketBuffer *pObject; // ecx
  int (__thiscall *Write)(struct Scaleform::GFx::AS3::SocketBuffer *, const unsigned __int8 *, int); // edx

  p_SendingBufferLock = &this->SendingBufferLock;
  EnterCriticalSection(&this->SendingBufferLock.cs);
  pObject = this->SendingBuffer.pObject;
  Write = pObject->Write;
  sendValue = (unsigned __int16)sendValue;
  Write(pObject, (const unsigned __int8 *)&sendValue, 2);
  LeaveCriticalSection(&p_SendingBufferLock->cs);
}
