void __stdcall Scaleform::GFx::GFx_DebugIDLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  int v2; // edi
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v4; // eax
  unsigned int Pos; // eax
  unsigned __int8 v6; // cl
  void *v7; // esi
  char acHex[4]; // [esp+Ch] [ebp-8h] BYREF
  Scaleform::String strSwdId; // [esp+10h] [ebp-4h] BYREF

  Scaleform::String::String(&strSwdId);
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
    _itoa_s((char *)v2, v6, acHex, 3u, 0x10u);
    Scaleform::String::AppendString(&strSwdId, acHex, 0xFFFFFFFF);
    --v2;
  }
  while ( v2 );
  v7 = (void *)(strSwdId.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((strSwdId.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
}
