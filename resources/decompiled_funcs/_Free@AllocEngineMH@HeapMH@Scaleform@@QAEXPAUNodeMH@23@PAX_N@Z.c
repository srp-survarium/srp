void __thiscall Scaleform::HeapMH::AllocEngineMH::Free(
        Scaleform::HeapMH::AllocEngineMH *this,
        Scaleform::HeapMH::NodeMH *node,
        _BYTE *ptr,
        bool __formal)
{
  unsigned int v5; // eax
  unsigned int Align; // edi
  Scaleform::SysAlloc *pSysAlloc; // ecx

  Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::Remove(
    &Scaleform::HeapMH::GlobalRootMH->HeapTree,
    node);
  v5 = node->pHeap & 3;
  if ( v5 == 3 )
    Align = node->Align;
  else
    Align = 1 << (v5 + 2);
  pSysAlloc = this->pSysAlloc;
  --this->UseCount;
  this->Footprint -= (unsigned int)node + (Align > 0x10 ? 20 : 16) - (_DWORD)ptr;
  this->UsedSpace += ptr - (_BYTE *)node;
  pSysAlloc->Free(pSysAlloc, ptr, (unsigned int)node + (Align > 0x10 ? 20 : 16) - (_DWORD)ptr, Align);
}
