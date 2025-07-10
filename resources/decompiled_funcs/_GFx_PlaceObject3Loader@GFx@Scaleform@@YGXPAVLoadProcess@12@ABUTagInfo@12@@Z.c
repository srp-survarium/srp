void __thiscall Scaleform::GFx::GFx_PlaceObject3Loader(
        Scaleform::GFx::AS3::RefCountBaseGC<328> *this,
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *v4; // esi
  Scaleform::GFx::SWFProcessInfo *pAltStream; // ebx
  unsigned int v6; // edi
  Scaleform::GFx::ASSupport *v7; // ecx
  unsigned __int8 *pCurrent; // esi
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx
  unsigned int BytesLeft; // edx
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  unsigned int v12; // eax
  Scaleform::GFx::SWFProcessInfo *pin; // [esp+10h] [ebp-4h]
  bool hasEventHandlers; // [esp+18h] [ebp+4h]

  v4 = &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(this);
  if ( p->pAltStream )
  {
    pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    pin = pAltStream;
  }
  else
  {
    pAltStream = &p->ProcessInfo;
    pin = &p->ProcessInfo;
  }
  v6 = Scaleform::GFx::PlaceObject3Tag::ComputeDataSize(&pAltStream->Stream);
  hasEventHandlers = Scaleform::GFx::PlaceObject2Tag::HasEventHandlers(&pAltStream->Stream);
  if ( !hasEventHandlers || (v6 += 4, (p->pLoadData.pObject->FileAttributes & 8) != 0) )
  {
    pObject = p->pLoadData.pObject;
    BytesLeft = pObject->TagMemAllocator.BytesLeft;
    p_TagMemAllocator = &pObject->TagMemAllocator;
    v12 = (v6 + 10) & 0xFFFFFFFC;
    if ( v12 > BytesLeft )
    {
      pCurrent = (unsigned __int8 *)Scaleform::GFx::DataAllocator::OverflowAlloc(
                                      p_TagMemAllocator,
                                      (v6 + 10) & 0xFFFFFFFC);
    }
    else
    {
      pCurrent = p_TagMemAllocator->pCurrent;
      p_TagMemAllocator->pCurrent += v12;
      pAltStream = pin;
      p_TagMemAllocator->BytesLeft = BytesLeft - v12;
    }
    if ( !pCurrent )
      return;
    *(_DWORD *)pCurrent = &Scaleform::GFx::PlaceObject3Tag::`vftable';
  }
  else
  {
    v7 = p->pLoadStates.pObject->pAS2Support.pObject;
    if ( !v7 )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        v4,
        "GFx_PlaceObject3Loader - AS2 support is not installed. Tag is skipped.");
      return;
    }
    pCurrent = (unsigned __int8 *)v7->AllocPlaceObject3Tag(v7, p, v6);
  }
  if ( pCurrent )
  {
    if ( hasEventHandlers )
    {
      Scaleform::GFx::Stream::ReadToBuffer(&pAltStream->Stream, pCurrent + 8, v6 - 4);
      Scaleform::GFx::PlaceObject2Tag::RestructureForEventHandlers(pCurrent + 4);
    }
    else
    {
      Scaleform::GFx::Stream::ReadToBuffer(&pAltStream->Stream, pCurrent + 4, v6);
    }
    Scaleform::GFx::LoadProcess::AddExecuteTag(p, (Scaleform::GFx::ExecuteTag *)pCurrent);
  }
}
