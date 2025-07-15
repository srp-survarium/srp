void __thiscall Scaleform::Render::ContextImpl::RTHandle::RTHandle(
        Scaleform::Render::ContextImpl::RTHandle *this,
        Scaleform::Render::ContextImpl::Entry *entry)
{
  Scaleform::Render::ContextImpl::Context *v3; // esi
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v4; // eax
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v5; // eax
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v6; // edi
  _RTL_CRITICAL_SECTION *p_cs; // edi
  Scaleform::Render::ContextImpl::RTHandle::HandleData *pObject; // eax

  this->pData.pObject = 0;
  if ( entry )
  {
    v3 = *(Scaleform::Render::ContextImpl::Context **)(*(_DWORD *)(((unsigned int)entry & 0xFFFFF000) + 0xC) + 8);
    v4 = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                                   Scaleform::Memory::pGlobalHeap,
                                                                   28,
                                                                   0);
    if ( v4 )
    {
      Scaleform::Render::ContextImpl::RTHandle::HandleData::HandleData(v4, entry, v3);
      v6 = v5;
    }
    else
    {
      v6 = 0;
    }
    if ( this->pData.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)this->pData.pObject);
    this->pData.pObject = v6;
    p_cs = &v3->pCaptureLock.pObject->LockObject.cs;
    EnterCriticalSection(p_cs);
    entry->pNative = (Scaleform::Render::ContextImpl::EntryData *)((int)entry->pNative | 1);
    pObject = this->pData.pObject;
    pObject->pPrev = v3->RTHandleList.Root.pPrev;
    pObject->pNext = (Scaleform::Render::ContextImpl::RTHandle::HandleData *)&v3->RenderNode.4;
    v3->RTHandleList.Root.pPrev->pNext = pObject;
    v3->RTHandleList.Root.pPrev = pObject;
    LeaveCriticalSection(p_cs);
  }
}
