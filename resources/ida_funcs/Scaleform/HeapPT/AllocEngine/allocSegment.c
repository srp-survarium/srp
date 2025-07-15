Scaleform::Heap::HeapSegment *__thiscall Scaleform::HeapPT::AllocEngine::allocSegment(
        Scaleform::HeapPT::AllocEngine *this,
        unsigned __int16 segType,
        unsigned int dataSize,
        unsigned int alignSize,
        unsigned int bookkeepingSize,
        bool *limHandlerOK)
{
  unsigned int Limit; // eax
  Scaleform::LockSafe *p_RootLock; // esi
  unsigned int v10; // ebx
  Scaleform::Heap::HeapSegment *v11; // esi
  unsigned __int8 *v12; // eax
  Scaleform::Heap::HeapSegment *pNext; // edx

  Limit = this->Limit;
  if ( Limit && dataSize + this->Footprint > Limit && this->pLimHandler )
  {
    p_RootLock = &Scaleform::HeapPT::GlobalRoot->RootLock;
    LeaveCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
    *limHandlerOK = (*(int (__thiscall **)(void *, Scaleform::MemoryHeapPT *, unsigned int))(*(_DWORD *)this->pLimHandler
                                                                                           + 4))(
                      this->pLimHandler,
                      this->pHeap,
                      this->Footprint + dataSize - this->Limit);
    EnterCriticalSection(&p_RootLock->mLock.cs);
    return 0;
  }
  *limHandlerOK = 0;
  v10 = (bookkeepingSize + 47) & 0xFFFFFFF0;
  v11 = (Scaleform::Heap::HeapSegment *)Scaleform::HeapPT::Bookkeeper::Alloc(this->pBookkeeper, v10);
  if ( !v11 )
    return 0;
  v11->SelfSize = v10;
  v11->SegType = segType;
  v11->Alignment = (unsigned __int8)Scaleform::Alg::UpperBit(alignSize);
  v11->UseCount = 0;
  v11->pHeap = this->pHeap;
  v11->DataSize = dataSize;
  v11->pData = 0;
  if ( dataSize )
  {
    if ( alignSize < 0x1000 )
      alignSize = 4096;
    v12 = (unsigned __int8 *)this->pSysAlloc->Alloc(this->pSysAlloc, dataSize, alignSize);
    v11->pData = v12;
    if ( !v12 )
      goto LABEL_12;
    if ( !Scaleform::HeapPT::PageTable::MapRange(Scaleform::HeapPT::GlobalPageTable, (unsigned int)v12, v11->DataSize) )
    {
      this->pSysAlloc->Free(this->pSysAlloc, v11->pData, dataSize, alignSize);
LABEL_12:
      Scaleform::HeapPT::Bookkeeper::Free(this->pBookkeeper, (void *)v11, v10);
      return 0;
    }
    Scaleform::HeapPT::PageTable::SetSegmentInRange(
      Scaleform::HeapPT::GlobalPageTable,
      (unsigned int)v11->pData,
      v11->DataSize,
      v11);
  }
  pNext = this->SegmentList.Root.pNext;
  v11->pPrev = (Scaleform::Heap::HeapSegment *)&this->SegmentList;
  v11->pNext = pNext;
  this->SegmentList.Root.pNext->pPrev = v11;
  this->SegmentList.Root.pNext = v11;
  this->Footprint += v11->DataSize;
  *limHandlerOK = 1;
  return v11;
}
