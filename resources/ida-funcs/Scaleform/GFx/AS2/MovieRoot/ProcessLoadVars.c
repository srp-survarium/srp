void __thiscall Scaleform::GFx::AS2::MovieRoot::ProcessLoadVars(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::String p_entry,
        Scaleform::GFx::LoadStates *pls)
{
  Scaleform::GFx::LoadQueueEntry *pData; // ebp
  Scaleform::String *p_RefCount; // esi
  int Length; // eax
  Scaleform::GFx::LoadStates *v7; // ebx
  Scaleform::File *v8; // eax
  Scaleform::RefCountVImpl *v9; // esi
  void *v10; // esi
  void *v11; // esi
  void *v12; // esi
  char v13; // [esp+0h] [ebp-28h]
  Scaleform::String data; // [esp+10h] [ebp-18h] BYREF
  int fileLen; // [esp+14h] [ebp-14h] BYREF
  Scaleform::String level0Path; // [esp+18h] [ebp-10h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [esp+1Ch] [ebp-Ch] BYREF

  Scaleform::String::String(&level0Path);
  Scaleform::GFx::AS2::MovieRoot::GetLevel0Path(this, &level0Path);
  Scaleform::String::String(&data);
  pData = (Scaleform::GFx::LoadQueueEntry *)p_entry.pData;
  p_RefCount = (Scaleform::String *)&p_entry.pData[1].RefCount;
  fileLen = 0;
  Length = Scaleform::String::GetLength((Scaleform::String *)&p_entry.pData[1].RefCount);
  v7 = pls;
  if ( Length )
  {
    loc.Use = File_LoadVars;
    Scaleform::String::String(&loc.FileName, p_RefCount);
    Scaleform::String::String(&loc.ParentPath, &level0Path);
    Scaleform::String::String(&p_entry);
    Scaleform::GFx::LoadStates::BuildURL(v7, &p_entry, &loc);
    v8 = Scaleform::GFx::LoadStates::OpenFile(v7, (const char *)((p_entry.HeapTypeBits & 0xFFFFFFFC) + 8), 0);
    v9 = (Scaleform::RefCountVImpl *)v8;
    if ( v8 )
    {
      if ( pData[1].QuietOpen == 6 )
      {
        if ( !Scaleform::GFx::MovieImpl::ReadTextData((int)v8, &data, (Scaleform::String)v8, &fileLen, 1, v13) )
          Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&pData[1].QuietOpen);
      }
      else
      {
        Scaleform::GFx::MovieImpl::ReadTextData((int)v8, &data, (Scaleform::String)v8, &fileLen, 1, v13);
      }
      Scaleform::RefCountImpl::Release(v9);
    }
    v10 = (void *)(p_entry.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((p_entry.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v10);
    Scaleform::GFx::URLBuilder::LocationInfo::~LocationInfo(&loc);
  }
  Scaleform::GFx::AS2::MovieRoot::DoProcessLoadVars(this, pData, v7, &data, fileLen, 1);
  v11 = (void *)(data.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((data.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
  v12 = (void *)(level0Path.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((level0Path.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
}
