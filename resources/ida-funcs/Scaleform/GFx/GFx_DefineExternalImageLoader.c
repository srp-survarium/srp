void __stdcall Scaleform::GFx::GFx_DefineExternalImageLoader(
        Scaleform::String p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *pData; // ebx
  Scaleform::GFx::Stream *Size; // eax
  int U32; // eax
  Scaleform::GFx::Stream *pAltStream; // esi
  int v6; // ebp
  int v7; // ecx
  unsigned int Pos; // eax
  Scaleform::GFx::ResourceHandle::HandleType v9; // edx
  Scaleform::GFx::Stream *p_Stream; // esi
  int v11; // eax
  unsigned int v12; // eax
  unsigned __int8 *pBuffer; // ecx
  __int16 v14; // dx
  Scaleform::GFx::Stream *v15; // esi
  int v16; // eax
  unsigned int v17; // eax
  unsigned __int16 v18; // di
  Scaleform::GFx::Stream *v19; // esi
  void *v20; // esi
  void *v21; // esi
  Scaleform::String pstr; // [esp+10h] [ebp-14h] BYREF
  Scaleform::GFx::Stream *v23; // [esp+14h] [ebp-10h]
  int v24; // [esp+18h] [ebp-Ch]
  Scaleform::GFx::ResourceHandle v25; // [esp+1Ch] [ebp-8h] BYREF

  pData = (Scaleform::GFx::LoadProcess *)p.pData;
  Size = (Scaleform::GFx::Stream *)p.pData[71].Size;
  if ( !Size )
    Size = (Scaleform::GFx::Stream *)&p.pData[4];
  v23 = Size;
  U32 = Scaleform::GFx::LoadProcess::ReadU32((Scaleform::GFx::LoadProcess *)p.pData);
  pAltStream = pData->pAltStream;
  v6 = U32;
  if ( !pAltStream )
    pAltStream = &pData->ProcessInfo.Stream;
  v7 = pAltStream->DataSize - pAltStream->Pos;
  pAltStream->UnusedBits = 0;
  if ( v7 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(pAltStream, 2);
  Pos = pAltStream->Pos;
  v9 = (unsigned __int16)(pAltStream->pBuffer[Pos] | (pAltStream->pBuffer[Pos + 1] << 8));
  pAltStream->Pos = Pos + 2;
  p_Stream = pData->pAltStream;
  v25.HType = v9;
  if ( !p_Stream )
    p_Stream = &pData->ProcessInfo.Stream;
  v11 = p_Stream->DataSize - p_Stream->Pos;
  p_Stream->UnusedBits = 0;
  if ( v11 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(p_Stream, 2);
  v12 = p_Stream->Pos;
  pBuffer = p_Stream->pBuffer;
  v14 = pBuffer[v12 + 1];
  LOWORD(pBuffer) = pBuffer[v12];
  p_Stream->Pos = v12 + 2;
  v15 = pData->pAltStream;
  v24 = (unsigned __int16)((unsigned __int16)pBuffer | (v14 << 8));
  if ( !v15 )
    v15 = &pData->ProcessInfo.Stream;
  v16 = v15->DataSize - v15->Pos;
  v15->UnusedBits = 0;
  if ( v16 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v15, 2);
  v17 = v15->Pos;
  v18 = *(_WORD *)&v15->pBuffer[v17];
  v15->Pos = v17 + 2;
  Scaleform::String::String(&pstr);
  Scaleform::String::String(&p);
  v19 = v23;
  Scaleform::GFx::Stream::ReadStringWithLength(v23, &pstr);
  Scaleform::GFx::Stream::ReadStringWithLength(v19, &p);
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
    v19,
    "  DefineExternalImage: tagInfo.TagType = %d, id = 0x%X, fmt = %d, name = '%s', exp = '%s', w = %d, h = %d\n",
    tagInfo->TagType,
    v6,
    LOWORD(v25.HType),
    (const char *)((p.HeapTypeBits & 0xFFFFFFFC) + 8),
    (const char *)((pstr.HeapTypeBits & 0xFFFFFFFC) + 8),
    (unsigned __int16)v24,
    v18);
  Scaleform::GFx::GFx_CreateImageFileResourceHandle(
    &v25,
    pData,
    (Scaleform::GFx::ResourceId)(v6 & 0x9FFFF),
    (const __m128i *)((p.HeapTypeBits & 0xFFFFFFFC) + 8),
    (const __m128i *)((pstr.HeapTypeBits & 0xFFFFFFFC) + 8),
    v25.HType,
    v24,
    v18);
  if ( v25.HType == RH_Pointer && v25.BindIndex )
    Scaleform::GFx::Resource::Release(v25.pResource);
  v20 = (void *)(p.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((p.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v20);
  v21 = (void *)(pstr.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((pstr.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v21);
}
