void __thiscall Scaleform::GFx::AS2::MovieRoot::DoActionsForSession(
        Scaleform::GFx::AS2::MovieRoot *this,
        unsigned int sessionId)
{
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *i; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionQueueSessionIterator iter; // [esp+4h] [ebp-14h] BYREF

  iter.SessionId = sessionId;
  iter.pActionQueue = &this->ActionQueue;
  iter.ModId = 0;
  iter.CurrentPrio = 0;
  iter.pLastEntry = 0;
  for ( i = (Scaleform::GFx::AS2::MovieRoot::ActionEntry *)Scaleform::GFx::AS2::MovieRoot::ActionQueueSessionIterator::getNext(&iter);
        i;
        i = (Scaleform::GFx::AS2::MovieRoot::ActionEntry *)Scaleform::GFx::AS2::MovieRoot::ActionQueueSessionIterator::getNext(&iter) )
  {
    Scaleform::GFx::AS2::MovieRoot::ActionEntry::Execute(i, this);
  }
  if ( iter.pLastEntry )
    Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(iter.pActionQueue, iter.pLastEntry);
}
