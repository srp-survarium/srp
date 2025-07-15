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


Scaleform::HeapPT::DualTNode *__thiscall Scaleform::HeapPT::AllocLite::pullBest(
        Scaleform::HeapPT::AllocLite *this,
        unsigned int blocks,
        unsigned int alignMask)
{
  Scaleform::HeapPT::DualTNode *result; // eax
  Scaleform::HeapPT::DualTNode *GrEq; // esi
  unsigned int MinShift; // ebp
  unsigned int v8; // eax
  unsigned int v9; // ecx
  Scaleform::HeapPT::DualTNode *pPrev; // eax
  Scaleform::HeapPT::DualTNode *pNext; // ecx
  Scaleform::HeapPT::DualTNode *head; // [esp+10h] [ebp+4h]

  if ( alignMask <= this->MinMask )
    return Scaleform::HeapPT::AllocLite::pullBest(this, blocks);
  GrEq = (Scaleform::HeapPT::DualTNode *)Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::FindGrEq(
                                           &this->SizeTree.Tree,
                                           blocks);
  head = GrEq;
  if ( GrEq )
  {
    MinShift = this->MinShift;
    while ( 1 )
    {
      v8 = ~alignMask & ((unsigned int)GrEq + alignMask);
      v9 = v8 - (_DWORD)GrEq;
      if ( v8 != (_DWORD)GrEq )
      {
        do
        {
          if ( v9 >= 0x40 )
            break;
          v8 += alignMask + 1;
          v9 += alignMask + 1;
        }
        while ( v9 );
      }
      if ( (blocks << MinShift) + v8 <= (unsigned int)GrEq + (GrEq->Size << MinShift) )
        break;
      GrEq = GrEq->pNext;
      if ( GrEq == head )
      {
        result = (Scaleform::HeapPT::DualTNode *)Scaleform::RadixTree<Scaleform::HeapPT::DualTNode,Scaleform::HeapPT::AllocLite::SizeAccessor>::FindGrEq(
                                                   &this->SizeTree.Tree,
                                                   GrEq->Size + 1);
        GrEq = result;
        head = result;
        if ( !result )
          return result;
      }
    }
    pPrev = GrEq->pPrev;
    if ( GrEq->pPrev == GrEq )
    {
      Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
        &this->SizeTree.Tree,
        GrEq);
    }
    else
    {
      pNext = GrEq->pNext;
      pNext->pPrev = pPrev;
      pPrev->pNext = pNext;
      Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Remove(
        &this->SizeTree.Tree,
        GrEq,
        pPrev);
    }
    Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Remove(&this->AddrTree, GrEq);
    this->FreeBlocks -= GrEq->Size;
  }
  return GrEq;
}
