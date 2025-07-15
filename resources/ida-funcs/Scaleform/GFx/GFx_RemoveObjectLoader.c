void __stdcall Scaleform::GFx::GFx_RemoveObjectLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // eax
  Scaleform::GFx::ASSupport *v3; // ecx
  unsigned __int8 *pCurrent; // eax
  unsigned int BytesLeft; // edx
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  unsigned __int8 *v7; // esi

  pObject = p->pLoadData.pObject;
  if ( (pObject->FileAttributes & 8) == 0 )
  {
    v3 = p->pLoadStates.pObject->pAS2Support.pObject;
    if ( !v3 )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogError(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "GFx_RemoveObjectLoader - AS2 support is not installed. Tag is skipped.");
      return;
    }
    pCurrent = (unsigned __int8 *)v3->AllocRemoveObjectTag(v3, p);
    goto LABEL_10;
  }
  BytesLeft = pObject->TagMemAllocator.BytesLeft;
  p_TagMemAllocator = &pObject->TagMemAllocator;
  if ( BytesLeft < 0xC )
  {
    pCurrent = Scaleform::GFx::DataAllocator::OverflowAlloc(p_TagMemAllocator, 0xCu);
  }
  else
  {
    pCurrent = p_TagMemAllocator->pCurrent;
    p_TagMemAllocator->pCurrent += 12;
    p_TagMemAllocator->BytesLeft = BytesLeft - 12;
  }
  if ( pCurrent )
  {
    *(_DWORD *)pCurrent = &Scaleform::GFx::RemoveObjectTag::`vftable';
LABEL_10:
    v7 = pCurrent;
    if ( pCurrent )
    {
      (*(void (__thiscall **)(unsigned __int8 *, Scaleform::GFx::LoadProcess *))(*(_DWORD *)pCurrent + 32))(pCurrent, p);
      Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
        &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
        "  RemoveObject(%d, %d)\n",
        *((unsigned __int16 *)v7 + 4),
        *((unsigned __int16 *)v7 + 2));
      Scaleform::GFx::LoadProcess::AddExecuteTag(p, (Scaleform::GFx::ExecuteTag *)v7);
    }
  }
}
