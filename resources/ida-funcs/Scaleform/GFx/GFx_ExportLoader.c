void __stdcall Scaleform::GFx::GFx_ExportLoader(Scaleform::GFx::LoadProcess *p, const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v3; // eax
  unsigned int Pos; // eax
  unsigned __int16 v5; // dx
  int v6; // esi
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // esi
  int v8; // edx
  unsigned int v9; // eax
  unsigned __int8 *pBuffer; // ecx
  __int16 v11; // dx
  unsigned __int16 v12; // bx
  Scaleform::GFx::SWFProcessInfo *Stream; // eax
  void *v14; // esi
  int v15; // [esp+Ch] [ebp-14h]
  Scaleform::GFx::ResourceHandle phandle; // [esp+10h] [ebp-10h] BYREF
  Scaleform::StringDH v17; // [esp+18h] [ebp-8h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v3 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v3 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v5 = *(_WORD *)&pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 2;
  v6 = v5;
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  export: count = %d\n",
    v5);
  if ( v6 )
  {
    v15 = v6;
    do
    {
      p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
      if ( !p_ProcessInfo )
        p_ProcessInfo = &p->ProcessInfo;
      v8 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
      p_ProcessInfo->Stream.UnusedBits = 0;
      if ( v8 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
      v9 = p_ProcessInfo->Stream.Pos;
      pBuffer = p_ProcessInfo->Stream.pBuffer;
      v11 = pBuffer[v9 + 1];
      LOWORD(pBuffer) = pBuffer[v9];
      p_ProcessInfo->Stream.Pos = v9 + 2;
      v12 = (unsigned __int16)pBuffer | (v11 << 8);
      Scaleform::StringDH::StringDH(&v17, p->pLoadData.pObject->pHeap);
      Stream = Scaleform::GFx::LoadProcess::GetStream(p);
      Scaleform::GFx::Stream::ReadString(&Stream->Stream, &v17);
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "  export: id = %d, name = %s\n",
        v12,
        (const char *)((v17.HeapTypeBits & 0xFFFFFFFC) + 8));
      phandle.HType = RH_Pointer;
      phandle.BindIndex = 0;
      if ( Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
             p->pLoadData.pObject,
             (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType *)&phandle,
             (Scaleform::GFx::ResourceId)v12) )
      {
        Scaleform::GFx::MovieDataDef::LoadTaskData::ExportResource(
          p->pLoadData.pObject,
          &v17,
          (Scaleform::GFx::ResourceId)v12,
          &phandle);
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
          &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
          "Don't know how to export Resource '%s'",
          (const char *)((v17.HeapTypeBits & 0xFFFFFFFC) + 8));
      }
      if ( phandle.HType == RH_Pointer && phandle.BindIndex )
        Scaleform::GFx::Resource::Release(phandle.pResource);
      v14 = (void *)(v17.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((v17.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
      --v15;
    }
    while ( v15 );
  }
}
