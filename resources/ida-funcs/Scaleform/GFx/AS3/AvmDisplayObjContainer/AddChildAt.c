void __thiscall Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChildAt(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::InteractiveObject *ch,
        Scaleform::GFx::DisplayObjectBase *index)
{
  Scaleform::GFx::DisplayObject *pDispObj; // ecx
  Scaleform::GFx::DisplayObjectBase *pObject; // edi
  Scaleform::GFx::InteractiveObject *pParent; // eax
  Scaleform::GFx::DisplayList *p_LastHitTestY; // ebp
  int v8; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v9; // eax
  Scaleform::GFx::InteractiveObject *v10; // edx
  __int16 v11; // ax
  int v12; // eax
  Scaleform::GFx::AS3::AvmInteractiveObj *v13; // eax
  char v14; // cl
  Scaleform::GFx::DisplayObject *v15; // edi
  Scaleform::GFx::DisplayObject_vtbl **v16; // ecx
  long double *p_x1; // eax
  Scaleform::Render::Rect<double> r; // [esp+10h] [ebp-20h] BYREF

  pDispObj = this->pDispObj;
  pObject = index;
  if ( (Scaleform::Render::TreeNode *)index > pDispObj[1].pRenNode.pObject )
    pObject = (Scaleform::GFx::DisplayObjectBase *)pDispObj[1].pRenNode.pObject;
  pParent = ch->pParent;
  p_LastHitTestY = (Scaleform::GFx::DisplayList *)&pDispObj[1].LastHitTestY;
  if ( pParent )
  {
    if ( pParent == pDispObj )
    {
      Scaleform::GFx::AS3::AvmDisplayObjContainer::SetChildIndex(this, ch, pObject);
      return;
    }
    v8 = (*(int (__thiscall **)(int))(*((_DWORD *)&pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                      + pParent->AvmObjOffset)
                                    + 20))((int)pParent + 4 * pParent->AvmObjOffset);
    if ( v8 )
      v9 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v8 - 36);
    else
      v9 = 0;
    Scaleform::GFx::AS3::AvmDisplayObjContainer::RemoveChild(v9, ch);
  }
  Scaleform::GFx::DisplayList::AddEntryAtIndex(p_LastHitTestY, this->pDispObj, pObject, ch);
  v10 = (Scaleform::GFx::InteractiveObject *)this->pDispObj;
  ch->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags &= 0xEFEFu;
  v11 = ch->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags >> 7;
  ch->pParent = v10;
  ch->Depth = -1;
  if ( (v11 & 1) != 0 && Scaleform::GFx::InteractiveObject::IsInPlayList(ch) )
  {
    v12 = (*(int (__thiscall **)(char *))(*((_DWORD *)&ch->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + ch->AvmObjOffset)
                                        + 4))(
            (char *)&ch->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
          + 4 * ch->AvmObjOffset);
    if ( v12 )
      v13 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v12 - 28);
    else
      v13 = 0;
    Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v13);
  }
  v14 = HIBYTE(ch->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) & 1;
  v15 = v14 != 0 ? ch : 0;
  if ( v15 )
    v16 = &v15->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
        + *(v14 != 0 ? &ch->AvmObjOffset : (unsigned __int8 *)65);
  else
    v16 = 0;
  if ( Scaleform::GFx::AS3::VMAppDomain::Enabled )
    v16[5] = (Scaleform::GFx::DisplayObject_vtbl *)this->AppDomain;
  ((void (__thiscall *)(Scaleform::GFx::DisplayObject_vtbl **, _DWORD))(*v16)->SetX)(v16, 0);
  p_x1 = &v15->pScrollRect->Rectangle.x1;
  if ( p_x1 )
  {
    r.x1 = *p_x1;
    r.y1 = p_x1[1];
    r.x2 = p_x1[2];
    r.y2 = p_x1[3];
    Scaleform::GFx::DisplayObject::SetScrollRect(v15, &r);
  }
}
