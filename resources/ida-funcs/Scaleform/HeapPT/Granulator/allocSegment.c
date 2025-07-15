char __thiscall Scaleform::HeapPT::Granulator::allocSegment(
        Scaleform::HeapPT::Granulator *this,
        unsigned int size,
        unsigned int alignSize)
{
  unsigned int v3; // eax
  unsigned int MinAlign; // ecx
  unsigned int MinSize; // esi
  unsigned int MaxAlign; // ecx
  unsigned int v8; // edx
  unsigned int v9; // ebp
  unsigned int v10; // ebp
  void *v11; // eax
  int v12; // ecx
  Scaleform::HeapPT::HdrPage *v13; // edi
  _DWORD *p_pNext; // eax
  Scaleform::HeapPT::TreeSeg *v15; // edx
  Scaleform::HeapPT::TreeSeg *v16; // esi
  unsigned int hdrPageSize; // [esp+10h] [ebp-Ch]
  unsigned __int8 *alignedEnd; // [esp+14h] [ebp-8h]
  __int16 newSpacePtr; // [esp+18h] [ebp-4h]
  unsigned int i; // [esp+20h] [ebp+4h]
  unsigned int segAlign; // [esp+24h] [ebp+8h]

  v3 = alignSize;
  MinAlign = this->MinAlign;
  if ( alignSize < MinAlign )
    v3 = MinAlign;
  if ( (Scaleform::List2<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegListAccessor> *)this->FreeSeg.Root.AddrChild[1] == &this->FreeSeg )
    hdrPageSize = this->HdrPageSize;
  else
    hdrPageSize = 0;
  MinSize = this->Allocator.MinSize;
  segAlign = v3;
  if ( v3 < MinSize )
    segAlign = this->Allocator.MinSize;
  MaxAlign = this->MaxAlign;
  if ( segAlign > MaxAlign )
    segAlign = this->MaxAlign;
  v8 = MaxAlign < v3 ? v3 : 0;
  v9 = segAlign < MinSize ? MinSize : 0;
  if ( v8 <= v9 )
    v8 = 0;
  v10 = ~(MinSize - 1)
      & (v9
       + this->Granularity
       * (((~(v3 - 1) & (size + hdrPageSize + v8 + v3 - 1)) + this->Granularity - 1)
        / this->Granularity)
       + MinSize
       - 1);
  v11 = this->pSysAlloc->Alloc(this->pSysAlloc, v10, segAlign);
  newSpacePtr = (__int16)v11;
  if ( !v11 )
    return 0;
  v12 = ~(MinSize - 1);
  alignedEnd = (unsigned __int8 *)(v12 & ((unsigned int)v11 + v10));
  v13 = (Scaleform::HeapPT::HdrPage *)(v12 & ((unsigned int)v11 + MinSize - 1));
  if ( hdrPageSize )
  {
    memset((int)v13, 0, hdrPageSize);
    v13->UseCount = 0;
    i = 0;
    if ( this->HdrCapacity )
    {
      p_pNext = &v13[1].pNext;
      do
      {
        p_pNext[2] = v13;
        v15 = this->FreeSeg.Root.AddrChild[0];
        p_pNext[1] = &this->FreeSeg;
        *p_pNext = v15;
        this->FreeSeg.Root.AddrChild[0]->AddrChild[1] = (Scaleform::HeapPT::TreeSeg *)(p_pNext - 1);
        this->FreeSeg.Root.AddrChild[0] = (Scaleform::HeapPT::TreeSeg *)(p_pNext - 1);
        p_pNext += 8;
        ++i;
      }
      while ( i < this->HdrCapacity );
    }
    v13->pPrev = this->HdrList.Root.pPrev;
    v13->pNext = (Scaleform::HeapPT::HdrPage *)&this->HdrList;
    this->HdrList.Root.pPrev->pNext = v13;
    this->HdrList.Root.pPrev = v13;
  }
  v16 = this->FreeSeg.Root.AddrChild[1];
  v16->AddrChild[0]->AddrChild[1] = v16->AddrChild[1];
  v16->AddrChild[1]->AddrChild[0] = v16->AddrChild[0];
  ++v16->Headers->UseCount;
  v16->Buffer = (unsigned __int8 *)v13 + hdrPageSize;
  v16->Size = alignedEnd - ((unsigned __int8 *)v13 + hdrPageSize);
  v16->UseCount = 0;
  v16->AlignShift = (unsigned __int8)Scaleform::Alg::UpperBit(segAlign);
  v16->HeadBytes = (_WORD)v13 - newSpacePtr;
  Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor>::Insert(
    &this->UsedSeg,
    v16);
  Scaleform::HeapPT::AllocLite::InitSegment(&this->Allocator, v16);
  this->Footprint += v10;
  return 1;
}
