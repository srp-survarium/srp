Scaleform::GFx::AS2::MovieRoot::ActionEntry *__thiscall Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
        Scaleform::GFx::AS2::MovieRoot::ActionQueueType *this,
        Scaleform::GFx::ActionPriority::Priority prio)
{
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *result; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *pInsertEntry; // edx
  Scaleform::GFx::AS2::MovieRoot::ActionQueueEntry *v5; // ecx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v6; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v7; // esi
  Scaleform::RefCountNTSImpl *pObject; // ecx

  result = this->pFreeEntry;
  if ( result )
  {
    this->pFreeEntry = result->pNextEntry;
    result->pNextEntry = 0;
    --this->FreeEntriesCount;
  }
  else
  {
    v6 = (Scaleform::GFx::AS2::MovieRoot::ActionEntry *)this->pHeap->Alloc(this->pHeap, 68, 0);
    v7 = v6;
    if ( !v6 )
      return 0;
    v6->pCharacter.pObject = 0;
    v6->pActionBuffer.pObject = 0;
    v6->mEventId.Id = 0;
    v6->mEventId.WcharCode = 0;
    v6->mEventId.KeyCode = 0;
    v6->mEventId.AsciiCode = 0;
    v6->mEventId.RollOverCnt = 0;
    v6->mEventId.KeysState.States = 0;
    v6->mEventId.MouseWheelDelta = 0;
    v6->mEventId.ControllerIndex = -1;
    v6->Function.Flags = 0;
    v6->Function.Function = 0;
    v6->Function.pLocalFrame = 0;
    v6->FunctionParams.Data.Data = 0;
    v6->FunctionParams.Data.Size = 0;
    v6->FunctionParams.Data.Policy.Capacity = 0;
    v6->pNextEntry = 0;
    v6->Type = Entry_None;
    pObject = v6->pActionBuffer.pObject;
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
    v7->pActionBuffer.pObject = 0;
    v7->SessionId = 0;
    result = v7;
  }
  pInsertEntry = this->Entries[prio].pInsertEntry;
  v5 = &this->Entries[prio];
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
  result->SessionId = this->CurrentSessionId;
  ++this->ModId;
  return result;
}
