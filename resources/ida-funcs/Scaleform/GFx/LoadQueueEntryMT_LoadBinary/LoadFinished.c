char __thiscall Scaleform::GFx::LoadQueueEntryMT_LoadBinary::LoadFinished(
        Scaleform::GFx::LoadQueueEntryMT_LoadBinary *this)
{
  Scaleform::GFx::LoadBinaryTask *pObject; // ecx
  char Data; // al
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // edx
  BOOL v6; // [esp+Ch] [ebp-14h] BYREF
  unsigned int v7; // [esp+10h] [ebp-10h] BYREF
  Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> v8; // [esp+14h] [ebp-Ch] BYREF

  pObject = this->pTask.pObject;
  memset(&v8, 0, sizeof(v8));
  Data = Scaleform::GFx::LoadBinaryTask::GetData(pObject, &v8, (int *)&v7, (bool *)&v6);
  pQueueEntry = this->pQueueEntry;
  if ( pQueueEntry->Canceled )
  {
    if ( Data )
      goto LABEL_9;
  }
  else if ( Data )
  {
    this->pMovieImpl->pASMovieRoot.pObject->ProcessLoadBinaryMT(
      this->pMovieImpl->pASMovieRoot.pObject,
      pQueueEntry,
      this->pLoadStates.pObject,
      (const Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)&v8,
      v7,
      v6);
LABEL_9:
    if ( v8.Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8.Data);
    return 1;
  }
  if ( v8.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8.Data);
  return 0;
}
