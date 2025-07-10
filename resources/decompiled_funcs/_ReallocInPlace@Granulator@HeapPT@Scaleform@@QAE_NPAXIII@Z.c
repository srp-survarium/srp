bool __thiscall Scaleform::HeapPT::Granulator::ReallocInPlace(
        Scaleform::HeapPT::Granulator *this,
        char *oldPtr,
        unsigned int oldSize,
        unsigned int newSize,
        unsigned int alignSize)
{
  Scaleform::HeapPT::TreeSeg *LeEq; // edi
  int v7; // eax
  unsigned int v9; // ebp
  unsigned int SegSize; // eax
  unsigned int Granularity; // ecx
  char *v12; // esi
  unsigned int v13; // ebp
  unsigned int v14; // esi
  unsigned __int8 *segBase; // [esp+Ch] [ebp-14h]
  Scaleform::HeapPT::AllocLite *p_Allocator; // [esp+10h] [ebp-10h]
  unsigned int oldEnd; // [esp+14h] [ebp-Ch]
  unsigned int oldSegSize; // [esp+18h] [ebp-8h]
  Scaleform::HeapPT::AllocLite::ReallocResult res; // [esp+1Ch] [ebp-4h]

  if ( alignSize < this->Allocator.MinSize )
    alignSize = this->Allocator.MinSize;
  LeEq = (Scaleform::HeapPT::TreeSeg *)Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor>::FindLeEq(
                                         &this->UsedSeg,
                                         (unsigned int)oldPtr);
  p_Allocator = &this->Allocator;
  v7 = Scaleform::HeapPT::AllocLite::ReallocInPlace(&this->Allocator, LeEq, oldPtr, oldSize, newSize, alignSize);
  res = v7;
  if ( !this->HasRealloc )
    return v7 < 2;
  if ( !v7 )
    return 1;
  v9 = (unsigned int)&LeEq->Buffer[-LeEq->HeadBytes
                                 - (LeEq->Buffer == (unsigned __int8 *)LeEq->Headers + this->HdrPageSize
                                  ? this->HdrPageSize
                                  : 0)];
  segBase = (unsigned __int8 *)v9;
  SegSize = Scaleform::HeapPT::Granulator::getSegSize(this, LeEq);
  Granularity = this->Granularity;
  oldSegSize = SegSize;
  v12 = &oldPtr[-v9];
  v13 = ~(alignSize - 1);
  oldEnd = Granularity * (((v13 & (unsigned int)&v12[oldSize - 1 + alignSize]) + Granularity - 1) / Granularity);
  v14 = Granularity * (((v13 & (unsigned int)&v12[newSize - 1 + alignSize]) + Granularity - 1) / Granularity);
  if ( res == ReallocShrinkedAtTail )
  {
    if ( v14 < oldEnd )
    {
      Scaleform::HeapPT::AllocLite::TrimAt(p_Allocator, LeEq, &segBase[v14]);
      if ( this->pSysAlloc->ReallocInPlace(this->pSysAlloc, segBase, oldSegSize, v14, 1 << LOBYTE(LeEq->AlignShift)) )
      {
        this->Footprint += v14 - oldSegSize;
        return 1;
      }
      Scaleform::HeapPT::AllocLite::Extend(p_Allocator, LeEq, oldSegSize - v14);
    }
    return 1;
  }
  else
  {
    if ( res != ReallocFailedAtTail )
      return 0;
    for ( ; v14 <= oldEnd; v14 += Granularity )
      ;
    if ( this->pSysAlloc->ReallocInPlace(this->pSysAlloc, segBase, SegSize, v14, 1 << LOBYTE(LeEq->AlignShift)) )
    {
      this->Footprint += v14 - oldSegSize;
      Scaleform::HeapPT::AllocLite::Extend(p_Allocator, LeEq, v14 - oldSegSize);
      Scaleform::HeapPT::AllocLite::ReallocInPlace(p_Allocator, LeEq, oldPtr, oldSize, newSize, alignSize);
      return 1;
    }
    else
    {
      return 0;
    }
  }
}
