Scaleform::AllocAddrNode *__thiscall Scaleform::AllocAddr::pullBest(Scaleform::AllocAddr *this, unsigned int size)
{
  Scaleform::RadixTreeMulti<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor> *p_SizeTree; // edi
  Scaleform::AllocAddrNode *result; // eax
  Scaleform::HeapPT::DualTNode *pNext; // esi
  Scaleform::HeapPT::DualTNode *pPrev; // eax
  Scaleform::HeapPT::DualTNode *v7; // ecx

  p_SizeTree = &this->SizeTree;
  result = (Scaleform::AllocAddrNode *)Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::FindGrEq(
                                         &this->SizeTree.Tree,
                                         size);
  if ( result )
  {
    pNext = (Scaleform::HeapPT::DualTNode *)result->pNext;
    pPrev = pNext->pPrev;
    if ( pNext->pPrev == pNext )
    {
      Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(
        (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *)p_SizeTree,
        pNext);
    }
    else
    {
      v7 = pNext->pNext;
      v7->pPrev = pPrev;
      pPrev->pNext = v7;
      Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor>::Remove(
        (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::AddrAccessor> *)p_SizeTree,
        pNext,
        pPrev);
    }
    Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
      (Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *)&this->AddrTree,
      pNext);
    return (Scaleform::AllocAddrNode *)pNext;
  }
  return result;
}
