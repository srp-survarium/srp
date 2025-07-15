void __thiscall Scaleform::Render::ContextImpl::Context::destroySnapshot(
        Scaleform::Render::ContextImpl::Context *this,
        Scaleform::Render::ContextImpl::Snapshot *p)
{
  Scaleform::Render::ContextImpl::Snapshot *v2; // esi
  Scaleform::Render::ContextImpl::Snapshot *i; // eax
  Scaleform::Render::ContextImpl::Context *pContext; // ecx
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::Page *j; // ebx
  unsigned int v6; // ebp
  Scaleform::Render::ContextImpl::EntryChange *Items; // edi
  int v8; // ecx

  v2 = p;
  if ( p )
  {
    for ( i = (Scaleform::Render::ContextImpl::Snapshot *)p->SnapshotPages.Root.pNext;
          i != (Scaleform::Render::ContextImpl::Snapshot *)&p->SnapshotPages;
          i = i->pNext )
    {
      pContext = i->pContext;
      if ( pContext )
        pContext->Table.FreeNodes.Root.pPrev = (Scaleform::Render::ContextImpl::Entry *)i;
    }
    for ( j = p->Changes.pPages; j; j = j->pNext )
    {
      v6 = 0;
      if ( j->Count )
      {
        Items = j->Items;
        do
        {
          if ( Items->pNode )
          {
            if ( (Items->ChangeBits & 0x80000000) == 0 )
            {
              v8 = *(_DWORD *)(*(_DWORD *)(((int)Items->pNode & 0xFFFFF000) + 0x18)
                             + 4 * ((int)((int)&Items->pNode[-1] - ((int)Items->pNode & 0xFFFFF000)) / 28)
                             + 20);
              (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 16))(v8);
              v2 = p;
            }
          }
          ++v6;
          ++Items;
        }
        while ( v6 < j->Count );
      }
    }
    Scaleform::Render::ContextImpl::Context::destroyNativeNodes(this, &v2->DestroyedNodes);
    Scaleform::Render::ContextImpl::Snapshot::~Snapshot(v2);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v2);
  }
}
