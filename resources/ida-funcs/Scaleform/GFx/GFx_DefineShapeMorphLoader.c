void __stdcall Scaleform::GFx::GFx_DefineShapeMorphLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v3; // eax
  unsigned int Pos; // eax
  unsigned __int16 v5; // cx
  Scaleform::GFx::ResourceId v6; // esi
  Scaleform::GFx::MorphCharacterDef *v7; // eax
  Scaleform::GFx::MorphCharacterDef *v8; // eax
  Scaleform::GFx::MorphCharacterDef *v9; // ebx

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
  v6.Id = v5;
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  ShapeMorphLoader: id = %d\n",
    v5);
  v7 = (Scaleform::GFx::MorphCharacterDef *)p->pLoadData.pObject->pHeap->Alloc(p->pLoadData.pObject->pHeap, 28, 0);
  if ( v7 )
  {
    Scaleform::GFx::MorphCharacterDef::MorphCharacterDef(v7);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  Scaleform::GFx::MorphCharacterDef::Read(v9, p, tagInfo, 1);
  if ( p->LoadState == LS_LoadingRoot )
    Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(p->pLoadData.pObject, v6, v9);
  if ( v9 )
    Scaleform::GFx::Resource::Release(v9);
}
