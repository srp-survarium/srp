void __thiscall Scaleform::GFx::LoadProcess::ReportProgress(
        Scaleform::GFx::LoadProcess *this,
        const Scaleform::String *fileURL,
        const Scaleform::GFx::TagInfo *tagInfo,
        BOOL calledFromDefSprite)
{
  Scaleform::GFx::LoadStates *pObject; // eax
  Scaleform::GFx::ProgressHandler *v5; // esi
  int TagLength; // ebx
  int TagOffset; // ebp
  int TagDataOffset; // edi
  void *v9; // esi
  Scaleform::String v10; // [esp+8h] [ebp-14h] BYREF
  const Scaleform::GFx::TagInfo *v11; // [esp+Ch] [ebp-10h]
  int v12; // [esp+10h] [ebp-Ch]
  int v13; // [esp+14h] [ebp-8h]
  int v14; // [esp+18h] [ebp-4h]
  const Scaleform::GFx::TagInfo *tagInfoa; // [esp+24h] [ebp+8h]

  pObject = this->pLoadStates.pObject;
  if ( pObject->pProgressHandler.pObject )
  {
    v5 = pObject->pProgressHandler.pObject;
    TagLength = tagInfo->TagLength;
    TagOffset = tagInfo->TagOffset;
    TagDataOffset = tagInfo->TagDataOffset;
    tagInfoa = (const Scaleform::GFx::TagInfo *)tagInfo->TagType;
    Scaleform::String::String(&v10, fileURL);
    v11 = tagInfoa;
    v12 = TagOffset;
    v13 = TagLength;
    v14 = TagDataOffset;
    v5->LoadTagUpdate(v5, (const Scaleform::GFx::ProgressHandler::TagInfo *)&v10, calledFromDefSprite);
    v9 = (void *)(v10.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((v10.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v9);
  }
}
