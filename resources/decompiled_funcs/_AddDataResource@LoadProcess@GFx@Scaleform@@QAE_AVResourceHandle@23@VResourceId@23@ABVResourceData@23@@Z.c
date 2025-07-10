Scaleform::GFx::ResourceHandle *__thiscall Scaleform::GFx::LoadProcess::AddDataResource(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::GFx::ResourceHandle *result,
        Scaleform::GFx::ResourceId rid,
        const Scaleform::GFx::ResourceData *resData)
{
  Scaleform::GFx::ResourceHandle *v4; // ebx
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // ebp
  unsigned int BytesLeft; // eax
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // ecx
  unsigned __int8 *pCurrent; // esi
  volatile LONG *p_pResourceNodes; // eax

  v4 = result;
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
    v4 = result;
    *((_DWORD *)pCurrent + 2) = result->BindIndex;
    if ( !this->pResourceData )
      this->pResourceData = (Scaleform::GFx::ResourceDataNode *)pCurrent;
    p_pResourceNodes = (volatile LONG *)&pObject->BindData.pResourceNodes;
    if ( pObject->BindData.pResourceNodes.Value )
      p_pResourceNodes = (volatile LONG *)&pObject->BindData.pResourceNodesLast->pNext;
    InterlockedExchange(p_pResourceNodes, (LONG)pCurrent);
    pObject->BindData.pResourceNodesLast = (Scaleform::GFx::ResourceDataNode *)pCurrent;
    ++this->ResourceDataCount;
  }
  return v4;
}
