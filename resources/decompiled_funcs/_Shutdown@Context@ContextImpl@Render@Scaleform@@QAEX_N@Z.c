void __thiscall Scaleform::Render::ContextImpl::Context::Shutdown(
        Scaleform::Render::ContextImpl::Context *this,
        int waitFlag)
{
  Scaleform::Render::ContextImpl::ContextCaptureNotify *i; // ecx
  Scaleform::Ptr<Scaleform::Render::ContextImpl::ContextLock> *v4; // eax
  Scaleform::Render::ContextImpl::ContextCaptureNotify *pNext; // edi
  Scaleform::Lock *p_LockObject; // edi
  char v7; // bl
  Scaleform::Lock *v8; // edi
  Scaleform::Render::ContextImpl::RenderNotify *pRenderer; // eax
  Scaleform::Event waitEvent; // [esp+10h] [ebp-2Ch] BYREF

  for ( i = this->CaptureNotifyList.Root.pNext; ; i = pNext )
  {
    v4 = this == (Scaleform::Render::ContextImpl::Context *)-60 ? 0 : &this->pCaptureLock;
    if ( i == (Scaleform::Render::ContextImpl::ContextCaptureNotify *)v4 )
      break;
    pNext = i->pNext;
    ((void (__stdcall *)(int))i->OnShutdown)(waitFlag);
  }
  this->DIChangesRequired = 0;
  while ( 1 )
  {
    p_LockObject = &this->pCaptureLock.pObject->LockObject;
    v7 = 0;
    EnterCriticalSection(&p_LockObject->cs);
    Scaleform::Render::ContextImpl::Context::handleFinalizingSnaphot(this);
    this->ShutdownRequested = 1;
    if ( !(_BYTE)waitFlag )
      goto LABEL_14;
    if ( this->pRenderer )
    {
      if ( this->MultiThreadedUse )
      {
        v7 = 1;
        goto LABEL_14;
      }
      Scaleform::Render::ContextImpl::Context::shutdownRendering_NoLock(this);
    }
    Scaleform::Render::ContextImpl::Context::clearRTHandleList(this);
    this->pCaptureLock.pObject->pContext = 0;
LABEL_14:
    LeaveCriticalSection(&p_LockObject->cs);
    if ( !v7 )
      break;
    Scaleform::Event::Event(&waitEvent, 0, 0);
    v8 = &this->pCaptureLock.pObject->LockObject;
    EnterCriticalSection(&v8->cs);
    if ( this->pRenderer )
    {
      pRenderer = this->pRenderer;
      this->pShutdownEvent = &waitEvent;
      if ( pRenderer->pRTCommandQueue )
        pRenderer->pRTCommandQueue->PushThreadCommand(pRenderer->pRTCommandQueue, &pRenderer->ServiceCommandInstance);
    }
    else
    {
      v7 = 0;
    }
    LeaveCriticalSection(&v8->cs);
    if ( v7 )
      Scaleform::Event::Wait(&waitEvent, 0xFFFFFFFF);
    Scaleform::Event::~Event(&waitEvent);
  }
}
