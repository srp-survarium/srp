const Scaleform::GFx::AS3::MovieRoot::ActionEntry *__thiscall Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator::getNext(
        Scaleform::GFx::AS3::MovieRoot::ActionQueueIterator *this)
{
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *pActionQueue; // edx
  int ModId; // eax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pRootEntry; // eax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pNextEntry; // eax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pCurEntry; // eax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v7; // edi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry **p_pInsertEntry; // ecx
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *v9; // edx
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v10; // eax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v11; // ecx
  Scaleform::GFx::AS3::MovieRoot::ActionQueueType *v12; // eax
  bool v13; // zf
  Scaleform::GFx::AS3::MovieRoot::ActionQueueEntry *v14; // eax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pLastEntry; // eax

  pActionQueue = this->pActionQueue;
  ModId = pActionQueue->ModId;
  if ( ModId != this->ModId )
  {
    this->ModId = ModId;
    pRootEntry = this->pRootEntry;
    if ( pRootEntry )
      pNextEntry = pRootEntry->pNextEntry;
    else
      pNextEntry = pActionQueue->Entries[this->Level].pActionRoot;
    this->pCurEntry = pNextEntry;
  }
  pCurEntry = this->pCurEntry;
  v7 = pCurEntry;
  if ( pCurEntry )
  {
    p_pInsertEntry = &pActionQueue->Entries[this->Level].pInsertEntry;
    if ( pCurEntry == pActionQueue->Entries[this->Level].pInsertEntry )
    {
      if ( pCurEntry->pNextEntry )
        *p_pInsertEntry = pCurEntry->pNextEntry;
      else
        *p_pInsertEntry = this->pRootEntry;
    }
    v9 = this->pActionQueue;
    v10 = this->pCurEntry;
    if ( v10 == v9->Entries[this->Level].pActionRoot )
    {
      v9->Entries[this->Level].pActionRoot = v10->pNextEntry;
    }
    else
    {
      v11 = this->pRootEntry;
      if ( v11 )
        v11->pNextEntry = v10->pNextEntry;
    }
    this->pCurEntry = this->pCurEntry->pNextEntry;
  }
  v12 = this->pActionQueue;
  v13 = v12->Entries[this->Level].pActionRoot == 0;
  v14 = &v12->Entries[this->Level];
  if ( v13 )
  {
    v14->pInsertEntry = 0;
    this->pActionQueue->Entries[this->Level].pLastEntry = 0;
  }
  pLastEntry = this->pLastEntry;
  if ( pLastEntry )
  {
    pLastEntry->pNextEntry = 0;
    Scaleform::GFx::AS3::MovieRoot::ActionQueueType::AddToFreeList(this->pActionQueue, this->pLastEntry);
    this->ModId = ++this->pActionQueue->ModId;
  }
  this->pLastEntry = v7;
  return v7;
}
