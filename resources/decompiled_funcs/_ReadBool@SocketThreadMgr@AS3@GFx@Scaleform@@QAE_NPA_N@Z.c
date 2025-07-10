char __thiscall Scaleform::GFx::AS3::SocketThreadMgr::ReadBool(
        Scaleform::GFx::AS3::SocketThreadMgr *this,
        bool *valueRead)
{
  Scaleform::Lock *p_ReceivedBufferLock; // edi
  Scaleform::GFx::AS3::SocketBuffer *pObject; // ecx
  int (__thiscall *Read)(struct Scaleform::GFx::AS3::SocketBuffer *, unsigned __int8 *, int); // eax
  char v7; // [esp+Bh] [ebp-1h] BYREF

  p_ReceivedBufferLock = &this->ReceivedBufferLock;
  EnterCriticalSection(&this->ReceivedBufferLock.cs);
  if ( this->ReceivedBuffer.pObject->BytesAvailable(this->ReceivedBuffer.pObject) )
  {
    pObject = this->ReceivedBuffer.pObject;
    Read = pObject->Read;
    v7 = 0;
    Read(pObject, (unsigned __int8 *)&v7, 1);
    *valueRead = v7 != 0;
    LeaveCriticalSection(&p_ReceivedBufferLock->cs);
    return 1;
  }
  else
  {
    LeaveCriticalSection(&p_ReceivedBufferLock->cs);
    return 0;
  }
}
