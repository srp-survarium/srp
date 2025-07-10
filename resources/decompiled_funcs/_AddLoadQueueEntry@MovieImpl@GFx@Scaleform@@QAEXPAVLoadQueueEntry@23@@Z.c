void __thiscall Scaleform::GFx::MovieImpl::AddLoadQueueEntry(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::LoadQueueEntry *pentry)
{
  Scaleform::GFx::LoadQueueEntry *pLoadQueueHead; // eax

  pentry->EntryTime = ++this->LastLoadQueueEntryCnt;
  pLoadQueueHead = this->pLoadQueueHead;
  if ( pLoadQueueHead )
  {
    for ( ; pLoadQueueHead->pNext; pLoadQueueHead = pLoadQueueHead->pNext )
      ;
    pLoadQueueHead->pNext = pentry;
  }
  else
  {
    this->pLoadQueueHead = pentry;
  }
}
