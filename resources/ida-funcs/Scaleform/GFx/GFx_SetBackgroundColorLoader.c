void __stdcall Scaleform::GFx::GFx_SetBackgroundColorLoader(
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ecx
  unsigned int BytesLeft; // edx
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  unsigned __int8 *pCurrent; // eax
  Scaleform::GFx::SetBackgroundColorTag *v6; // esi

  pObject = p->pLoadData.pObject;
  BytesLeft = pObject->TagMemAllocator.BytesLeft;
  p_TagMemAllocator = &pObject->TagMemAllocator;
  if ( BytesLeft < 8 )
  {
    pCurrent = (unsigned __int8 *)Scaleform::GFx::DataAllocator::OverflowAlloc(p_TagMemAllocator, 8u);
  }
  else
  {
    pCurrent = p_TagMemAllocator->pCurrent;
    p_TagMemAllocator->pCurrent += 8;
    p_TagMemAllocator->BytesLeft = BytesLeft - 8;
  }
  if ( pCurrent )
  {
    *(_DWORD *)pCurrent = &Scaleform::GFx::SetBackgroundColorTag::`vftable';
    v6 = (Scaleform::GFx::SetBackgroundColorTag *)pCurrent;
  }
  else
  {
    v6 = 0;
  }
  Scaleform::GFx::SetBackgroundColorTag::Read(v6, p);
  Scaleform::GFx::LoadProcess::AddExecuteTag(p, v6);
}
