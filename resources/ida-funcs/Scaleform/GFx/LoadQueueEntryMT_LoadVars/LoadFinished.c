char __thiscall Scaleform::GFx::LoadQueueEntryMT_LoadVars::LoadFinished(
        Scaleform::GFx::LoadQueueEntryMT_LoadVars *this)
{
  Scaleform::GFx::LoadVarsTask *pObject; // esi
  unsigned int FileLen; // edx
  char v4; // cl
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // eax
  void *v6; // esi
  void *v8; // esi
  void *v9; // esi
  Scaleform::String data; // [esp+14h] [ebp-8h] BYREF
  unsigned int succeeded; // [esp+18h] [ebp-4h]

  Scaleform::String::String(&data);
  pObject = this->pTask.pObject;
  if ( pObject->Done == 1 )
  {
    Scaleform::String::operator=(&data, &pObject->Data);
    FileLen = pObject->FileLen;
    LOBYTE(succeeded) = pObject->Succeeded;
    v4 = 1;
  }
  else
  {
    FileLen = succeeded;
    v4 = 0;
  }
  pQueueEntry = this->pQueueEntry;
  if ( pQueueEntry->Canceled )
  {
    if ( v4 )
    {
      v6 = (void *)(data.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((data.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
        return 1;
      }
      return 1;
    }
  }
  else if ( v4 )
  {
    this->pMovieImpl->pASMovieRoot.pObject->ProcessLoadVarsMT(
      this->pMovieImpl->pASMovieRoot.pObject,
      pQueueEntry,
      this->pLoadStates.pObject,
      &data,
      FileLen,
      succeeded);
    v9 = (void *)(data.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((data.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
    return 1;
  }
  v8 = (void *)(data.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((data.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
  return 0;
}
