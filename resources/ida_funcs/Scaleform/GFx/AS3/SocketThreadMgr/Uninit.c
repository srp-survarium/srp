void __thiscall Scaleform::GFx::AS3::SocketThreadMgr::Uninit(Scaleform::GFx::AS3::SocketThreadMgr *this)
{
  Scaleform::Lock *p_StatusLock; // edi
  Scaleform::Thread *pObject; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::RefCountVImpl *v5; // ecx
  Scaleform::RefCountVImpl *v6; // ecx

  p_StatusLock = &this->StatusLock;
  EnterCriticalSection(&this->StatusLock.cs);
  this->Exiting = 1;
  LeaveCriticalSection(&p_StatusLock->cs);
  pObject = this->SocketThread.pObject;
  if ( pObject )
  {
    Scaleform::Waitable::Wait(pObject, 0xFFFFFFFF);
    v4 = (Scaleform::RefCountVImpl *)this->SocketThread.pObject;
    if ( v4 )
      Scaleform::RefCountImpl::Release(v4);
    this->SocketThread.pObject = 0;
  }
  v5 = (Scaleform::RefCountVImpl *)this->ReceivedBuffer.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  this->ReceivedBuffer.pObject = 0;
  v6 = (Scaleform::RefCountVImpl *)this->SendingBuffer.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  this->SendingBuffer.pObject = 0;
}
