unsigned int __thiscall Scaleform::AllocAddr::Free(Scaleform::AllocAddr *this, unsigned int addr, unsigned int size)
{
  Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor> *p_AddrTree; // edi
  Scaleform::AllocAddrNode *LeEq; // esi
  Scaleform::AllocAddrNode *GrEq; // eax

  if ( !size )
    return 0;
  p_AddrTree = &this->AddrTree;
  LeEq = (Scaleform::AllocAddrNode *)Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::FindLeEq(
                                       &this->AddrTree,
                                       addr);
  GrEq = (Scaleform::AllocAddrNode *)Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::FindGrEq(
                                       p_AddrTree,
                                       addr + size);
  if ( !LeEq || LeEq->Addr + LeEq->Size != addr )
    LeEq = 0;
  if ( !GrEq || GrEq->Addr != addr + size )
    GrEq = 0;
  return Scaleform::AllocAddr::mergeNodes(this, LeEq, GrEq, addr, size);
}
