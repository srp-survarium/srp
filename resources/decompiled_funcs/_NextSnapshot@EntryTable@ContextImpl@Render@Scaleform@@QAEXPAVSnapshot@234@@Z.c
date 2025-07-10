void __thiscall Scaleform::Render::ContextImpl::EntryTable::NextSnapshot(
        Scaleform::Render::ContextImpl::EntryTable *this,
        Scaleform::Render::ContextImpl::Snapshot *pnewSnapshot)
{
  Scaleform::Render::ContextImpl::EntryTable *v2; // esi
  Scaleform::Render::ContextImpl::EntryTable *pNext; // ebp
  Scaleform::Render::ContextImpl::Entry *pPrev; // ebx
  Scaleform::Render::ContextImpl::Entry *v5; // eax

  v2 = this;
  pNext = (Scaleform::Render::ContextImpl::EntryTable *)this->EntryPages.Root.pNext;
  if ( pNext == (Scaleform::Render::ContextImpl::EntryTable *)&this->EntryPages )
  {
    this->pActiveSnapshot = pnewSnapshot;
  }
  else
  {
    do
    {
      pPrev = pNext->FreeNodes.Root.pPrev;
      v5 = (Scaleform::Render::ContextImpl::Entry *)v2->pHeap->Alloc(v2->pHeap, 600u, 16u, 0);
      if ( v5 )
      {
        v5->pPrev = 0;
        v5->RefCount = 0;
        v5->pNative = pPrev->pNative;
        v5->pParent = 0;
        v5->pRenderer = (Scaleform::Render::TreeCacheNode *)pPrev;
        qmemcpy(&v5->PNode, &pPrev->PNode, 0x244u);
        v2 = this;
        pPrev->pParent = v5;
      }
      else
      {
        v5 = 0;
      }
      pNext->FreeNodes.Root.pPrev = v5;
      pNext->EntryPages.Root.pNext = (Scaleform::Render::ContextImpl::EntryPageBase *)pnewSnapshot;
      pNext = (Scaleform::Render::ContextImpl::EntryTable *)pNext->pHeap;
    }
    while ( pNext != (Scaleform::Render::ContextImpl::EntryTable *)&v2->EntryPages );
    v2->pActiveSnapshot = pnewSnapshot;
  }
}
