void __stdcall Scaleform::GFx::GFx_DefineBinaryData(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v3; // eax
  unsigned int Pos; // eax
  unsigned int v5; // ecx
  Scaleform::GFx::ResourceId v6; // esi
  Scaleform::GFx::ButtonDef *v7; // eax
  Scaleform::GFx::Resource *v8; // eax
  Scaleform::GFx::Resource *v9; // ebx

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
  v5 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 2;
  v6.Id = v5;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v5);
  Scaleform::GFx::LoadProcess::ReadU32(p);
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
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(p->pLoadData.pObject, v6, v9);
  if ( v9 )
    Scaleform::GFx::Resource::Release(v9);
}
