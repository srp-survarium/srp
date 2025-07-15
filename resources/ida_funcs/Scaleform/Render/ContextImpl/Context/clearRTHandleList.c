void __thiscall Scaleform::Render::ContextImpl::Context::clearRTHandleList(
        Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::RTHandle::HandleData *v1; // eax
  Scaleform::Render::ContextImpl::RTHandle::HandleData *pNext; // eax
  Scaleform::Render::ContextImpl::Entry *pEntry; // edx

  while ( 1 )
  {
    v1 = this == (Scaleform::Render::ContextImpl::Context *)-96
       ? 0
       : (Scaleform::Render::ContextImpl::RTHandle::HandleData *)&this->RenderNode.4;
    if ( this->RTHandleList.Root.pNext == v1 )
      break;
    pNext = this->RTHandleList.Root.pNext;
    pNext->pPrev->pNext = pNext->pNext;
    pNext->pNext->pPrev = pNext->pPrev;
    pEntry = pNext->pEntry;
    pNext->State = State_Dead;
    if ( pEntry )
      pEntry->pNative = (Scaleform::Render::ContextImpl::EntryData *)((int)pEntry->pNative & ~1u);
    pNext->pEntry = 0;
  }
}
