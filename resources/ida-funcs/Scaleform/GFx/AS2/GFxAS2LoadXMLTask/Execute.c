void __thiscall Scaleform::GFx::AS2::GFxAS2LoadXMLTask::Execute(Scaleform::GFx::AS2::GFxAS2LoadXMLTask *this)
{
  void *v2; // edi
  void *v3; // esi
  Scaleform::String pdest; // [esp+Ch] [ebp-14h] BYREF
  Scaleform::String v5; // [esp+10h] [ebp-10h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [esp+14h] [ebp-Ch] BYREF

  loc.Use = File_LoadXML;
  Scaleform::String::String(&loc.FileName, &this->Url);
  Scaleform::String::String(&loc.ParentPath, &this->Level0Path);
  Scaleform::String::String(&pdest);
  Scaleform::GFx::LoadStates::BuildURL(this->pLoadStates.pObject, &pdest, &loc);
  Scaleform::String::String(&v5, (const __m128i *)((pdest.HeapTypeBits & 0xFFFFFFFC) + 8));
  this->pXMLLoader.pObject->Load(
    this->pXMLLoader.pObject,
    &v5,
    this->pLoadStates.pObject->pBindStates.pObject->pFileOpener.pObject);
  v2 = (void *)(v5.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v5.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v2);
  InterlockedExchange((volatile LONG *)&this->Done, 1);
  v3 = (void *)(pdest.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((pdest.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
  Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&loc);
}
