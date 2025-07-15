Scaleform::GFx::DisplayObjectBase *__thiscall Scaleform::GFx::AS3::AvmDisplayObjContainer::RemoveChildAt(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        unsigned int index)
{
  Scaleform::GFx::DisplayObject *pDispObj; // eax
  Scaleform::GFx::DisplayList *p_LastHitTestY; // edi
  int v6; // esi
  Scaleform::GFx::InteractiveObject *v7; // edi
  int v8; // ecx
  int v9; // eax
  Scaleform::GFx::AS3::AvmInteractiveObj *v10; // eax
  void (__thiscall *v11)(int, _DWORD); // eax
  Scaleform::GFx::AS3::AvmDisplayObj *v12; // ecx

  pDispObj = this->pDispObj;
  if ( (Scaleform::Render::TreeNode *)index >= pDispObj[1].pRenNode.pObject )
    return 0;
  p_LastHitTestY = (Scaleform::GFx::DisplayList *)&pDispObj[1].LastHitTestY;
  v6 = *(_DWORD *)(LODWORD(pDispObj[1].LastHitTestY) + 12 * index);
  if ( v6 )
    ++*(_DWORD *)(v6 + 4);
  if ( (*(_BYTE *)(v6 + 63) & 1) != 0 )
    Scaleform::GFx::DisplayObject::SetMask((Scaleform::GFx::DisplayObject *)v6, 0);
  if ( *(__int16 *)(v6 + 62) < 0 )
    Scaleform::GFx::MovieImpl::RemoveTopmostLevelCharacter(
      this->pDispObj->pASRoot->pMovieImpl,
      (Scaleform::GFx::InteractiveObject *)v6);
  Scaleform::GFx::DisplayList::RemoveEntryAtIndex(p_LastHitTestY, this->pDispObj, index);
  p_LastHitTestY->Flags |= 3u;
  v7 = (unsigned __int8)*(_WORD *)(v6 + 62) >> 7 != 0 ? (Scaleform::GFx::InteractiveObject *)v6 : 0;
  if ( ((*(_WORD *)(v6 + 62) & 0x100) != 0 ? v6 : 0) != 0 )
    v8 = ((*(_WORD *)(v6 + 62) & 0x100) != 0 ? v6 : 0)
       + 4 * *(unsigned __int8 *)((*(_WORD *)(v6 + 62) & 0x100) != 0 ? v6 + 0x41 : 65);
  else
    v8 = 0;
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v8 + 56))(v8, 0);
  *(_DWORD *)(v6 + 32) = 0;
  if ( v7 && Scaleform::GFx::InteractiveObject::IsInPlayList(v7) )
  {
    v9 = (*(int (__thiscall **)(int))(*((_DWORD *)&v7->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                      + v7->AvmObjOffset)
                                    + 4))((int)v7 + 4 * v7->AvmObjOffset);
    if ( v9 )
      v10 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v9 - 28);
    else
      v10 = 0;
    Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v10);
  }
  if ( (*(_BYTE *)(v6 + 80) & 1) != 0 )
  {
    v11 = *(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v6 + 204);
    *(_WORD *)(v6 + 80) &= ~1u;
    v11(v6, 0);
    v12 = (Scaleform::GFx::AS3::AvmDisplayObj *)(v6 + 4 * *(unsigned __int8 *)(v6 + 65));
    *(_DWORD *)(v6 + 28) = 0;
    *(_DWORD *)(v6 + 24) = -1;
    Scaleform::GFx::AS3::AvmDisplayObj::OnDetachFromTimeline(v12);
  }
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v6);
  return (Scaleform::GFx::DisplayObjectBase *)v6;
}
