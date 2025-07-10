char __userpurge Scaleform::GFx::AS3::SocketThreadMgr::Init@<al>(
        Scaleform::GFx::AS3::SocketThreadMgr *this@<ecx>,
        int a2@<ebp>,
        char *address,
        int port)
{
  Scaleform::Thread *pObject; // ecx
  int v6; // eax
  Scaleform::GFx::AS3::SocketBuffer *v7; // eax
  Scaleform::GFx::AS3::SocketBuffer *v8; // edi
  Scaleform::RefCountVImpl *v9; // ecx
  Scaleform::GFx::AS3::SocketBuffer *v10; // ebp
  bool v11; // zf
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,327>,Scaleform::ArrayConstPolicy<0,4,1> > *p_Data; // edi
  Scaleform::GFx::AS3::SocketBuffer *v13; // eax
  Scaleform::GFx::AS3::SocketBuffer *v14; // edi
  Scaleform::RefCountVImpl *v15; // ecx
  Scaleform::Thread *v16; // eax
  Scaleform::Thread *v17; // eax
  Scaleform::Thread *v18; // edi
  Scaleform::RefCountVImpl *v19; // ecx
  int retaddr; // [esp+1Ch] [ebp+0h]

  pObject = this->SocketThread.pObject;
  if ( pObject && !(unsigned __int8)Scaleform::Thread::IsSignaled(pObject) )
    Scaleform::GFx::AS3::SocketThreadMgr::Uninit(this);
  v6 = port;
  this->Exiting = 0;
  this->Port = v6;
  Scaleform::String::operator=(&this->IpAddress, address);
  port = 2;
  v7 = (Scaleform::GFx::AS3::SocketBuffer *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              24,
                                              &port);
  if ( v7 )
  {
    v7->__vftable = (Scaleform::GFx::AS3::SocketBuffer_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v7->RefCount = 1;
    v7->__vftable = (Scaleform::GFx::AS3::SocketBuffer_vtbl *)&Scaleform::GFx::AS3::SocketBuffer::`vftable';
    v7->Data.Data.Data = 0;
    v7->Data.Data.Size = 0;
    v7->Data.Data.Policy.Capacity = 0;
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  v9 = (Scaleform::RefCountVImpl *)this->ReceivedBuffer.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  this->ReceivedBuffer.pObject = v8;
  v10 = v8;
  v11 = v8->Data.Data.Size == 0;
  p_Data = &v8->Data.Data;
  if ( v11 )
  {
    if ( p_Data->Policy.Capacity )
      goto LABEL_14;
  }
  else if ( (p_Data->Policy.Capacity & 0xFFFFFFFE) == 0 )
  {
    goto LABEL_14;
  }
  Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH<unsigned char,327>,Scaleform::ArrayConstPolicy<0,4,1>>::Reserve(
    p_Data,
    p_Data,
    0);
LABEL_14:
  p_Data->Size = 0;
  ((void (__thiscall *)(Scaleform::GFx::AS3::SocketBuffer *, int))v10->SeekToBegin)(v10, a2);
  port = 2;
  v13 = (Scaleform::GFx::AS3::SocketBuffer *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                               Scaleform::Memory::pGlobalHeap,
                                               this,
                                               24,
                                               &port);
  if ( v13 )
  {
    v13->__vftable = (Scaleform::GFx::AS3::SocketBuffer_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v13->RefCount = 1;
    v13->__vftable = (Scaleform::GFx::AS3::SocketBuffer_vtbl *)&Scaleform::GFx::AS3::SocketBuffer::`vftable';
    v13->Data.Data.Data = 0;
    v13->Data.Data.Size = 0;
    v13->Data.Data.Policy.Capacity = 0;
    v14 = v13;
  }
  else
  {
    v14 = 0;
  }
  v15 = (Scaleform::RefCountVImpl *)this->SendingBuffer.pObject;
  if ( v15 )
    Scaleform::RefCountImpl::Release(v15);
  this->SendingBuffer.pObject = v14;
  retaddr = 2;
  v16 = (Scaleform::Thread *)((int (__thiscall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::SocketThreadMgr *, int))Scaleform::Memory::pGlobalHeap->AllocAutoHeap)(
                               Scaleform::Memory::pGlobalHeap,
                               this,
                               56);
  if ( v16 )
  {
    Scaleform::Thread::Thread(
      v16,
      (int (__cdecl *)(Scaleform::Thread *, void *))Scaleform::GFx::AS3::SocketThreadMgr::SocketThreadLoop,
      this,
      (unsigned int)&loc_20000,
      -1,
      NotRunning);
    v18 = v17;
  }
  else
  {
    v18 = 0;
  }
  v19 = (Scaleform::RefCountVImpl *)this->SocketThread.pObject;
  if ( v19 )
    Scaleform::RefCountImpl::Release(v19);
  this->SocketThread.pObject = v18;
  if ( !v18 || !v18->Start(v18, Running) )
    return 0;
  this->SocketThread.pObject->SetThreadName(this->SocketThread.pObject, "Scaleform AS3 Socket");
  return 1;
}
