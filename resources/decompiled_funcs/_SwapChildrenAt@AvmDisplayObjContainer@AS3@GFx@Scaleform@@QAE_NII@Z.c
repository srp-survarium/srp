char __thiscall Scaleform::GFx::AS3::AvmDisplayObjContainer::SwapChildrenAt(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        unsigned int i1,
        unsigned int i2)
{
  Scaleform::GFx::DisplayObject *pDispObj; // eax
  unsigned int pObject; // ecx
  char *p_LastHitTestY; // ebx
  int v7; // esi
  int v8; // edi
  int v9; // eax
  Scaleform::GFx::AS3::AvmInteractiveObj *v10; // ecx
  int v11; // eax

  pDispObj = this->pDispObj;
  pObject = (unsigned int)pDispObj[1].pRenNode.pObject;
  p_LastHitTestY = (char *)&pDispObj[1].LastHitTestY;
  if ( i1 >= pObject )
    return 0;
  if ( i2 >= pObject
    || !Scaleform::GFx::DisplayList::SwapEntriesAtIndexes(
          (Scaleform::GFx::DisplayList *)&pDispObj[1].LastHitTestY,
          pDispObj,
          i1,
          i2) )
  {
    return 0;
  }
  v7 = *(_DWORD *)(*(_DWORD *)p_LastHitTestY + 12 * i1);
  v8 = *(_DWORD *)(*(_DWORD *)p_LastHitTestY + 12 * i2);
  if ( v7 )
  {
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 204))(v7, 0);
    *(_DWORD *)(v7 + 28) = 0;
    *(_DWORD *)(v7 + 24) = -1;
  }
  if ( v8 )
  {
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v8 + 204))(v8, 0);
    *(_DWORD *)(v8 + 28) = 0;
    *(_DWORD *)(v8 + 24) = -1;
  }
  p_LastHitTestY[20] |= 3u;
  if ( *(char *)(v7 + 62) < 0 )
  {
    v9 = (*(int (__thiscall **)(int))(*(_DWORD *)(v7 + 4 * *(unsigned __int8 *)(v7 + 65)) + 4))(v7 + 4 * *(unsigned __int8 *)(v7 + 65));
    if ( v9 )
      v10 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v9 - 28);
    else
      v10 = 0;
    Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v10);
  }
  if ( *(char *)(v8 + 62) < 0 )
  {
    v11 = (*(int (__thiscall **)(int))(*(_DWORD *)(v8 + 4 * *(unsigned __int8 *)(v8 + 65)) + 4))(v8 + 4 * *(unsigned __int8 *)(v8 + 65));
    if ( v11 )
    {
      Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList((Scaleform::GFx::AS3::AvmInteractiveObj *)(v11 - 28));
      return 1;
    }
    Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(0);
  }
  return 1;
}
