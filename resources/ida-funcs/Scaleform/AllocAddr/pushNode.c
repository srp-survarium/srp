void __thiscall Scaleform::AllocAddr::pushNode(
        Scaleform::AllocAddr *this,
        Scaleform::AllocAddrNode *node,
        unsigned int addr,
        unsigned int size)
{
  Scaleform::AllocAddrNode *v5; // eax

  node->Size = size;
  node->Addr = addr;
  node->pPrev = node;
  node->pNext = node;
  v5 = Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::SizeAccessor>::Insert(
         &this->SizeTree.Tree,
         node);
  if ( v5 )
  {
    node->pNext = v5->pNext;
    node->pPrev = v5;
    v5->pNext = node;
    node->pNext->Scaleform::ListNode<Scaleform::AllocAddrNode>::$EDDFB6E6111D817B2CB971CA9EC17793::pPrev = node;
  }
  Scaleform::RadixTree<Scaleform::AllocAddrNode,Scaleform::AllocAddr::AddrAccessor>::Insert(&this->AddrTree, node);
}
