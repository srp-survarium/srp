unsigned int __thiscall Scaleform::GFx::AS3::SocketThreadMgr::GetBytesPending(
        Scaleform::GFx::AS3::SocketThreadMgr *this)
{
  Scaleform::Lock *p_SendingBufferLock; // edi
  unsigned int Size; // esi

  p_SendingBufferLock = &this->SendingBufferLock;
  EnterCriticalSection(&this->SendingBufferLock.cs);
  Size = this->SendingBuffer.pObject->Data.Data.Size;
  LeaveCriticalSection(&p_SendingBufferLock->cs);
  return Size;
}
