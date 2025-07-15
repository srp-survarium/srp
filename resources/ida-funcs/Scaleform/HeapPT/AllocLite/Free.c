void __thiscall Scaleform::HeapPT::AllocLite::Free(
        Scaleform::HeapPT::AllocLite *this,
        Scaleform::HeapPT::TreeSeg *seg,
        Scaleform::HeapPT::DualTNode *ptr,
        unsigned int size,
        unsigned int alignSize)
{
  unsigned int MinSize; // ecx
  unsigned int v7; // edi
  unsigned int v8; // eax
  Scaleform::HeapPT::DualTNode *v9; // esi
  unsigned int v10; // edi
  Scaleform::HeapPT::DualTNode *LeEq; // ebx
  Scaleform::HeapPT::DualTNode *GrEq; // eax
  unsigned int v13; // edi
  Scaleform::HeapPT::DualTNode *v14; // eax
  Scaleform::HeapPT::DualTNode *v15; // [esp+18h] [ebp+Ch]

  MinSize = this->MinSize;
  v7 = size;
  if ( size < MinSize )
    v7 = MinSize;
  v8 = alignSize;
  if ( alignSize < MinSize )
    v8 = MinSize;
  v9 = ptr;
  v10 = ~(v8 - 1) & (v7 + v8 - 1);
  LeEq = (Scaleform::HeapPT::DualTNode *)Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindLeEq(
                                           &this->AddrTree,
                                           (unsigned int)ptr);
  GrEq = (Scaleform::HeapPT::DualTNode *)Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::FindGrEq(
                                           &this->AddrTree,
                                           (unsigned int)ptr + v10);
  v15 = GrEq;
  if ( !LeEq
    || LeEq->ParentSeg != seg
    || (Scaleform::HeapPT::DualTNode *)((char *)LeEq + (LeEq->Size << this->MinShift)) != ptr )
  {
    LeEq = 0;
  }
  if ( !GrEq || GrEq->ParentSeg != seg || GrEq != (Scaleform::HeapPT::DualTNode *)((char *)ptr + v10) )
  {
    v15 = 0;
    GrEq = 0;
  }
  v13 = v10 >> this->MinShift;
  ptr->ParentSeg = seg;
  ptr->Size = v13;
  if ( LeEq )
  {
    v13 += LeEq->Size;
    v9 = LeEq;
    Scaleform::HeapPT::AllocLite::pullNode(this, LeEq);
    GrEq = v15;
  }
  if ( GrEq )
  {
    v13 += GrEq->Size;
    Scaleform::HeapPT::AllocLite::pullNode(this, GrEq);
  }
  v9->Size = v13;
  v9->ParentSeg = seg;
  v9->pPrev = v9;
  v9->pNext = v9;
  v14 = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Insert(
          &this->SizeTree.Tree,
          v9);
  if ( v14 )
  {
    v9->pNext = v14->pNext;
    v9->pPrev = v14;
    v14->pNext = v9;
    v9->pNext->Scaleform::ListNode<Scaleform::HeapPT::DualTNode>::$2060FFF33C3A9317469158F368502EC1::pPrev = v9;
  }
  Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Insert(
    &this->AddrTree,
    v9);
  this->FreeBlocks += v13;
}
