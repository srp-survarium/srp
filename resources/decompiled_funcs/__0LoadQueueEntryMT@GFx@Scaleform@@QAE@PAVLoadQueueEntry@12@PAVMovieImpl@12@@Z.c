void __thiscall Scaleform::GFx::LoadQueueEntryMT::LoadQueueEntryMT(
        Scaleform::GFx::LoadQueueEntryMT *this,
        Scaleform::GFx::LoadQueueEntry *pqueueEntry,
        Scaleform::GFx::MovieImpl *pmovieRoot)
{
  this->pNext = 0;
  this->pPrev = 0;
  this->__vftable = (Scaleform::GFx::LoadQueueEntryMT_vtbl *)&Scaleform::GFx::LoadQueueEntryMT::`vftable';
  this->pMovieImpl = pmovieRoot;
  this->pQueueEntry = pqueueEntry;
}
