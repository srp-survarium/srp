Scaleform::GFx::AS2::MovieRoot::ActionEntry *__thiscall Scaleform::GFx::AS2::MovieRoot::ActionQueueType::FindEntry(
        Scaleform::GFx::AS2::MovieRoot::ActionQueueType *this,
        Scaleform::GFx::ActionPriority::Priority prio,
        const Scaleform::GFx::AS2::MovieRoot::ActionEntry *entry)
{
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *result; // eax
  unsigned int Id; // edx

  result = this->Entries[prio].pActionRoot;
  if ( !result )
    return 0;
  while ( 1 )
  {
    if ( result->Type == entry->Type
      && result->pActionBuffer.pObject == entry->pActionBuffer.pObject
      && result->pCharacter.pObject == entry->pCharacter.pObject
      && result->CFunction == entry->CFunction
      && result->Function.Function == entry->Function.Function )
    {
      Id = result->mEventId.Id;
      if ( Id == entry->mEventId.Id
        && (((unsigned int)&loc_20000 & Id) == 0 || result->mEventId.KeyCode == entry->mEventId.KeyCode) )
      {
        break;
      }
    }
    result = result->pNextEntry;
    if ( !result )
      return 0;
  }
  return result;
}
