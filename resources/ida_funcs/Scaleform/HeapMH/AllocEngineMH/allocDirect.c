char *__thiscall Scaleform::HeapMH::AllocEngineMH::allocDirect(
        Scaleform::HeapMH::AllocEngineMH *this,
        unsigned int size,
        unsigned int alignSize,
        bool *limHandlerOK,
        Scaleform::HeapMH::PageInfoMH *info)
{
  unsigned int v5; // ebx
  int v7; // edi
  unsigned int Limit; // eax
  Scaleform::LockSafe *p_RootLock; // ebp
  char *result; // eax
  Scaleform::HeapMH::NodeMH *v11; // ebp
  char *ptr; // [esp+10h] [ebp-4h]
  Scaleform::HeapMH::RootMH *sizea; // [esp+18h] [ebp+4h]

  v5 = (size + 3) & 0xFFFFFFFC;
  v7 = alignSize > 0x10 ? 20 : 16;
  Limit = this->Limit;
  if ( Limit && this->Footprint + v7 + v5 > Limit && this->pLimHandler )
  {
    p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
    LeaveCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
    *limHandlerOK = (*(int (__thiscall **)(void *, Scaleform::MemoryHeapMH *, unsigned int))(*(_DWORD *)this->pLimHandler
                                                                                           + 4))(
                      this->pLimHandler,
                      this->pHeap,
                      this->Footprint + v5 + v7 - this->Limit);
    EnterCriticalSection(&p_RootLock->mLock.cs);
    return 0;
  }
  else
  {
    *limHandlerOK = 0;
    result = (char *)this->pSysAlloc->Alloc(this->pSysAlloc, v7 + v5, alignSize);
    ptr = result;
    if ( result )
    {
      v11 = (Scaleform::HeapMH::NodeMH *)&result[v5];
      sizea = Scaleform::HeapMH::GlobalRootMH;
      Scaleform::HeapMH::NodeMH::SetHeap((Scaleform::HeapMH::NodeMH *)&result[v5], (unsigned int)this->pHeap, alignSize);
      Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::Insert(&sizea->HeapTree, v11);
      info->UsableSize = v5;
      info->Page = 0;
      info->Node = v11;
      ++this->UseCount;
      result = ptr;
      this->Footprint += v5 + v7;
      this->UsedSpace += v5;
      *limHandlerOK = 1;
    }
  }
  return result;
}
