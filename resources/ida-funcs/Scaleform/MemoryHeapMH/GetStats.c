char __thiscall Scaleform::MemoryHeapMH::GetStats(Scaleform::MemoryHeapMH *this, Scaleform::StatBag *bag)
{
  Scaleform::StatBag *v3; // esi
  Scaleform::MemoryHeap *pNext; // ebx
  int v5; // ecx
  Scaleform::List<Scaleform::MemoryHeap,Scaleform::MemoryHeap> *p_ChildHeaps; // edi
  int v7; // eax
  unsigned int (__thiscall *GetTotalFootprint)(Scaleform::MemoryHeap *); // eax
  int v9; // eax
  Scaleform::Stat pstat[4]; // [esp+10h] [ebp-Ch] BYREF
  unsigned int Footprint; // [esp+14h] [ebp-8h]
  LPCRITICAL_SECTION lpCriticalSection; // [esp+18h] [ebp-4h]

  lpCriticalSection = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  v3 = bag;
  Footprint = this->pEngine->Footprint;
  *(_DWORD *)pstat = Footprint;
  Scaleform::StatBag::Add(bag, 0x12u, pstat);
  bag = (Scaleform::StatBag *)this->pEngine->UsedSpace;
  Scaleform::StatBag::Add(v3, 0x15u, (Scaleform::Stat *)&bag);
  bag = 0;
  Scaleform::StatBag::Add(v3, 0x1Au, (Scaleform::Stat *)&bag);
  bag = 0;
  Scaleform::StatBag::Add(v3, 0x1Cu, (Scaleform::Stat *)&bag);
  bag = 0;
  Scaleform::StatBag::Add(v3, 0x17u, (Scaleform::Stat *)&bag);
  bag = 0;
  Scaleform::StatBag::Add(v3, 0x19u, (Scaleform::Stat *)&bag);
  bag = 0;
  Scaleform::StatBag::Add(v3, 0x1Bu, (Scaleform::Stat *)&bag);
  bag = 0;
  Scaleform::StatBag::Add(v3, 0x16u, (Scaleform::Stat *)&bag);
  pNext = this->ChildHeaps.Root.pNext;
  v5 = 0;
  bag = 0;
  p_ChildHeaps = &this->ChildHeaps;
  while ( 1 )
  {
    v7 = p_ChildHeaps ? (int)&p_ChildHeaps[-1].Root.4 : 0;
    if ( pNext == (Scaleform::MemoryHeap *)v7 )
      break;
    if ( (pNext->Info.Desc.Flags & 0x1000) == 0 )
    {
      GetTotalFootprint = pNext->GetTotalFootprint;
      *(_DWORD *)pstat = v5 + 1;
      v9 = GetTotalFootprint(pNext);
      bag = (Scaleform::StatBag *)((char *)bag + v9);
      v5 = *(_DWORD *)pstat;
    }
    pNext = pNext->pNext;
  }
  if ( v5 )
  {
    *(_DWORD *)pstat = v5;
    Scaleform::StatBag::Add(v3, 0x14u, pstat);
    *(_DWORD *)pstat = bag;
    Scaleform::StatBag::Add(v3, 0x13u, pstat);
  }
  bag = (Scaleform::StatBag *)((char *)bag + Footprint);
  Scaleform::StatBag::Add(v3, 0x11u, (Scaleform::Stat *)&bag);
  LeaveCriticalSection(lpCriticalSection);
  return 1;
}
