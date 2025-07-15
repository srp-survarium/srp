void __stdcall Scaleform::GFx::GFx_DefineExternalGradientImageLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v3; // eax
  unsigned int Pos; // eax
  unsigned int v5; // ecx
  int v6; // eax
  int v7; // edx
  Scaleform::GFx::ResourceId v8; // ebp
  unsigned int v9; // eax
  unsigned __int16 v10; // di
  int v11; // edx
  unsigned int v12; // eax
  unsigned __int16 v13; // bx
  void *v14; // esi
  Scaleform::String pstr; // [esp+10h] [ebp-Ch] BYREF
  Scaleform::GFx::ResourceHandle v16; // [esp+14h] [ebp-8h] BYREF

  if ( p->pAltStream )
    pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  else
    pAltStream = &p->ProcessInfo;
  v3 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v3 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v5 = Pos + 2;
  v6 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[Pos] | 0x50000;
  v7 = pAltStream->Stream.DataSize - v5;
  pAltStream->Stream.Pos = v5;
  v8.Id = v6;
  pAltStream->Stream.UnusedBits = 0;
  if ( v7 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v9 = pAltStream->Stream.Pos;
  v10 = *(_WORD *)&pAltStream->Stream.pBuffer[v9];
  v9 += 2;
  v11 = pAltStream->Stream.DataSize - v9;
  pAltStream->Stream.Pos = v9;
  pAltStream->Stream.UnusedBits = 0;
  if ( v11 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v12 = pAltStream->Stream.Pos;
  v13 = *(_WORD *)&pAltStream->Stream.pBuffer[v12];
  pAltStream->Stream.Pos = v12 + 2;
  Scaleform::String::String(&pstr);
  Scaleform::GFx::Stream::ReadStringWithLength(&pAltStream->Stream, &pstr);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
    &pAltStream->Stream,
    "  DefineExternalGradientImage: tagInfo.TagType = %d, id = 0x%X, fmt = %d, name = '%s', size = %d\n",
    tagInfo->TagType,
    v8.Id,
    v10,
    (const char *)((pstr.HeapTypeBits & 0xFFFFFFFC) + 8),
    v13);
  Scaleform::GFx::GFx_CreateImageFileResourceHandle(
    &v16,
    p,
    v8,
    (const __m128i *)((pstr.HeapTypeBits & 0xFFFFFFFC) + 8),
    (const __m128i *)uri,
    v10,
    0,
    0);
  if ( v16.HType == RH_Pointer && v16.BindIndex )
    Scaleform::GFx::Resource::Release(v16.pResource);
  v14 = (void *)(pstr.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((pstr.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
}
