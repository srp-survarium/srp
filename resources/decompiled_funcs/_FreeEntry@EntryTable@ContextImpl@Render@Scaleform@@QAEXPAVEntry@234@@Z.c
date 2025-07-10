void __thiscall Scaleform::Render::ContextImpl::EntryTable::FreeEntry(
        Scaleform::Render::ContextImpl::EntryTable *this,
        unsigned int p)
{
  *(_DWORD *)(p + 4) = this->FreeNodes.Root.pNext;
  *(_DWORD *)p = &this->FreeNodes;
  this->FreeNodes.Root.pNext->pPrev = (Scaleform::Render::ContextImpl::Entry *)p;
  this->FreeNodes.Root.RefCount = p;
  *(_DWORD *)(*(_DWORD *)((p & 0xFFFFF000) + 0x10) + 4 * ((int)(p - (p & 0xFFFFF000) - 28) / 28) + 20) = 0;
  if ( (*(_DWORD *)((p & 0xFFFFF000) + 8))-- == 1 )
    Scaleform::Render::ContextImpl::EntryTable::FreeEntryPage(
      this,
      (Scaleform::Render::ContextImpl::EntryPage *)(p & 0xFFFFF000));
}
