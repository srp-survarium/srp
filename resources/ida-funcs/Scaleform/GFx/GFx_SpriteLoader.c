void __stdcall Scaleform::GFx::GFx_SpriteLoader(Scaleform::GFx::LoadProcess *p, const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v3; // eax
  unsigned int Pos; // eax
  unsigned __int16 v5; // cx
  Scaleform::GFx::ResourceId v6; // esi
  Scaleform::GFx::SpriteDef *v7; // eax
  Scaleform::GFx::SpriteDef *v8; // eax
  Scaleform::GFx::SpriteDef *v9; // ebx
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // edi

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
    "  sprite\n  char id = %d\n",
    v5);
  v7 = (Scaleform::GFx::SpriteDef *)p->pLoadData.pObject->pHeap->Alloc(p->pLoadData.pObject->pHeap, 56, 0);
  if ( v7 )
  {
    Scaleform::GFx::SpriteDef::SpriteDef(v7, p->pDataDef_Unsafe);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  Scaleform::GFx::SpriteDef::Read(v9, p, v6);
  pObject = p->pLoadData.pObject;
  v9->Id = v6;
  Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(pObject, v6, v9);
  if ( v9 )
    Scaleform::GFx::Resource::Release(v9);
}
