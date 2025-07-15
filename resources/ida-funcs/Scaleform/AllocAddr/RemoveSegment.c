void __thiscall Scaleform::AllocAddr::RemoveSegment(Scaleform::AllocAddr *this, unsigned int addr, unsigned int size)
{
  Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor> *p_AddrTree; // ebx
  Scaleform::HeapPT::DualTNode *LeEq; // esi
  Scaleform::HeapPT::DualTNode *pPrev; // eax
  Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor> *p_SizeTree; // ecx
  Scaleform::HeapPT::DualTNode *pNext; // edx

  p_AddrTree = &this->AddrTree;
  LeEq = (Scaleform::HeapPT::DualTNode *)Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::FindLeEq(
                                           &this->AddrTree,
                                           addr);
  pPrev = LeEq->pPrev;
  p_SizeTree = &this->SizeTree;
  if ( LeEq->pPrev == LeEq )
  {
    Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(
      (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *)p_SizeTree,
      LeEq);
  }
  else
  {
    pNext = LeEq->pNext;
    pNext->pPrev = pPrev;
    pPrev->pNext = pNext;
    Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
      (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *)p_SizeTree,
      LeEq,
      pPrev);
  }
  Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
    (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *)p_AddrTree,
    LeEq);
  Scaleform::AllocAddr::splitNode(this, (Scaleform::AllocAddrNode *)LeEq, addr, size);
}
