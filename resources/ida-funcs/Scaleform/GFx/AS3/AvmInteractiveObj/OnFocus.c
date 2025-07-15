void __thiscall Scaleform::GFx::AS3::AvmInteractiveObj::OnFocus(
        Scaleform::GFx::AS3::AvmInteractiveObj *this,
        const char *evt,
        Scaleform::GFx::InteractiveObject *oldOrNewFocusCh,
        Scaleform::GFx::AS3::Instances::fl_events::FocusEvent_vtbl *controllerIdx,
        Scaleform::GFx::FocusMovedType __formal)
{
  bool v6; // zf
  int v7; // eax
  int v8; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v9; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v10; // ebp
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *pClassName; // eax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v12; // ebx
  int v13; // ecx
  Scaleform::GFx::ASStringManager *v14; // esi
  Scaleform::GFx::InteractiveObject *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *pObject; // ecx
  Scaleform::GFx::AS3::Instances::fl_events::FocusEvent_vtbl *v19; // [esp-18h] [ebp-24h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent> focusEvt; // [esp+4h] [ebp-8h] BYREF
  Scaleform::GFx::AS3::AvmInteractiveObj *v21; // [esp+8h] [ebp-4h]
  char *focusName; // [esp+10h] [ebp+4h]

  v6 = this[-1].pClassName == 0;
  v21 = this;
  if ( !v6 || this[-1].pDispObj )
  {
    v6 = evt == 0;
    focusName = "focusOut";
    if ( !v6 )
      focusName = "focusIn";
    if ( oldOrNewFocusCh )
    {
      v7 = (*(int (__thiscall **)(char *))(*((_DWORD *)&oldOrNewFocusCh->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                           + oldOrNewFocusCh->AvmObjOffset)
                                         + 4))(
             (char *)&oldOrNewFocusCh->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
           + 4 * oldOrNewFocusCh->AvmObjOffset);
      if ( v7 )
        v8 = v7 - 28;
      else
        v8 = 0;
      if ( *(_DWORD *)(v8 + 8) )
        v9 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v8 + 8);
      else
        v9 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v8 + 4);
      if ( ((unsigned __int8)v9 & 1) != 0 )
        v9 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v9 - 1);
      v10 = v9;
    }
    else
    {
      v10 = 0;
    }
    pClassName = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].pClassName;
    if ( !pClassName )
      pClassName = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].pDispObj;
    v12 = pClassName;
    if ( ((unsigned __int8)pClassName & 1) != 0 )
      v12 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)pClassName - 1);
    v13 = *(_DWORD *)(*((_DWORD *)this[-1].AppDomain->ChildDomains.Data.Data + 2) + 12);
    v14 = (Scaleform::GFx::ASStringManager *)(*(int (__thiscall **)(int))(*(_DWORD *)v13 + 208))(v13);
    ConstStringNode = (Scaleform::GFx::InteractiveObject *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                             v14,
                                                             focusName,
                                                             strlen(focusName),
                                                             0);
    v19 = controllerIdx;
    oldOrNewFocusCh = ConstStringNode;
    ++ConstStringNode->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable;
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateFocusEventObject(
      v12,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&focusEvt,
      (const Scaleform::GFx::ASString *)&oldOrNewFocusCh,
      v10,
      v19,
      0,
      0);
    v16 = (Scaleform::GFx::ASStringNode *)oldOrNewFocusCh;
    --oldOrNewFocusCh->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable;
    if ( !v16->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
      v12,
      focusEvt.pObject,
      (Scaleform::GFx::DisplayObject *)v21[-1].AppDomain);
    if ( focusEvt.pObject && ((int)focusEvt.pObject & 1) == 0 )
    {
      RefCount = focusEvt.pObject->RefCount;
      pObject = focusEvt.pObject;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        focusEvt.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
}
