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
  unsigned __int8 *v15; // [esp+Ch] [ebp-14h]
  Scaleform::HeapPT::AllocLite *p_Allocator; // [esp+10h] [ebp-10h]
  unsigned int v17; // [esp+14h] [ebp-Ch]
  unsigned int v18; // [esp+18h] [ebp-8h]
  int v19; // [esp+1Ch] [ebp-4h]

  if ( alignSize < this->Allocator.MinSize )
    alignSize = this->Allocator.MinSize;
  LeEq = (Scaleform::HeapPT::TreeSeg *)Scaleform::RadixTree<Scaleform::HeapPT::TreeSeg,Scaleform::HeapPT::Granulator::SegTreeAccessor>::FindLeEq(
                                         &this->UsedSeg,
                                         (unsigned int)oldPtr);
  p_Allocator = &this->Allocator;
  v7 = Scaleform::HeapPT::AllocLite::ReallocInPlace(&this->Allocator, LeEq, oldPtr, oldSize, newSize, alignSize);
  v19 = v7;
  if ( !this->HasRealloc )
    return v7 < 2;
  if ( !v7 )
    return 1;
  v9 = (unsigned int)&LeEq->Buffer[-LeEq->HeadBytes
                                 - (LeEq->Buffer == (unsigned __int8 *)LeEq->Headers + this->HdrPageSize
                                  ? this->HdrPageSize
                                  : 0)];
  v15 = (unsigned __int8 *)v9;
  SegSize = Scaleform::HeapPT::Granulator::getSegSize(this, LeEq);
  Granularity = this->Granularity;
  v18 = SegSize;
  v12 = &oldPtr[-v9];
  v13 = ~(alignSize - 1);
  v17 = Granularity * (((v13 & (unsigned int)&v12[oldSize - 1 + alignSize]) + Granularity - 1) / Granularity);
  v14 = Granularity * (((v13 & (unsigned int)&v12[newSize - 1 + alignSize]) + Granularity - 1) / Granularity);
  if ( v19 == 1 )
  {
    if ( v14 < v17 )
    {
      Scaleform::HeapPT::AllocLite::TrimAt(p_Allocator, LeEq, &v15[v14]);
      if ( this->pSysAlloc->ReallocInPlace(this->pSysAlloc, v15, v18, v14, 1 << LOBYTE(LeEq->AlignShift)) )
      {
        this->Footprint += v14 - v18;
        return 1;
      }
      Scaleform::HeapPT::AllocLite::Extend(p_Allocator, LeEq, v18 - v14);
    }
    return 1;
  }
  else
  {
    if ( v19 != 3 )
      return 0;
    for ( ; v14 <= v17; v14 += Granularity )
      ;
    if ( this->pSysAlloc->ReallocInPlace(this->pSysAlloc, v15, SegSize, v14, 1 << LOBYTE(LeEq->AlignShift)) )
    {
      this->Footprint += v14 - v18;
      Scaleform::HeapPT::AllocLite::Extend(p_Allocator, LeEq, v14 - v18);
      Scaleform::HeapPT::AllocLite::ReallocInPlace(p_Allocator, LeEq, oldPtr, oldSize, newSize, alignSize);
      return 1;
    }
    else
    {
      return 0;
    }
  }
}
