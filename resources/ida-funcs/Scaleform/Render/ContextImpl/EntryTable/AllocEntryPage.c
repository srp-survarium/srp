char __thiscall Scaleform::Render::ContextImpl::EntryTable::AllocEntryPage(
        Scaleform::Render::ContextImpl::EntryTable *this)
{
  Scaleform::Render::ContextImpl::EntryPage *v2; // eax
  Scaleform::Render::ContextImpl::EntryPage *v3; // esi
  Scaleform::Render::ContextImpl::SnapshotPage *v4; // eax
  Scaleform::Render::ContextImpl::EntryPageBase *pPrev; // edx

  v2 = (Scaleform::Render::ContextImpl::EntryPage *)this->pHeap->Alloc(this->pHeap, 4092, 4096, 0);
  v3 = v2;
  if ( !v2 )
    return 0;
  memset((int)v2, 0, 4092);
  v4 = (Scaleform::Render::ContextImpl::SnapshotPage *)this->pHeap->Alloc(this->pHeap, 600, 16, 0);
  if ( v4 )
  {
    v4->pPrev = 0;
    v4->pNext = 0;
    v4->pEntryPage = v3;
    v4->pOlderSnapshotPage = 0;
    v4->pNewerSnapshotPage = 0;
  }
  else
  {
    v4 = 0;
  }
  v3->pSnapshotPage = v4;
  if ( !v4 )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
    return 0;
  }
  v3->pDisplaySnapshotPage = 0;
  v3->pSnapshot = this->pActiveSnapshot;
  v3->UseCount = 0;
  Scaleform::Render::ContextImpl::EntryPage::AddEntriesToList(v3, &this->FreeNodes);
  pPrev = this->EntryPages.Root.pPrev;
  v3->pNext = (Scaleform::Render::ContextImpl::EntryPageBase *)&this->EntryPages;
  v3->pPrev = pPrev;
  this->EntryPages.Root.pPrev->pNext = v3;
  this->EntryPages.Root.pPrev = v3;
  return 1;
}
