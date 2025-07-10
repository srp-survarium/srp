void __thiscall Scaleform::HeapPT::AllocLite::pullNode(
        Scaleform::HeapPT::AllocLite *this,
        Scaleform::HeapPT::DualTNode *node)
{
  Scaleform::HeapPT::DualTNode *pPrev; // eax
  Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *p_SizeTree; // ecx
  Scaleform::HeapPT::DualTNode *pNext; // edx
  Scaleform::HeapPT::DualTNode *v6; // [esp-4h] [ebp-Ch]

  this->FreeBlocks -= node->Size;
  pPrev = node->pPrev;
  p_SizeTree = &this->SizeTree;
  if ( node->pPrev == node )
  {
    Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(&p_SizeTree->Tree, node);
  }
  else
  {
    pNext = node->pNext;
    v6 = node->pPrev;
    pNext->pPrev = pPrev;
    pPrev->pNext = pNext;
    Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
      &p_SizeTree->Tree,
      node,
      v6);
  }
  Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(&this->AddrTree, node);
}
