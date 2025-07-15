void __thiscall Scaleform::Render::ContextImpl::EntryTable::FreeEntryPage(
        Scaleform::Render::ContextImpl::EntryTable *this,
        Scaleform::Render::ContextImpl::EntryPage *ppage)
{
  Scaleform::Lock *p_LockObject; // ebx
  Scaleform::Render::ContextImpl::SnapshotPage *pSnapshotPage; // eax
  Scaleform::Render::ContextImpl::SnapshotPage *i; // ecx
  Scaleform::Render::ContextImpl::SnapshotPage *v6; // eax
  Scaleform::Render::ContextImpl::SnapshotPage *v7; // eax
  Scaleform::Render::ContextImpl::SnapshotPage *pNewerSnapshotPage; // ecx
  Scaleform::Render::ContextImpl::SnapshotPage *pOlderSnapshotPage; // ecx

  p_LockObject = &this->pContext->pCaptureLock.pObject->LockObject;
  EnterCriticalSection(&p_LockObject->cs);
  ppage->pPrev->pNext = ppage->pNext;
  ppage->pNext->Scaleform::Render::ContextImpl::EntryPageBase::Scaleform::ListNode<Scaleform::Render::ContextImpl::EntryPageBase>::$0C503D7469F7CED3D5AC099D4C721B0A::pPrev = ppage->pPrev;
  Scaleform::Render::ContextImpl::EntryPage::RemoveEntriesFromList(ppage, &this->FreeNodes);
  pSnapshotPage = ppage->pSnapshotPage;
  for ( i = pSnapshotPage->pNewerSnapshotPage; i; i = i->pNewerSnapshotPage )
    pSnapshotPage = i;
  do
  {
    pSnapshotPage->pEntryPage = 0;
    pSnapshotPage = pSnapshotPage->pOlderSnapshotPage;
  }
  while ( pSnapshotPage );
  v6 = ppage->pSnapshotPage;
  if ( v6->pNext )
  {
    v6->pPrev->pNext = v6->pNext;
    v6->pNext->Scaleform::ListNode<Scaleform::Render::ContextImpl::SnapshotPage>::$BA975D4AA5D1C976BB87C4661EC708FF::pPrev = v6->pPrev;
  }
  v7 = ppage->pSnapshotPage;
  pNewerSnapshotPage = v7->pNewerSnapshotPage;
  if ( pNewerSnapshotPage )
    pNewerSnapshotPage->pOlderSnapshotPage = v7->pOlderSnapshotPage;
  pOlderSnapshotPage = v7->pOlderSnapshotPage;
  if ( pOlderSnapshotPage )
    pOlderSnapshotPage->pNewerSnapshotPage = v7->pNewerSnapshotPage;
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, ppage);
  LeaveCriticalSection(&p_LockObject->cs);
}
