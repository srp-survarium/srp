void __stdcall Scaleform::GFx::GFx_ImportLoader(Scaleform::String p, const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *pData; // ebp
  Scaleform::GFx::Stream *Size; // esi
  const Scaleform::GFx::TagInfo *v4; // ebx
  int v5; // ecx
  unsigned int Pos; // eax
  unsigned __int16 v7; // dx
  const Scaleform::GFx::TagInfo *v8; // edi
  const char *v9; // ecx
  Scaleform::GFx::ImportData *v10; // ebx
  int v11; // eax
  unsigned int v12; // eax
  unsigned __int16 v13; // di
  void *v14; // edi
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx
  unsigned int BytesLeft; // edx
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  unsigned __int8 *pCurrent; // eax
  unsigned __int8 *v19; // edi
  Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0> > *p_Data; // ebp
  unsigned int v21; // esi
  Scaleform::GFx::ExecuteTag **Data; // eax
  unsigned __int8 **v23; // esi
  void *v24; // esi
  Scaleform::String pstr; // [esp+10h] [ebp-Ch] BYREF
  Scaleform::GFx::ResourceHandle result; // [esp+14h] [ebp-8h] BYREF

  pData = (Scaleform::GFx::LoadProcess *)p.pData;
  Size = (Scaleform::GFx::Stream *)p.pData[71].Size;
  if ( !Size )
    Size = (Scaleform::GFx::Stream *)&p.pData[4];
  Scaleform::String::String(&pstr);
  Scaleform::GFx::Stream::ReadString(Size, &pstr);
  v4 = tagInfo;
  if ( tagInfo->TagType == Tag_Import2 )
    Scaleform::GFx::LoadProcess::ReadU16(pData);
  v5 = Size->DataSize - Size->Pos;
  Size->UnusedBits = 0;
  if ( v5 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(Size, 2);
  Pos = Size->Pos;
  v7 = *(_WORD *)&Size->pBuffer[Pos];
  Size->Pos = Pos + 2;
  v8 = (const Scaleform::GFx::TagInfo *)v7;
  v9 = "  importAssets: SourceUrl = %s, count = %d\n";
  if ( v4->TagType == Tag_Import2 )
    v9 = "  importAssets2: SourceUrl = %s, count = %d\n";
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
    &pData->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    v9,
    (pstr.HeapTypeBits & 0xFFFFFFFC) + 8,
    v7);
  v10 = (Scaleform::GFx::ImportData *)Scaleform::GFx::LoadProcess::AllocMovieDefClass<Scaleform::GFx::ImportData>(pData);
  v10->Frame = pData->pLoadData.pObject->LoadingFrame;
  Scaleform::String::operator=(&v10->SourceUrl, &pstr);
  if ( (int)v8 > 0 )
  {
    tagInfo = v8;
    do
    {
      Scaleform::String::String(&p);
      v11 = Size->DataSize - Size->Pos;
      Size->UnusedBits = 0;
      if ( v11 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(Size, 2);
      v12 = Size->Pos;
      v13 = *(_WORD *)&Size->pBuffer[v12];
      Size->Pos = v12 + 2;
      Scaleform::GFx::Stream::ReadString(Size, &p);
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
        &pData->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "  import: id = %d, name = %s\n",
        v13,
        (const char *)((p.HeapTypeBits & 0xFFFFFFFC) + 8));
      Scaleform::GFx::MovieDataDef::LoadTaskData::AddNewResourceHandle(
        pData->pLoadData.pObject,
        &result,
        (Scaleform::GFx::ResourceId)v13);
      Scaleform::GFx::ImportData::AddSymbol(
        v10,
        (const __m128i *)((p.HeapTypeBits & 0xFFFFFFFC) + 8),
        v13,
        result.BindIndex);
      if ( result.HType == RH_Pointer && result.BindIndex )
        Scaleform::GFx::Resource::Release(result.pResource);
      v14 = (void *)(p.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((p.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
      tagInfo = (const Scaleform::GFx::TagInfo *)((char *)tagInfo - 1);
    }
    while ( tagInfo );
  }
  Scaleform::GFx::LoadProcess::AddImportData(pData, v10);
  pObject = pData->pLoadData.pObject;
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
  v19 = 0;
  if ( pCurrent )
  {
    *((_DWORD *)pCurrent + 1) = 0;
    *(_DWORD *)pCurrent = &Scaleform::GFx::GFxInitImportActions::`vftable';
    v19 = pCurrent;
  }
  p_Data = &pData->InitActionTags.Data;
  *((_DWORD *)v19 + 1) = v10->ImportIndex;
  v21 = p_Data->Size + 1;
  if ( v21 >= p_Data->Size )
  {
    if ( v21 >= p_Data->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>::Reserve(
        p_Data,
        p_Data,
        v21 + (v21 >> 2));
  }
  else if ( v21 < p_Data->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>::Reserve(
      p_Data,
      p_Data,
      p_Data->Size + 1);
  }
  Data = p_Data->Data;
  p_Data->Size = v21;
  v23 = (unsigned __int8 **)&Data[v21 - 1];
  if ( v23 )
    *v23 = v19;
  v24 = (void *)(pstr.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((pstr.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v24);
}
