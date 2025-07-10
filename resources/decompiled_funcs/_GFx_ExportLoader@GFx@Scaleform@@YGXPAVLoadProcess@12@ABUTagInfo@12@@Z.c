void __stdcall Scaleform::GFx::GFx_ExportLoader(Scaleform::GFx::LoadProcess *p, const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v3; // eax
  unsigned int Pos; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v5; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v6; // esi
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // esi
  int v8; // edx
  unsigned int v9; // eax
  unsigned __int8 *pBuffer; // ecx
  __int16 v11; // dx
  unsigned __int16 v12; // bx
  Scaleform::GFx::SWFProcessInfo *Stream; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v14; // ecx
  void *v15; // esi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v16; // [esp+Ch] [ebp-14h]
  Scaleform::GFx::ResourceHandle hres; // [esp+10h] [ebp-10h] BYREF
  Scaleform::StringDH symbolName; // [esp+18h] [ebp-8h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v3 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v3 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v5 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*(unsigned __int16 *)&pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 2;
  v6 = v5;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v5);
  if ( v6 )
  {
    v16 = v6;
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
      Scaleform::StringDH::StringDH(&symbolName, p->pLoadData.pObject->pHeap);
      Stream = Scaleform::GFx::LoadProcess::GetStream(p);
      Scaleform::GFx::Stream::ReadString(&Stream->Stream, &symbolName);
      Scaleform::Render::JPEG::JPEGRwSource::TermSource(v14);
      hres.HType = RH_Pointer;
      hres.BindIndex = 0;
      if ( Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
             p->pLoadData.pObject,
             &hres,
             (Scaleform::GFx::ResourceId)v12) )
      {
        Scaleform::GFx::MovieDataDef::LoadTaskData::ExportResource(
          p->pLoadData.pObject,
          &symbolName,
          (Scaleform::GFx::ResourceId)v12,
          &hres);
      }
      else
      {
        Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
          &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
          "Don't know how to export Resource '%s'",
          (const char *)((symbolName.HeapTypeBits & 0xFFFFFFFC) + 8));
      }
      if ( hres.HType == RH_Pointer && hres.BindIndex )
        Scaleform::GFx::Resource::Release(hres.pResource);
      v15 = (void *)(symbolName.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((symbolName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v15);
      v16 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v16 - 1);
    }
    while ( v16 );
  }
}
