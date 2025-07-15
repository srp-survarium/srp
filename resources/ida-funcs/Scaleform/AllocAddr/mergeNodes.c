unsigned int __thiscall Scaleform::AllocAddr::mergeNodes(
        Scaleform::AllocAddr *this,
        Scaleform::AllocAddrNode *prev,
        Scaleform::AllocAddrNode *next,
        unsigned int addr,
        unsigned int size)
{
  unsigned int v6; // edi
  unsigned int v7; // edi
  unsigned int v9; // edi
  Scaleform::AllocAddrNode *v10; // eax

  if ( prev )
  {
    v6 = prev->Size;
    if ( next )
    {
      v7 = size + next->Size + v6;
      Scaleform::AllocAddr::pullNode(this, (Scaleform::HeapPT::DualTNode *)prev);
      Scaleform::AllocAddr::pullNode(this, (Scaleform::HeapPT::DualTNode *)next);
      Scaleform::AllocAddr::pushNode(this, prev, prev->Addr, v7);
      this->pNodeHeap->Free(this->pNodeHeap, next);
    }
    else
    {
      v7 = size + v6;
      Scaleform::AllocAddr::pullNode(this, (Scaleform::HeapPT::DualTNode *)prev);
      Scaleform::AllocAddr::pushNode(this, prev, prev->Addr, v7);
    }
    return v7;
  }
  else if ( next )
  {
    v9 = size + next->Size;
    Scaleform::AllocAddr::pullNode(this, (Scaleform::HeapPT::DualTNode *)next);
    Scaleform::AllocAddr::pushNode(this, next, addr, v9);
    return v9;
  }
  else
  {
    v10 = (Scaleform::AllocAddrNode *)((int (__stdcall *)(int, _DWORD))this->pNodeHeap->Alloc)(40, 0);
    Scaleform::AllocAddr::pushNode(this, v10, addr, size);
    return size;
  }
}
