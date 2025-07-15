int __thiscall Scaleform::HeapPT::AllocLite::ReallocInPlace(
        Scaleform::HeapPT::AllocLite *this,
        Scaleform::HeapPT::TreeSeg *seg,
        char *ptr,
        unsigned int oldSize,
        unsigned int newSize,
        unsigned int alignSize)
{
  unsigned int v6; // eax
  unsigned int MinSize; // ecx
  int v9; // ecx
  unsigned int v10; // edi
  unsigned int v11; // esi
  const Scaleform::HeapPT::DualTNode *GrEq; // eax
  Scaleform::HeapPT::DualTNode *v14; // ebx
  unsigned __int8 *v15; // eax
  unsigned __int8 *alignSizea; // [esp+20h] [ebp+14h]

  v6 = alignSize;
  MinSize = this->MinSize;
  if ( alignSize < MinSize )
    v6 = MinSize;
  v9 = ~(v6 - 1);
  v10 = v9 & (oldSize + v6 - 1);
  v11 = v9 & (newSize + v6 - 1);
  if ( v11 == v10 )
    return 0;
  if ( v11 <= v10 )
  {
    Scaleform::HeapPT::AllocLite::Free(
      this,
      seg,
      (Scaleform::HeapPT::DualTNode *)&ptr[v11],
      (Scaleform::HeapPT::DualTNode *)(v10 - v11),
      v6);
    return &ptr[(*(_DWORD *)&ptr[v11 + 36] << this->MinShift) + v11] == (char *)&seg->Buffer[seg->Size];
  }
  else
  {
    alignSizea = (unsigned __int8 *)&ptr[v10];
    GrEq = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindGrEq(
             &this->AddrTree,
             (unsigned int)&ptr[v10]);
    v14 = (Scaleform::HeapPT::DualTNode *)GrEq;
    if ( !GrEq || GrEq->ParentSeg != seg || GrEq != (const Scaleform::HeapPT::DualTNode *)alignSizea )
      return (alignSizea == &seg->Buffer[seg->Size]) + 2;
    v15 = (unsigned __int8 *)GrEq + (GrEq->Size << this->MinShift);
    if ( &ptr[v11] <= (char *)v15 )
    {
      Scaleform::HeapPT::AllocLite::pullNode(this, v14);
      Scaleform::HeapPT::AllocLite::splitNode(this, v14, (unsigned __int8 *)v14, v11 - v10);
      return 0;
    }
    if ( v15 == &seg->Buffer[seg->Size] )
      return 3;
    else
      return (alignSizea == &seg->Buffer[seg->Size]) + 2;
  }
}
