void __thiscall Scaleform::GFx::AMP::Server::SetListeningPort(Scaleform::GFx::AMP::Server *this, void *port)
{
  Scaleform::GFx::AMP::ThreadMgr *v3; // ecx

  if ( this->ToggleStateLock.cs.LockSemaphore != port )
  {
    v3 = (Scaleform::GFx::AMP::ThreadMgr *)this->Port;
    this->ToggleStateLock.cs.LockSemaphore = port;
    if ( Scaleform::GFx::AMP::ThreadMgr::IsRunning(v3) )
    {
      this->Scaleform::RefCountBase<Scaleform::GFx::AMP::Server,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable[5].~Scaleform::GFx::AMP::Server(this);
      this->Scaleform::RefCountBase<Scaleform::GFx::AMP::Server,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable[4].~Scaleform::GFx::AMP::Server(this);
    }
  }
}
