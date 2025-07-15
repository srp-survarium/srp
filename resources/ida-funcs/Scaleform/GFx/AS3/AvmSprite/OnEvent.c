char __thiscall Scaleform::GFx::AS3::AvmSprite::OnEvent(
        Scaleform::GFx::AS3::AvmSprite *this,
        const Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::Sprite *pDispObj; // esi
  Scaleform::GFx::TimelineDef *pObject; // eax
  char Value; // cl
  HINSTANCE__ *v6; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // eax
  unsigned int WcharCode; // edx
  unsigned int KeyCode; // ecx
  unsigned int TouchID; // edx
  int v11; // ecx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v12; // ecx
  Scaleform::GFx::MouseState *MouseState; // eax
  Scaleform::GFx::EventId e; // [esp+8h] [ebp-14h] BYREF

  if ( (this->Flags & 1) == 0 )
    return Scaleform::GFx::AS3::AvmInteractiveObj::OnEvent(this, id);
  pDispObj = (Scaleform::GFx::Sprite *)this->pDispObj;
  if ( (pDispObj->Flags & 0x40) != 0 )
    pObject = pDispObj->pDef.pObject;
  else
    pObject = 0;
  if ( !pObject )
    goto LABEL_18;
  Value = pObject[3].RefCount.Value;
  if ( (Value & 7) == 0 )
    goto LABEL_18;
  v6 = (HINSTANCE__ *)id->Id;
  if ( id->Id > 0x2000 )
  {
    if ( v6 != (HINSTANCE__ *)0x4000 )
    {
      if ( v6 == (HINSTANCE__ *)0x8000 )
        goto LABEL_38;
      if ( v6 != &_sbh_sizeHeaderList )
        goto LABEL_18;
      if ( (pDispObj->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags & 0x4000) == 0 )
        goto LABEL_13;
    }
LABEL_16:
    if ( (Value & 1) != 0 )
      Scaleform::GFx::Sprite::GotoLabeledFrame(pDispObj, "_up", 0);
    goto LABEL_18;
  }
  if ( id->Id == 0x2000 )
  {
    if ( (Value & 4) == 0 )
      goto LABEL_18;
    MouseState = Scaleform::GFx::MovieImpl::GetMouseState(pDispObj->pASRoot->pMovieImpl, id->ControllerIndex);
    if ( (pDispObj->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags & 0x4000) != 0
      && (MouseState->PrevButtonsState & 1) != 0 )
    {
      goto LABEL_30;
    }
    if ( (MouseState->CurButtonsState & 1) == 0 )
    {
LABEL_14:
      Scaleform::GFx::Sprite::GotoLabeledFrame(pDispObj, "_over", 0);
      goto LABEL_18;
    }
    goto LABEL_18;
  }
  if ( (unsigned int)v6 > 0x800 )
  {
    if ( v6 != (HINSTANCE__ *)4096 )
      goto LABEL_18;
    goto LABEL_16;
  }
  if ( v6 == (HINSTANCE__ *)2048 )
    goto LABEL_13;
  if ( v6 != (HINSTANCE__ *)16 )
  {
    if ( v6 != (HINSTANCE__ *)32 )
      goto LABEL_18;
LABEL_13:
    if ( (Value & 4) == 0 )
      goto LABEL_18;
    goto LABEL_14;
  }
LABEL_38:
  if ( (Value & 2) != 0 )
LABEL_30:
    Scaleform::GFx::Sprite::GotoLabeledFrame(pDispObj, "_down", 0);
LABEL_18:
  if ( id->Id != 1024 )
    return Scaleform::GFx::AS3::AvmInteractiveObj::OnEvent(this, id);
  pAS3RawPtr = this->pAS3RawPtr;
  if ( pAS3RawPtr || this->pAS3CollectiblePtr.pObject )
  {
    WcharCode = id->WcharCode;
    e.Id = id->Id;
    KeyCode = id->KeyCode;
    e.WcharCode = WcharCode;
    TouchID = id->TouchID;
    e.KeyCode = KeyCode;
    v11 = *(_DWORD *)&id->RollOverCnt;
    e.TouchID = TouchID;
    *(_DWORD *)&e.RollOverCnt = v11;
    e.Id = 16777228;
    if ( !pAS3RawPtr )
      pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
    v12 = pAS3RawPtr;
    if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
      v12 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(v12, &e, this->pDispObj);
  }
  return 1;
}


bool __thiscall Scaleform::GFx::AS3::AvmSprite::OnEvent(char *this, const Scaleform::GFx::EventId *a2)
{
  return Scaleform::GFx::AS3::AvmSprite::OnEvent((Scaleform::GFx::AS3::AvmSprite *)(this - 28), a2);
}


bool __thiscall Scaleform::GFx::AS3::AvmSprite::OnEvent(char *this, const Scaleform::GFx::EventId *a2)
{
  return Scaleform::GFx::AS3::AvmSprite::OnEvent((Scaleform::GFx::AS3::AvmSprite *)(this - 36), a2);
}


bool __thiscall Scaleform::GFx::AS3::AvmSprite::OnEvent(char *this, const Scaleform::GFx::EventId *a2)
{
  return Scaleform::GFx::AS3::AvmSprite::OnEvent((Scaleform::GFx::AS3::AvmSprite *)(this - 40), a2);
}
