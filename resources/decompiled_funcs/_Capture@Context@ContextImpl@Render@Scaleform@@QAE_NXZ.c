char __thiscall Scaleform::Render::ContextImpl::Context::Capture(Scaleform::Render::ContextImpl::Context *this)
{
  Scaleform::Render::ContextImpl::Context *v1; // esi
  Scaleform::Render::ContextImpl::Snapshot *v3; // edi
  Scaleform::Render::ContextImpl::Snapshot *v4; // ebx
  int v5; // ecx
  int v6; // edx
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::Page *i; // eax
  unsigned int v8; // ecx
  Scaleform::Render::ContextImpl::EntryChange *Items; // edx
  Scaleform::Render::ContextImpl::Snapshot *v10; // eax
  Scaleform::Render::ContextImpl::Snapshot *v11; // eax
  Scaleform::Render::ContextImpl::Snapshot *v12; // edi
  bool v13; // cf
  Scaleform::Render::ContextImpl::Snapshot *v14; // eax
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::Page *pPages; // eax
  Scaleform::Render::ContextImpl::EntryChange *v16; // edx
  Scaleform::Render::ContextImpl::Entry *pNode; // ebp
  int v18; // edi
  int v19; // ebx
  unsigned int v20; // ecx
  Scaleform::Render::ContextImpl::ContextCaptureNotify *pNext; // edi
  Scaleform::List<Scaleform::Render::ContextImpl::ContextCaptureNotify,Scaleform::Render::ContextImpl::ContextCaptureNotify> *p_CaptureNotifyList; // esi
  int v23; // eax
  Scaleform::Render::PagedItemBuffer<Scaleform::Render::ContextImpl::EntryChange,126>::Page *pcbPage; // [esp+10h] [ebp-14h]
  unsigned int iitem; // [esp+18h] [ebp-Ch]
  Scaleform::Render::ContextImpl::EntryChange *v27; // [esp+1Ch] [ebp-8h]
  _RTL_CRITICAL_SECTION *scopeLock; // [esp+20h] [ebp-4h]

  v1 = this;
  Scaleform::Render::ContextImpl::Context::PropagateChangesUp(this);
  if ( v1->ShutdownRequested )
    return 0;
  scopeLock = &v1->pCaptureLock.pObject->LockObject.cs;
  EnterCriticalSection(scopeLock);
  Scaleform::Render::ContextImpl::Context::handleFinalizingSnaphot(v1);
  v3 = v1->pSnapshots[0];
  Scaleform::Render::ContextImpl::EntryTable::GetActiveSnapshotPages(
    &v1->Table,
    (Scaleform::Render::ContextImpl::SnapshotPage *)&v3->SnapshotPages);
  if ( v1->pSnapshots[1] )
  {
    Scaleform::Render::ContextImpl::Snapshot::Merge(v3, v1->pSnapshots[1]);
    v4 = v1->pSnapshots[1];
    if ( v4 )
    {
      Scaleform::Render::ContextImpl::Snapshot::~Snapshot(v1->pSnapshots[1]);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
    }
  }
  v5 = v1->SnapshotFrameIds[0];
  v6 = HIDWORD(v1->SnapshotFrameIds[0]);
  v1->pSnapshots[1] = v3;
  LODWORD(v1->SnapshotFrameIds[1]) = v5;
  HIDWORD(v1->SnapshotFrameIds[1]) = v6;
  for ( i = v3->Changes.pPages; i; i = i->pNext )
  {
    v8 = 0;
    if ( i->Count )
    {
      Items = i->Items;
      do
      {
        if ( Items->pNode )
          Items->pNode->pPrev = 0;
        ++v8;
        ++Items;
      }
      while ( v8 < i->Count );
    }
  }
  v10 = (Scaleform::Render::ContextImpl::Snapshot *)v1->pHeap->Alloc(v1->pHeap, 80u, 0);
  if ( v10 )
  {
    Scaleform::Render::ContextImpl::Snapshot::Snapshot(v10, v1, v1->pHeap);
    v12 = v11;
  }
  else
  {
    v12 = 0;
  }
  Scaleform::Render::ContextImpl::EntryTable::NextSnapshot(&v1->Table, v12);
  v13 = __CFADD__(LODWORD(v1->SnapshotFrameIds[0])++, 1);
  v14 = v1->pSnapshots[2];
  v1->pSnapshots[0] = v12;
  HIDWORD(v1->SnapshotFrameIds[0]) += v13;
  if ( v14 )
  {
    pPages = v14->Changes.pPages;
    pcbPage = pPages;
    if ( pPages )
    {
      while ( 1 )
      {
        iitem = 0;
        if ( pPages->Count )
        {
          v16 = pPages->Items;
          v27 = pPages->Items;
          do
          {
            pNode = v16->pNode;
            if ( v16->pNode && (v16->ChangeBits & 0x80000000) == 0 )
            {
              v18 = *(_DWORD *)(((unsigned int)pNode & 0xFFFFF000) + 0x14);
              v19 = *(_DWORD *)(v18 + 16);
              v20 = *(_DWORD *)(v19 + 4 * ((int)((int)&pNode[-1] - ((unsigned int)pNode & 0xFFFFF000)) / 28) + 20)
                  & 0xFFFFFFFE;
              if ( *(_DWORD *)(v18 + 4 * ((int)((int)&pNode[-1] - ((unsigned int)pNode & 0xFFFFF000)) / 28) + 20) == v20 )
              {
                (*(void (__thiscall **)(unsigned int, unsigned int))(*(_DWORD *)v20 + 8))(
                  v20,
                  (int)pNode->pNative & 0xFFFFFFFE);
                *(_DWORD *)(v19 + 4 * ((int)((int)&pNode[-1] - ((unsigned int)pNode & 0xFFFFF000)) / 28) + 20) = (int)pNode->pNative ^ (*(_DWORD *)(v19 + 4 * ((int)((int)&pNode[-1] - ((unsigned int)pNode & 0xFFFFF000)) / 28) + 20) ^ (int)pNode->pNative) & 1;
              }
              v1 = this;
              pPages = pcbPage;
            }
            v16 = v27 + 1;
            ++iitem;
            ++v27;
          }
          while ( iitem < pPages->Count );
        }
        pcbPage = pPages->pNext;
        if ( !pPages->pNext )
          break;
        pPages = pPages->pNext;
      }
    }
  }
  pNext = v1->CaptureNotifyList.Root.pNext;
  v1->CaptureCalled = 1;
  p_CaptureNotifyList = &v1->CaptureNotifyList;
  while ( 1 )
  {
    v23 = p_CaptureNotifyList ? (int)&p_CaptureNotifyList[-1].Root.4 : 0;
    if ( pNext == (Scaleform::Render::ContextImpl::ContextCaptureNotify *)v23 )
      break;
    pNext->OnCapture(pNext);
    pNext = pNext->pNext;
  }
  LeaveCriticalSection(scopeLock);
  return 1;
}
