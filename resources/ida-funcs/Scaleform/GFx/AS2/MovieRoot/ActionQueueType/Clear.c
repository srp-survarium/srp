void __thiscall Scaleform::GFx::AS2::MovieRoot::ActionQueueType::Clear(
        Scaleform::GFx::AS2::MovieRoot::ActionQueueType *this)
{
  Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator iter; // [esp+0h] [ebp-10h] BYREF

  iter.pActionQueue = this;
  iter.ModId = 0;
  iter.CurrentPrio = 0;
  iter.pLastEntry = 0;
  while ( Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator::getNext(&iter) )
    ;
  if ( iter.pLastEntry )
    Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(iter.pActionQueue, iter.pLastEntry);
}
