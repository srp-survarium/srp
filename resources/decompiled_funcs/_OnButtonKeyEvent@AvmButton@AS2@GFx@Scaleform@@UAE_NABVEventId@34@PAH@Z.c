char __thiscall Scaleform::GFx::AS2::AvmButton::OnButtonKeyEvent(
        Scaleform::GFx::AS2::AvmButton *this,
        Scaleform::GFx::MovieImpl *id,
        int *__formal)
{
  int v5; // ebx
  unsigned int v6; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // esi
  Scaleform::GFx::AvmButtonBase_vtbl *v8; // ebp
  unsigned int RefCount; // ecx
  unsigned int v10; // edx
  Scaleform::GFx::LoadQueueEntry *pLoadQueueHead; // ebx
  unsigned int pObject; // eax
  Scaleform::RefCountNTSImpl *v13; // ecx
  Scaleform::RefCountNTSImpl *v14; // ecx
  unsigned int v15; // ecx
  unsigned int v16; // edx
  unsigned int v17; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASString methodName; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::Value method; // [esp+14h] [ebp-24h] BYREF
  unsigned int v22; // [esp+24h] [ebp-14h]
  unsigned int v23; // [esp+28h] [ebp-10h]
  unsigned int v24; // [esp+2Ch] [ebp-Ch]
  unsigned int v25; // [esp+30h] [ebp-8h]
  Scaleform::GFx::LoadQueueEntry *v26; // [esp+34h] [ebp-4h]
  Scaleform::GFx::MovieImpl *proot; // [esp+3Ch] [ebp+4h]

  v5 = ((int (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface::UserDataHolder **))this[-1].pUserDataHolder[15].pUserData)(&this[-1].pUserDataHolder);
  Scaleform::GFx::AS2::EventId_GetFunctionName(
    &methodName,
    (Scaleform::GFx::AS2::StringManager *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v5 + 116) + 20) + 12) + 164),
    (const Scaleform::GFx::EventId *)id);
  proot = (Scaleform::GFx::MovieImpl *)*((_DWORD *)this[-1].ToAvmTextFieldBase + 2);
  if ( methodName.pNode->Size )
  {
    v6 = (unsigned int)id->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
    method.T.Type = 0;
    if ( v6 == 64 || v6 == 128 )
    {
      if ( ((unsigned __int8 (__thiscall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *, int, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this[-1].pProto.pObject->pWatchpoints)(
             &this[-1].pProto,
             v5 + 116,
             &methodName,
             &method) )
      {
        if ( *(_BYTE *)(v5 + 120) >= 6u )
        {
          if ( Scaleform::GFx::MovieImpl::IsKeyboardFocused(
                 proot,
                 (const Scaleform::GFx::InteractiveObject *)this[-1].Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable,
                 SBYTE1(id->pLoadQueueHead)) )
          {
            inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                         (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)((char *)this[-1].ToAvmTextFieldBase + 68),
                         AP_Frame);
            if ( inserted )
            {
              v8 = this[-1].Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable;
              RefCount = id->RefCount;
              v10 = (unsigned int)id->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::__vftable;
              pLoadQueueHead = id->pLoadQueueHead;
              v22 = (unsigned int)id->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
              pObject = (unsigned int)id->pASMovieRoot.pObject;
              v23 = RefCount;
              v24 = v10;
              v25 = pObject;
              v26 = pLoadQueueHead;
              inserted->Type = Entry_Event;
              if ( v8 )
                ++v8->ToAvmInteractiveObjBase;
              v13 = inserted->pCharacter.pObject;
              if ( v13 )
                Scaleform::RefCountNTSImpl::Release(v13);
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
              *(_WORD *)&inserted->mEventId.RollOverCnt = (_WORD)pLoadQueueHead;
              inserted->mEventId.KeysState.States = v16;
              inserted->mEventId.MouseWheelDelta = v17;
            }
          }
        }
      }
      if ( method.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&method);
    }
  }
  pNode = methodName.pNode;
  --methodName.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return 1;
}
