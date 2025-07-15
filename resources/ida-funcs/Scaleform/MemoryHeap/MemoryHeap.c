void __thiscall Scaleform::MemoryHeap::MemoryHeap(Scaleform::MemoryHeap *this)
{
  Scaleform::List<Scaleform::MemoryHeap,Scaleform::MemoryHeap> *p_ChildHeaps; // eax
  char **p_pName; // ecx

  this->__vftable = (Scaleform::MemoryHeap_vtbl *)&Scaleform::MemoryHeap::`vftable';
  this->SelfSize = 0;
  this->RefCount = 1;
  this->OwnerThreadId = 0;
  this->pAutoRelease = 0;
  this->Info.Desc.Granularity = 0x2000;
  this->Info.Desc.Reserve = 0x2000;
  p_ChildHeaps = &this->ChildHeaps;
  this->Info.Desc.Flags = 0;
  this->Info.Desc.MinAlign = 16;
  this->Info.Desc.Threshold = -1;
  this->Info.Desc.Limit = 0;
  this->Info.Desc.HeapId = 0;
  this->Info.Desc.Arena = 0;
  if ( this == (Scaleform::MemoryHeap *)-68 )
    p_pName = 0;
  else
    p_pName = &this->Info.pName;
  p_ChildHeaps->Root.pPrev = (Scaleform::MemoryHeap *)p_pName;
  p_ChildHeaps->Root.pNext = (Scaleform::MemoryHeap *)p_pName;
  Scaleform::Lock::Lock(&this->HeapLock, 0);
  this->UseLocks = 1;
  this->TrackDebugInfo = 1;
  this->Info.Desc.Flags = 0;
  this->Info.Desc.MinAlign = 0;
  this->Info.Desc.Granularity = 0;
  this->Info.Desc.Reserve = 0;
  this->Info.Desc.Threshold = 0;
  this->Info.Desc.Limit = 0;
  this->Info.Desc.HeapId = 0;
  this->Info.Desc.Arena = 0;
  this->Info.pParent = 0;
  this->Info.pName = 0;
}
