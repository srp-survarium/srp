bool __thiscall Scaleform::Render::ContextImpl::RTHandle::NextCapture(
        Scaleform::Render::ContextImpl::RTHandle *this,
        Scaleform::Render::ContextImpl::RenderNotify *render)
{
  Scaleform::Lock *p_LockObject; // ebx
  Scaleform::Render::ContextImpl::RTHandle::HandleData *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pContext; // esi
  _RTL_CRITICAL_SECTION *p_cs; // ebp
  Scaleform::Render::ContextImpl::Context *v8; // ecx
  Scaleform::Render::ContextImpl::Snapshot *v9; // eax
  bool v10; // bl
  Scaleform::List<Scaleform::Render::ContextImpl::SnapshotPage,Scaleform::Render::ContextImpl::SnapshotPage> *p_SnapshotPages; // edx
  Scaleform::Render::ContextImpl::SnapshotPage *i; // eax
  Scaleform::Render::ContextImpl::EntryPage *pEntryPage; // ecx
  Scaleform::Render::ContextImpl::Snapshot *v14; // ecx
  int v15; // edx
  int v16; // eax
  int v17; // ecx
  int v18; // edx
  Scaleform::Render::ContextImpl::ContextCaptureNotify *j; // ecx
  int v20; // eax
  Scaleform::Render::ContextImpl::ContextCaptureNotify *pNext; // edi
  Scaleform::Render::ContextImpl::Snapshot *displaySnaphot; // [esp+Ch] [ebp-8h]
  Scaleform::Lock *lockObject; // [esp+10h] [ebp-4h]

  if ( !this->pData.pObject )
    return 0;
  p_LockObject = &this->pData.pObject->pContextLock.pObject->LockObject;
  lockObject = p_LockObject;
  EnterCriticalSection(&p_LockObject->cs);
  pObject = this->pData.pObject;
  pContext = this->pData.pObject->pContextLock.pObject->pContext;
  if ( !pContext || pObject->State == State_Dead )
  {
    LeaveCriticalSection(&p_LockObject->cs);
    return 0;
  }
  else
  {
    p_cs = &pContext->pCaptureLock.pObject->LockObject.cs;
    displaySnaphot = 0;
    EnterCriticalSection(p_cs);
    if ( !pContext->NextCaptureCalledInFrame )
    {
      if ( pContext->ShutdownRequested )
      {
        Scaleform::Render::ContextImpl::Context::clearRTHandleList(pContext);
        Scaleform::Render::ContextImpl::Context::shutdownRendering_NoLock(v8);
        LeaveCriticalSection(p_cs);
        this->pData.pObject->pContextLock.pObject->pContext = 0;
        LeaveCriticalSection(&p_LockObject->cs);
        return 0;
      }
      if ( pContext->CreateThreadId != (void *)Scaleform::GetCurrentThreadId() )
        pContext->MultiThreadedUse = 1;
      if ( render )
        pContext->NextCaptureCalledInFrame = 1;
      v9 = pContext->pSnapshots[1];
      if ( v9 )
      {
        p_SnapshotPages = &v9->SnapshotPages;
        for ( i = v9->SnapshotPages.Root.pNext;
              i != (Scaleform::Render::ContextImpl::SnapshotPage *)p_SnapshotPages;
              i = i->pNext )
        {
          pEntryPage = i->pEntryPage;
          if ( pEntryPage )
            pEntryPage->pDisplaySnapshotPage = i;
        }
        v14 = pContext->pSnapshots[1];
        v15 = pContext->SnapshotFrameIds[2];
        pContext->pSnapshots[3] = pContext->pSnapshots[2];
        v16 = HIDWORD(pContext->SnapshotFrameIds[2]);
        pContext->pSnapshots[2] = v14;
        v17 = pContext->SnapshotFrameIds[1];
        LODWORD(pContext->SnapshotFrameIds[3]) = v15;
        v18 = HIDWORD(pContext->SnapshotFrameIds[1]);
        pContext->pSnapshots[1] = 0;
        HIDWORD(pContext->SnapshotFrameIds[3]) = v16;
        LODWORD(pContext->SnapshotFrameIds[2]) = v17;
        HIDWORD(pContext->SnapshotFrameIds[2]) = v18;
        if ( render )
        {
          displaySnaphot = pContext->pSnapshots[2];
          render->NewCapture(render, pContext, 1);
        }
        for ( j = pContext->CaptureNotifyList.Root.pNext; ; j = pNext )
        {
          v20 = pContext == (Scaleform::Render::ContextImpl::Context *)-60 ? 0 : (int)&pContext->pCaptureLock;
          if ( j == (Scaleform::Render::ContextImpl::ContextCaptureNotify *)v20 )
            break;
          pNext = j->pNext;
          ((void (__stdcall *)(Scaleform::Render::ContextImpl::RenderNotify *))j->OnNextCapture)(render);
        }
        pContext->DIChangesRequired = 0;
      }
      else if ( render )
      {
        render->NewCapture(render, pContext, 0);
      }
    }
    LeaveCriticalSection(p_cs);
    if ( this->pData.pObject->State == State_PreCapture )
      this->pData.pObject->State = State_Valid;
    v10 = this->pData.pObject->State == State_Valid;
    LeaveCriticalSection(&lockObject->cs);
    if ( displaySnaphot )
      Scaleform::Render::ContextImpl::Context::nextCapture_NotifyChanges(pContext, displaySnaphot, render);
    return v10;
  }
}
