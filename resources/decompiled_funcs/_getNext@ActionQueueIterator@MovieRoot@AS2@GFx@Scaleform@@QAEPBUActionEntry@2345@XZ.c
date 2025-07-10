const Scaleform::GFx::AS2::MovieRoot::ActionEntry *__thiscall Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator::getNext(
        Scaleform::GFx::AS2::MovieRoot::ActionQueueIterator *this)
{
  Scaleform::GFx::AS2::MovieRoot::ActionQueueType *pActionQueue; // ecx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *pActionRoot; // edi
  int v4; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionQueueType *v5; // eax
  bool v6; // zf
  Scaleform::GFx::AS2::MovieRoot::ActionQueueEntry *v7; // eax

  pActionQueue = this->pActionQueue;
  if ( pActionQueue->ModId != this->ModId )
  {
    this->CurrentPrio = 0;
    this->ModId = pActionQueue->ModId;
  }
  pActionRoot = pActionQueue->Entries[this->CurrentPrio].pActionRoot;
  if ( pActionRoot )
  {
LABEL_8:
    if ( pActionRoot == pActionQueue->Entries[this->CurrentPrio].pInsertEntry )
      pActionQueue->Entries[this->CurrentPrio].pInsertEntry = pActionRoot->pNextEntry;
    this->pActionQueue->Entries[this->CurrentPrio].pActionRoot = pActionRoot->pNextEntry;
    pActionRoot->pNextEntry = 0;
  }
  else
  {
    while ( 1 )
    {
      v4 = ++this->CurrentPrio;
      if ( v4 >= 6 )
        break;
      pActionRoot = pActionQueue->Entries[v4].pActionRoot;
      if ( pActionRoot )
        goto LABEL_8;
    }
  }
  v5 = this->pActionQueue;
  v6 = v5->Entries[this->CurrentPrio].pActionRoot == 0;
  v7 = &v5->Entries[this->CurrentPrio];
  if ( v6 )
  {
    v7->pInsertEntry = 0;
    this->pActionQueue->Entries[this->CurrentPrio].pLastEntry = 0;
  }
  if ( this->pLastEntry )
    Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(this->pActionQueue, this->pLastEntry);
  this->pLastEntry = pActionRoot;
  return pActionRoot;
}
