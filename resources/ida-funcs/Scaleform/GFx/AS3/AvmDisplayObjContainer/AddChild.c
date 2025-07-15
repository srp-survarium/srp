void __thiscall Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChild(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::InteractiveObject *ch)
{
  Scaleform::GFx::InteractiveObject *pParent; // eax
  Scaleform::GFx::DisplayObject *pDispObj; // ecx
  Scaleform::GFx::DisplayObjectBase *pObject; // ebp
  Scaleform::GFx::DisplayList *p_LastHitTestY; // edi
  int v7; // eax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v8; // ecx
  Scaleform::GFx::InteractiveObject *v9; // edx
  __int16 v10; // ax
  int v11; // eax
  Scaleform::GFx::AS3::AvmInteractiveObj *v12; // eax
  char v13; // cl
  Scaleform::GFx::DisplayObject *v14; // edi
  Scaleform::GFx::DisplayObject_vtbl **v15; // ecx
  long double *p_x1; // eax
  Scaleform::Render::Rect<double> r; // [esp+10h] [ebp-20h] BYREF

  pParent = ch->pParent;
  pDispObj = this->pDispObj;
  pObject = (Scaleform::GFx::DisplayObjectBase *)pDispObj[1].pRenNode.pObject;
  p_LastHitTestY = (Scaleform::GFx::DisplayList *)&pDispObj[1].LastHitTestY;
  if ( pParent )
  {
    if ( pParent == pDispObj )
    {
      Scaleform::GFx::AS3::AvmDisplayObjContainer::SetChildIndex(
        this,
        ch,
        (Scaleform::GFx::DisplayObjectBase *)((char *)pObject - 1));
      return;
    }
    v7 = (*(int (__thiscall **)(int))(*((_DWORD *)&pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                      + pParent->AvmObjOffset)
                                    + 20))((int)pParent + 4 * pParent->AvmObjOffset);
    if ( v7 )
      v8 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v7 - 36);
    else
      v8 = 0;
    Scaleform::GFx::AS3::AvmDisplayObjContainer::RemoveChild(v8, ch);
  }
  Scaleform::GFx::DisplayList::AddEntryAtIndex(p_LastHitTestY, this->pDispObj, pObject, ch);
  p_LastHitTestY->Flags |= 3u;
  v9 = (Scaleform::GFx::InteractiveObject *)this->pDispObj;
  ch->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags &= 0xEFEFu;
  v10 = ch->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags >> 7;
  ch->pParent = v9;
  ch->Depth = -1;
  if ( (v10 & 1) != 0 && Scaleform::GFx::InteractiveObject::IsInPlayList(ch) )
  {
    v11 = (*(int (__thiscall **)(char *))(*((_DWORD *)&ch->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                          + ch->AvmObjOffset)
                                        + 4))(
            (char *)&ch->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
          + 4 * ch->AvmObjOffset);
    if ( v11 )
      v12 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v11 - 28);
    else
      v12 = 0;
    Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v12);
  }
  v13 = HIBYTE(ch->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) & 1;
  v14 = v13 != 0 ? ch : 0;
  if ( v14 )
    v15 = &v14->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
        + *(v13 != 0 ? &ch->AvmObjOffset : (unsigned __int8 *)65);
  else
    v15 = 0;
  if ( Scaleform::GFx::AS3::VMAppDomain::Enabled )
    v15[5] = (Scaleform::GFx::DisplayObject_vtbl *)this->AppDomain;
  ((void (__thiscall *)(Scaleform::GFx::DisplayObject_vtbl **, _DWORD))(*v15)->SetX)(v15, 0);
  p_x1 = &v14->pScrollRect->Rectangle.x1;
  if ( p_x1 )
  {
    r.x1 = *p_x1;
    r.y1 = p_x1[1];
    r.x2 = p_x1[2];
    r.y2 = p_x1[3];
    Scaleform::GFx::DisplayObject::SetScrollRect(v14, &r);
  }
}
