void __thiscall Scaleform::Render::ContextImpl::Snapshot::~Snapshot(Scaleform::Render::ContextImpl::Snapshot *this)
{
  Scaleform::List<Scaleform::Render::ContextImpl::Snapshot::HeapNode,Scaleform::Render::ContextImpl::Snapshot::HeapNode> *p_Heaps; // edi
  Scaleform::Render::ContextImpl::Snapshot::HeapNode *pNext; // esi
  Scaleform::Render::ContextImpl::SnapshotPage *v4; // eax
  Scaleform::Render::ContextImpl::SnapshotPage *pNewerSnapshotPage; // ecx
  Scaleform::Render::ContextImpl::SnapshotPage *pOlderSnapshotPage; // ecx

  p_Heaps = &this->Heaps;
  if ( (Scaleform::List<Scaleform::Render::ContextImpl::Snapshot::HeapNode,Scaleform::Render::ContextImpl::Snapshot::HeapNode> *)this->Heaps.Root.pNext != &this->Heaps )
  {
    do
    {
      pNext = this->Heaps.Root.pNext;
      pNext->pPrev->pNext = pNext->pNext;
      pNext->pNext->Scaleform::ListNode<Scaleform::Render::ContextImpl::Snapshot::HeapNode>::$E7F4EF65E359D67DD8FB4306098C3B03::pPrev = pNext->pPrev;
      Scaleform::Render::LinearHeap::ClearAndRelease(&pNext->ChangeHeap);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pNext);
    }
    while ( (Scaleform::List<Scaleform::Render::ContextImpl::Snapshot::HeapNode,Scaleform::Render::ContextImpl::Snapshot::HeapNode> *)p_Heaps->Root.pNext != p_Heaps );
  }
  while ( (Scaleform::List<Scaleform::Render::ContextImpl::SnapshotPage,Scaleform::Render::ContextImpl::SnapshotPage> *)this->SnapshotPages.Root.pNext != &this->SnapshotPages )
  {
    v4 = this->SnapshotPages.Root.pNext;
    v4->pPrev->pNext = v4->pNext;
    v4->pNext->Scaleform::ListNode<Scaleform::Render::ContextImpl::SnapshotPage>::$C3DCB7443EC176C973748899EB0467D2::pPrev = v4->pPrev;
    pNewerSnapshotPage = v4->pNewerSnapshotPage;
    if ( pNewerSnapshotPage )
      pNewerSnapshotPage->pOlderSnapshotPage = v4->pOlderSnapshotPage;
    pOlderSnapshotPage = v4->pOlderSnapshotPage;
    if ( pOlderSnapshotPage )
      pOlderSnapshotPage->pNewerSnapshotPage = v4->pNewerSnapshotPage;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
  }
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::freePages(&this->Changes, 0);
}
