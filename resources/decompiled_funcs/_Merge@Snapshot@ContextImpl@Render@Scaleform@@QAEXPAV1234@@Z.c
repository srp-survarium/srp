void __thiscall Scaleform::Render::ContextImpl::Snapshot::Merge(
        Scaleform::Render::ContextImpl::Snapshot *this,
        Scaleform::Render::ContextImpl::Snapshot *pold)
{
  Scaleform::Render::ContextImpl::Snapshot *v2; // ebx
  Scaleform::Render::ContextImpl::Snapshot *v3; // edi
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::Page *v4; // ecx
  Scaleform::Render::ContextImpl::Entry *pNode; // ebx
  int v6; // eax
  int v7; // esi
  int v8; // ebp
  Scaleform::Render::ContextImpl::Entry *pPrev; // eax
  Scaleform::Render::ContextImpl::EntryChange *pFreeChangeNodes; // eax
  unsigned int ChangeBits; // edi
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::Page *pLast; // eax
  unsigned int Count; // ecx
  bool ForceUpdateImagesFlag; // al
  Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *pNext; // edx
  Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *p_DestroyedNodes; // eax
  Scaleform::Render::ContextImpl::Entry *v17; // esi
  Scaleform::Render::ContextImpl::Snapshot::HeapNode *v18; // edx
  Scaleform::List<Scaleform::Render::ContextImpl::Snapshot::HeapNode,Scaleform::Render::ContextImpl::Snapshot::HeapNode> *p_Heaps; // eax
  Scaleform::Render::ContextImpl::Snapshot::HeapNode *v20; // esi
  Scaleform::Render::ContextImpl::EntryChange *Items; // [esp+Ch] [ebp-10h]
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::Page *poldPage; // [esp+10h] [ebp-Ch]
  unsigned int iitem; // [esp+14h] [ebp-8h]

  v2 = pold;
  v3 = this;
  poldPage = pold->Changes.pPages;
  if ( poldPage )
  {
    do
    {
      v4 = poldPage;
      iitem = 0;
      if ( poldPage->Count )
      {
        Items = poldPage->Items;
        do
        {
          pNode = Items->pNode;
          if ( Items->pNode )
          {
            v6 = *(_DWORD *)(((unsigned int)pNode & 0xFFFFF000) + 0x10);
            v7 = (int)((int)&pNode[-1] - ((unsigned int)pNode & 0xFFFFF000)) / 28;
            v8 = *(_DWORD *)(*(_DWORD *)(v6 + 12) + 4 * v7 + 20);
            if ( *(_DWORD *)(v6 + 4 * v7 + 20) == v8 )
            {
              pFreeChangeNodes = this->pFreeChangeNodes;
              ChangeBits = Items->ChangeBits;
              if ( pFreeChangeNodes )
              {
                this->pFreeChangeNodes = pFreeChangeNodes->pNextFreeNode;
              }
              else
              {
                Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::ensureCountAvailable(
                  &this->Changes,
                  1u);
                pLast = this->Changes.pLast;
                Count = pLast->Count;
                pLast->Count = Count + 1;
                pFreeChangeNodes = &pLast->Items[Count];
              }
              pFreeChangeNodes->pNode = pNode;
              pFreeChangeNodes->ChangeBits = ChangeBits;
            }
            else
            {
              if ( (Items->ChangeBits & 0x80000000) == 0 )
              {
                if ( (*(_DWORD *)(*(_DWORD *)(((unsigned int)pNode & 0xFFFFF000) + 0x10) + 4 * v7 + 20) & 0xFFFFFFFE) == v8 )
                {
                  (*(void (__thiscall **)(int, unsigned int))(*(_DWORD *)v8 + 8))(v8, (int)pNode->pNative & 0xFFFFFFFE);
                  *(_DWORD *)(*(_DWORD *)(((unsigned int)pNode & 0xFFFFF000) + 0x10) + 4 * v7 + 20) = (int)Items->pNode->pNative ^ (*(_DWORD *)(*(_DWORD *)(((unsigned int)pNode & 0xFFFFF000) + 0x10) + 4 * v7 + 20) ^ (int)Items->pNode->pNative) & 1;
                }
                (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 16))(v8);
              }
              pPrev = Items->pNode->pPrev;
              if ( pPrev && (*(_BYTE *)(*(_DWORD *)(((unsigned int)pNode & 0xFFFFF000) + 0x10) + 4 * v7 + 20) & 1) == 0 )
                pPrev->RefCount |= Items->ChangeBits & 0x7FFFFFFF;
            }
          }
          v4 = poldPage;
          ++Items;
          ++iitem;
        }
        while ( iitem < poldPage->Count );
        v2 = pold;
        v3 = this;
      }
      poldPage = v4->pNext;
    }
    while ( v4->pNext );
  }
  ForceUpdateImagesFlag = v2->ForceUpdateImagesFlag;
  if ( ForceUpdateImagesFlag )
    v3->ForceUpdateImagesFlag = ForceUpdateImagesFlag;
  pNext = (Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *)v2->DestroyedNodes.Root.pNext;
  p_DestroyedNodes = &v2->DestroyedNodes;
  if ( pNext != &v2->DestroyedNodes )
  {
    v17 = p_DestroyedNodes->Root.pPrev;
    p_DestroyedNodes->Root.pPrev = &p_DestroyedNodes->Root;
    v2->DestroyedNodes.Root.RefCount = (unsigned int)&v2->DestroyedNodes;
    v17->RefCount = v3->DestroyedNodes.Root.RefCount;
    pNext->Root.pPrev = &v3->DestroyedNodes.Root;
    v3->DestroyedNodes.Root.pNext->pPrev = v17;
    v3->DestroyedNodes.Root.RefCount = (unsigned int)pNext;
  }
  v18 = v2->Heaps.Root.pNext;
  p_Heaps = &v2->Heaps;
  if ( v18 != (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)&v2->Heaps )
  {
    v20 = p_Heaps->Root.pPrev;
    p_Heaps->Root.pPrev = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)p_Heaps;
    v2->Heaps.Root.pNext = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)&v2->Heaps;
    v20->pNext = v3->Heaps.Root.pNext;
    v18->pPrev = (Scaleform::Render::ContextImpl::Snapshot::HeapNode *)&v3->Heaps;
    v3->Heaps.Root.pNext->pPrev = v20;
    v3->Heaps.Root.pNext = v18;
  }
}
