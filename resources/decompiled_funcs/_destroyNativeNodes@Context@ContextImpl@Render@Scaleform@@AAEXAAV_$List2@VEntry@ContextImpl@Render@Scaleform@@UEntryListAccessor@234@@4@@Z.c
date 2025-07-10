void __thiscall Scaleform::Render::ContextImpl::Context::destroyNativeNodes(
        Scaleform::Render::ContextImpl::Context *this,
        Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *destroyList)
{
  unsigned int RefCount; // esi
  Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *p_FreeNodes; // edi
  Scaleform::Render::ContextImpl::EntryTable *p_Table; // [esp+4h] [ebp-4h]

  RefCount = destroyList->Root.RefCount;
  if ( (Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *)RefCount != destroyList )
  {
    p_Table = &this->Table;
    p_FreeNodes = &this->Table.FreeNodes;
    do
    {
      *(_DWORD *)(*(_DWORD *)RefCount + 4) = *(_DWORD *)(RefCount + 4);
      **(_DWORD **)(RefCount + 4) = *(_DWORD *)RefCount;
      (*(void (__thiscall **)(unsigned int))(*(_DWORD *)(*(_DWORD *)(RefCount + 8) & 0xFFFFFFFE) + 16))(*(_DWORD *)(RefCount + 8) & 0xFFFFFFFE);
      ((void (__stdcall *)(unsigned int))Scaleform::Memory::pGlobalHeap->Free)(*(_DWORD *)(RefCount + 8) & 0xFFFFFFFE);
      *(_DWORD *)(RefCount + 8) = 0;
      *(_DWORD *)(RefCount + 4) = p_FreeNodes->Root.pNext;
      *(_DWORD *)RefCount = p_FreeNodes;
      p_FreeNodes->Root.pNext->pPrev = (Scaleform::Render::ContextImpl::Entry *)RefCount;
      p_FreeNodes->Root.RefCount = RefCount;
      *(_DWORD *)(*(_DWORD *)((RefCount & 0xFFFFF000) + 0x10)
                + 4 * ((int)(RefCount - (RefCount & 0xFFFFF000) - 28) / 28)
                + 20) = 0;
      if ( (*(_DWORD *)((RefCount & 0xFFFFF000) + 8))-- == 1 )
        Scaleform::Render::ContextImpl::EntryTable::FreeEntryPage(
          p_Table,
          (Scaleform::Render::ContextImpl::EntryPage *)(RefCount & 0xFFFFF000));
      RefCount = destroyList->Root.RefCount;
    }
    while ( (Scaleform::List2<Scaleform::Render::ContextImpl::Entry,Scaleform::Render::ContextImpl::EntryListAccessor> *)RefCount != destroyList );
  }
}
