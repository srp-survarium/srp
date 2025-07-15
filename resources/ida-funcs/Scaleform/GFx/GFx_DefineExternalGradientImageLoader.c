void __stdcall Scaleform::GFx::GFx_DefineExternalGradientImageLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v3; // eax
  unsigned int Pos; // eax
  unsigned int v5; // ecx
  unsigned int v6; // eax
  int v7; // edx
  Scaleform::GFx::ResourceId v8; // ebp
  unsigned int v9; // eax
  unsigned __int16 v10; // di
  int v11; // edx
  void *v12; // esi
  Scaleform::String imageFileName; // [esp+10h] [ebp-Ch] BYREF
  Scaleform::GFx::ResourceHandle result; // [esp+14h] [ebp-8h] BYREF

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
  v6 = (unsigned int)&loc_50000 | *(unsigned __int16 *)&pAltStream->Stream.pBuffer[Pos];
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
  pAltStream->Stream.Pos += 2;
  Scaleform::String::String(&imageFileName);
  Scaleform::GFx::Stream::ReadStringWithLength(&pAltStream->Stream, &imageFileName);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)tagInfo->TagType);
  Scaleform::GFx::GFx_CreateImageFileResourceHandle(
    &result,
    p,
    v8,
    (char *)((imageFileName.HeapTypeBits & 0xFFFFFFFC) + 8),
    (char *)&buf,
    v10,
    0,
    0);
  if ( result.HType == RH_Pointer && result.BindIndex )
    Scaleform::GFx::Resource::Release(result.pResource);
  v12 = (void *)(imageFileName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((imageFileName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
}
