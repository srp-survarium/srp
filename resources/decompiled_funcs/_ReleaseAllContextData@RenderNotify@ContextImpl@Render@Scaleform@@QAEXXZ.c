void __thiscall Scaleform::Render::ContextImpl::RenderNotify::ReleaseAllContextData(
        Scaleform::Render::ContextImpl::RenderNotify *this)
{
  Scaleform::List<Scaleform::Render::ContextImpl::RenderNotify::ContextNode,Scaleform::Render::ContextImpl::RenderNotify::ContextNode> *p_ActiveContextSet; // ebp
  Scaleform::Render::ContextImpl::Context *pContext; // edi
  _RTL_CRITICAL_SECTION *p_cs; // esi

  p_ActiveContextSet = &this->ActiveContextSet;
  if ( (Scaleform::List<Scaleform::Render::ContextImpl::RenderNotify::ContextNode,Scaleform::Render::ContextImpl::RenderNotify::ContextNode> *)this->ActiveContextSet.Root.pNext != &this->ActiveContextSet )
  {
    do
    {
      pContext = this->ActiveContextSet.Root.pNext->pContext;
      p_cs = &pContext->pCaptureLock.pObject->LockObject.cs;
      EnterCriticalSection(p_cs);
      if ( pContext->CreateThreadId != (void *)Scaleform::GetCurrentThreadId() )
        pContext->MultiThreadedUse = 1;
      Scaleform::Render::ContextImpl::Context::shutdownRendering_NoLock(pContext);
      LeaveCriticalSection(p_cs);
    }
    while ( (Scaleform::List<Scaleform::Render::ContextImpl::RenderNotify::ContextNode,Scaleform::Render::ContextImpl::RenderNotify::ContextNode> *)p_ActiveContextSet->Root.pNext != p_ActiveContextSet );
  }
}
