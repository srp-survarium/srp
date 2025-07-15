char __thiscall Scaleform::GFx::AS2::AvmButton::OnButtonKeyEvent(
        Scaleform::GFx::AS2::AvmButton *this,
        const Scaleform::GFx::EventId *id,
        int *__formal)
{
  int v5; // ebx
  unsigned int v6; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // esi
  Scaleform::GFx::AvmButtonBase_vtbl *v8; // ebp
  unsigned int WcharCode; // ecx
  unsigned int KeyCode; // edx
  int v11; // ebx
  unsigned int TouchID; // eax
  Scaleform::RefCountNTSImpl *pObject; // ecx
  Scaleform::RefCountNTSImpl *v14; // ecx
  unsigned int v15; // ecx
  unsigned int v16; // edx
  unsigned int v17; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString result; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::Value v21; // [esp+14h] [ebp-24h] BYREF
  unsigned int v22; // [esp+24h] [ebp-14h]
  unsigned int v23; // [esp+28h] [ebp-10h]
  unsigned int v24; // [esp+2Ch] [ebp-Ch]
  unsigned int v25; // [esp+30h] [ebp-8h]
  int v26; // [esp+34h] [ebp-4h]
  Scaleform::GFx::MovieImpl *evt; // [esp+3Ch] [ebp+4h]

  v5 = ((int (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface::UserDataHolder **))this[-1].pUserDataHolder[15].pUserData)(&this[-1].pUserDataHolder);
  Scaleform::GFx::AS2::EventId_GetFunctionName(
    &result,
    (Scaleform::GFx::AS2::StringManager *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v5 + 116) + 20) + 12) + 164),
    id);
  evt = (Scaleform::GFx::MovieImpl *)*((_DWORD *)this[-1].ToAvmTextFieldBase + 2);
  if ( result.pNode->Size )
  {
    v6 = id->Id;
    v21.T.Type = 0;
    if ( v6 == 64 || v6 == 128 )
    {
      if ( ((unsigned __int8 (__thiscall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *, int, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this[-1].pProto.pObject->pWatchpoints)(
             &this[-1].pProto,
             v5 + 116,
             &result,
             &v21) )
      {
        if ( *(_BYTE *)(v5 + 120) >= 6u )
        {
          if ( Scaleform::GFx::MovieImpl::IsKeyboardFocused(
                 evt,
                 (Scaleform::GFx::Sprite *)this[-1].Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable,
                 (Scaleform::Ptr<Scaleform::GFx::Sprite>)id->ControllerIndex) )
          {
            inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                         (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)((char *)this[-1].ToAvmTextFieldBase + 68),
                         AP_Frame);
            if ( inserted )
            {
              v8 = this[-1].Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable;
              WcharCode = id->WcharCode;
              KeyCode = id->KeyCode;
              v11 = *(_DWORD *)&id->RollOverCnt;
              v22 = id->Id;
              TouchID = id->TouchID;
              v23 = WcharCode;
              v24 = KeyCode;
              v25 = TouchID;
              v26 = v11;
              inserted->Type = Entry_Event;
              if ( v8 )
                ++v8->ToAvmInteractiveObjBase;
              pObject = inserted->pCharacter.pObject;
              if ( pObject )
                Scaleform::RefCountNTSImpl::Release(pObject);
              inserted->pCharacter.pObject = (Scaleform::GFx::InteractiveObject *)v8;
              v14 = inserted->pActionBuffer.pObject;
              if ( v14 )
                Scaleform::RefCountNTSImpl::Release(v14);
              v15 = v22;
              v16 = v23;
              v17 = v24;
              inserted->pActionBuffer.pObject = 0;
              inserted->mEventId.Id = v15;
              LOBYTE(v15) = v25;
              inserted->mEventId.WcharCode = v16;
              LOBYTE(v16) = BYTE2(v26);
              inserted->mEventId.KeyCode = v17;
              LOBYTE(v17) = HIBYTE(v26);
              inserted->mEventId.AsciiCode = v15;
              *(_WORD *)&inserted->mEventId.RollOverCnt = v11;
              inserted->mEventId.KeysState.States = v16;
              inserted->mEventId.MouseWheelDelta = v17;
            }
          }
        }
      }
      if ( v21.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v21);
    }
  }
  pNode = result.pNode;
  --result.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return 1;
}
