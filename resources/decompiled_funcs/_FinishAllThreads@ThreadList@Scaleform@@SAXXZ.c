void __cdecl Scaleform::ThreadList::FinishAllThreads()
{
  Scaleform::ThreadList *volatile v0; // [esp+0h] [ebp-4h]

  if ( Scaleform::ThreadList::pRunningThreads )
  {
    Scaleform::ThreadList::finishAllThreads(Scaleform::ThreadList::pRunningThreads);
    v0 = Scaleform::ThreadList::pRunningThreads;
    if ( Scaleform::ThreadList::pRunningThreads )
    {
      Scaleform::ThreadList::~ThreadList(Scaleform::ThreadList::pRunningThreads);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v0);
    }
    Scaleform::ThreadList::pRunningThreads = 0;
  }
}
