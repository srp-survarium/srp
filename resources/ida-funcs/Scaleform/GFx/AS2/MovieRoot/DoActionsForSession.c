void __thiscall Scaleform::GFx::AS2::MovieRoot::DoActionsForSession(
        Scaleform::GFx::AS2::MovieRoot *this,
        unsigned int sessionId)
{
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *i; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionQueueSessionIterator v4; // [esp+4h] [ebp-14h] BYREF

  v4.SessionId = sessionId;
  v4.pActionQueue = &this->ActionQueue;
  v4.ModId = 0;
  v4.CurrentPrio = 0;
  v4.pLastEntry = 0;
  for ( i = (Scaleform::GFx::AS2::MovieRoot::ActionEntry *)Scaleform::GFx::AS2::MovieRoot::ActionQueueSessionIterator::getNext(&v4);
        i;
        i = (Scaleform::GFx::AS2::MovieRoot::ActionEntry *)Scaleform::GFx::AS2::MovieRoot::ActionQueueSessionIterator::getNext(&v4) )
  {
    Scaleform::GFx::AS2::MovieRoot::ActionEntry::Execute(i, this);
  }
  if ( v4.pLastEntry )
    Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(v4.pActionQueue, v4.pLastEntry);
}
