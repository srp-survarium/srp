char __thiscall Scaleform::GFx::AS3::AvmDisplayObj::IsStageAccessible(Scaleform::GFx::AS3::AvmDisplayObj *this)
{
  Scaleform::GFx::DisplayObject *pDispObj; // eax
  Scaleform::GFx::DisplayObject_vtbl **v3; // ecx
  int v4; // eax
  int v5; // ecx
  Scaleform::GFx::InteractiveObject *pParent; // eax
  int v8; // eax
  _DWORD *v9; // esi
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  _DWORD *v15; // eax

  pDispObj = this->pDispObj;
  if ( SLOBYTE(pDispObj->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
  {
    if ( pDispObj
      && (v3 = &pDispObj->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
             + pDispObj->AvmObjOffset,
          (v4 = ((int (__thiscall *)(Scaleform::GFx::DisplayObject_vtbl **))(*v3)->CreateRenderNode)(v3)) != 0) )
    {
      v5 = v4 - 28;
    }
    else
    {
      v5 = 0;
    }
    if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 88))(v5) )
      return 1;
  }
  pParent = this->pDispObj->pParent;
  if ( pParent
    && (v8 = (*(int (__thiscall **)(int))(*((_DWORD *)&pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + pParent->AvmObjOffset)
                                        + 4))((int)pParent + 4 * pParent->AvmObjOffset)) != 0 )
  {
    v9 = (_DWORD *)(v8 - 28);
  }
  else
  {
    v9 = 0;
  }
  if ( !v9 )
    return 0;
  while ( 1 )
  {
    v10 = *(_DWORD *)(v9[3] + 32);
    if ( !v10 )
      break;
    v11 = v10 + 4 * *(unsigned __int8 *)(v10 + 65);
    v12 = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 4))(v11);
    if ( !v12 || v12 == 28 )
      break;
    v13 = *(_DWORD *)(v9[3] + 32);
    if ( v13
      && (v14 = (*(int (__thiscall **)(int))(*(_DWORD *)(v13 + 4 * *(unsigned __int8 *)(v13 + 65)) + 4))(v13 + 4 * *(unsigned __int8 *)(v13 + 65))) != 0 )
    {
      v15 = (_DWORD *)(v14 - 28);
    }
    else
    {
      v15 = 0;
    }
    v9 = v15;
    if ( !v15 )
      return 0;
  }
  return (*(int (__thiscall **)(_DWORD *))(*v9 + 88))(v9);
}
