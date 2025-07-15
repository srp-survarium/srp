Scaleform::GFx::ResourceHandle *__thiscall Scaleform::GFx::LoadProcess::AddDataResource(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::GFx::ResourceHandle *result,
        Scaleform::GFx::ResourceId rid,
        const Scaleform::GFx::ResourceData *resData)
{
  Scaleform::GFx::ResourceHandle *v5; // ebx
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ebp
  unsigned int BytesLeft; // eax
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  unsigned __int8 *pCurrent; // esi
  volatile LONG *p_pResourceNodes; // eax
  Scaleform::AmpStats *Stats; // esi
  Scaleform::AmpStats_vtbl *v12; // edi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::AmpFunctionTimer v15; // [esp+10h] [ebp-10h] BYREF

  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v15,
    this->LoadProcessStats.pObject,
    "LoadProcess::AddDataResource",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_Invalid);
  v5 = result;
  Scaleform::GFx::MovieDataDef::LoadTaskData::AddNewResourceHandle(this->pLoadData.pObject, result, rid);
  pObject = this->pLoadData.pObject;
  BytesLeft = pObject->TagMemAllocator.BytesLeft;
  p_TagMemAllocator = &pObject->TagMemAllocator;
  if ( BytesLeft < 0x10 )
  {
    pCurrent = Scaleform::GFx::DataAllocator::OverflowAlloc(p_TagMemAllocator, 0x10u);
  }
  else
  {
    pCurrent = p_TagMemAllocator->pCurrent;
    p_TagMemAllocator->pCurrent += 16;
    pObject->TagMemAllocator.BytesLeft = BytesLeft - 16;
  }
  if ( pCurrent )
  {
    *(_DWORD *)pCurrent = 0;
    *((_DWORD *)pCurrent + 1) = 0;
    *((_DWORD *)pCurrent + 3) = 0;
    if ( resData->pInterface )
      resData->pInterface->AddRef(resData->pInterface, resData->hData);
    if ( *(_DWORD *)pCurrent )
      (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)pCurrent + 8))(
        *(_DWORD *)pCurrent,
        *((_DWORD *)pCurrent + 1));
    *(Scaleform::GFx::ResourceData *)pCurrent = *resData;
    *((_DWORD *)pCurrent + 2) = result->BindIndex;
    if ( !this->pResourceData )
      this->pResourceData = (Scaleform::GFx::ResourceDataNode *)pCurrent;
    p_pResourceNodes = (volatile LONG *)&pObject->BindData.pResourceNodes;
    if ( pObject->BindData.pResourceNodes.Value )
      p_pResourceNodes = (volatile LONG *)&pObject->BindData.pResourceNodesLast->pNext;
    InterlockedExchange(p_pResourceNodes, (LONG)pCurrent);
    v5 = result;
    pObject->BindData.pResourceNodesLast = (Scaleform::GFx::ResourceDataNode *)pCurrent;
    ++this->ResourceDataCount;
  }
  Stats = v15.Stats;
  if ( v15.Stats )
  {
    v12 = v15.Stats->__vftable;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))v12->NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v15.StartTicks),
      (ProfileTicks - v15.StartTicks) >> 32);
  }
  return v5;
}
