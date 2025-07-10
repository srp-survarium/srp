Scaleform::MemoryHeapPT *__thiscall Scaleform::HeapPT::HeapRoot::CreateHeap(
        Scaleform::HeapPT::HeapRoot *this,
        const char *name,
        Scaleform::MemoryHeapPT *parent,
        const Scaleform::MemoryHeap::HeapDesc *desc)
{
  Scaleform::LockSafe *p_RootLock; // edi
  unsigned int v6; // esi
  Scaleform::MemoryHeapPT *result; // eax
  Scaleform::MemoryHeapPT *v9; // eax
  Scaleform::MemoryHeapPT *v10; // ebx
  Scaleform::HeapPT::HeapRoot *v11; // eax
  Scaleform::HeapPT::AllocEngine *v12; // eax
  unsigned int Flags; // ecx
  unsigned int engineFlags; // [esp+Ch] [ebp-10h]
  unsigned __int8 *heapBuf; // [esp+10h] [ebp-Ch]
  Scaleform::HeapPT::Bookkeeper *p_AllocBookkeeper; // [esp+18h] [ebp-4h]
  const Scaleform::MemoryHeap::HeapDesc *desca; // [esp+28h] [ebp+Ch]
  const Scaleform::MemoryHeap::HeapDesc *descb; // [esp+28h] [ebp+Ch]

  p_RootLock = &this->RootLock;
  EnterCriticalSection(&this->RootLock.mLock.cs);
  LeaveCriticalSection(&p_RootLock->mLock.cs);
  v6 = (strlen(name) + 680) & 0xFFFFFFF0;
  p_AllocBookkeeper = &this->AllocBookkeeper;
  result = (Scaleform::MemoryHeapPT *)Scaleform::HeapPT::Bookkeeper::Alloc(&this->AllocBookkeeper, v6);
  heapBuf = (unsigned __int8 *)result;
  if ( result )
  {
    engineFlags = 0;
    if ( (desc->Flags & 2) != 0 )
      engineFlags = 16;
    if ( (desc->Flags & 4) == 0 )
      engineFlags |= 0x20u;
    Scaleform::MemoryHeapPT::MemoryHeapPT(result);
    v10 = v9;
    if ( heapBuf == (unsigned __int8 *)-112 )
    {
      v12 = 0;
    }
    else
    {
      desca = (const Scaleform::MemoryHeap::HeapDesc *)desc->Arena;
      EnterCriticalSection(&p_RootLock->mLock.cs);
      if ( desca )
      {
        descb = (const Scaleform::MemoryHeap::HeapDesc *)this->pArenas[(_DWORD)desca - 1];
        LeaveCriticalSection(&p_RootLock->mLock.cs);
        v11 = (Scaleform::HeapPT::HeapRoot *)descb;
      }
      else
      {
        LeaveCriticalSection(&p_RootLock->mLock.cs);
        v11 = this;
      }
      Scaleform::HeapPT::AllocEngine::AllocEngine(
        (Scaleform::HeapPT::AllocEngine *)(heapBuf + 112),
        &v11->AllocWrapper,
        v10,
        engineFlags,
        desc->MinAlign,
        desc->Granularity,
        desc->Reserve,
        desc->Threshold,
        desc->Limit);
    }
    if ( v12->Valid )
    {
      v10->SelfSize = v6;
      v10->RefCount = 1;
      v10->pAutoRelease = 0;
      qmemcpy(&v10->Info, desc, 0x20u);
      v10->Info.pParent = parent;
      v10->Info.pName = (char *)(heapBuf + 664);
      v10->UseLocks = (desc->Flags & 1) == 0;
      Flags = desc->Flags;
      v10->pEngine = v12;
      v10->TrackDebugInfo = (Flags & 0x10) == 0;
      strcpy((char *)heapBuf + 664, name);
      return v10;
    }
    else
    {
      Scaleform::HeapPT::Bookkeeper::Free(p_AllocBookkeeper, heapBuf, v6);
      return 0;
    }
  }
  return result;
}
