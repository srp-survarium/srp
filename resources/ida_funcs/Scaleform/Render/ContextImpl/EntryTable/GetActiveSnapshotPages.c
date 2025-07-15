void __thiscall Scaleform::Render::ContextImpl::EntryTable::GetActiveSnapshotPages(
        Scaleform::Render::ContextImpl::EntryTable *this,
        Scaleform::Render::ContextImpl::SnapshotPage *plist)
{
  Scaleform::Render::ContextImpl::EntryTable *i; // edx
  Scaleform::Render::ContextImpl::SnapshotPage *pPrev; // eax

  for ( i = (Scaleform::Render::ContextImpl::EntryTable *)this->EntryPages.Root.pNext;
        i != (Scaleform::Render::ContextImpl::EntryTable *)&this->EntryPages;
        i = (Scaleform::Render::ContextImpl::EntryTable *)i->pHeap )
  {
    pPrev = (Scaleform::Render::ContextImpl::SnapshotPage *)i->FreeNodes.Root.pPrev;
    pPrev->pPrev = plist->pPrev;
    pPrev->pNext = plist;
    plist->pPrev->pNext = pPrev;
    plist->pPrev = pPrev;
  }
}
