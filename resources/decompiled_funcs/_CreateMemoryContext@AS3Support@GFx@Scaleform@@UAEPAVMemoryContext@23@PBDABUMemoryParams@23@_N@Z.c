Scaleform::GFx::MemoryContext *__userpurge Scaleform::GFx::AS3Support::CreateMemoryContext@<eax>(
        Scaleform::GFx::AS3Support *this@<ecx>,
        int a2@<ebp>,
        const char *heapName,
        const Scaleform::GFx::MemoryParams *memParams,
        bool debugHeap)
{
  unsigned int InitialDynamicLimit; // eax
  Scaleform::MemoryHeap *v6; // edi
  int v7; // eax
  int v8; // esi
  Scaleform::GFx::AS3::ASRefCountCollector *v9; // eax
  int v10; // eax
  Scaleform::RefCountVImpl *v11; // ecx
  Scaleform::GFx::ASStringManager *v12; // eax
  int v13; // eax
  Scaleform::RefCountVImpl *v14; // ecx
  Scaleform::MemoryHeap::HeapDesc desc; // [esp+Ch] [ebp-20h] BYREF
  int debugHeapa; // [esp+38h] [ebp+Ch]
  int v18; // [esp+3Ch] [ebp+10h]

  qmemcpy((void *)&desc, memParams, sizeof(desc));
  desc.Flags |= (debugHeap ? 0x1000 : 0) | 3;
  InitialDynamicLimit = memParams->InitialDynamicLimit;
  desc.HeapId = 3;
  desc.Limit = (unsigned int)&loc_20000;
  if ( InitialDynamicLimit != -1 )
    desc.Limit = InitialDynamicLimit;
  v6 = (Scaleform::MemoryHeap *)((int (__thiscall *)(Scaleform::MemoryHeap *, const char *, Scaleform::MemoryHeap::HeapDesc *, int))Scaleform::Memory::pGlobalHeap->CreateHeap)(
                                  Scaleform::Memory::pGlobalHeap,
                                  heapName,
                                  &desc,
                                  a2);
  v7 = (int)v6->Alloc(v6, 48u, 0);
  if ( v7 )
  {
    *(_DWORD *)v7 = &Scaleform::RefCountImplCore::`vftable';
    *(_DWORD *)(v7 + 4) = 1;
    *(_DWORD *)v7 = &Scaleform::GFx::AS2::MemoryContextImpl::`vftable';
    *(_DWORD *)(v7 + 8) = 0;
    *(_DWORD *)(v7 + 12) = 0;
    *(_DWORD *)(v7 + 16) = 0;
    *(_DWORD *)(v7 + 20) = 0;
    *(float *)(v7 + 44) = 0.25;
    *(_DWORD *)(v7 + 24) = &Scaleform::GFx::AS3::MemoryContextImpl::HeapLimit::`vftable';
    *(_DWORD *)(v7 + 32) = 0;
    *(_DWORD *)(v7 + 36) = 0;
    *(_DWORD *)(v7 + 40) = 0;
    *(_DWORD *)(v7 + 28) = v7;
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  *(_DWORD *)(v8 + 8) = v6;
  v9 = (Scaleform::GFx::AS3::ASRefCountCollector *)v6->Alloc(v6, 152u, 0);
  if ( v9 )
  {
    Scaleform::GFx::AS3::ASRefCountCollector::ASRefCountCollector(v9);
    v18 = v10;
  }
  else
  {
    v18 = 0;
  }
  v11 = *(Scaleform::RefCountVImpl **)(v8 + 16);
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  *(_DWORD *)(v8 + 16) = v18;
  Scaleform::GFx::AS3::ASRefCountCollector::SetParams(
    *(Scaleform::GFx::AS3::ASRefCountCollector **)(v8 + 16),
    memParams->FramesBetweenCollections,
    memParams->MaxCollectionRoots,
    memParams->RunsToUpgradeGen,
    memParams->RunsToCollectYoung,
    memParams->RunsToCollectOld);
  v12 = (Scaleform::GFx::ASStringManager *)((int (__thiscall *)(Scaleform::MemoryHeap *, int))v6->Alloc)(v6, 88);
  if ( v12 )
  {
    Scaleform::GFx::ASStringManager::ASStringManager(v12, v6);
    debugHeapa = v13;
  }
  else
  {
    debugHeapa = 0;
  }
  v14 = *(Scaleform::RefCountVImpl **)(v8 + 12);
  if ( v14 )
    Scaleform::RefCountImpl::Release(v14);
  *(_DWORD *)(v8 + 12) = debugHeapa;
  *(_DWORD *)(v8 + 32) = memParams->Desc.Limit;
  *(float *)(v8 + 44) = memParams->HeapLimitMultiplier;
  v6->SetLimitHandler(v6, (Scaleform::MemoryHeap::LimitHandler *)(v8 + 24));
  Scaleform::MemoryHeap::ReleaseOnFree(v6, (void *)v8);
  return (Scaleform::GFx::MemoryContext *)v8;
}
