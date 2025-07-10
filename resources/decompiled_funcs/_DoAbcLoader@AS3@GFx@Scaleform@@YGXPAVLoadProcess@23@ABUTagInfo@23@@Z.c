void __stdcall Scaleform::GFx::AS3::DoAbcLoader(Scaleform::GFx::LoadProcess *p, const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v3; // eax
  unsigned int Pos; // ecx
  unsigned __int8 v5; // al
  unsigned __int8 v6; // bl
  int v7; // edi
  unsigned int ASInitActionTagsNum; // ebp
  Scaleform::StringLH *v9; // ebp
  Scaleform::StringLH *v10; // edi
  void *v11; // esi
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // eax
  unsigned int BytesLeft; // edx
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  unsigned __int8 *pCurrent; // eax
  Scaleform::GFx::ExecuteTag *v16; // esi
  Scaleform::RefCountVImpl *v17; // ecx
  Scaleform::StringDH name; // [esp+10h] [ebp-1Ch] BYREF
  char buf[20]; // [esp+18h] [ebp-14h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v3 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v3 < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
  Pos = pAltStream->Stream.Pos;
  v5 = pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 4;
  v6 = v5;
  Scaleform::StringDH::StringDH(&name, p->pLoadData.pObject->pHeap);
  Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &name);
  v7 = tagInfo->TagLength
     + tagInfo->TagDataOffset
     - (pAltStream->Stream.Pos
      + pAltStream->Stream.FilePos
      - pAltStream->Stream.DataSize);
  if ( (*(_DWORD *)(name.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) == 0 )
  {
    ASInitActionTagsNum = p->ASInitActionTagsNum;
    if ( ASInitActionTagsNum )
    {
      Scaleform::SFsprintf(buf, 0x14u, "%d", ASInitActionTagsNum);
      Scaleform::String::operator=(&name, buf);
    }
  }
  v9 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, v7 + 27, 0);
  if ( v9 )
  {
    v9->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
    v9[1].HeapTypeBits = 1;
    v9->HeapTypeBits = (unsigned int)&Scaleform::GFx::AS3::AbcDataBuffer::`vftable';
    Scaleform::String::String(v9 + 2, &name);
    v9[3].HeapTypeBits = v7;
    LOBYTE(v9[4].pData) = v6;
    Scaleform::StringLH::StringLH(v9 + 5);
    v10 = v9;
  }
  else
  {
    v10 = 0;
  }
  Scaleform::String::operator=(
    v10 + 5,
    (char *)((p->pDataDef_Unsafe->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFC) + 8));
  if ( Scaleform::GFx::Stream::ReadToBuffer(&pAltStream->Stream, (unsigned __int8 *)&v10[6], v10[3].HeapTypeBits) != v10[3].HeapTypeBits )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
      &pAltStream->Stream,
      "Can't read completely ABCData at offset %d",
      tagInfo->TagOffset);
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v10);
    v11 = (void *)(name.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((name.HeapTypeBits & 0xFFFFFFFC) + 4), -1) != 1 )
      return;
    goto LABEL_23;
  }
  pObject = p->pLoadData.pObject;
  BytesLeft = pObject->TagMemAllocator.BytesLeft;
  p_TagMemAllocator = &pObject->TagMemAllocator;
  if ( BytesLeft < 8 )
  {
    pCurrent = Scaleform::GFx::DataAllocator::OverflowAlloc(p_TagMemAllocator, 8u);
  }
  else
  {
    pCurrent = p_TagMemAllocator->pCurrent;
    p_TagMemAllocator->pCurrent += 8;
    p_TagMemAllocator->BytesLeft = BytesLeft - 8;
  }
  if ( pCurrent )
  {
    *(_DWORD *)pCurrent = &Scaleform::GFx::AS3::DoAbc::`vftable';
    *((_DWORD *)pCurrent + 1) = 0;
    v16 = (Scaleform::GFx::ExecuteTag *)pCurrent;
  }
  else
  {
    v16 = 0;
  }
  Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v10);
  v17 = (Scaleform::RefCountVImpl *)v16[1].__vftable;
  if ( v17 )
    Scaleform::RefCountImpl::Release(v17);
  v16[1].__vftable = (Scaleform::GFx::ExecuteTag_vtbl *)v10;
  Scaleform::GFx::LoadProcess::AddInitAction(p, 0, v16);
  ++p->ASInitActionTagsNum;
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v10);
  v11 = (void *)(name.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((name.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
LABEL_23:
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v11);
}
