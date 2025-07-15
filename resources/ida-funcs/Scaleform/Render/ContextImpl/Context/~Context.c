void __thiscall Scaleform::Render::ContextImpl::Context::~Context(Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Snapshot *v2; // eax
  Scaleform::Render::ContextImpl::ContextCaptureNotify *v3; // eax
  Scaleform::Render::ContextImpl::ContextCaptureNotify *pNext; // eax
  Scaleform::RefCountVImpl *pObject; // ecx

  Scaleform::Render::ContextImpl::Context::Shutdown(this, 1);
  Scaleform::Render::ContextImpl::Context::destroySnapshot(this, this->pSnapshots[3]);
  Scaleform::Render::ContextImpl::Context::destroySnapshot(this, this->pSnapshots[2]);
  Scaleform::Render::ContextImpl::Context::destroySnapshot(this, this->pSnapshots[1]);
  v2 = this->pSnapshots[0];
  if ( v2 )
  {
    Scaleform::Render::ContextImpl::EntryTable::GetActiveSnapshotPages(
      &this->Table,
      (Scaleform::Render::ContextImpl::SnapshotPage *)&v2->SnapshotPages);
    Scaleform::Render::ContextImpl::Context::destroySnapshot(this, this->pSnapshots[0]);
  }
  while ( 1 )
  {
    v3 = this == (Scaleform::Render::ContextImpl::Context *)-60
       ? 0
       : (Scaleform::Render::ContextImpl::ContextCaptureNotify *)&this->pCaptureLock;
    if ( this->CaptureNotifyList.Root.pNext == v3 )
      break;
    pNext = this->CaptureNotifyList.Root.pNext;
    pNext->pOwnedContext = 0;
    pNext->pPrev->pNext = pNext->pNext;
    pNext->pNext->pPrev = pNext->pPrev;
  }
  pObject = (Scaleform::RefCountVImpl *)this->pCaptureLock.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
}
