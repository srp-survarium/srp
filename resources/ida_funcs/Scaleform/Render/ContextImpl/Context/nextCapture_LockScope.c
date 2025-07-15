char __thiscall Scaleform::Render::ContextImpl::Context::nextCapture_LockScope(
        Scaleform::Render::ContextImpl::Context *this,
        Scaleform::Render::ContextImpl::Snapshot **updateSnapshot,
        Scaleform::Render::ContextImpl::RenderNotify *pnotify,
        Scaleform::Render::ContextImpl::Context::CaptureMode mode)
{
  Scaleform::Lock *p_LockObject; // edi
  Scaleform::Render::ContextImpl::Context *v7; // ecx
  Scaleform::Render::ContextImpl::Snapshot *v8; // eax
  Scaleform::List<Scaleform::Render::ContextImpl::SnapshotPage,Scaleform::Render::ContextImpl::SnapshotPage> *p_SnapshotPages; // edx
  Scaleform::Render::ContextImpl::SnapshotPage *i; // eax
  Scaleform::Render::ContextImpl::EntryPage *pEntryPage; // ecx
  Scaleform::Render::ContextImpl::Snapshot *v12; // edx
  int v13; // eax
  int v14; // ecx
  int v15; // edx
  int v16; // eax
  Scaleform::Render::ContextImpl::ContextCaptureNotify *pNext; // ecx
  Scaleform::Ptr<Scaleform::Render::ContextImpl::ContextLock> *v18; // eax
  Scaleform::Render::ContextImpl::ContextCaptureNotify *v19; // edi
  Scaleform::Lock::Locker scopeLock; // [esp+Ch] [ebp-4h]

  p_LockObject = &this->pCaptureLock.pObject->LockObject;
  scopeLock.pLock = p_LockObject;
  EnterCriticalSection(&p_LockObject->cs);
  if ( mode == Capture_OnceAFrame && this->NextCaptureCalledInFrame )
  {
    LeaveCriticalSection(&p_LockObject->cs);
    return 1;
  }
  if ( this->ShutdownRequested )
  {
    Scaleform::Render::ContextImpl::Context::clearRTHandleList(this);
    Scaleform::Render::ContextImpl::Context::shutdownRendering_NoLock(v7);
    LeaveCriticalSection(&p_LockObject->cs);
    return 0;
  }
  if ( this->CreateThreadId != (void *)Scaleform::GetCurrentThreadId() )
    this->MultiThreadedUse = 1;
  if ( pnotify && mode == Capture_OnceAFrame )
    this->NextCaptureCalledInFrame = 1;
  v8 = this->pSnapshots[1];
  if ( v8 )
  {
    p_SnapshotPages = &v8->SnapshotPages;
    for ( i = v8->SnapshotPages.Root.pNext;
          i != (Scaleform::Render::ContextImpl::SnapshotPage *)p_SnapshotPages;
          i = i->pNext )
    {
      pEntryPage = i->pEntryPage;
      if ( pEntryPage )
        pEntryPage->pDisplaySnapshotPage = i;
    }
    v12 = this->pSnapshots[1];
    v13 = this->SnapshotFrameIds[2];
    this->pSnapshots[3] = this->pSnapshots[2];
    v14 = HIDWORD(this->SnapshotFrameIds[2]);
    this->pSnapshots[2] = v12;
    v15 = this->SnapshotFrameIds[1];
    LODWORD(this->SnapshotFrameIds[3]) = v13;
    v16 = HIDWORD(this->SnapshotFrameIds[1]);
    this->pSnapshots[1] = 0;
    HIDWORD(this->SnapshotFrameIds[3]) = v14;
    LODWORD(this->SnapshotFrameIds[2]) = v15;
    HIDWORD(this->SnapshotFrameIds[2]) = v16;
    if ( pnotify )
    {
      *updateSnapshot = this->pSnapshots[2];
      pnotify->NewCapture(pnotify, this, 1);
    }
    pNext = this->CaptureNotifyList.Root.pNext;
    while ( 1 )
    {
      v18 = this == (Scaleform::Render::ContextImpl::Context *)-60 ? 0 : &this->pCaptureLock;
      if ( pNext == (Scaleform::Render::ContextImpl::ContextCaptureNotify *)v18 )
        break;
      v19 = pNext->pNext;
      ((void (__stdcall *)(Scaleform::Render::ContextImpl::RenderNotify *))pNext->OnNextCapture)(pnotify);
      pNext = v19;
      p_LockObject = scopeLock.pLock;
    }
    this->DIChangesRequired = 0;
  }
  else if ( pnotify )
  {
    pnotify->NewCapture(pnotify, this, (bool)this->pSnapshots[1]);
    LeaveCriticalSection(&p_LockObject->cs);
    return 1;
  }
  LeaveCriticalSection(&p_LockObject->cs);
  return 1;
}
