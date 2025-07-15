Scaleform::MemoryHeapMH *__thiscall Scaleform::HeapMH::RootMH::CreateHeap(
        Scaleform::HeapMH::RootMH *this,
        const char *name,
        Scaleform::MemoryHeapMH *parent,
        const Scaleform::MemoryHeap::HeapDesc *desc)
{
  unsigned int v5; // kr00_4
  Scaleform::MemoryHeapMH *result; // eax
  Scaleform::MemoryHeapMH *v7; // ebp
  Scaleform::MemoryHeapMH *v8; // eax
  Scaleform::MemoryHeapMH *v9; // ebx
  Scaleform::HeapMH::AllocEngineMH *v10; // eax
  unsigned int Flags; // ecx
  Scaleform::MemoryHeapMH *v12; // [esp+Ch] [ebp-4h]

  v5 = strlen(name);
  result = (Scaleform::MemoryHeapMH *)this->pSysAlloc->Alloc(this->pSysAlloc, (v5 + 300) & 0xFFFFFFF0, 4);
  v7 = result;
  v12 = result;
  if ( result )
  {
    Scaleform::MemoryHeapMH::MemoryHeapMH(result);
    v9 = v8;
    if ( v7 == (Scaleform::MemoryHeapMH *)-112 )
      v10 = 0;
    else
      Scaleform::HeapMH::AllocEngineMH::AllocEngineMH(
        (Scaleform::HeapMH::AllocEngineMH *)&v7[1],
        this->pSysAlloc,
        v8,
        desc->MinAlign,
        desc->Limit);
    v9->SelfSize = (v5 + 300) & 0xFFFFFFF0;
    v9->RefCount = 1;
    v9->pAutoRelease = 0;
    qmemcpy(&v9->Info, desc, 0x20u);
    v9->Info.pParent = parent;
    v9->Info.pName = (char *)&v12[2].Info.pParent;
    v9->UseLocks = (desc->Flags & 1) == 0;
    Flags = desc->Flags;
    v9->pEngine = v10;
    v9->TrackDebugInfo = (Flags & 0x10) == 0;
    strcpy((char *)&v12[2].Info.pParent, name);
    return v9;
  }
  return result;
}
