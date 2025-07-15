Scaleform::HeapMH::NodeMH *__thiscall Scaleform::HeapMH::AllocEngineMH::reallocInNodeNoLock(
        Scaleform::HeapMH::AllocEngineMH *this,
        Scaleform::HeapMH::NodeMH *node,
        char *oldPtr,
        unsigned int newSize,
        Scaleform::HeapMH::PageInfoMH *newInfo)
{
  unsigned int v5; // eax
  unsigned int Align; // eax
  int v8; // ebp
  char *v9; // ebx
  unsigned int v10; // edi
  Scaleform::LockSafe *p_RootLock; // ebp
  Scaleform::HeapMH::NodeMH *v12; // eax
  Scaleform::HeapMH::NodeMH *v13; // ebp
  Scaleform::HeapMH::NodeMH *result; // eax
  Scaleform::HeapMH::RootMH *v15; // edi
  Scaleform::HeapMH::NodeMH *v16; // ebx
  unsigned int v17; // [esp+18h] [ebp-8h]
  int v18; // [esp+1Ch] [ebp-4h]
  Scaleform::HeapMH::NodeMH *nodea; // [esp+24h] [ebp+4h]
  Scaleform::HeapMH::RootMH *v20; // [esp+28h] [ebp+8h]

  v5 = node->pHeap & 3;
  if ( v5 == 3 )
    Align = node->Align;
  else
    Align = 1 << (v5 + 2);
  v8 = Align > 0x10 ? 20 : 16;
  v9 = (char *)node + v8 - (_DWORD)oldPtr;
  v10 = v8 + ((newSize + 3) & 0xFFFFFFFC);
  v17 = Align;
  v18 = v8;
  if ( v10 > (unsigned int)v9 && this->Limit )
  {
    while ( v10 + this->Footprint - (_DWORD)v9 > this->Limit && this->pLimHandler )
    {
      p_RootLock = &Scaleform::HeapMH::GlobalRootMH->RootLock;
      LeaveCriticalSection(&Scaleform::HeapMH::GlobalRootMH->RootLock.mLock.cs);
      if ( !(*(unsigned __int8 (__thiscall **)(void *, Scaleform::MemoryHeapMH *, unsigned int))(*(_DWORD *)this->pLimHandler
                                                                                               + 4))(
              this->pLimHandler,
              this->pHeap,
              v10 + this->Footprint - this->Limit - (_DWORD)v9) )
      {
        EnterCriticalSection(&p_RootLock->mLock.cs);
        return 0;
      }
      EnterCriticalSection(&p_RootLock->mLock.cs);
      v8 = v18;
      if ( !this->Limit )
        break;
    }
  }
  Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::Remove(
    &Scaleform::HeapMH::GlobalRootMH->HeapTree,
    node);
  v12 = (Scaleform::HeapMH::NodeMH *)this->pSysAlloc->Realloc(this->pSysAlloc, oldPtr, v9, v10, v17);
  nodea = v12;
  if ( v12 )
  {
    v20 = Scaleform::HeapMH::GlobalRootMH;
    v13 = (Scaleform::HeapMH::NodeMH *)((char *)v12 + v10 - v18);
    Scaleform::HeapMH::NodeMH::SetHeap(v13, (unsigned int)this->pHeap, v17);
    Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::Insert(&v20->HeapTree, v13);
    newInfo->Node = v13;
    newInfo->UsableSize = v10 - v18;
    newInfo->Page = 0;
    this->Footprint += v10 - (_DWORD)v9;
    result = nodea;
    this->UsedSpace += v10 - (_DWORD)v9;
  }
  else
  {
    v15 = Scaleform::HeapMH::GlobalRootMH;
    v16 = (Scaleform::HeapMH::NodeMH *)&v9[(_DWORD)oldPtr - v8];
    Scaleform::HeapMH::NodeMH::SetHeap(v16, (unsigned int)this->pHeap, v17);
    Scaleform::RadixTree<Scaleform::HeapMH::NodeMH,Scaleform::HeapMH::TreeNodeAccessor>::Insert(&v15->HeapTree, v16);
    return 0;
  }
  return result;
}
