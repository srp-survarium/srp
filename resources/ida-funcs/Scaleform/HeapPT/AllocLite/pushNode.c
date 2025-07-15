void __thiscall Scaleform::HeapPT::AllocLite::pushNode(
        Scaleform::HeapPT::AllocLite *this,
        Scaleform::HeapPT::DualTNode *node,
        Scaleform::HeapPT::TreeSeg *seg,
        unsigned int blocks)
{
  Scaleform::HeapPT::DualTNode *v5; // eax

  node->Size = blocks;
  node->ParentSeg = seg;
  node->pPrev = node;
  node->pNext = node;
  v5 = Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::Insert(
         &this->SizeTree.Tree,
         node);
  if ( v5 )
  {
    node->pNext = v5->pNext;
    node->pPrev = v5;
    v5->pNext = node;
    node->pNext->Scaleform::ListNode<Scaleform::HeapPT::DualTNode>::$FA7D61F44F114A80126F7766EA9000B1::pPrev = node;
  }
  Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Insert(
    &this->AddrTree,
    node);
  this->FreeBlocks += blocks;
}
