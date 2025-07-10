void __thiscall Scaleform::GFx::LoadVarsTask::Execute(Scaleform::GFx::LoadVarsTask *this)
{
  Scaleform::File *v2; // eax
  Scaleform::RefCountVImpl *v3; // edi
  void *v4; // esi
  char v5; // [esp+0h] [ebp-18h]
  Scaleform::String fileName; // [esp+8h] [ebp-10h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [esp+Ch] [ebp-Ch] BYREF

  loc.Use = File_LoadVars;
  Scaleform::String::String(&loc.FileName, &this->Url);
  Scaleform::String::String(&loc.ParentPath, &this->Level0Path);
  Scaleform::String::String(&fileName);
  Scaleform::GFx::LoadStates::BuildURL(this->pLoadStates.pObject, &fileName, &loc);
  v2 = Scaleform::GFx::LoadStates::OpenFile(
         this->pLoadStates.pObject,
         (const char *)((fileName.HeapTypeBits & 0xFFFFFFFC) + 8),
         0);
  v3 = (Scaleform::RefCountVImpl *)v2;
  if ( v2 )
    this->Succeeded = Scaleform::GFx::MovieImpl::ReadTextData(
                        (int)this,
                        &this->Data,
                        (Scaleform::String)v2,
                        &this->FileLen,
                        0,
                        v5);
  else
    this->Succeeded = 0;
  InterlockedExchange((volatile LONG *)&this->Done, 1);
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v4 = (void *)(fileName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((fileName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v4);
  Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&loc);
}
