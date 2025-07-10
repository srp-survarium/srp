void __stdcall Scaleform::GFx::GFx_DefineExternalImageLoader(
        Scaleform::String p,
        Scaleform::GFx::AS3::RefCountBaseGC<328> *tagInfo)
{
  Scaleform::GFx::LoadProcess *pData; // ebx
  Scaleform::GFx::SWFProcessInfo *Size; // eax
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
  Scaleform::String imageExportName; // [esp+10h] [ebp-14h] BYREF
  Scaleform::GFx::Stream *pin; // [esp+14h] [ebp-10h]
  unsigned __int16 targetWidth[2]; // [esp+18h] [ebp-Ch]
  Scaleform::GFx::ResourceHandle result; // [esp+1Ch] [ebp-8h] BYREF

  pData = (Scaleform::GFx::LoadProcess *)p.pData;
  Size = (Scaleform::GFx::SWFProcessInfo *)p.pData[71].Size;
  if ( !Size )
    Size = (Scaleform::GFx::SWFProcessInfo *)&p.pData[4];
  pin = &Size->Stream;
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
  result.HType = v9;
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
  *(_DWORD *)targetWidth = (unsigned __int16)((unsigned __int16)pBuffer | (v14 << 8));
  if ( !v15 )
    v15 = &pData->ProcessInfo.Stream;
  v16 = v15->DataSize - v15->Pos;
  v15->UnusedBits = 0;
  if ( v16 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(v15, 2);
  v17 = v15->Pos;
  v18 = *(_WORD *)&v15->pBuffer[v17];
  v15->Pos = v17 + 2;
  Scaleform::String::String(&imageExportName);
  Scaleform::String::String(&p);
  v19 = pin;
  Scaleform::GFx::Stream::ReadStringWithLength(pin, &imageExportName);
  Scaleform::GFx::Stream::ReadStringWithLength(v19, &p);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(tagInfo);
  Scaleform::GFx::GFx_CreateImageFileResourceHandle(
    &result,
    pData,
    (Scaleform::GFx::ResourceId)(v6 & 0x9FFFF),
    (char *)((p.HeapTypeBits & 0xFFFFFFFC) + 8),
    (char *)((imageExportName.HeapTypeBits & 0xFFFFFFFC) + 8),
    result.HType,
    targetWidth[0],
    v18);
  if ( result.HType == RH_Pointer && result.BindIndex )
    Scaleform::GFx::Resource::Release(result.pResource);
  v20 = (void *)(p.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((p.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v20);
  v21 = (void *)(imageExportName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((imageExportName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v21);
}
