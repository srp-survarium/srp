void __thiscall Scaleform::AllocAddr::pullNode(Scaleform::AllocAddr *this, Scaleform::HeapPT::DualTNode *node)
{
  Scaleform::HeapPT::DualTNode *pPrev; // eax
  Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor> *p_SizeTree; // ecx
  Scaleform::HeapPT::DualTNode *pNext; // edx
  Scaleform::HeapPT::DualTNode *v6; // [esp-4h] [ebp-Ch]

  pPrev = node->pPrev;
  p_SizeTree = &this->SizeTree;
  if ( node->pPrev == node )
  {
    Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(
      (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *)p_SizeTree,
      node);
  }
  else
  {
    pNext = node->pNext;
    v6 = node->pPrev;
    pNext->pPrev = pPrev;
    pPrev->pNext = pNext;
    Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
      (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *)p_SizeTree,
      node,
      v6);
  }
  Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
    (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *)&this->AddrTree,
    node);
}
