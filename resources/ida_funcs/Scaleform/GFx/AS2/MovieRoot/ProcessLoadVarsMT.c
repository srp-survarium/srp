void __thiscall Scaleform::GFx::AS2::MovieRoot::ProcessLoadVarsMT(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::LoadQueueEntry *p_entry,
        Scaleform::GFx::LoadStates *pls,
        const Scaleform::String *data,
        unsigned int fileLen,
        bool succeeded)
{
  void *v7; // esi
  Scaleform::String decodedData; // [esp+4h] [ebp-4h] BYREF

  Scaleform::String::String(&decodedData);
  Scaleform::GFx::ASUtils::Unescape(
    (const char *)((data->HeapTypeBits & 0xFFFFFFFC) + 8),
    *(_DWORD *)(data->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
    &decodedData);
  Scaleform::GFx::AS2::MovieRoot::DoProcessLoadVars(this, p_entry, pls, &decodedData, fileLen, succeeded);
  v7 = (void *)(decodedData.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((decodedData.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
}
