void __stdcall Scaleform::GFx::GFx_DebugIDLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  int v2; // edi
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v4; // eax
  unsigned int Pos; // eax
  unsigned __int8 v6; // cl
  Scaleform::AmpServer *Instance; // eax
  void *v8; // esi
  char v9[4]; // [esp+Ch] [ebp-8h] BYREF
  Scaleform::String v10; // [esp+10h] [ebp-4h] BYREF

  Scaleform::String::String(&v10);
  v2 = 16;
  do
  {
    pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !pAltStream )
      pAltStream = &p->ProcessInfo;
    v4 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v4 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
    Pos = pAltStream->Stream.Pos;
    v6 = pAltStream->Stream.pBuffer[Pos];
    pAltStream->Stream.Pos = Pos + 1;
    _itoa_s((char *)v2, v6, v9, 3u, 0x10u);
    Scaleform::String::AppendString(&v10, (const __m128i *)v9, 0xFFFFFFFF);
    --v2;
  }
  while ( v2 );
  Instance = Scaleform::AmpServer::GetInstance();
  Instance->AddSwf(
    Instance,
    p->pLoadData.pObject->SwdHandle,
    (const char *)((v10.HeapTypeBits & 0xFFFFFFFC) + 8),
    (const char *)((p->pLoadData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFC) + 8));
  v8 = (void *)(v10.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v10.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
}
