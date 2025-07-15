const Scaleform::GFx::AS2::MovieRoot::ActionEntry *__thiscall Scaleform::GFx::AS2::MovieRoot::ActionQueueSessionIterator::getNext(
        Scaleform::GFx::AS2::MovieRoot::ActionQueueSessionIterator *this)
{
  Scaleform::GFx::AS2::MovieRoot::ActionQueueType *pActionQueue; // edx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *pActionRoot; // esi
  int CurrentPrio; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v5; // ecx
  int v6; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry **p_pInsertEntry; // eax

  pActionQueue = this->pActionQueue;
  if ( pActionQueue->ModId != this->ModId )
  {
    this->CurrentPrio = 0;
    this->ModId = pActionQueue->ModId;
  }
  pActionRoot = 0;
  if ( this->CurrentPrio < 6 )
  {
    while ( 1 )
    {
      CurrentPrio = this->CurrentPrio;
      pActionRoot = pActionQueue->Entries[CurrentPrio].pActionRoot;
      v5 = 0;
      if ( pActionRoot )
        break;
LABEL_7:
      v6 = CurrentPrio + 1;
      this->CurrentPrio = v6;
      if ( v6 >= 6 )
        goto LABEL_19;
    }
    while ( pActionRoot->SessionId != this->SessionId )
    {
      v5 = pActionRoot;
      pActionRoot = pActionRoot->pNextEntry;
      if ( !pActionRoot )
        goto LABEL_7;
    }
    if ( v5 )
      v5->pNextEntry = pActionRoot->pNextEntry;
    else
      pActionQueue->Entries[CurrentPrio].pActionRoot = pActionRoot->pNextEntry;
    if ( !pActionRoot->pNextEntry )
      this->pActionQueue->Entries[this->CurrentPrio].pLastEntry = v5;
    p_pInsertEntry = &this->pActionQueue->Entries[this->CurrentPrio].pInsertEntry;
    if ( pActionRoot == *p_pInsertEntry )
    {
      if ( pActionRoot->pNextEntry )
        *p_pInsertEntry = pActionRoot->pNextEntry;
      else
        *p_pInsertEntry = v5;
    }
    pActionRoot->pNextEntry = 0;
  }
LABEL_19:
  if ( this->pLastEntry )
    Scaleform::GFx::AS2::MovieRoot::ActionQueueType::AddToFreeList(this->pActionQueue, this->pLastEntry);
  this->pLastEntry = pActionRoot;
  return pActionRoot;
}
