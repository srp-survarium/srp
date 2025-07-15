Scaleform::GFx::AS3::MovieRoot::ActionEntry *__thiscall Scaleform::GFx::AS3::MovieRoot::ActionQueueType::InsertEntry(
        Scaleform::GFx::AS3::MovieRoot::ActionQueueType *this,
        Scaleform::GFx::AS3::MovieRoot::ActionLevel lvl)
{
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *result; // eax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *pInsertEntry; // edx
  Scaleform::GFx::AS3::MovieRoot::ActionQueueEntry *v5; // ecx

  result = Scaleform::GFx::AS3::MovieRoot::ActionQueueType::GetNewEntry(this);
  pInsertEntry = this->Entries[lvl].pInsertEntry;
  v5 = &this->Entries[lvl];
  if ( pInsertEntry )
  {
    result->pNextEntry = pInsertEntry->pNextEntry;
    v5->pInsertEntry->pNextEntry = result;
  }
  else
  {
    result->pNextEntry = v5->pActionRoot;
    v5->pActionRoot = result;
  }
  v5->pInsertEntry = result;
  if ( !result->pNextEntry )
    v5->pLastEntry = result;
  ++this->ModId;
  return result;
}
