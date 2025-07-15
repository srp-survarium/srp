Scaleform::GFx::InteractiveObject *__thiscall Scaleform::GFx::AS3::AvmDisplayObjContainer::FindInsertToPlayList(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::InteractiveObject *ch)
{
  Scaleform::GFx::DisplayObject *pDispObj; // eax
  Scaleform::Render::TreeNode *pObject; // ebp
  unsigned int v4; // esi
  int v6; // ebx
  float LastHitTestY; // ecx
  int v8; // edi
  bool v9; // zf
  unsigned int v10; // esi
  int v11; // edi
  float v12; // ecx
  int v13; // ebx
  Scaleform::GFx::DisplayObject *v14; // edx
  Scaleform::GFx::InteractiveObject *v15; // ecx
  Scaleform::GFx::InteractiveObject *pParent; // eax
  Scaleform::GFx::DisplayObject *v17; // [esp+4h] [ebp-Ch]
  Scaleform::GFx::InteractiveObject *dobPrevSpr; // [esp+8h] [ebp-8h]

  pDispObj = this->pDispObj;
  v17 = pDispObj;
  if ( (pDispObj->Scaleform::GFx::DisplayObjectBase::Flags & 0x10) != 0
    || (pDispObj->Scaleform::GFx::DisplayObjectBase::Flags & 0x1000) != 0
    || pDispObj->Depth < -1 )
  {
    return 0;
  }
  pObject = pDispObj[1].pRenNode.pObject;
  v4 = 0;
  if ( !pObject )
    return (Scaleform::GFx::InteractiveObject *)pDispObj[1].RefCount;
  dobPrevSpr = 0;
  v6 = 0;
  do
  {
    LastHitTestY = pDispObj[1].LastHitTestY;
    v8 = *(_DWORD *)(v6 + LODWORD(LastHitTestY));
    if ( (Scaleform::GFx::InteractiveObject *)v8 == ch )
      break;
    if ( *(char *)(v8 + 62) < 0 )
    {
      v9 = !Scaleform::GFx::InteractiveObject::IsInPlayList(*(Scaleform::GFx::InteractiveObject **)(v6
                                                                                                  + LODWORD(LastHitTestY)));
      pDispObj = v17;
      if ( !v9 )
        dobPrevSpr = (Scaleform::GFx::InteractiveObject *)v8;
    }
    ++v4;
    v6 += 12;
  }
  while ( v4 < (unsigned int)pObject );
  if ( !dobPrevSpr )
    return (Scaleform::GFx::InteractiveObject *)pDispObj[1].RefCount;
  v10 = v4 + 1;
  if ( v10 >= (unsigned int)pObject )
  {
LABEL_20:
    v14 = this->pDispObj;
    v15 = dobPrevSpr;
    do
    {
      pParent = v15;
      while ( pParent != v14 )
      {
        if ( pParent != v14->pParent )
        {
          pParent = pParent->pParent;
          if ( pParent )
            continue;
        }
        return v15;
      }
      v15 = v15->pPlayPrev;
    }
    while ( v15 );
    return 0;
  }
  else
  {
    v11 = 12 * v10;
    while ( 1 )
    {
      v12 = pDispObj[1].LastHitTestY;
      v13 = *(_DWORD *)(v11 + LODWORD(v12));
      if ( *(char *)(v13 + 62) < 0 )
      {
        if ( Scaleform::GFx::InteractiveObject::IsInPlayList(*(Scaleform::GFx::InteractiveObject **)(v11 + LODWORD(v12))) )
          return (Scaleform::GFx::InteractiveObject *)v13;
      }
      ++v10;
      v11 += 12;
      if ( v10 >= (unsigned int)pObject )
        goto LABEL_20;
      pDispObj = v17;
    }
  }
}
