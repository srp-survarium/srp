char __thiscall Scaleform::GFx::AS3::SocketThreadMgr::ReadDouble(
        Scaleform::GFx::AS3::SocketThreadMgr *this,
        long double *valueRead)
{
  Scaleform::Lock *p_ReceivedBufferLock; // edi
  Scaleform::GFx::AS3::SocketBuffer *pObject; // ecx
  Scaleform::GFx::AS3::SocketBuffer_vtbl *v6; // eax
  long double v7; // [esp+8h] [ebp-8h] BYREF

  p_ReceivedBufferLock = &this->ReceivedBufferLock;
  EnterCriticalSection(&this->ReceivedBufferLock.cs);
  if ( this->ReceivedBuffer.pObject->BytesAvailable(this->ReceivedBuffer.pObject) )
  {
    pObject = this->ReceivedBuffer.pObject;
    v6 = pObject->__vftable;
    v7 = 0.0;
    v6->Read(pObject, (unsigned __int8 *)&v7, 8);
    *valueRead = v7;
    LeaveCriticalSection(&p_ReceivedBufferLock->cs);
    return 1;
  }
  else
  {
    LeaveCriticalSection(&p_ReceivedBufferLock->cs);
    return 0;
  }
}
