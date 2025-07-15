void __thiscall Scaleform::GFx::GFx_PlaceObject2Loader(
        Scaleform::GFx::AS3::RefCountBaseGC<328> *this,
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *v4; // edi
  Scaleform::GFx::SWFProcessInfo *pAltStream; // ebx
  unsigned int v6; // ebp
  Scaleform::GFx::MovieDataDef::LoadTaskData *v7; // eax
  Scaleform::GFx::ASSupport *pObject; // ecx
  Scaleform::GFx::PlaceObject2Taga *v9; // eax
  Scaleform::GFx::PlaceObject2Taga *v10; // edi
  bool hasEventHandlers; // [esp+14h] [ebp+4h]

  v4 = &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(this);
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v6 = Scaleform::GFx::PlaceObject2Tag::ComputeDataSize(&pAltStream->Stream, p->pLoadData.pObject->Header.Version);
  hasEventHandlers = Scaleform::GFx::PlaceObject2Tag::HasEventHandlers(&pAltStream->Stream);
  if ( !hasEventHandlers || (v7 = p->pLoadData.pObject, v6 += 4, (v7->FileAttributes & 8) != 0) )
  {
    if ( p->pLoadData.pObject->Header.Version < 6u )
      v9 = Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::PlaceObject2Taga>(p, v6);
    else
      v9 = (Scaleform::GFx::PlaceObject2Taga *)Scaleform::GFx::LoadProcess::AllocTag<Scaleform::GFx::PlaceObject2Tag>(
                                                 p,
                                                 v6);
  }
  else
  {
    pObject = p->pLoadStates.pObject->pAS2Support.pObject;
    if ( !pObject )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        v4,
        "GFx_PlaceObject2Loader - AS2 support is not installed. Tag is skipped.");
      return;
    }
    v9 = (Scaleform::GFx::PlaceObject2Taga *)pObject->AllocPlaceObject2Tag(pObject, p, v6, v7->Header.Version);
  }
  v10 = v9;
  if ( v9 )
  {
    if ( hasEventHandlers )
    {
      Scaleform::GFx::Stream::ReadToBuffer(&pAltStream->Stream, (unsigned __int8 *)&v9[1], v6 - 4);
      Scaleform::GFx::PlaceObject2Tag::RestructureForEventHandlers(v10->pData);
    }
    else
    {
      Scaleform::GFx::Stream::ReadToBuffer(&pAltStream->Stream, v9->pData, v6);
    }
    Scaleform::GFx::LoadProcess::AddExecuteTag(p, v10);
  }
}
