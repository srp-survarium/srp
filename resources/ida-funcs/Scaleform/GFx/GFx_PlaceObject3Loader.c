void __stdcall Scaleform::GFx::GFx_PlaceObject3Loader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess> *v3; // esi
  Scaleform::GFx::SWFProcessInfo *pAltStream; // ebx
  unsigned int v5; // edi
  Scaleform::GFx::ASSupport *v6; // ecx
  unsigned __int8 *pCurrent; // esi
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx
  unsigned int BytesLeft; // edx
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  unsigned int v11; // eax
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // [esp+10h] [ebp-4h]
  char HasEventHandlers; // [esp+18h] [ebp+4h]

  v3 = &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>;
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  PlaceObject3Tag\n");
  if ( p->pAltStream )
  {
    pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    p_ProcessInfo = pAltStream;
  }
  else
  {
    pAltStream = &p->ProcessInfo;
    p_ProcessInfo = &p->ProcessInfo;
  }
  v5 = Scaleform::GFx::PlaceObject3Tag::ComputeDataSize(&pAltStream->Stream);
  HasEventHandlers = Scaleform::GFx::PlaceObject2Tag::HasEventHandlers(&pAltStream->Stream);
  if ( !HasEventHandlers || (v5 += 4, (p->pLoadData.pObject->FileAttributes & 8) != 0) )
  {
    pObject = p->pLoadData.pObject;
    BytesLeft = pObject->TagMemAllocator.BytesLeft;
    p_TagMemAllocator = &pObject->TagMemAllocator;
    v11 = (v5 + 10) & 0xFFFFFFFC;
    if ( v11 > BytesLeft )
    {
      pCurrent = Scaleform::GFx::DataAllocator::OverflowAlloc(p_TagMemAllocator, (v5 + 10) & 0xFFFFFFFC);
    }
    else
    {
      pCurrent = p_TagMemAllocator->pCurrent;
      p_TagMemAllocator->pCurrent += v11;
      pAltStream = p_ProcessInfo;
      p_TagMemAllocator->BytesLeft = BytesLeft - v11;
    }
    if ( !pCurrent )
      return;
    *(_DWORD *)pCurrent = &Scaleform::GFx::PlaceObject3Tag::`vftable';
  }
  else
  {
    v6 = p->pLoadStates.pObject->pAS2Support.pObject;
    if ( !v6 )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        v3,
        "GFx_PlaceObject3Loader - AS2 support is not installed. Tag is skipped.");
      return;
    }
    pCurrent = (unsigned __int8 *)v6->AllocPlaceObject3Tag(v6, p, v5);
  }
  if ( pCurrent )
  {
    if ( HasEventHandlers )
    {
      Scaleform::GFx::Stream::ReadToBuffer(&pAltStream->Stream, pCurrent + 8, v5 - 4);
      Scaleform::GFx::PlaceObject2Tag::RestructureForEventHandlers(pCurrent + 4);
    }
    else
    {
      Scaleform::GFx::Stream::ReadToBuffer(&pAltStream->Stream, pCurrent + 4, v5);
    }
    Scaleform::GFx::LoadProcess::AddExecuteTag(p, (Scaleform::GFx::ExecuteTag *)pCurrent);
  }
}
