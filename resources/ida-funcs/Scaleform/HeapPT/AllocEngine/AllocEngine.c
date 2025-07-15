void __thiscall Scaleform::HeapPT::AllocEngine::AllocEngine(
        Scaleform::HeapPT::AllocEngine *this,
        Scaleform::SysAllocPaged *sysAlloc,
        Scaleform::MemoryHeapPT *heap,
        char allocFlags,
        unsigned int minAlignSize,
        unsigned int granularity,
        unsigned int reserve,
        unsigned int threshold,
        unsigned int limit)
{
  unsigned int v9; // ebp
  unsigned __int8 v11; // al
  char v12; // al
  unsigned int v13; // ecx
  char v14; // dl
  unsigned int v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // eax
  unsigned int v18; // ecx
  Scaleform::SysAllocPaged *pSysAlloc; // ecx
  unsigned int v20; // ecx
  unsigned int v21; // eax
  unsigned int v22; // edx
  unsigned int v23; // edi
  unsigned int v24; // eax
  unsigned int v25; // edx
  unsigned int v26; // edx
  unsigned int v27; // eax
  unsigned int v28; // eax
  _DWORD v29[2]; // [esp+10h] [ebp-18h] BYREF
  unsigned int v30; // [esp+18h] [ebp-10h]
  unsigned int v31; // [esp+1Ch] [ebp-Ch]
  unsigned int v32; // [esp+20h] [ebp-8h]
  BOOL v33; // [esp+24h] [ebp-4h]

  v9 = minAlignSize;
  this->pHeap = heap;
  this->pSysAlloc = sysAlloc;
  this->pBookkeeper = &Scaleform::HeapPT::GlobalRoot->AllocBookkeeper;
  v11 = Scaleform::Alg::UpperBit(v9);
  this->MinAlignShift = v11;
  this->MinAlignMask = (1 << v11) - 1;
  Scaleform::HeapPT::AllocBitSet2::AllocBitSet2(&this->Allocator, v11);
  this->SegmentList.Root.pPrev = (Scaleform::Heap::HeapSegment *)&this->SegmentList;
  this->SegmentList.Root.pNext = (Scaleform::Heap::HeapSegment *)&this->SegmentList;
  this->TinyBlocks[1].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[1];
  this->TinyBlocks[1].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[1];
  this->TinyBlocks[2].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[2];
  this->TinyBlocks[2].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[2];
  this->TinyBlocks[3].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[3];
  this->TinyBlocks[3].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[3];
  this->TinyBlocks[4].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[4];
  this->TinyBlocks[4].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[4];
  this->TinyBlocks[0].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)this->TinyBlocks;
  this->TinyBlocks[0].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)this->TinyBlocks;
  this->TinyBlocks[5].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[5];
  this->TinyBlocks[5].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[5];
  this->TinyBlocks[6].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[6];
  this->TinyBlocks[6].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[6];
  this->TinyBlocks[7].Root.pNext = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[7];
  v12 = allocFlags;
  this->TinyBlocks[7].Root.pPrev = (Scaleform::HeapPT::AllocEngine::TinyBlock *)&this->TinyBlocks[7];
  v13 = granularity;
  v14 = v12;
  this->AllowDynaSize = (v12 & 0x20) != 0;
  v15 = reserve;
  v16 = (v13 + 4095) & 0xFFFFF000;
  this->AllowTinyBlocks = (v14 & 0x10) != 0;
  this->Granularity = v16;
  this->Valid = 0;
  this->HasRealloc = 0;
  this->SysGranularity = 4096;
  this->SysDirectThreshold = 0;
  this->Footprint = 0;
  this->TinyFreeSpace = 0;
  this->SysDirectSpace = 0;
  this->pCachedBSeg = 0;
  v17 = v16 * ((v16 + v15 - 1) / v16);
  v18 = threshold;
  this->Reserve = v17;
  this->Threshold = v18;
  pSysAlloc = this->pSysAlloc;
  this->Limit = limit;
  v29[0] = 0;
  v29[1] = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  this->pCachedTSeg = 0;
  this->pLimHandler = 0;
  pSysAlloc->GetInfo(pSysAlloc, (Scaleform::SysAllocPaged::Info *)v29);
  this->HasRealloc = v33;
  v20 = v30;
  if ( v30 < 0x1000 )
  {
    v20 = 4096;
    v30 = 4096;
  }
  v21 = (this->Granularity + v20 - 1) / v20;
  v22 = v32;
  v23 = v31;
  this->SysGranularity = v20;
  this->SysDirectThreshold = v23;
  v24 = v20 * v21;
  this->Granularity = v24;
  if ( v22 )
  {
    v25 = (v22 + 4095) & 0xFFFFF000;
    v32 = v25;
    if ( v24 > v25 )
    {
      this->Granularity = v25;
      this->AllowTinyBlocks = 0;
      this->AllowDynaSize = 0;
    }
  }
  v26 = this->Threshold;
  if ( v26 < 32 * v20 && v26 )
    this->Threshold = 32 * v20;
  if ( v23 )
  {
    if ( this->Threshold > v23 )
      this->Threshold = v23;
    v27 = this->Threshold;
    if ( v27 < 0x1000 && v27 )
      this->Threshold = 4096;
    if ( this->Granularity > v23 )
      this->Granularity = (v23 + 4095) & 0xFFFFF000;
    if ( v20 > v23 )
      this->SysGranularity = (v23 + 4095) & 0xFFFFF000;
    if ( this->Reserve > v23 )
      this->Reserve = v23;
    this->AllowDynaSize = 0;
  }
  v28 = this->Reserve;
  if ( v28 )
    this->Valid = Scaleform::HeapPT::AllocEngine::allocSegmentBitSet(this, v28, v9, this->Granularity, (bool *)&heap) != 0;
  else
    this->Valid = 1;
}
