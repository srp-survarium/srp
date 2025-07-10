Scaleform::HeapPT::DualTNode *__thiscall Scaleform::HeapPT::AllocLite::pullBest(
        Scaleform::HeapPT::AllocLite *this,
        unsigned int blocks)
{
  Scaleform::RadixTreeMulti<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor> *p_SizeTree; // edi
  Scaleform::HeapPT::DualTNode *result; // eax
  Scaleform::HeapPT::DualTNode *pNext; // esi
  Scaleform::HeapPT::DualTNode *pPrev; // eax
  Scaleform::HeapPT::DualTNode *v7; // ecx

  p_SizeTree = &this->SizeTree;
  result = (Scaleform::HeapPT::DualTNode *)Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::FindGrEq(
                                             &this->SizeTree.Tree,
                                             blocks);
  if ( result )
  {
    pNext = result->pNext;
    pPrev = pNext->pPrev;
    if ( pNext->pPrev == pNext )
    {
      Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
        &p_SizeTree->Tree,
        pNext);
    }
    else
    {
      v7 = pNext->pNext;
      v7->pPrev = pPrev;
      pPrev->pNext = v7;
      Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
        &p_SizeTree->Tree,
        pNext,
        pPrev);
    }
    Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(&this->AddrTree, pNext);
    this->FreeBlocks -= pNext->Size;
    return pNext;
  }
  return result;
}
