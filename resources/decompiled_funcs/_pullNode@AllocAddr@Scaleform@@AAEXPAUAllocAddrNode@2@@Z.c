void __thiscall Scaleform::AllocAddr::pullNode(Scaleform::AllocAddr *this, Scaleform::AllocAddrNode *node)
{
  Scaleform::AllocAddrNode *pPrev; // eax
  Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor> *p_SizeTree; // ecx
  Scaleform::AllocAddrNode *pNext; // edx
  Scaleform::AllocAddrNode *v6; // [esp-4h] [ebp-Ch]

  pPrev = node->pPrev;
  p_SizeTree = &this->SizeTree;
  if ( node->pPrev == node )
  {
    Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(
      (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *)p_SizeTree,
      (Scaleform::HeapPT::DualTNode *)node);
  }
  else
  {
    pNext = node->pNext;
    v6 = node->pPrev;
    pNext->pPrev = pPrev;
    pPrev->pNext = pNext;
    Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
      (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *)p_SizeTree,
      (Scaleform::HeapPT::DualTNode *)node,
      (Scaleform::HeapPT::DualTNode *)v6);
  }
  Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
    (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *)&this->AddrTree,
    (Scaleform::HeapPT::DualTNode *)node);
}
