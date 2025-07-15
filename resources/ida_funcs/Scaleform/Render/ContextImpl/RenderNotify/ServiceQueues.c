void __thiscall Scaleform::Render::ContextImpl::RenderNotify::ServiceQueues(
        Scaleform::Render::ContextImpl::RenderNotify *this)
{
  Scaleform::Render::ContextImpl::RenderNotify::ContextNode *pNext; // ebp
  Scaleform::List<Scaleform::Render::ContextImpl::RenderNotify::ContextNode,Scaleform::Render::ContextImpl::RenderNotify::ContextNode> *p_ActiveContextSet; // ecx
  Scaleform::Render::ContextImpl::RenderNotify::ContextNode *v3; // eax
  Scaleform::Event *volatile pShutdownEvent; // edx
  Scaleform::Render::ContextImpl::Context *pContext; // edi
  _RTL_CRITICAL_SECTION *p_cs; // esi
  Scaleform::List<Scaleform::Render::ContextImpl::RenderNotify::ContextNode,Scaleform::Render::ContextImpl::RenderNotify::ContextNode> *v7; // [esp+4h] [ebp-4h]

  pNext = this->ActiveContextSet.Root.pNext;
  p_ActiveContextSet = &this->ActiveContextSet;
  v7 = p_ActiveContextSet;
  while ( pNext != (Scaleform::Render::ContextImpl::RenderNotify::ContextNode *)p_ActiveContextSet )
  {
    v3 = pNext;
    pShutdownEvent = pNext->pContext->pShutdownEvent;
    pNext = pNext->pNext;
    if ( pShutdownEvent )
    {
      pContext = v3->pContext;
      p_cs = &pContext->pCaptureLock.pObject->LockObject.cs;
      EnterCriticalSection(p_cs);
      if ( pContext->CreateThreadId != (void *)Scaleform::GetCurrentThreadId() )
        pContext->MultiThreadedUse = 1;
      Scaleform::Render::ContextImpl::Context::shutdownRendering_NoLock(pContext);
      LeaveCriticalSection(p_cs);
      p_ActiveContextSet = v7;
    }
  }
}
