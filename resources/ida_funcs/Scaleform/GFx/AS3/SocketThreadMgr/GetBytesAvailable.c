unsigned int __thiscall Scaleform::GFx::AS3::SocketThreadMgr::GetBytesAvailable(
        Scaleform::GFx::AS3::SocketThreadMgr *this)
{
  Scaleform::Lock *p_ReceivedBufferLock; // edi
  unsigned int Size; // esi

  p_ReceivedBufferLock = &this->ReceivedBufferLock;
  EnterCriticalSection(&this->ReceivedBufferLock.cs);
  Size = this->ReceivedBuffer.pObject->Data.Data.Size;
  LeaveCriticalSection(&p_ReceivedBufferLock->cs);
  return Size;
}
