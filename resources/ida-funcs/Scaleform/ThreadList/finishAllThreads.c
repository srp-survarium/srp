Scaleform::ThreadList *Scaleform::ThreadList::FinishAllThreads()
{
  Scaleform::ThreadList *result; // eax
  Scaleform::ThreadList *volatile v1; // [esp+0h] [ebp-4h]

  result = Scaleform::ThreadList::pRunningThreads;
  if ( Scaleform::ThreadList::pRunningThreads )
  {
    Scaleform::ThreadList::finishAllThreads(Scaleform::ThreadList::pRunningThreads);
    v1 = Scaleform::ThreadList::pRunningThreads;
    result = Scaleform::ThreadList::pRunningThreads;
    if ( Scaleform::ThreadList::pRunningThreads )
    {
      Scaleform::ThreadList::~ThreadList(Scaleform::ThreadList::pRunningThreads);
      result = (Scaleform::ThreadList *)((int (__thiscall *)(Scaleform::MemoryHeap *, Scaleform::ThreadList *volatile))Scaleform::Memory::pGlobalHeap->Free)(
                                          Scaleform::Memory::pGlobalHeap,
                                          v1);
    }
    Scaleform::ThreadList::pRunningThreads = 0;
  }
  return result;
}
