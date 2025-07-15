bool __thiscall Scaleform::Render::ContextImpl::RTHandle::NextCapture(
        Scaleform::Render::ContextImpl::RTHandle *this,
        Scaleform::Render::ContextImpl::RenderNotify *render)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v4; // eax
  Scaleform::AmpStats *v5; // edi
  void (__thiscall **v6)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v7; // rax
  Scaleform::Lock *p_LockObject; // ebx
  Scaleform::Render::ContextImpl::RTHandle::HandleData *pObject; // eax
  Scaleform::Render::ContextImpl::Context *pContext; // esi
  _RTL_CRITICAL_SECTION *p_cs; // ebp
  Scaleform::Render::ContextImpl::Context *v13; // ecx
  Scaleform::Render::ContextImpl::Snapshot *v14; // eax
  bool v15; // bl
  Scaleform::List<Scaleform::Render::ContextImpl::SnapshotPage,Scaleform::Render::ContextImpl::SnapshotPage> *p_SnapshotPages; // edx
  Scaleform::Render::ContextImpl::SnapshotPage *i; // eax
  Scaleform::Render::ContextImpl::EntryPage *pEntryPage; // ecx
  Scaleform::Render::ContextImpl::Snapshot *v19; // ecx
  int v20; // edx
  int v21; // eax
  int v22; // ecx
  int v23; // edx
  Scaleform::Render::ContextImpl::ContextCaptureNotify *j; // ecx
  int v25; // eax
  Scaleform::Render::ContextImpl::ContextCaptureNotify *pNext; // edi
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::Render::ContextImpl::Snapshot *displaySnaphot; // [esp+Ch] [ebp-18h]
  _RTL_CRITICAL_SECTION *lpCriticalSection; // [esp+10h] [ebp-14h]
  Scaleform::AmpFunctionTimer v33; // [esp+14h] [ebp-10h] BYREF

  Instance = Scaleform::AmpServer::GetInstance();
  v4 = Instance->GetDisplayStats(Instance);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v33,
    v4,
    "RTHandle::NextCapture",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_NextCapture);
  if ( this->pData.pObject )
  {
    p_LockObject = &this->pData.pObject->pContextLock.pObject->LockObject;
    lpCriticalSection = &p_LockObject->cs;
    EnterCriticalSection(&p_LockObject->cs);
    pObject = this->pData.pObject;
    pContext = this->pData.pObject->pContextLock.pObject->pContext;
    if ( !pContext || pObject->State == State_Dead )
    {
      LeaveCriticalSection(&p_LockObject->cs);
      Stats = v33.Stats;
      if ( v33.Stats )
      {
        p_NativePopCallstack = &v33.Stats->NativePopCallstack;
        ProfileTicks = Scaleform::Timer::GetProfileTicks();
        ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
          Stats,
          ProfileTicks - LODWORD(v33.StartTicks),
          (ProfileTicks - v33.StartTicks) >> 32);
      }
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
          Scaleform::Render::ContextImpl::Context::shutdownRendering_NoLock(v13);
          LeaveCriticalSection(p_cs);
          this->pData.pObject->pContextLock.pObject->pContext = 0;
          LeaveCriticalSection(&p_LockObject->cs);
          Scaleform::AmpFunctionTimer::~AmpFunctionTimer(&v33);
          return 0;
        }
        if ( pContext->CreateThreadId != (void *)Scaleform::GetCurrentThreadId() )
          pContext->MultiThreadedUse = 1;
        if ( render )
          pContext->NextCaptureCalledInFrame = 1;
        v14 = pContext->pSnapshots[1];
        if ( v14 )
        {
          p_SnapshotPages = &v14->SnapshotPages;
          for ( i = v14->SnapshotPages.Root.pNext;
                i != (Scaleform::Render::ContextImpl::SnapshotPage *)p_SnapshotPages;
                i = i->pNext )
          {
            pEntryPage = i->pEntryPage;
            if ( pEntryPage )
              pEntryPage->pDisplaySnapshotPage = i;
          }
          v19 = pContext->pSnapshots[1];
          v20 = pContext->SnapshotFrameIds[2];
          pContext->pSnapshots[3] = pContext->pSnapshots[2];
          v21 = HIDWORD(pContext->SnapshotFrameIds[2]);
          pContext->pSnapshots[2] = v19;
          v22 = pContext->SnapshotFrameIds[1];
          LODWORD(pContext->SnapshotFrameIds[3]) = v20;
          v23 = HIDWORD(pContext->SnapshotFrameIds[1]);
          pContext->pSnapshots[1] = 0;
          HIDWORD(pContext->SnapshotFrameIds[3]) = v21;
          LODWORD(pContext->SnapshotFrameIds[2]) = v22;
          HIDWORD(pContext->SnapshotFrameIds[2]) = v23;
          if ( render )
          {
            displaySnaphot = pContext->pSnapshots[2];
            render->NewCapture(render, pContext, 1);
          }
          for ( j = pContext->CaptureNotifyList.Root.pNext; ; j = pNext )
          {
            v25 = pContext == (Scaleform::Render::ContextImpl::Context *)-60 ? 0 : (int)&pContext->pCaptureLock;
            if ( j == (Scaleform::Render::ContextImpl::ContextCaptureNotify *)v25 )
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
      v15 = this->pData.pObject->State == State_Valid;
      LeaveCriticalSection(lpCriticalSection);
      if ( displaySnaphot )
        Scaleform::Render::ContextImpl::Context::nextCapture_NotifyChanges(pContext, displaySnaphot, render);
      Scaleform::AmpFunctionTimer::~AmpFunctionTimer(&v33);
      return v15;
    }
  }
  else
  {
    v5 = v33.Stats;
    if ( v33.Stats )
    {
      v6 = &v33.Stats->NativePopCallstack;
      v7 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v6)(
        v5,
        v7 - LODWORD(v33.StartTicks),
        (v7 - v33.StartTicks) >> 32);
    }
    return 0;
  }
}
