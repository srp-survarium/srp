void __thiscall Scaleform::Render::ContextImpl::Context::nextCapture_NotifyChanges(
        Scaleform::Render::ContextImpl::Context *this,
        Scaleform::Render::ContextImpl::Snapshot *displaySnaphot,
        Scaleform::Render::ContextImpl::RenderNotify *pnotify)
{
  Scaleform::Render::ContextImpl::Snapshot *pNext; // esi
  Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *p_DestroyedNodes; // ebp
  Scaleform::Render::ContextImpl::Entry *v5; // edi
  Scaleform::Lock *p_LockObject; // esi

  if ( displaySnaphot )
  {
    pnotify->EntryChanges(pnotify, this, &displaySnaphot->Changes, displaySnaphot->ForceUpdateImagesFlag);
    pNext = (Scaleform::Render::ContextImpl::Snapshot *)displaySnaphot->DestroyedNodes.Root.pNext;
    p_DestroyedNodes = &displaySnaphot->DestroyedNodes;
    displaySnaphot->ForceUpdateImagesFlag = 0;
    if ( pNext != (Scaleform::Render::ContextImpl::Snapshot *)&displaySnaphot->DestroyedNodes )
    {
      do
      {
        pnotify->EntryDestroy(pnotify, (Scaleform::Render::ContextImpl::Entry *)pNext);
        pNext->SnapshotPages.Root.pPrev = (Scaleform::Render::ContextImpl::SnapshotPage *)2989;
        pNext = pNext->pNext;
      }
      while ( pNext != (Scaleform::Render::ContextImpl::Snapshot *)p_DestroyedNodes );
      v5 = displaySnaphot->DestroyedNodes.Root.pNext;
      p_LockObject = &this->pCaptureLock.pObject->LockObject;
      EnterCriticalSection(&p_LockObject->cs);
      do
      {
        if ( ((int)v5->pNative & 1) != 0 )
          Scaleform::Render::ContextImpl::Context::clearRTHandle(this, v5);
        v5 = v5->pNext;
      }
      while ( v5 != (Scaleform::Render::ContextImpl::Entry *)p_DestroyedNodes );
      LeaveCriticalSection(&p_LockObject->cs);
    }
  }
}
