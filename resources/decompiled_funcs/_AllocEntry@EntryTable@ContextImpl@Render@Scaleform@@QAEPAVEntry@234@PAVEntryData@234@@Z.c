Scaleform::Render::ContextImpl::Entry *__thiscall Scaleform::Render::ContextImpl::EntryTable::AllocEntry(
        Scaleform::Render::ContextImpl::EntryTable *this,
        Scaleform::Render::ContextImpl::EntryData *pdata)
{
  Scaleform::Render::ContextImpl::Entry *pNext; // ecx

  if ( (Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *)this->FreeNodes.Root.pNext == &this->FreeNodes
    && !Scaleform::Render::ContextImpl::EntryTable::AllocEntryPage(this) )
  {
    return 0;
  }
  pNext = this->FreeNodes.Root.pNext;
  pNext->pPrev->RefCount = pNext->RefCount;
  pNext->pNext->$98779B275605A540A5FF3CE1916F2CF0::pPrev = pNext->pPrev;
  ++*(_DWORD *)(((unsigned int)pNext & 0xFFFFF000) + 8);
  *(_DWORD *)(*(_DWORD *)(((unsigned int)pNext & 0xFFFFF000) + 0x10)
            + 4 * ((int)((int)&pNext[-1] - ((unsigned int)pNext & 0xFFFFF000)) / 28)
            + 20) = pdata;
  return pNext;
}
