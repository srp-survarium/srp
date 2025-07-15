void __thiscall Scaleform::GFx::AS2::MovieRoot::ActionQueueType::Clear(
        Scaleform::GFx::AS2::MovieRoot::ActionQueueType *this)
{
  Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator v1; // [esp+0h] [ebp-10h] BYREF

  v1.pActionQueue = this;
  v1.ModId = 0;
  v1.CurrentPrio = 0;
  v1.pLastEntry = 0;
  while ( Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator::getNext(&v1) )
    ;
  if ( v1.pLastEntry )
    Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(v1.pActionQueue, v1.pLastEntry);
}
