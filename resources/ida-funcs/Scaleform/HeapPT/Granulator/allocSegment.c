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
  unsigned int HdrPageSize; // [esp+10h] [ebp-Ch]
  int v19; // [esp+14h] [ebp-8h]
  __int16 v20; // [esp+18h] [ebp-4h]
  unsigned int v21; // [esp+20h] [ebp+4h]
  unsigned int v22; // [esp+24h] [ebp+8h]

  v3 = alignSize;
  MinAlign = this->MinAlign;
  if ( alignSize < MinAlign )
    v3 = MinAlign;
  if ( (Scaleform::List2<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegListAccessor> *)this->FreeSeg.Root.AddrChild[1] == &this->FreeSeg )
    HdrPageSize = this->HdrPageSize;
  else
    HdrPageSize = 0;
  MinSize = this->Allocator.MinSize;
  v22 = v3;
  if ( v3 < MinSize )
    v22 = this->Allocator.MinSize;
  MaxAlign = this->MaxAlign;
  if ( v22 > MaxAlign )
    v22 = this->MaxAlign;
  v8 = MaxAlign < v3 ? v3 : 0;
  v9 = v22 < MinSize ? MinSize : 0;
  if ( v8 <= v9 )
    v8 = 0;
  v10 = ~(MinSize - 1)
      & (v9
       + this->Granularity
       * (((~(v3 - 1) & (size + HdrPageSize + v8 + v3 - 1)) + this->Granularity - 1)
        / this->Granularity)
       + MinSize
       - 1);
  v11 = this->pSysAlloc->Alloc(this->pSysAlloc, v10, v22);
  v20 = (__int16)v11;
  if ( !v11 )
    return 0;
  v12 = ~(MinSize - 1);
  v19 = v12 & ((unsigned int)v11 + v10);
  v13 = (Scaleform::HeapPT::HdrPage *)(v12 & ((unsigned int)v11 + MinSize - 1));
  if ( HdrPageSize )
  {
    memset((int)v13, 0, HdrPageSize);
    v13->UseCount = 0;
    v21 = 0;
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
        ++v21;
      }
      while ( v21 < this->HdrCapacity );
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
  v16->Buffer = (unsigned __int8 *)v13 + HdrPageSize;
  v16->Size = v19 - ((_DWORD)v13 + HdrPageSize);
  v16->UseCount = 0;
  v16->AlignShift = (unsigned __int8)Scaleform::Alg::UpperBit(v22);
  v16->HeadBytes = (_WORD)v13 - v20;
  Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor>::Insert(
    &this->UsedSeg,
    v16);
  Scaleform::HeapPT::AllocLite::InitSegment(&this->Allocator, v16);
  this->Footprint += v10;
  return 1;
}
