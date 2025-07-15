char __thiscall Scaleform::MemoryHeapPT::GetStats(Scaleform::MemoryHeapPT *this, Scaleform::StatBag *bag)
{
  unsigned int Footprint; // eax
  Scaleform::StatBag *v4; // edi
  Scaleform::MemoryHeap *pNext; // ebx
  Scaleform::StatBag *v6; // ecx
  Scaleform::StatBag *v7; // ebp
  Scaleform::List<Scaleform::MemoryHeap,Scaleform::MemoryHeap> *p_ChildHeaps; // esi
  int v9; // eax
  unsigned int (__thiscall *GetTotalFootprint)(Scaleform::MemoryHeap *); // eax
  int v11; // eax
  Scaleform::Stat v13[4]; // [esp+10h] [ebp-1Ch] BYREF
  unsigned int v14; // [esp+14h] [ebp-18h]
  LPCRITICAL_SECTION lpCriticalSection; // [esp+18h] [ebp-14h]
  Scaleform::HeapPT::HeapOtherStats otherStats; // [esp+1Ch] [ebp-10h] BYREF

  lpCriticalSection = &this->HeapLock.cs;
  EnterCriticalSection(&this->HeapLock.cs);
  Footprint = Scaleform::HeapPT::AllocEngine::GetFootprint(this->pEngine);
  v4 = bag;
  v14 = Footprint;
  *(_DWORD *)v13 = Footprint;
  Scaleform::StatBag::Add(bag, 0x12u, v13);
  bag = (Scaleform::StatBag *)Scaleform::HeapPT::AllocEngine::GetUsedSpace(this->pEngine);
  Scaleform::StatBag::Add(v4, 0x15u, (Scaleform::Stat *)&bag);
  bag = (Scaleform::StatBag *)this->Info.Desc.Granularity;
  Scaleform::StatBag::Add(v4, 0x1Au, (Scaleform::Stat *)&bag);
  bag = (Scaleform::StatBag *)this->Info.Desc.Reserve;
  Scaleform::StatBag::Add(v4, 0x1Cu, (Scaleform::Stat *)&bag);
  Scaleform::HeapPT::AllocEngine::GetHeapOtherStats(this->pEngine, &otherStats);
  otherStats.Bookkeeping += this->SelfSize;
  bag = (Scaleform::StatBag *)otherStats.Bookkeeping;
  Scaleform::StatBag::Add(v4, 0x17u, (Scaleform::Stat *)&bag);
  bag = (Scaleform::StatBag *)otherStats.Segments;
  Scaleform::StatBag::Add(v4, 0x19u, (Scaleform::Stat *)&bag);
  bag = (Scaleform::StatBag *)otherStats.DynamicGranularity;
  Scaleform::StatBag::Add(v4, 0x1Bu, (Scaleform::Stat *)&bag);
  bag = (Scaleform::StatBag *)otherStats.SysDirectSpace;
  Scaleform::StatBag::Add(v4, 0x16u, (Scaleform::Stat *)&bag);
  pNext = this->ChildHeaps.Root.pNext;
  v6 = 0;
  v7 = 0;
  p_ChildHeaps = &this->ChildHeaps;
  while ( 1 )
  {
    v9 = p_ChildHeaps ? (int)&p_ChildHeaps[-1].Root.4 : 0;
    if ( pNext == (Scaleform::MemoryHeap *)v9 )
      break;
    if ( (pNext->Info.Desc.Flags & 0x1000) == 0 )
    {
      GetTotalFootprint = pNext->GetTotalFootprint;
      bag = (Scaleform::StatBag *)((char *)&v6->pMem + 1);
      v11 = GetTotalFootprint(pNext);
      v6 = bag;
      v7 = (Scaleform::StatBag *)((char *)v7 + v11);
    }
    pNext = pNext->pNext;
  }
  if ( v6 )
  {
    bag = v6;
    Scaleform::StatBag::Add(v4, 0x14u, (Scaleform::Stat *)&bag);
    bag = v7;
    Scaleform::StatBag::Add(v4, 0x13u, (Scaleform::Stat *)&bag);
  }
  bag = (Scaleform::StatBag *)((char *)v7 + v14);
  Scaleform::StatBag::Add(v4, 0x11u, (Scaleform::Stat *)&bag);
  LeaveCriticalSection(lpCriticalSection);
  return 1;
}
