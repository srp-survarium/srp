void __userpurge Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(
        Scaleform::GFx::AS3::MovieRoot *this@<ecx>,
        int a2@<ebp>,
        Scaleform::GFx::AS3::MovieRoot::ActionLevel lvl)
{
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *i; // eax
  Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator iter; // [esp+4h] [ebp-18h] BYREF

  iter.Level = lvl;
  iter.pActionQueue = &this->ActionQueue;
  iter.pCurEntry = this->ActionQueue.Entries[lvl].pActionRoot;
  iter.ModId = 0;
  iter.pLastEntry = 0;
  iter.pRootEntry = 0;
  for ( i = (Scaleform::GFx::AS3::MovieRoot::ActionEntry *)Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(&iter);
        i;
        i = (Scaleform::GFx::AS3::MovieRoot::ActionEntry *)Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(&iter) )
  {
    Scaleform::GFx::AS3::MovieRoot::ActionEntry::Execute(i, a2, this);
  }
  if ( iter.pLastEntry )
    Scaleform::GFx::AS3::MovieRoot::ActionQueueType::AddToFreeList(iter.pActionQueue, iter.pLastEntry);
}
