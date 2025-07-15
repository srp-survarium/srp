void __thiscall Scaleform::GFx::AS2Support::DoActionLoader(
        Scaleform::GFx::AS2Support *this,
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx
  unsigned int BytesLeft; // edx
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  unsigned __int8 *pCurrent; // eax
  Scaleform::GFx::AS2::DoActionTag *v7; // esi

  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "tag %d: DoActionLoader\n",
    tagInfo->TagType);
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParseAction(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "-- actions in frame %d\n",
    p->pLoadData.pObject->LoadingFrame);
  pObject = p->pLoadData.pObject;
  BytesLeft = pObject->TagMemAllocator.BytesLeft;
  p_TagMemAllocator = &pObject->TagMemAllocator;
  if ( BytesLeft < 8 )
  {
    pCurrent = Scaleform::GFx::DataAllocator::OverflowAlloc(p_TagMemAllocator, 8u);
  }
  else
  {
    pCurrent = p_TagMemAllocator->pCurrent;
    p_TagMemAllocator->pCurrent += 8;
    p_TagMemAllocator->BytesLeft = BytesLeft - 8;
  }
  v7 = 0;
  if ( pCurrent )
  {
    *(_DWORD *)pCurrent = &Scaleform::GFx::AS2::DoActionTag::`vftable';
    *((_DWORD *)pCurrent + 1) = 0;
    v7 = (Scaleform::GFx::AS2::DoActionTag *)pCurrent;
  }
  Scaleform::GFx::AS2::DoActionTag::Read(v7, p);
  Scaleform::GFx::LoadProcess::AddExecuteTag(p, v7);
}
