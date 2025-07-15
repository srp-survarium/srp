void __stdcall Scaleform::GFx::GFx_PlaceObject2Loader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *v3; // edi
  Scaleform::GFx::SWFProcessInfo *pAltStream; // ebx
  unsigned int v5; // ebp
  Scaleform::GFx::MovieDataDef::LoadTaskData *v6; // eax
  Scaleform::GFx::ASSupport *pObject; // ecx
  Scaleform::GFx::PlaceObject2Taga *v8; // eax
  Scaleform::GFx::PlaceObject2Taga *v9; // edi
  char HasEventHandlers; // [esp+14h] [ebp+4h]

  v3 = &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>;
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  PlaceObject2Tag\n");
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v5 = Scaleform::GFx::PlaceObject2Tag::ComputeDataSize(&pAltStream->Stream, p->pLoadData.pObject->Header.Version);
  HasEventHandlers = Scaleform::GFx::PlaceObject2Tag::HasEventHandlers(&pAltStream->Stream);
  if ( !HasEventHandlers || (v6 = p->pLoadData.pObject, v5 += 4, (v6->FileAttributes & 8) != 0) )
  {
    if ( p->pLoadData.pObject->Header.Version < 6u )
      v8 = Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::PlaceObject2Taga>(p, v5);
    else
      v8 = (Scaleform::GFx::PlaceObject2Taga *)Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::PlaceObject2Tag>(
                                                 p,
                                                 v5);
  }
  else
  {
    pObject = p->pLoadStates.pObject->pAS2Support.pObject;
    if ( !pObject )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        v3,
        "GFx_PlaceObject2Loader - AS2 support is not installed. Tag is skipped.");
      return;
    }
    v8 = (Scaleform::GFx::PlaceObject2Taga *)pObject->AllocPlaceObject2Tag(pObject, p, v5, v6->Header.Version);
  }
  v9 = v8;
  if ( v8 )
  {
    if ( HasEventHandlers )
    {
      Scaleform::GFx::Stream::ReadToBuffer(&pAltStream->Stream, (unsigned __int8 *)&v8[1], v5 - 4);
      Scaleform::GFx::PlaceObject2Tag::RestructureForEventHandlers(v9->pData);
    }
    else
    {
      Scaleform::GFx::Stream::ReadToBuffer(&pAltStream->Stream, v8->pData, v5);
    }
    Scaleform::GFx::LoadProcess::AddExecuteTag(p, v9);
  }
}
