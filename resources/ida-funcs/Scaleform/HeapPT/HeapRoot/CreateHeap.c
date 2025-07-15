Scaleform::MemoryHeapPT *__thiscall Scaleform::HeapPT::HeapRoot::CreateHeap(
        Scaleform::HeapPT::HeapRoot *this,
        const char *name,
        Scaleform::MemoryHeapPT *parent,
        Scaleform::SysAllocPaged *desc)
{
  Scaleform::LockSafe *p_RootLock; // edi
  Scaleform::Heap::HeapSegment *v6; // esi
  Scaleform::MemoryHeapPT *result; // eax
  Scaleform::MemoryHeapPT *v9; // eax
  Scaleform::MemoryHeapPT *v10; // ebx
  Scaleform::HeapPT::HeapRoot *v11; // eax
  Scaleform::HeapPT::AllocEngine *v12; // eax
  Scaleform::SysAllocPaged_vtbl *v13; // ecx
  char allocFlags; // [esp+Ch] [ebp-10h]
  Scaleform::MemoryHeapPT *ptr; // [esp+10h] [ebp-Ch]
  Scaleform::HeapPT::Bookkeeper *p_AllocBookkeeper; // [esp+18h] [ebp-4h]
  Scaleform::SysAllocPaged *sysAlloc; // [esp+28h] [ebp+Ch]
  Scaleform::SysAllocPaged *sysAlloca; // [esp+28h] [ebp+Ch]

  p_RootLock = &this->RootLock;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  v6 = (Scaleform::Heap::HeapSegment *)((strlen(name) + 680) & 0xFFFFFFF0);
  p_AllocBookkeeper = &this->AllocBookkeeper;
  result = (Scaleform::MemoryHeapPT *)Scaleform::HeapPT::Bookkeeper::Alloc(&this->AllocBookkeeper, v6);
  ptr = result;
  if ( result )
  {
    allocFlags = 0;
    if ( ((int)desc->__vftable & 2) != 0 )
      allocFlags = 16;
    if ( ((int)desc->__vftable & 4) == 0 )
      allocFlags |= 0x20u;
    Scaleform::MemoryHeapPT::MemoryHeapPT(result);
    v10 = v9;
    if ( ptr == (Scaleform::MemoryHeapPT *)-112 )
    {
      v12 = 0;
    }
    else
    {
      sysAlloc = (Scaleform::SysAllocPaged *)desc[7].__vftable;
      EnterCriticalSection(&p_RootLock->mLock.cs);
      if ( sysAlloc )
      {
        sysAlloca = this->pArenas[(_DWORD)sysAlloc - 1];
        LeaveCriticalSection(&p_RootLock->mLock.cs);
        v11 = (Scaleform::HeapPT::HeapRoot *)sysAlloca;
      }
      else
      {
        LeaveCriticalSection(&p_RootLock->mLock.cs);
        v11 = this;
      }
      Scaleform::HeapPT::AllocEngine::AllocEngine(
        (Scaleform::HeapPT::AllocEngine *)&ptr[1],
        &v11->AllocWrapper,
        v10,
        allocFlags,
        (unsigned int)desc[1].__vftable,
        (unsigned int)desc[2].__vftable,
        (unsigned int)desc[3].__vftable,
        (unsigned int)desc[4].__vftable,
        (unsigned int)desc[5].__vftable);
    }
    if ( v12->Valid )
    {
      v10->SelfSize = (unsigned int)v6;
      v10->RefCount = 1;
      v10->pAutoRelease = 0;
      qmemcpy(&v10->Info, desc, 0x20u);
      v10->Info.pParent = parent;
      v10->Info.pName = (char *)&ptr[5].pEngine;
      v10->UseLocks = ((int)desc->__vftable & 1) == 0;
      v13 = desc->__vftable;
      v10->pEngine = v12;
      v10->TrackDebugInfo = ((unsigned __int8)v13 & 0x10) == 0;
      strcpy((char *)&ptr[5].pEngine, name);
      return v10;
    }
    else
    {
      Scaleform::HeapPT::Bookkeeper::Free(p_AllocBookkeeper, (unsigned int)ptr, (unsigned int)v6);
      return 0;
    }
  }
  return result;
}
