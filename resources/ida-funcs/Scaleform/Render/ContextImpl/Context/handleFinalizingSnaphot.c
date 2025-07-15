void __thiscall Scaleform::Render::ContextImpl::Context::handleFinalizingSnaphot(
        Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Context *v1; // edi
  Scaleform::Render::ContextImpl::Snapshot *v2; // esi
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::Page *i; // ebp
  Scaleform::Render::ContextImpl::EntryChange *Items; // ebx
  Scaleform::Render::ContextImpl::Entry *pNode; // edi
  int v6; // eax
  int v7; // ecx
  int v8; // edx
  int v9; // ecx
  int v10; // edx
  unsigned int v11; // [esp+8h] [ebp-Ch]
  Scaleform::Render::ContextImpl::Snapshot *v12; // [esp+Ch] [ebp-8h]

  v1 = this;
  v2 = this->pSnapshots[3];
  v12 = v2;
  if ( v2 )
  {
    for ( i = v2->Changes.pPages; i; i = i->pNext )
    {
      v11 = 0;
      if ( i->Count )
      {
        Items = i->Items;
        do
        {
          pNode = Items->pNode;
          if ( Items->pNode && (Items->ChangeBits & 0x80000000) == 0 )
          {
            v6 = (int)((int)&pNode[-1] - ((unsigned int)pNode & 0xFFFFF000)) / 28;
            v7 = *(_DWORD *)(((unsigned int)pNode & 0xFFFFF000) + 0x10);
            v8 = *(_DWORD *)(*(_DWORD *)(((unsigned int)pNode & 0xFFFFF000) + 0x14) + 12);
            if ( *(_DWORD *)(v8 + 4 * v6 + 20) == (*(_DWORD *)(v7 + 4 * v6 + 20) & 0xFFFFFFFE) )
              *(_DWORD *)(v7 + 4 * v6 + 20) = (int)pNode->pNative
                                            ^ (*(_DWORD *)(v7 + 4 * v6 + 20)
                                             ^ (int)pNode->pNative)
                                            & 1;
            (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(v8 + 4 * v6 + 20) + 16))(*(_DWORD *)(v8 + 4 * v6 + 20));
            v2 = v12;
          }
          ++Items;
          ++v11;
        }
        while ( v11 < i->Count );
        v1 = this;
      }
    }
    Scaleform::Render::ContextImpl::Context::destroyNativeNodes(v1, &v2->DestroyedNodes);
    if ( v2 )
    {
      Scaleform::Render::ContextImpl::Snapshot::~Snapshot(v2);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v2);
    }
    v9 = v1->SnapshotFrameIds[3];
    v10 = HIDWORD(v1->SnapshotFrameIds[3]);
    v1->pSnapshots[3] = 0;
    LODWORD(v1->FinalizedFrameId) = v9;
    HIDWORD(v1->FinalizedFrameId) = v10;
  }
}
