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


void __thiscall Scaleform::HeapMH::AllocEngineMH::Free(
        Scaleform::HeapMH::AllocEngineMH *this,
        Scaleform::HeapMH::PageMH *page,
        unsigned __int8 *ptr,
        bool globalLocked)
{
  int v5; // eax
  Scaleform::HeapMH::MagicHeadersInfo headers; // [esp+8h] [ebp-1Ch] BYREF

  Scaleform::HeapMH::AllocBitSet2MH::Free(&this->Allocator, page, ptr, &headers, (unsigned int *)&ptr);
  this->UsedSpace -= (unsigned int)ptr;
  v5 = 0;
  if ( headers.Header1 )
    v5 = --headers.Header1->UseCount;
  if ( headers.Header2 )
    v5 = --headers.Header2->UseCount;
  if ( !v5 )
    Scaleform::HeapMH::AllocEngineMH::freePage(this, page, globalLocked);
  --this->UseCount;
}
