void __thiscall Scaleform::Render::ContextImpl::Snapshot::Snapshot(
        Scaleform::Render::ContextImpl::Snapshot *this,
        Scaleform::Render::ContextImpl::Context *pcontext,
        Scaleform::MemoryHeap *pheap)
{
  Scaleform::List<Scaleform::Render::ContextImpl::Snapshot::HeapNode,Scaleform::Render::ContextImpl::Snapshot::HeapNode> *p_Heaps; // edi
  Scaleform::Render::ContextImpl::Snapshot::HeapNode *v4; // eax
  Scaleform::Render::ContextImpl::Snapshot::HeapNode *pPrev; // ecx

  this->pContext = pcontext;
  this->SnapshotPages.Root.pPrev = (Scaleform::Render::ContextImpl::SnapshotPage *)&this->SnapshotPages;
  this->SnapshotPages.Root.pNext = (Scaleform::Render::ContextImpl::SnapshotPage *)&this->SnapshotPages;
  this->Changes.pPages = 0;
  this->Changes.pLast = 0;
  this->pFreeChangeNodes = 0;
  this->PropagateEntrys.Root.pPrev = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)&this->PropagateEntrys;
  this->PropagateEntrys.Root.pNext = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)&this->PropagateEntrys;
  this->DestroyedNodes.Root.pPrev = &this->DestroyedNodes.Root;
  this->DestroyedNodes.Root.RefCount = (unsigned int)&this->DestroyedNodes;
  this->ForceUpdateImagesFlag = 0;
  p_Heaps = &this->Heaps;
  this->Heaps.Root.pPrev = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)&this->Heaps;
  this->Heaps.Root.pNext = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)&this->Heaps;
  v4 = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)pheap->Alloc(pheap, 28, 0);
  if ( v4 )
  {
    v4->ChangeHeap.pHeap = pheap;
    v4->ChangeHeap.Granularity = 0x2000;
    v4->ChangeHeap.pPagePool = 0;
    v4->ChangeHeap.pLastPage = 0;
    v4->ChangeHeap.MaxPages = 0;
  }
  else
  {
    v4 = 0;
  }
  pPrev = p_Heaps->Root.pPrev;
  v4->pNext = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)p_Heaps;
  v4->pPrev = pPrev;
  p_Heaps->Root.pPrev->pNext = v4;
  p_Heaps->Root.pPrev = v4;
}
