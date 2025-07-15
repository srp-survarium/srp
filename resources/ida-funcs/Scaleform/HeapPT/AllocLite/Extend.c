void __thiscall Scaleform::HeapPT::AllocLite::Extend(
        Scaleform::HeapPT::AllocLite *this,
        Scaleform::HeapPT::TreeSeg *seg,
        unsigned int incSize)
{
  Scaleform::HeapPT::DualTNode *v4; // esi
  Scaleform::HeapPT::DualTNode *LeEq; // eax
  Scaleform::HeapPT::DualTNode *v6; // ebp
  unsigned int v7; // ebp
  Scaleform::HeapPT::DualTNode *v8; // eax

  v4 = (Scaleform::HeapPT::DualTNode *)&seg->Buffer[seg->Size];
  LeEq = (Scaleform::HeapPT::DualTNode *)Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindLeEq(
                                           &this->AddrTree,
                                           (unsigned int)&v4[-1].Size + 3);
  v6 = LeEq;
  if ( LeEq
    && LeEq->ParentSeg == seg
    && (Scaleform::HeapPT::DualTNode *)((char *)LeEq + (LeEq->Size << this->MinShift)) == v4 )
  {
    Scaleform::HeapPT::AllocLite::pullNode(this, LeEq);
    Scaleform::HeapPT::AllocLite::pushNode(this, v6, seg, v6->Size + (incSize >> this->MinShift));
    seg->Size += incSize;
  }
  else
  {
    v7 = incSize >> this->MinShift;
    v4->ParentSeg = seg;
    v4->Size = v7;
    v4->pPrev = v4;
    v4->pNext = v4;
    v8 = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Insert(
           &this->SizeTree.Tree,
           v4);
    if ( v8 )
    {
      v4->pNext = v8->pNext;
      v4->pPrev = v8;
      v8->pNext = v4;
      v4->pNext->Scaleform::ListNode<Scaleform::HeapPT::DualTNode>::$2060FFF33C3A9317469158F368502EC1::pPrev = v4;
    }
    Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Insert(
      &this->AddrTree,
      v4);
    this->FreeBlocks += v7;
    seg->Size += incSize;
  }
}
