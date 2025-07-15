void __stdcall Scaleform::GFx::GFx_ImportLoader(Scaleform::String p, const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *pData; // ebp
  Scaleform::GFx::SWFProcessInfo *Size; // esi
  const Scaleform::GFx::TagInfo *v4; // ebx
  int v5; // ecx
  unsigned int Pos; // eax
  unsigned __int16 v7; // dx
  const Scaleform::GFx::TagInfo *v8; // edi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v9; // ecx
  Scaleform::GFx::ImportData *v10; // ebx
  int v11; // eax
  unsigned int v12; // eax
  unsigned __int16 v13; // di
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v14; // ecx
  void *v15; // edi
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx
  unsigned int BytesLeft; // edx
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  unsigned __int8 *pCurrent; // eax
  unsigned __int8 *v20; // edi
  Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0> > *p_Data; // ebp
  unsigned int v22; // esi
  Scaleform::GFx::ExecuteTag **Data; // eax
  unsigned __int8 **v24; // esi
  void *v25; // esi
  Scaleform::String sourceUrl; // [esp+10h] [ebp-Ch] BYREF
  Scaleform::GFx::ResourceHandle rh; // [esp+14h] [ebp-8h] BYREF

  pData = (Scaleform::GFx::LoadProcess *)p.pData;
  Size = (Scaleform::GFx::SWFProcessInfo *)p.pData[71].Size;
  if ( !Size )
    Size = (Scaleform::GFx::SWFProcessInfo *)&p.pData[4];
  Scaleform::String::String(&sourceUrl);
  Scaleform::GFx::Stream::ReadString(&Size->Stream, &sourceUrl);
  v4 = tagInfo;
  if ( tagInfo->TagType == Tag_Import2 )
    Scaleform::GFx::LoadProcess::ReadU16(pData);
  v5 = Size->Stream.DataSize - Size->Stream.Pos;
  Size->Stream.UnusedBits = 0;
  if ( v5 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&Size->Stream, 2);
  Pos = Size->Stream.Pos;
  v7 = *(_WORD *)&Size->Stream.pBuffer[Pos];
  Size->Stream.Pos = Pos + 2;
  v8 = (const Scaleform::GFx::TagInfo *)v7;
  v9 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)"  importAssets: SourceUrl = %s, count = %d\n";
  if ( v4->TagType == Tag_Import2 )
    v9 = &stru_855944;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v9);
  v10 = (Scaleform::GFx::ImportData *)Scaleform::GFx::LoadProcess::AllocMovieDefClass<Scaleform::GFx::ImportData>(pData);
  v10->Frame = pData->pLoadData.pObject->LoadingFrame;
  Scaleform::String::operator=(&v10->SourceUrl, &sourceUrl);
  if ( (int)v8 > 0 )
  {
    tagInfo = v8;
    do
    {
      Scaleform::String::String(&p);
      v11 = Size->Stream.DataSize - Size->Stream.Pos;
      Size->Stream.UnusedBits = 0;
      if ( v11 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&Size->Stream, 2);
      v12 = Size->Stream.Pos;
      v13 = *(_WORD *)&Size->Stream.pBuffer[v12];
      Size->Stream.Pos = v12 + 2;
      Scaleform::GFx::Stream::ReadString(&Size->Stream, &p);
      Scaleform::Render::JPEG::JPEGRwSource::TermSource(v14);
      Scaleform::GFx::MovieDataDef::LoadTaskData::AddNewResourceHandle(
        pData->pLoadData.pObject,
        &rh,
        (Scaleform::GFx::ResourceId)v13);
      Scaleform::GFx::ImportData::AddSymbol(v10, (char *)((p.HeapTypeBits & 0xFFFFFFFC) + 8), v13, rh.BindIndex);
      if ( rh.HType == RH_Pointer && rh.BindIndex )
        Scaleform::GFx::Resource::Release(rh.pResource);
      v15 = (void *)(p.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((p.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
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
    pCurrent = (unsigned __int8 *)Scaleform::GFx::DataAllocator::OverflowAlloc(p_TagMemAllocator, 8u);
  }
  else
  {
    pCurrent = p_TagMemAllocator->pCurrent;
    p_TagMemAllocator->pCurrent += 8;
    p_TagMemAllocator->BytesLeft = BytesLeft - 8;
  }
  v20 = 0;
  if ( pCurrent )
  {
    *((_DWORD *)pCurrent + 1) = 0;
    *(_DWORD *)pCurrent = &Scaleform::GFx::GFxInitImportActions::`vftable';
    v20 = pCurrent;
  }
  p_Data = &pData->InitActionTags.Data;
  *((_DWORD *)v20 + 1) = v10->ImportIndex;
  v22 = p_Data->Size + 1;
  if ( v22 >= p_Data->Size )
  {
    if ( v22 >= p_Data->Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>::Reserve(
        p_Data,
        p_Data,
        v22 + (v22 >> 2));
  }
  else if ( v22 < p_Data->Policy.Capacity >> 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::ExecuteTag *,Scaleform::AllocatorGH<Scaleform::GFx::ExecuteTag *,2>,Scaleform::ArrayConstPolicy<32,16,0>>::Reserve(
      p_Data,
      p_Data,
      p_Data->Size + 1);
  }
  Data = p_Data->Data;
  p_Data->Size = v22;
  v24 = (unsigned __int8 **)&Data[v22 - 1];
  if ( v24 )
    *v24 = v20;
  v25 = (void *)(sourceUrl.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((sourceUrl.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v25);
}
