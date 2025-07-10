void __thiscall Scaleform::Render::ContextImpl::Context::clearRTHandle(
        Scaleform::Render::ContextImpl::Context *this,
        Scaleform::Render::ContextImpl::Entry *entry)
{
  Scaleform::Render::ContextImpl::RTHandle::HandleData *pNext; // eax
  Scaleform::List<Scaleform::Render::ContextImpl::RTHandle::HandleData,Scaleform::Render::ContextImpl::RTHandle::HandleData> *p_RTHandleList; // edx
  int v4; // ecx

  pNext = this->RTHandleList.Root.pNext;
  p_RTHandleList = &this->RTHandleList;
  while ( 1 )
  {
    v4 = p_RTHandleList ? (int)&p_RTHandleList[-1] : 0;
    if ( pNext == (Scaleform::Render::ContextImpl::RTHandle::HandleData *)v4 )
      break;
    if ( pNext->pEntry == entry )
    {
      pNext->pPrev->pNext = pNext->pNext;
      pNext->pNext->pPrev = pNext->pPrev;
      pNext->State = State_Dead;
      pNext->pEntry = 0;
      entry->pNative = (Scaleform::Render::ContextImpl::EntryData *)((int)entry->pNative & ~1u);
      return;
    }
    pNext = pNext->pNext;
  }
}
