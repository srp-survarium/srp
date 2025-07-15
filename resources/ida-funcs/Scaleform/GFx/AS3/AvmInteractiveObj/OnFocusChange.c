char __thiscall Scaleform::GFx::AS3::AvmInteractiveObj::OnFocusChange(
        Scaleform::GFx::AS3::AvmInteractiveObj *this,
        Scaleform::GFx::AS3::Instances::fl_events::Event *toBeFocused,
        Scaleform::GFx::AS3::Instances::fl_events::FocusEvent_vtbl *controllerIdx,
        Scaleform::GFx::FocusMovedType fmt,
        Scaleform::GFx::ProcessFocusKeyInfo *pfocusKeyInfo)
{
  int v6; // eax
  int v7; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v8; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v9; // ebp
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // eax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v11; // ebx
  Scaleform::GFx::ASMovieRootBase *pObject; // ecx
  Scaleform::GFx::ASStringManager *v13; // esi
  Scaleform::GFx::ASStringNode *ConstStringNode; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ProcessFocusKeyInfo *v16; // eax
  bool v17; // bl
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_events::Event *v19; // ecx
  Scaleform::GFx::AS3::Instances::fl_events::FocusEvent_vtbl *v21; // [esp-18h] [ebp-28h]
  char *focusName; // [esp+4h] [ebp-Ch]
  Scaleform::GFx::ASString type; // [esp+8h] [ebp-8h] BYREF
  Scaleform::GFx::AS3::AvmInteractiveObj *v24; // [esp+Ch] [ebp-4h]

  v24 = this;
  focusName = "keyFocusChange";
  if ( fmt != GFx_FocusMovedByKeyboard )
    focusName = "mouseFocusChange";
  if ( !this->pAS3RawPtr && !this->pAS3CollectiblePtr.pObject )
    return 1;
  if ( toBeFocused )
  {
    v6 = (*(int (__thiscall **)(char *))(*((_DWORD *)&toBeFocused->__vftable + BYTE1(toBeFocused[1].pPrev)) + 4))((char *)&toBeFocused->__vftable + 4 * BYTE1(toBeFocused[1].pPrev));
    if ( v6 )
      v7 = v6 - 28;
    else
      v7 = 0;
    if ( *(_DWORD *)(v7 + 8) )
      v8 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v7 + 8);
    else
      v8 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v7 + 4);
    if ( ((unsigned __int8)v8 & 1) != 0 )
      v8 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v8 - 1);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  pAS3RawPtr = this->pAS3RawPtr;
  if ( !pAS3RawPtr )
    pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
  v11 = pAS3RawPtr;
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    v11 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
  pObject = this->pDispObj->pASRoot->pMovieImpl->pASMovieRoot.pObject;
  v13 = pObject->GetStringManager(pObject);
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(v13, focusName, strlen(focusName), 0);
  v21 = controllerIdx;
  type.pNode = ConstStringNode;
  ++ConstStringNode->RefCount;
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateFocusEventObject(
    v11,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&toBeFocused,
    &type,
    v9,
    v21,
    0,
    0);
  pNode = type.pNode;
  --type.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  *((_BYTE *)toBeFocused + 48) |= 2u;
  if ( fmt == GFx_FocusMovedByKeyboard )
  {
    v16 = pfocusKeyInfo;
    toBeFocused[1].pRCCRaw = pfocusKeyInfo->KeyCode;
    LOBYTE(toBeFocused[1].__vftable) = v16->KeysState & 1;
  }
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(v11, toBeFocused, v24->pDispObj);
  v17 = (*((_BYTE *)toBeFocused + 48) & 4) == 0;
  if ( ((unsigned __int8)toBeFocused & 1) == 0 )
  {
    RefCount = toBeFocused->RefCount;
    v19 = toBeFocused;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      toBeFocused->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v19);
    }
  }
  return v17;
}
