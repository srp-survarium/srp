void __userpurge Scaleform::Render::ContextImpl::Context::Context(
        Scaleform::Render::ContextImpl::Context *this@<ecx>,
        int a2@<edi>,
        Scaleform::MemoryHeap *pheap)
{
  Scaleform::List<Scaleform::Render::ContextImpl::ContextCaptureNotify,Scaleform::Render::ContextImpl::ContextCaptureNotify> *p_CaptureNotifyList; // eax
  Scaleform::Ptr<Scaleform::Render::ContextImpl::ContextLock> *p_pCaptureLock; // ecx
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v6; // ecx
  int v7; // eax
  Scaleform::Render::ContextImpl::ContextLock *v8; // edi
  Scaleform::RefCountVImpl *pObject; // ecx
  void *CurrentThreadId; // eax
  Scaleform::MemoryHeap *v11; // ecx
  Scaleform::Render::ContextImpl::Snapshot *v12; // eax
  Scaleform::Render::ContextImpl::Snapshot *v13; // eax

  this->pHeap = pheap;
  this->Table.pHeap = pheap;
  this->Table.pContext = this;
  this->Table.EntryPages.Root.pPrev = (Scaleform::Render::ContextImpl::EntryPageBase *)&this->Table.EntryPages;
  this->Table.EntryPages.Root.pNext = (Scaleform::Render::ContextImpl::EntryPageBase *)&this->Table.EntryPages;
  this->Table.FreeNodes.Root.pPrev = &this->Table.FreeNodes.Root;
  this->Table.FreeNodes.Root.RefCount = (unsigned int)&this->Table.FreeNodes;
  p_CaptureNotifyList = &this->CaptureNotifyList;
  this->pCaptureLock.pObject = 0;
  if ( this == (Scaleform::Render::ContextImpl::Context *)-60 )
    p_pCaptureLock = 0;
  else
    p_pCaptureLock = &this->pCaptureLock;
  p_CaptureNotifyList->Root.pPrev = (Scaleform::Render::ContextImpl::ContextCaptureNotify *)p_pCaptureLock;
  p_CaptureNotifyList->Root.pNext = (Scaleform::Render::ContextImpl::ContextCaptureNotify *)p_pCaptureLock;
  this->pRenderer = 0;
  this->NextCaptureCalledInFrame = 0;
  this->DIChangesRequired = 0;
  this->ShutdownRequested = 0;
  this->pShutdownEvent = 0;
  this->RenderNode.pContext = this;
  if ( this == (Scaleform::Render::ContextImpl::Context *)-96 )
    v6 = 0;
  else
    v6 = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)&this->RenderNode.4;
  this->RTHandleList.Root.pPrev = v6;
  this->RTHandleList.Root.pNext = v6;
  v7 = ((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, int))Scaleform::Memory::pGlobalHeap->Alloc)(
         Scaleform::Memory::pGlobalHeap,
         36,
         0,
         a2);
  v8 = (Scaleform::Render::ContextImpl::ContextLock *)v7;
  if ( v7 )
  {
    *(_DWORD *)v7 = &Scaleform::RefCountImplCore::`vftable';
    *(_DWORD *)(v7 + 4) = 1;
    *(_DWORD *)v7 = &Scaleform::Render::ContextImpl::ContextLock::`vftable';
    Scaleform::Lock::Lock((Scaleform::Lock *)(v7 + 8), 0);
    v8->pContext = this;
  }
  else
  {
    v8 = 0;
  }
  pObject = (Scaleform::RefCountVImpl *)this->pCaptureLock.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pCaptureLock.pObject = v8;
  CurrentThreadId = (void *)Scaleform::GetCurrentThreadId();
  v11 = this->pHeap;
  this->CreateThreadId = CurrentThreadId;
  this->MultiThreadedUse = 0;
  v12 = (Scaleform::Render::ContextImpl::Snapshot *)((int (__thiscall *)(Scaleform::MemoryHeap *, int))v11->Alloc)(
                                                      v11,
                                                      80);
  if ( v12 )
    Scaleform::Render::ContextImpl::Snapshot::Snapshot(v12, this, this->pHeap);
  else
    v13 = 0;
  this->pSnapshots[0] = v13;
  this->pSnapshots[3] = 0;
  this->pSnapshots[2] = 0;
  this->pSnapshots[1] = 0;
  LODWORD(this->FinalizedFrameId) = 0;
  HIDWORD(this->FinalizedFrameId) = 0;
  HIDWORD(this->SnapshotFrameIds[0]) = 0;
  LODWORD(this->SnapshotFrameIds[1]) = 0;
  HIDWORD(this->SnapshotFrameIds[1]) = 0;
  LODWORD(this->SnapshotFrameIds[2]) = 0;
  HIDWORD(this->SnapshotFrameIds[2]) = 0;
  LODWORD(this->SnapshotFrameIds[3]) = 0;
  HIDWORD(this->SnapshotFrameIds[3]) = 0;
  this->Table.pActiveSnapshot = v13;
  LODWORD(this->SnapshotFrameIds[0]) = 1;
  this->CaptureCalled = 0;
}
