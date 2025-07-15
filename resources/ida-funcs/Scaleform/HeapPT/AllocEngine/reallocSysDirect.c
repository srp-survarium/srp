unsigned __int8 *__thiscall Scaleform::HeapPT::AllocEngine::reallocSysDirect(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::Heap::HeapSegment *seg,
        __m128i *oldPtr,
        LPCRITICAL_SECTION newSize)
{
  unsigned __int16 Alignment; // cx
  unsigned int v8; // esi
  unsigned int DataSize; // ebx
  unsigned int Limit; // ecx
  void *pLimHandler; // edx
  unsigned __int8 *v12; // ebp
  unsigned __int8 *pData; // [esp-8h] [ebp-1Ch]
  unsigned int v14; // [esp+18h] [ebp+4h]
  Scaleform::LockSafe *lpCriticalSection; // [esp+20h] [ebp+Ch]

  if ( (seg->UseCount & 0x80000000) != 0 )
    return Scaleform::HeapPT::AllocEngine::reallocGeneral(
             this,
             seg,
             oldPtr,
             seg->DataSize,
             (unsigned int)newSize,
             seg->Alignment);
  Alignment = seg->Alignment;
  v14 = 1 << Alignment;
  v8 = this->SysGranularity
     * (((~((1 << Alignment) - 1) & ((unsigned int)newSize + (1 << Alignment) - 1)) + this->SysGranularity - 1)
      / this->SysGranularity);
  DataSize = seg->DataSize;
  if ( v8 == DataSize )
    return seg->pData;
  if ( v8 < DataSize && 2 * v8 < this->Threshold )
    return Scaleform::HeapPT::AllocEngine::reallocGeneral(this, seg, oldPtr, DataSize, v8, Alignment);
  if ( v8 > DataSize )
  {
    Limit = this->Limit;
    if ( Limit )
    {
      if ( v8 + this->Footprint - DataSize > Limit )
      {
        pLimHandler = this->pLimHandler;
        if ( pLimHandler )
        {
          if ( !(*(unsigned __int8 (__thiscall **)(void *, Scaleform::MemoryHeapPT *, unsigned int))(*(_DWORD *)pLimHandler + 4))(
                  this->pLimHandler,
                  this->pHeap,
                  v8 + this->Footprint - Limit - DataSize)
            || this->Footprint + v8 - DataSize > this->Limit )
          {
            return Scaleform::HeapPT::AllocEngine::reallocGeneral(this, seg, oldPtr, DataSize, v8, seg->Alignment);
          }
        }
      }
    }
  }
  lpCriticalSection = &Scaleform::HeapPT::GlobalRoot->RootLock;
  EnterCriticalSection(&Scaleform::HeapPT::GlobalRoot->RootLock.mLock.cs);
  if ( this->HasRealloc && this->pSysAlloc->ReallocInPlace(this->pSysAlloc, seg->pData, DataSize, v8, v14) )
  {
    pData = seg->pData;
    if ( v8 <= DataSize )
    {
      Scaleform::HeapPT::PageTable::RemapRange(Scaleform::HeapPT::GlobalPageTable, (unsigned int)pData, v8, DataSize);
    }
    else if ( !Scaleform::HeapPT::PageTable::RemapRange(
                 Scaleform::HeapPT::GlobalPageTable,
                 (unsigned int)pData,
                 v8,
                 DataSize) )
    {
      this->pSysAlloc->ReallocInPlace(this->pSysAlloc, seg->pData, v8, DataSize, v14);
      LeaveCriticalSection(&lpCriticalSection->mLock.cs);
      return 0;
    }
    this->Footprint += v8 - DataSize;
    this->SysDirectSpace += v8 - DataSize;
    seg->DataSize = v8;
    v12 = seg->pData;
    LeaveCriticalSection(&lpCriticalSection->mLock.cs);
    return v12;
  }
  else
  {
    LeaveCriticalSection(&lpCriticalSection->mLock.cs);
    return Scaleform::HeapPT::AllocEngine::reallocGeneral(this, seg, oldPtr, DataSize, v8, seg->Alignment);
  }
}
