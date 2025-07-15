void __thiscall Scaleform::GFx::AS3::SocketThreadMgr::SocketThreadMgr(
        Scaleform::GFx::AS3::SocketThreadMgr *this,
        bool initSocketLib,
        Scaleform::GFx::AMP::SocketImplFactory *socketFactory,
        Scaleform::GFx::AS3::Instances::fl_net::Socket *sock)
{
  this->__vftable = (Scaleform::GFx::AS3::SocketThreadMgr_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AS3::SocketThreadMgr_vtbl *)&Scaleform::GFx::AS3::SocketThreadMgr::`vftable';
  this->AS3Sock = sock;
  this->SocketThread.pObject = 0;
  Scaleform::Lock::Lock(&this->ReceivedBufferLock, 0);
  this->ReceivedBuffer.pObject = 0;
  Scaleform::Lock::Lock(&this->SendingBufferLock, 0);
  this->SendingBuffer.pObject = 0;
  this->Port = 0;
  Scaleform::StringLH::StringLH(&this->IpAddress);
  Scaleform::Lock::Lock(&this->SocketLock, 0);
  Scaleform::GFx::AMP::Socket::Socket(&this->Sock, initSocketLib, socketFactory);
  this->InitSocketLib = initSocketLib;
  Scaleform::Lock::Lock(&this->StatusLock, 0);
  this->Exiting = 0;
  this->ConnectTimeout = 20000;
  Scaleform::Lock::Lock(&this->EventQueueLock, 0);
  this->EventQueue.Data.Data = 0;
  this->EventQueue.Data.Size = 0;
  this->EventQueue.Data.Policy.Capacity = 0;
  Scaleform::GFx::AS3::AvmDisplayObj::Bind(
    (Scaleform::GFx::AS3::AvmDisplayObj *)&this->Sock,
    (Scaleform::GFx::DisplayObject *)&this->SocketLock);
}
