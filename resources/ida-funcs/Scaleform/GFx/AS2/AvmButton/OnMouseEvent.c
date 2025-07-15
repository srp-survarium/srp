char __thiscall Scaleform::GFx::AS2::AvmButton::OnMouseEvent(
        Scaleform::GFx::AS2::AvmButton *this,
        const Scaleform::GFx::EventId *event)
{
  const Scaleform::GFx::EventId *v2; // edi
  Scaleform::GFx::AS2::AvmButton *v3; // ebp
  HINSTANCE__ *Id; // eax
  Scaleform::GFx::AvmButtonBase_vtbl *v5; // ecx
  bool (__thiscall *OnEvent)(Scaleform::GFx::AvmDisplayObjBase *, const Scaleform::GFx::EventId *); // eax
  unsigned int v7; // esi
  Scaleform::GFx::AvmTextFieldBase *(__thiscall *ToAvmTextFieldBase)(Scaleform::GFx::AvmDisplayObjBase *); // ecx
  unsigned int v9; // eax
  _DWORD *v10; // ebx
  Scaleform::GFx::AS2::ASStringContext *v11; // edi
  unsigned int v12; // ebp
  int v13; // eax
  Scaleform::GFx::AS2::ActionBuffer *v14; // eax
  Scaleform::GFx::AS2::ActionBuffer *v15; // eax
  Scaleform::GFx::AS2::ActionBuffer *v16; // esi
  int v17; // eax
  int v18; // esi
  Scaleform::GFx::ASStringHash_GC<Scaleform::GFx::AS2::Object::Watchpoint> *pWatchpoints; // eax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // esi
  unsigned int KeyCode; // eax
  unsigned int TouchID; // ecx
  int v23; // ebx
  unsigned int v24; // ebp
  Scaleform::GFx::AvmButtonBase_vtbl *v25; // edi
  Scaleform::RefCountNTSImpl *pObject; // ecx
  Scaleform::RefCountNTSImpl *v27; // ecx
  unsigned int v28; // eax
  unsigned int v29; // ecx
  unsigned __int8 v30; // dl
  Scaleform::GFx::ASStringNode *v31; // eax
  char v33; // [esp+15h] [ebp-49h]
  int v34; // [esp+16h] [ebp-48h]
  int v35; // [esp+1Ah] [ebp-44h]
  unsigned int v36; // [esp+1Eh] [ebp-40h]
  unsigned int v37; // [esp+22h] [ebp-3Ch]
  Scaleform::GFx::AvmTextFieldBase *(__thiscall *v39)(Scaleform::GFx::AvmDisplayObjBase *); // [esp+2Ah] [ebp-34h]
  Scaleform::GFx::AS2::AvmSprite *v40; // [esp+2Eh] [ebp-30h]
  unsigned int v41; // [esp+32h] [ebp-2Ch]
  unsigned int v42; // [esp+36h] [ebp-28h]
  Scaleform::GFx::AS2::Value v43; // [esp+3Ah] [ebp-24h] BYREF
  unsigned int WcharCode; // [esp+4Eh] [ebp-10h]
  unsigned int v45; // [esp+52h] [ebp-Ch]
  unsigned int v46; // [esp+56h] [ebp-8h]
  int v47; // [esp+5Ah] [ebp-4h]

  v2 = event;
  v3 = this;
  v33 = 0;
  if ( !event->RollOverCnt )
  {
    Id = (HINSTANCE__ *)event->Id;
    v34 = 0;
    v35 = 0;
    if ( event->Id == 0x2000 )
    {
      v34 = 1;
    }
    else if ( Id == (HINSTANCE__ *)0x4000 )
    {
      v34 = 2;
    }
    else if ( Id == (HINSTANCE__ *)1024 )
    {
      v34 = 4;
    }
    else if ( Id == (HINSTANCE__ *)2048 )
    {
      v34 = 8;
    }
    else if ( Id == &_sbh_sizeHeaderList )
    {
      v34 = 16;
    }
    else if ( Id == (HINSTANCE__ *)0x8000 )
    {
      v34 = 32;
    }
    else if ( Id == (HINSTANCE__ *)4096 )
    {
      v34 = 64;
    }
    else if ( Id == (HINSTANCE__ *)&loc_20000 )
    {
      v35 = Scaleform::GFx::EventId::ConvertToButtonKeyCode(event);
    }
    v5 = v3[-1].Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable;
    OnEvent = v5->OnEvent;
    if ( OnEvent )
    {
      v7 = (*((_WORD *)OnEvent + 31) & 0x400) != 0 ? (unsigned int)OnEvent : 0;
      v36 = v7;
      if ( v7 )
      {
        ToAvmTextFieldBase = v5[1].ToAvmTextFieldBase;
        v9 = 0;
        v39 = ToAvmTextFieldBase;
        v37 = 0;
        v42 = *((_DWORD *)ToAvmTextFieldBase + 9);
        if ( v42 )
        {
          while ( 1 )
          {
            v10 = *(_DWORD **)(*((_DWORD *)ToAvmTextFieldBase + 8) + 4 * v9);
            if ( (v34 & v10[2] & 0xFFFF01FF) != 0 || v35 > 0 && (((int)v10[2] >> 9) & 0x7F) == v35 )
            {
              v40 = (Scaleform::GFx::AS2::AvmSprite *)(v7 + 4 * *(unsigned __int8 *)(v7 + 65));
              v11 = (Scaleform::GFx::AS2::ASStringContext *)(((int (*)(void))v40->GetASEnvironment)() + 116);
              v12 = 0;
              v41 = v10[4];
              if ( v41 )
              {
                do
                {
                  v13 = *(_DWORD *)(v10[3] + 4 * v12);
                  if ( *(_DWORD *)(v13 + 12) && **(_BYTE **)(v13 + 8) )
                  {
                    v14 = (Scaleform::GFx::AS2::ActionBuffer *)v11->pContext->pHeap->Alloc(v11->pContext->pHeap, 32u, 0);
                    if ( v14 )
                    {
                      Scaleform::GFx::AS2::ActionBuffer::ActionBuffer(
                        v14,
                        v11,
                        *(Scaleform::GFx::Resource **)(v10[3] + 4 * v12));
                      v16 = v15;
                    }
                    else
                    {
                      v16 = 0;
                    }
                    Scaleform::GFx::AS2::AvmSprite::AddActionBuffer(v40, v16, AP_Frame);
                    if ( v16 )
                      Scaleform::RefCountNTSImpl::Release(v16);
                    v7 = v36;
                  }
                  ++v12;
                }
                while ( v12 < v41 );
                v33 = 1;
              }
              v2 = event;
            }
            v9 = v37 + 1;
            v37 = v9;
            if ( v9 >= v42 )
              break;
            ToAvmTextFieldBase = v39;
          }
          v3 = this;
        }
      }
    }
  }
  v17 = ((int (__thiscall *)(Scaleform::GFx::AS2::ObjectInterface::UserDataHolder **))v3[-1].pUserDataHolder[15].pUserData)(&v3[-1].pUserDataHolder);
  if ( v17 )
  {
    v18 = v17 + 116;
    Scaleform::GFx::AS2::EventId_GetFunctionName(
      (Scaleform::GFx::ASString *)&event,
      (Scaleform::GFx::AS2::StringManager *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v17 + 116) + 20) + 12) + 164),
      v2);
    if ( event[1].Id )
    {
      pWatchpoints = v3[-1].pProto.pObject->pWatchpoints;
      v43.T.Type = 0;
      if ( ((unsigned __int8 (__thiscall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *, int, const Scaleform::GFx::EventId **, Scaleform::GFx::AS2::Value *))pWatchpoints)(
             &v3[-1].pProto,
             v18,
             &event,
             &v43) )
      {
        v33 = 1;
        inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                     (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)((char *)v3[-1].ToAvmTextFieldBase + 68),
                     AP_Frame);
        if ( inserted )
        {
          KeyCode = v2->KeyCode;
          TouchID = v2->TouchID;
          v23 = *(_DWORD *)&v2->RollOverCnt;
          v24 = v2->Id;
          WcharCode = v2->WcharCode;
          v25 = this[-1].Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable;
          v45 = KeyCode;
          v46 = TouchID;
          v47 = v23;
          inserted->Type = Entry_Event;
          if ( v25 )
            ++v25->ToAvmInteractiveObjBase;
          pObject = inserted->pCharacter.pObject;
          if ( pObject )
            Scaleform::RefCountNTSImpl::Release(pObject);
          inserted->pCharacter.pObject = (Scaleform::GFx::InteractiveObject *)v25;
          v27 = inserted->pActionBuffer.pObject;
          if ( v27 )
            Scaleform::RefCountNTSImpl::Release(v27);
          v28 = WcharCode;
          v29 = v45;
          v30 = v46;
          inserted->pActionBuffer.pObject = 0;
          inserted->mEventId.WcharCode = v28;
          LOBYTE(v28) = BYTE2(v47);
          inserted->mEventId.KeyCode = v29;
          LOBYTE(v29) = HIBYTE(v47);
          inserted->mEventId.Id = v24;
          inserted->mEventId.AsciiCode = v30;
          *(_WORD *)&inserted->mEventId.RollOverCnt = v23;
          inserted->mEventId.KeysState.States = v28;
          inserted->mEventId.MouseWheelDelta = v29;
        }
      }
      if ( v43.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v43);
    }
    v31 = (Scaleform::GFx::ASStringNode *)event;
    --event->TouchID;
    if ( !v31->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v31);
  }
  return v33;
}
