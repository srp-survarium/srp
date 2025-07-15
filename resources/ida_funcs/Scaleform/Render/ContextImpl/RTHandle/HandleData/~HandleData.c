void __thiscall Scaleform::Render::ContextImpl::RTHandle::HandleData::~HandleData(
        Scaleform::Render::ContextImpl::RTHandle::HandleData *this)
{
  Scaleform::Lock *p_LockObject; // edi
  Scaleform::Render::ContextImpl::Entry *pEntry; // eax
  Scaleform::RefCountVImpl *pObject; // ecx

  p_LockObject = &this->pContextLock.pObject->LockObject;
  this->__vftable = (Scaleform::Render::ContextImpl::RTHandle::HandleData_vtbl *)&Scaleform::Render::ContextImpl::RTHandle::HandleData::`vftable';
  EnterCriticalSection(&p_LockObject->cs);
  if ( this->pContextLock.pObject->pContext )
  {
    pEntry = this->pEntry;
    if ( pEntry )
    {
      pEntry->pNative = (Scaleform::Render::ContextImpl::EntryData *)((int)pEntry->pNative & ~1u);
      this->pPrev->pNext = this->pNext;
      this->pNext->pPrev = this->pPrev;
    }
  }
  LeaveCriticalSection(&p_LockObject->cs);
  pObject = (Scaleform::RefCountVImpl *)this->pContextLock.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
