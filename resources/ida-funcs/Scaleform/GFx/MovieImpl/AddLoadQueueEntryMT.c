void __thiscall Scaleform::GFx::MovieImpl::AddLoadQueueEntryMT(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::LoadQueueEntryMT *pentryMT)
{
  Scaleform::GFx::LoadQueueEntryMT *pLoadQueueMTHead; // eax

  pentryMT->pQueueEntry->EntryTime = ++this->LastLoadQueueEntryCnt;
  pLoadQueueMTHead = this->pLoadQueueMTHead;
  if ( pLoadQueueMTHead )
  {
    for ( ; pLoadQueueMTHead->pNext; pLoadQueueMTHead = pLoadQueueMTHead->pNext )
      ;
    pLoadQueueMTHead->pNext = pentryMT;
    pentryMT->pPrev = pLoadQueueMTHead;
  }
  else
  {
    this->pLoadQueueMTHead = pentryMT;
  }
}
