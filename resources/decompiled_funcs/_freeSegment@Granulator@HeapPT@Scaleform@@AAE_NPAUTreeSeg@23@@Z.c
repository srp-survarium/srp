bool __thiscall Scaleform::HeapPT::Granulator::freeSegment(
        Scaleform::HeapPT::Granulator *this,
        Scaleform::HeapMH::NodeMH *seg)
{
  Scaleform::HeapPT::HdrPage *pHeap; // ebx
  bool result; // al
  unsigned int SegSize; // ebp
  Scaleform::HeapPT::TreeSeg *Root; // edi
  unsigned int i; // ebp
  unsigned int v9; // ecx
  unsigned int *p_UseCount; // eax
  unsigned __int16 HeadBytes; // cx
  unsigned int v12; // edx
  unsigned int v13; // ebx
  bool ret; // [esp+18h] [ebp+4h]

  pHeap = (Scaleform::HeapPT::HdrPage *)seg->pHeap;
  result = 1;
  ret = 1;
  if ( (Scaleform::HeapPT::HdrPage *)((char *)pHeap + this->HdrPageSize) != (Scaleform::HeapPT::HdrPage *)seg->Align )
  {
    Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::Remove(
      (Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor> *)&this->UsedSeg,
      seg);
    seg->Child[1] = (Scaleform::HeapMH::NodeMH *)this->FreeSeg.Root.AddrChild[1];
    seg->Child[0] = (Scaleform::HeapMH::NodeMH *)&this->FreeSeg;
    this->FreeSeg.Root.AddrChild[1]->AddrChild[0] = (Scaleform::HeapPT::TreeSeg *)seg;
    this->FreeSeg.Root.AddrChild[1] = (Scaleform::HeapPT::TreeSeg *)seg;
    --pHeap->UseCount;
    SegSize = Scaleform::HeapPT::Granulator::getSegSize(this, (const Scaleform::HeapPT::TreeSeg *)seg);
    Scaleform::HeapPT::AllocLite::ReleaseSegment(&this->Allocator, (Scaleform::HeapPT::TreeSeg *)seg);
    this->Footprint -= SegSize;
    result = this->pSysAlloc->Free(
               this->pSysAlloc,
               (void *)(seg->Align
                      - HIWORD(seg[1].Child[1])
                      - (seg->Align == this->HdrPageSize + seg->pHeap ? this->HdrPageSize : 0)),
               SegSize,
               1 << LOBYTE(seg[1].Child[1]));
    ret = result;
  }
  if ( pHeap->UseCount == 1 )
  {
    Root = this->UsedSeg.Root;
    for ( i = (unsigned int)pHeap + this->HdrPageSize; Root; i *= 2 )
    {
      if ( Root->Buffer == (unsigned __int8 *)pHeap + this->HdrPageSize )
        break;
      Root = Root->AddrChild[i >> 31];
    }
    if ( Root->UseCount )
    {
      return ret;
    }
    else
    {
      Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::Remove(
        (Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor> *)&this->UsedSeg,
        (Scaleform::HeapMH::NodeMH *)Root);
      Root->AddrChild[1] = this->FreeSeg.Root.AddrChild[1];
      Root->AddrChild[0] = &this->FreeSeg.Root;
      this->FreeSeg.Root.AddrChild[1]->AddrChild[0] = Root;
      v9 = 0;
      this->FreeSeg.Root.AddrChild[1] = Root;
      if ( this->HdrCapacity )
      {
        p_UseCount = &pHeap[1].UseCount;
        do
        {
          *(_DWORD *)(*(p_UseCount - 1) + 8) = *p_UseCount;
          ++v9;
          *(_DWORD *)(*p_UseCount + 4) = *(p_UseCount - 1);
          p_UseCount += 8;
        }
        while ( v9 < this->HdrCapacity );
      }
      pHeap->pPrev->pNext = pHeap->pNext;
      pHeap->pNext->Scaleform::ListNode<Scaleform::HeapPT::HdrPage>::$E40FB752466EC49710C58491A779D7E5::pPrev = pHeap->pPrev;
      HeadBytes = Root->HeadBytes;
      if ( HeadBytes )
        v12 = this->Allocator.MinSize - HeadBytes;
      else
        v12 = 0;
      v13 = (Root->Buffer == (unsigned __int8 *)Root->Headers + this->HdrPageSize ? this->HdrPageSize : 0)
          + v12
          + HeadBytes
          + Root->Size;
      Scaleform::HeapPT::AllocLite::ReleaseSegment(&this->Allocator, Root);
      this->Footprint -= v13;
      return this->pSysAlloc->Free(
               this->pSysAlloc,
               &Root->Buffer[-Root->HeadBytes
                           - (Root->Buffer == (unsigned __int8 *)Root->Headers + this->HdrPageSize
                            ? this->HdrPageSize
                            : 0)],
               v13,
               1 << LOBYTE(Root->AlignShift));
    }
  }
  return result;
}
