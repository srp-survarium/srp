char __thiscall Scaleform::GFx::LoadQueueEntryMT_LoadBinary::LoadFinished(
        Scaleform::GFx::LoadQueueEntryMT_LoadBinary *this)
{
  Scaleform::GFx::LoadBinaryTask *pObject; // ecx
  char v3; // al
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // edx
  BOOL succeeded; // [esp+Ch] [ebp-14h] BYREF
  int fileLen; // [esp+10h] [ebp-10h] BYREF
  Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> data; // [esp+14h] [ebp-Ch] BYREF

  pObject = this->pTask.pObject;
  memset((void *)&data, 0, sizeof(data));
  v3 = Scaleform::GFx::LoadBinaryTask::GetData(pObject, &data, &fileLen, (bool *)&succeeded);
  pQueueEntry = this->pQueueEntry;
  if ( pQueueEntry->Canceled )
  {
    if ( v3 )
      goto LABEL_9;
  }
  else if ( v3 )
  {
    this->pMovieImpl->pASMovieRoot.pObject->ProcessLoadBinaryMT(
      this->pMovieImpl->pASMovieRoot.pObject,
      pQueueEntry,
      this->pLoadStates.pObject,
      &data,
      fileLen,
      succeeded);
LABEL_9:
    if ( data.Data.Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, data.Data.Data);
    return 1;
  }
  if ( data.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, data.Data.Data);
  return 0;
}
