void __thiscall Scaleform::GFx::AS3::MovieRoot::ActionQueueType::Clear(
        Scaleform::GFx::AS3::MovieRoot::ActionQueueType *this)
{
  Scaleform::GFx::AS3::MovieRoot::ActionLevel v2; // esi
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *v3; // edi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pActionRoot; // eax
  Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator iter; // [esp+10h] [ebp-18h] BYREF

  v2 = AL_Highest;
  v3 = this;
  do
  {
    pActionRoot = v3->Entries[0].pActionRoot;
    iter.pActionQueue = this;
    iter.Level = v2;
    iter.ModId = 0;
    iter.pLastEntry = 0;
    iter.pRootEntry = 0;
    iter.pCurEntry = pActionRoot;
    while ( Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(&iter) )
      ;
    if ( iter.pLastEntry )
      Scaleform::GFx::AS3::MovieRoot::ActionQueueType::AddToFreeList(iter.pActionQueue, iter.pLastEntry);
    ++v2;
    v3 = (Scaleform::GFx::AS3::MovieRoot::ActionQueueType *)((char *)v3 + 12);
  }
  while ( (unsigned int)v2 < AL_Total );
}
