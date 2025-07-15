void __stdcall Scaleform::GFx::AS3::SymbolClassLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LoadProcess *v2; // edi
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v4; // eax
  unsigned int Pos; // eax
  int v6; // ebx
  int v7; // edx
  unsigned int v8; // eax
  unsigned __int8 *pBuffer; // ecx
  __int16 v10; // dx
  unsigned __int16 v11; // bx
  void *v12; // edi
  int v13; // [esp+Ch] [ebp-14h]
  Scaleform::GFx::ResourceHandle hres; // [esp+10h] [ebp-10h] BYREF
  Scaleform::StringDH name; // [esp+18h] [ebp-8h] BYREF

  v2 = p;
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v4 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v4 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v6 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 2;
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  SymbolClassLoader: num = %d\n",
    v6);
  if ( v6 )
  {
    v13 = v6;
    while ( 1 )
    {
      v7 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v7 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v8 = pAltStream->Stream.Pos;
      pBuffer = pAltStream->Stream.pBuffer;
      v10 = pBuffer[v8 + 1];
      LOWORD(pBuffer) = pBuffer[v8];
      pAltStream->Stream.Pos = v8 + 2;
      v11 = (unsigned __int16)pBuffer | (v10 << 8);
      Scaleform::StringDH::StringDH(&name, v2->pLoadData.pObject->pHeap);
      Scaleform::GFx::Stream::ReadString(&pAltStream->Stream, &name);
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "       id = %d, symbol = '%s'\n",
        v11,
        (const char *)((name.HeapTypeBits & 0xFFFFFFFC) + 8));
      hres.HType = RH_Pointer;
      hres.BindIndex = 0;
      if ( !v11
        || Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
             p->pLoadData.pObject,
             (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType *)&hres,
             (Scaleform::GFx::ResourceId)v11) )
      {
        Scaleform::GFx::MovieDataDef::LoadTaskData::ExportResource(
          p->pLoadData.pObject,
          &name,
          (Scaleform::GFx::ResourceId)v11,
          &hres);
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
          &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
          "SymbolClassLoader can't find Resource with id = %d, name = '%s'",
          v11,
          (const char *)((name.HeapTypeBits & 0xFFFFFFFC) + 8));
      }
      if ( hres.HType == RH_Pointer && hres.BindIndex )
        Scaleform::GFx::Resource::Release(hres.pResource);
      v12 = (void *)(name.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((name.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
      if ( !--v13 )
        break;
      v2 = p;
    }
  }
}
