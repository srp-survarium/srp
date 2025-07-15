void __stdcall Scaleform::GFx::GFx_DefineBinaryData(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v3; // eax
  unsigned int Pos; // eax
  Scaleform::GFx::ResourceId v5; // ebp
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // eax
  Scaleform::GFx::ButtonDef *v7; // eax
  Scaleform::GFx::Resource *v8; // eax
  Scaleform::GFx::Resource *v9; // esi

  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "Tag 'DefineBinaryData' (87) is not supported, potentially 'TLF text' fields are used. Switch to 'Classic Text'.");
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v3 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v3 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  Pos = pAltStream->Stream.Pos;
  v5.Id = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 2;
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  DefineBinaryData: CharId = %d\n",
    v5.Id);
  Scaleform::GFx::LoadProcess::ReadU32(p);
  if ( (p->ParseFlags & 1) != 0 )
  {
    p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !p_ProcessInfo )
      p_ProcessInfo = &p->ProcessInfo;
    Scaleform::GFx::Stream::LogTagBytes(&p_ProcessInfo->Stream);
  }
  v7 = (Scaleform::GFx::ButtonDef *)p->pLoadData.pObject->pHeap->Alloc(p->pLoadData.pObject->pHeap, 52, 0);
  if ( v7 )
  {
    Scaleform::GFx::ButtonDef::ButtonDef(v7);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  if ( p->LoadState == LS_LoadingRoot )
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(p->pLoadData.pObject, v5, v9);
  if ( v9 )
    Scaleform::GFx::Resource::Release(v9);
}
