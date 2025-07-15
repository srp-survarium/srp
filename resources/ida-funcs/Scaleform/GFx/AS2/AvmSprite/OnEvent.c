char __thiscall Scaleform::GFx::AS2::AvmSprite::OnEvent(
        Scaleform::GFx::AS2::AvmSprite *this,
        const Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::Sprite *pDispObj; // ecx
  Scaleform::GFx::TimelineDef *pObject; // eax
  const Scaleform::GFx::EventId *v5; // edi
  char Value; // dl
  HINSTANCE__ *v7; // eax
  Scaleform::GFx::ASMovieRootBase *v8; // esi
  int v9; // eax
  int v10; // eax
  Scaleform::GFx::AS2::MovieClipObject *v11; // eax
  char v12; // bl
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // esi
  Scaleform::GFx::InteractiveObject *v15; // ebp
  unsigned int WcharCode; // edx
  unsigned int KeyCode; // eax
  int v18; // ebx
  unsigned int TouchID; // ecx
  Scaleform::RefCountNTSImpl *v20; // ecx
  Scaleform::RefCountNTSImpl *v21; // ecx
  __int64 v22; // kr00_8
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned __int8 Flags; // dl
  unsigned __int8 v25; // al
  Scaleform::GFx::ASStringNode *v27; // eax
  Scaleform::GFx::AS2::Value v28; // [esp+10h] [ebp-14h] BYREF
  int v29; // [esp+20h] [ebp-4h]

  pDispObj = (Scaleform::GFx::Sprite *)this->pDispObj;
  if ( (pDispObj->Flags & 0x40) != 0 )
    pObject = pDispObj->pDef.pObject;
  else
    pObject = 0;
  v5 = id;
  if ( !pObject )
    goto LABEL_13;
  Value = pObject[3].RefCount.Value;
  if ( (Value & 7) == 0 )
    goto LABEL_13;
  v7 = (HINSTANCE__ *)id->Id;
  if ( id->Id > 0x2000 )
  {
    if ( v7 == (HINSTANCE__ *)0x4000 )
    {
LABEL_11:
      if ( (Value & 1) != 0 )
        Scaleform::GFx::Sprite::GotoLabeledFrame(pDispObj, "_up", 0);
      goto LABEL_13;
    }
    if ( v7 != &_sbh_sizeHeaderList )
      goto LABEL_13;
    goto LABEL_20;
  }
  if ( id->Id == 0x2000 )
  {
LABEL_20:
    if ( (Value & 4) != 0 )
      Scaleform::GFx::Sprite::GotoLabeledFrame(pDispObj, "_over", 0);
    goto LABEL_13;
  }
  if ( v7 != (HINSTANCE__ *)1024 )
  {
    if ( v7 != (HINSTANCE__ *)2048 )
    {
      if ( v7 != (HINSTANCE__ *)4096 )
        goto LABEL_13;
      goto LABEL_11;
    }
    goto LABEL_20;
  }
  if ( (Value & 2) != 0 )
    Scaleform::GFx::Sprite::GotoLabeledFrame(pDispObj, "_down", 0);
LABEL_13:
  if ( Scaleform::GFx::AS2::AvmCharacter::HasClipEventHandler(this, v5) )
  {
LABEL_40:
    inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                 (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&this->pDispObj->pASRoot[3].pMovieImpl,
                 AP_Frame);
    if ( inserted )
    {
      v15 = this->pDispObj;
      WcharCode = v5->WcharCode;
      KeyCode = v5->KeyCode;
      v18 = *(_DWORD *)&v5->RollOverCnt;
      *(_DWORD *)&v28.T.Type = v5->Id;
      TouchID = v5->TouchID;
      *(_QWORD *)&v28.NV.NumberValue = __PAIR64__(KeyCode, WcharCode);
      *((_DWORD *)&v28.NV + 3) = TouchID;
      v29 = v18;
      inserted->Type = Entry_Event;
      if ( v15 )
        ++v15->RefCount;
      v20 = inserted->pCharacter.pObject;
      if ( v20 )
        Scaleform::RefCountNTSImpl::Release(v20);
      inserted->pCharacter.pObject = v15;
      v21 = inserted->pActionBuffer.pObject;
      if ( v21 )
        Scaleform::RefCountNTSImpl::Release(v21);
      v22 = *(_QWORD *)&v28.T.Type;
      pLocalFrame = v28.V.FunctionValue.pLocalFrame;
      inserted->pActionBuffer.pObject = 0;
      inserted->mEventId.Id = v22;
      Flags = v28.V.FunctionValue.Flags;
      inserted->mEventId.WcharCode = HIDWORD(v22);
      v25 = BYTE2(v29);
      inserted->mEventId.KeyCode = (unsigned int)pLocalFrame;
      LOBYTE(pLocalFrame) = HIBYTE(v29);
      inserted->mEventId.AsciiCode = Flags;
      *(_WORD *)&inserted->mEventId.RollOverCnt = v18;
      inserted->mEventId.KeysState.States = v25;
      inserted->mEventId.MouseWheelDelta = (char)pLocalFrame;
    }
    return 1;
  }
  v8 = this->GetASEnvironment(this)->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject;
  if ( v5->Id > 0x800000 )
    v9 = v5->Id - 16777191;
  else
    v9 = (unsigned __int8)Scaleform::Alg::BitCount32(v5->Id);
  if ( (unsigned int)(v9 - 1) > 0x21 )
    v10 = 46;
  else
    v10 = dword_6F9848[v9];
  id = (const Scaleform::GFx::EventId *)*((_DWORD *)&v8[8].RefCount + v10);
  ++id->TouchID;
  if ( id[1].Id )
  {
    v11 = this->ASMovieClipObj.pObject;
    v12 = 0;
    v28.T.Type = 0;
    if ( (v11 || (v11 = (Scaleform::GFx::AS2::MovieClipObject *)this->pProto.pObject) != 0)
      && v11->GetMemberRaw(
           &v11->Scaleform::GFx::AS2::ObjectInterface,
           &this->ASEnvironment.StringContext,
           (const Scaleform::GFx::ASString *)&id,
           &v28) )
    {
      v12 = 1;
    }
    if ( (v5->Id != 64 && v5->Id != 128
       || this->ASEnvironment.StringContext.SWFVersion >= 6u
       && Scaleform::GFx::MovieImpl::IsKeyboardFocused(
            this->pDispObj->pASRoot->pMovieImpl,
            (Scaleform::GFx::Sprite *)this->pDispObj,
            (Scaleform::Ptr<Scaleform::GFx::Sprite>)v5->ControllerIndex))
      && v12 )
    {
      if ( v28.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v28);
      v13 = (Scaleform::GFx::ASStringNode *)id;
      --id->TouchID;
      if ( !v13->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
      goto LABEL_40;
    }
    if ( v28.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v28);
  }
  v27 = (Scaleform::GFx::ASStringNode *)id;
  --id->TouchID;
  if ( !v27->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v27);
  return 0;
}


char __thiscall Scaleform::GFx::AS2::AvmSprite::OnEvent(char *this, const Scaleform::GFx::EventId *a2)
{
  return Scaleform::GFx::AS2::AvmSprite::OnEvent((Scaleform::GFx::AS2::AvmSprite *)(this - 24), a2);
}
