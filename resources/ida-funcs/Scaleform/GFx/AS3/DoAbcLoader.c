void __stdcall Scaleform::GFx::AS3::DoAbcLoader(Scaleform::GFx::LoadProcess *p, const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v3; // eax
  unsigned int Pos; // ecx
  unsigned __int8 *v5; // eax
  int v6; // ebx
  int v7; // edx
  int v8; // eax
  int v9; // ebx
  unsigned int v10; // edi
  unsigned int ASInitActionTagsNum; // ebp
  Scaleform::String *v12; // eax
  Scaleform::String *v13; // ebp
  Scaleform::String *v14; // edi
  void *v15; // esi
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // eax
  unsigned int BytesLeft; // edx
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  unsigned __int8 *pCurrent; // eax
  Scaleform::GFx::ExecuteTag *v20; // esi
  Scaleform::RefCountVImpl *v21; // ecx
  int dataOffset; // [esp+10h] [ebp-20h]
  Scaleform::StringDH name; // [esp+14h] [ebp-1Ch] BYREF
  char buf[20]; // [esp+1Ch] [ebp-14h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v3 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v3 < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
  Pos = pAltStream->Stream.Pos;
  v5 = &pAltStream->Stream.pBuffer[Pos];
  v6 = *((unsigned __int16 *)v5 + 1);
  v7 = v5[1];
  v8 = *v5;
  pAltStream->Stream.Pos = Pos + 4;
  v9 = v8 | ((v7 | (v6 << 8)) << 8);
  Scaleform::StringDH::StringDH(&name, p->pLoadData.pObject->pHeap);
  Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &name);
  dataOffset = pAltStream->Stream.Pos + pAltStream->Stream.FilePos - pAltStream->Stream.DataSize;
  v10 = tagInfo->TagLength + tagInfo->TagDataOffset - dataOffset;
  if ( (p->ParseFlags & 1) != 0 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  DoAbcLoader: flags = 0x%X, name = '%s', dataSize = %d\n",
      v9,
      (const char *)((name.HeapTypeBits & 0xFFFFFFFC) + 8),
      v10);
    Scaleform::GFx::Stream::LogBytes(&pAltStream->Stream, v10);
    Scaleform::GFx::Stream::SetPosition(
      &pAltStream->Stream,
      pAltStream->Stream.Pos + pAltStream->Stream.FilePos - pAltStream->Stream.DataSize - v10);
  }
  if ( (*(_DWORD *)(name.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) == 0 )
  {
    ASInitActionTagsNum = p->ASInitActionTagsNum;
    if ( ASInitActionTagsNum )
    {
      Scaleform::SFsprintf(buf, 0x14u, "%d", ASInitActionTagsNum);
      Scaleform::String::operator=(&name, (const __m128i *)buf);
    }
  }
  v12 = (Scaleform::String *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, v10 + 35, 0);
  v13 = v12;
  if ( v12 )
  {
    v12->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
    v12[1].HeapTypeBits = 1;
    v12->HeapTypeBits = (unsigned int)&Scaleform::GFx::AS3::AbcDataBuffer::`vftable';
    Scaleform::String::String(v12 + 2, &name);
    v13[3].HeapTypeBits = v10;
    LOBYTE(v13[4].pData) = v9;
    v13[5].HeapTypeBits = 0;
    v13[6].HeapTypeBits = 0;
    Scaleform::StringLH::StringLH((Scaleform::StringLH *)&v13[7]);
    v14 = v13;
  }
  else
  {
    v14 = 0;
  }
  Scaleform::String::operator=(
    v14 + 7,
    (const __m128i *)((p->pDataDef_Unsafe->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFC) + 8));
  if ( Scaleform::GFx::Stream::ReadToBuffer(&pAltStream->Stream, (unsigned __int8 *)&v14[8], v14[3].HeapTypeBits) != v14[3].HeapTypeBits )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
      &pAltStream->Stream,
      "Can't read completely ABCData at offset %d",
      tagInfo->TagOffset);
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v14);
    v15 = (void *)(name.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((name.HeapTypeBits & 0xFFFFFFFC) + 4), -1) != 1 )
      return;
    goto LABEL_27;
  }
  v14[5].pData = (Scaleform::String::DataDesc *)p->pLoadData.pObject->SwdHandle;
  v14[6].HeapTypeBits = dataOffset;
  if ( (p->ProcessInfo.Header.SWFFlags & 1) != 0 )
    v14[6].HeapTypeBits += 8;
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
    v20 = (Scaleform::GFx::ExecuteTag *)pCurrent;
  }
  else
  {
    v20 = 0;
  }
  Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v14);
  v21 = (Scaleform::RefCountVImpl *)v20[1].__vftable;
  if ( v21 )
    Scaleform::RefCountImpl::Release(v21);
  v20[1].__vftable = (Scaleform::GFx::ExecuteTag_vtbl *)v14;
  Scaleform::GFx::LoadProcess::AddInitAction(p, 0, v20);
  ++p->ASInitActionTagsNum;
  Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v14);
  v15 = (void *)(name.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((name.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
LABEL_27:
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
}
