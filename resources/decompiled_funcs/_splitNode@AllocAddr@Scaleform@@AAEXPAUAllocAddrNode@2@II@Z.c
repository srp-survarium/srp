void __thiscall Scaleform::AllocAddr::splitNode(
        Scaleform::AllocAddr *this,
        Scaleform::AllocAddrNode *node,
        unsigned int addr,
        unsigned int size)
{
  Scaleform::AllocAddrNode *v4; // eax
  unsigned int v5; // edx
  unsigned int v7; // esi

  v4 = node;
  v5 = node->Addr;
  v7 = v5 + node->Size - addr - size;
  if ( addr != v5 )
  {
    Scaleform::AllocAddr::pushNode(this, node, v5, addr - v5);
    if ( !v7 )
      return;
    v4 = (Scaleform::AllocAddrNode *)this->pNodeHeap->Alloc(this->pNodeHeap, 40, 0);
    goto LABEL_4;
  }
  if ( v7 )
  {
LABEL_4:
    Scaleform::AllocAddr::pushNode(this, v4, size + addr, v7);
    return;
  }
  this->pNodeHeap->Free(this->pNodeHeap, node);
}
