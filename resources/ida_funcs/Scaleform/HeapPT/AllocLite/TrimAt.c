char __thiscall Scaleform::HeapPT::AllocLite::TrimAt(
        Scaleform::HeapPT::AllocLite *this,
        Scaleform::HeapPT::TreeSeg *seg,
        unsigned __int8 *ptrAt)
{
  Scaleform::HeapPT::DualTNode *LeEq; // esi
  unsigned int v5; // ebx

  LeEq = (Scaleform::HeapPT::DualTNode *)Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindLeEq(
                                           &this->AddrTree,
                                           (unsigned int)ptrAt);
  if ( !LeEq
    || LeEq->ParentSeg != seg
    || ptrAt < (unsigned __int8 *)LeEq
    || ptrAt >= (unsigned __int8 *)LeEq + (LeEq->Size << this->MinShift) )
  {
    return 0;
  }
  Scaleform::HeapPT::AllocLite::pullNode(this, LeEq);
  v5 = (unsigned int)LeEq + (LeEq->Size << this->MinShift) - (_DWORD)ptrAt;
  if ( LeEq < (Scaleform::HeapPT::DualTNode *)ptrAt )
  {
    Scaleform::HeapPT::AllocLite::pushNode(this, LeEq, seg, (ptrAt - (unsigned __int8 *)LeEq) >> this->MinShift);
    *((_DWORD *)ptrAt + 8) = seg;
    *((_DWORD *)ptrAt + 9) = v5 >> this->MinShift;
  }
  seg->Size -= v5;
  return 1;
}
