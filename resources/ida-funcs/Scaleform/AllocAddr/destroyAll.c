void __thiscall Scaleform::AllocAddr::destroyAll(Scaleform::AllocAddr *this)
{
  Scaleform::AllocAddrNode *i; // eax
  Scaleform::AllocAddrNode *Root; // [esp-8h] [ebp-14h]
  Scaleform::List<Scaleform::AllocAddrNode,Scaleform::AllocAddrNode> nodes; // [esp+4h] [ebp-8h] BYREF

  nodes.Root.pPrev = (Scaleform::AllocAddrNode *)&nodes;
  Root = this->AddrTree.Root;
  nodes.Root.pNext = (Scaleform::AllocAddrNode *)&nodes;
  Scaleform::linearizeTree(Root, &nodes);
  this->AddrTree.Root = 0;
  this->SizeTree.Tree.Root = 0;
  for ( i = nodes.Root.pNext;
        (Scaleform::List<Scaleform::AllocAddrNode,Scaleform::AllocAddrNode> *)nodes.Root.pNext != &nodes;
        i = nodes.Root.pNext )
  {
    i->pPrev->pNext = i->pNext;
    i->pNext->Scaleform::ListNode<Scaleform::AllocAddrNode>::$EDDFB6E6111D817B2CB971CA9EC17793::pPrev = i->pPrev;
    this->pNodeHeap->Free(this->pNodeHeap, i);
  }
}
