Scaleform::Heap::HeapSegment *__thiscall Scaleform::HeapPT::AllocEngine::allocSegmentNoGranulator(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned int dataSize,
        unsigned int alignSize,
        bool *limHandlerOK)
{
  unsigned int Limit; // edx
  unsigned int Footprint; // eax
  void *pLimHandler; // ecx
  Scaleform::LockSafe *p_RootLock; // ebx
  Scaleform::Heap::HeapSegment *v10; // esi
  unsigned __int8 *v11; // ebp
  unsigned int v12; // eax
  unsigned int v13; // ebx
  unsigned __int16 v14; // dx
  unsigned int v15; // eax
  unsigned int v16; // [esp+14h] [ebp-20h]
  Scaleform::LockSafe *lpCriticalSection; // [esp+28h] [ebp-Ch]
  unsigned int v18; // [esp+2Ch] [ebp-8h] BYREF
  int v19; // [esp+30h] [ebp-4h] BYREF

  Limit = this->Limit;
  if ( Limit )
  {
    Footprint = this->Footprint;
    if ( Footprint + dataSize > Limit )
    {
      pLimHandler = this->pLimHandler;
      if ( pLimHandler )
      {
        *limHandlerOK = (*(int (__thiscall **)(void *, Scaleform::MemoryHeapPT *, unsigned int))(*(_DWORD *)pLimHandler
                                                                                               + 4))(
                          pLimHandler,
                          this->pHeap,
                          dataSize + Footprint - Limit);
        return 0;
      }
    }
  }
  *limHandlerOK = 0;
  p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
  lpCriticalSection = &Scaleform::HeapPT::GlobalRoot->RootLock;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  v10 = Scaleform::HeapPT::Bookkeeper::Alloc(this->pBookkeeper, (Scaleform::Heap::HeapSegment *)0x20);
  if ( !v10 )
    goto LABEL_9;
  v10->SelfSize = 32;
  v10->SegType = 9;
  v10->Alignment = 0;
  v10->UseCount = 0;
  v10->pHeap = this->pHeap;
  v10->DataSize = 0;
  v10->pData = 0;
  if ( dataSize )
  {
    v11 = (unsigned __int8 *)this->pSysAlloc->AllocSysDirect(this->pSysAlloc, dataSize, alignSize, &v19, &v18);
    v10->pData = v11;
    if ( !v11 )
    {
      Scaleform::HeapPT::Bookkeeper::Free(this->pBookkeeper, (unsigned int)v10, v10->SelfSize);
LABEL_9:
      LeaveCriticalSection(&p_RootLock->mLock.cs);
      return 0;
    }
    v12 = alignSize;
    if ( alignSize <= 0x1000 )
      v12 = 4096;
    v13 = (~(v12 - 1) & (unsigned int)&v11[v12 - 1]) - (_DWORD)v11;
    v14 = (unsigned __int8)Scaleform::Alg::UpperBit(v18);
    v10->UseCount = v13 | 0x80000000;
    v15 = v19 - v13;
    v16 = v19 - v13;
    v10->Alignment = v14;
    v10->DataSize = v15;
    v10->pData = &v11[v13];
    if ( !Scaleform::HeapPT::PageTable::MapRange(Scaleform::HeapPT::GlobalPageTable, (unsigned int)&v11[v13], v16) )
    {
      this->pSysAlloc->FreeSysDirect(
        this->pSysAlloc,
        &v10->pData[-v13],
        v13 + v10->DataSize,
        1 << LOBYTE(v10->Alignment));
      this->pSysAlloc->FreeSysDirect(this->pSysAlloc, v10->pData, dataSize, alignSize);
      Scaleform::HeapPT::Bookkeeper::Free(this->pBookkeeper, (unsigned int)v10, v10->SelfSize);
      LeaveCriticalSection(&lpCriticalSection->mLock.cs);
      return 0;
    }
    Scaleform::HeapPT::PageTable::SetSegmentInRange(
      Scaleform::HeapPT::GlobalPageTable,
      (unsigned int)v10->pData,
      v10->DataSize,
      v10);
    p_RootLock = lpCriticalSection;
  }
  v10->pNext = this->SegmentList.Root.pNext;
  v10->pPrev = (Scaleform::Heap::HeapSegment *)&this->SegmentList;
  this->SegmentList.Root.pNext->pPrev = v10;
  this->SegmentList.Root.pNext = v10;
  this->Footprint += v10->DataSize + (v10->UseCount & 0x7FFFFFFF);
  *limHandlerOK = 1;
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  return v10;
}
