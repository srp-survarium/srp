char __usercall Scaleform::GFx::AMP::ThreadMgr::BroadcastLoop@<al>(
        Scaleform::GFx::AMP::ThreadMgr *this@<ecx>,
        bool *p_InitLib@<ebx>,
        int a3@<ebp>,
        Scaleform::GFx::AS3::SoundObject *a4@<edi>)
{
  bool Exiting; // bl
  Scaleform::GFx::AMP::AmpStream *v7; // eax
  Scaleform::GFx::AS3::SoundObject *v8; // eax
  Scaleform::GFx::AS3::SoundObject *v9; // ebp
  Scaleform::GFx::AMP::MessagePort *v10; // eax
  Scaleform::RefCountVImpl *v11; // eax
  Scaleform::RefCountVImpl *v12; // edi
  Scaleform::GFx::ASSoundIntf_vtbl *ContextNotify; // eax
  bool v14; // bl
  unsigned int UsedSpace; // [esp+0h] [ebp-28h]
  int v19; // [esp+14h] [ebp-14h] BYREF
  Scaleform::GFx::AMP::BroadcastSocket v20; // [esp+1Ch] [ebp-Ch] BYREF

  Scaleform::GFx::AMP::BroadcastSocket::BroadcastSocket(&v20, this->InitSocketLib, this->SocketFactory);
  if ( !Scaleform::GFx::AMP::BroadcastSocket::Create(&v20, this->BroadcastPort, 1) )
  {
    Scaleform::GFx::AMP::BroadcastSocket::~BroadcastSocket(&v20);
    return 0;
  }
  EnterCriticalSection(&this->StatusLock.cs);
  Exiting = this->Exiting;
  LeaveCriticalSection(&this->StatusLock.cs);
  if ( Exiting )
    goto LABEL_20;
  while ( this->ValidConnection.Value )
  {
LABEL_14:
    Scaleform::Thread::Sleep(1u);
    EnterCriticalSection(&this->StatusLock.cs);
    v14 = this->Exiting;
    LeaveCriticalSection(&this->StatusLock.cs);
    if ( v14 )
      goto LABEL_20;
  }
  v19 = 2;
  v7 = (Scaleform::GFx::AMP::AmpStream *)((int (__thiscall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AMP::ThreadMgr *, int, int *, Scaleform::GFx::AS3::SoundObject *, int, bool *))Scaleform::Memory::pGlobalHeap->AllocAutoHeap)(
                                           Scaleform::Memory::pGlobalHeap,
                                           this,
                                           24,
                                           &v19,
                                           a4,
                                           a3,
                                           p_InitLib);
  if ( v7 )
  {
    Scaleform::GFx::AMP::AmpStream::AmpStream(v7);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  EnterCriticalSection(&this->BroadcastInfoLock.cs);
  p_InitLib = &v20.InitLib;
  *(_DWORD *)&v20.InitLib = 580;
  a3 = 48;
  v10 = (Scaleform::GFx::AMP::MessagePort *)((int (__thiscall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AMP::ThreadMgr *))Scaleform::Memory::pGlobalHeap->AllocAutoHeap)(
                                              Scaleform::Memory::pGlobalHeap,
                                              this);
  if ( v10 )
  {
    Scaleform::GFx::AMP::MessagePort::MessagePort(
      v10,
      this->Port,
      (const __m128i *)((this->BroadcastApp.HeapTypeBits & 0xFFFFFFFC) + 8),
      (const __m128i *)((this->BroadcastFile.HeapTypeBits & 0xFFFFFFFC) + 8));
    v12 = v11;
  }
  else
  {
    v12 = 0;
  }
  LeaveCriticalSection(&this->BroadcastInfoLock.cs);
  a4 = v9;
  v12->Release(v12);
  UsedSpace = Scaleform::SysAllocPagedMalloc::GetUsedSpace(v9);
  ContextNotify = Scaleform::Render::Renderer2D::GetContextNotify(v9);
  if ( Scaleform::GFx::AMP::BroadcastSocket::Broadcast(&v20, (const char *)ContextNotify, UsedSpace) >= 0 )
  {
    Scaleform::RefCountImpl::Release(v12);
    if ( v9 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v9);
    goto LABEL_14;
  }
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  if ( v9 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v9);
LABEL_20:
  Scaleform::GFx::AMP::BroadcastSocket::~BroadcastSocket(&v20);
  return 1;
}
