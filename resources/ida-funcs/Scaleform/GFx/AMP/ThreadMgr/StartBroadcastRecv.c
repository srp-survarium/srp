void __thiscall Scaleform::GFx::AMP::ThreadMgr::StartBroadcastRecv(
        Scaleform::GFx::AMP::ThreadMgr *this,
        unsigned int port)
{
  unsigned int v2; // eax
  Scaleform::Thread *v4; // eax
  Scaleform::Thread *v5; // eax
  Scaleform::Thread *v6; // edi
  Scaleform::RefCountVImpl *pObject; // ecx

  v2 = port;
  this->BroadcastRecvPort = port;
  if ( v2 && !this->BroadcastRecvThread.pObject )
  {
    port = 2;
    v4 = (Scaleform::Thread *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                Scaleform::Memory::pGlobalHeap,
                                this,
                                56,
                                &port);
    if ( v4 )
    {
      Scaleform::Thread::Thread(
        v4,
        (int (__cdecl *)(Scaleform::Thread *, void *))Scaleform::GFx::AMP::ThreadMgr::BroadcastRecvThreadLoop,
        this,
        (unsigned int)&loc_20000,
        -1,
        NotRunning);
      v6 = v5;
    }
    else
    {
      v6 = 0;
    }
    pObject = (Scaleform::RefCountVImpl *)this->BroadcastRecvThread.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    this->BroadcastRecvThread.pObject = v6;
    if ( v6 )
    {
      if ( v6->Start(v6, Running) )
        this->BroadcastRecvThread.pObject->SetThreadName(
          this->BroadcastRecvThread.pObject,
          "Scaleform AMP Broadcast/Receive");
    }
  }
}
