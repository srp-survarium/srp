bool __thiscall Scaleform::GFx::AS2::AvmButton::OnMouseEvent(
        Scaleform::GFx::AS2::AvmButton *this,
        const Scaleform::GFx::EventId *event)
{
  const Scaleform::GFx::EventId *v2; // edi
  Scaleform::GFx::AS2::AvmButton *v3; // ebp
  HINSTANCE__ *Id; // eax
  Scaleform::GFx::AvmButtonBase_vtbl *v5; // ecx
  bool (__thiscall *OnEvent)(Scaleform::GFx::AvmDisplayObjBase *, const Scaleform::GFx::EventId *); // eax
  Scaleform::GFx::Sprite *v7; // esi
  Scaleform::GFx::ButtonDef *ToAvmTextFieldBase; // ecx
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
  bool handlerFound; // [esp+15h] [ebp-49h]
  int c; // [esp+16h] [ebp-48h]
  int kc; // [esp+1Ah] [ebp-44h]
  Scaleform::GFx::Sprite *pparentSprite; // [esp+1Eh] [ebp-40h]
  unsigned int i; // [esp+22h] [ebp-3Ch]
  Scaleform::GFx::ButtonDef *pdef; // [esp+2Ah] [ebp-34h]
  Scaleform::GFx::AS2::AvmSprite *avmParentSpr; // [esp+2Eh] [ebp-30h]
  unsigned int v41; // [esp+32h] [ebp-2Ch]
  unsigned int n; // [esp+36h] [ebp-28h]
  Scaleform::GFx::AS2::Value method; // [esp+3Ah] [ebp-24h] BYREF
  unsigned int WcharCode; // [esp+4Eh] [ebp-10h]
  unsigned int v45; // [esp+52h] [ebp-Ch]
  unsigned int v46; // [esp+56h] [ebp-8h]
  int v47; // [esp+5Ah] [ebp-4h]

  v2 = event;
  v3 = this;
  handlerFound = 0;
  if ( !event->RollOverCnt )
  {
    Id = (HINSTANCE__ *)event->Id;
    c = 0;
    kc = 0;
    if ( event->Id == 0x2000 )
    {
      c = 1;
    }
    else if ( Id == (HINSTANCE__ *)0x4000 )
    {
      c = 2;
    }
    else if ( Id == (HINSTANCE__ *)1024 )
    {
      c = 4;
    }
    else if ( Id == (HINSTANCE__ *)2048 )
    {
      c = 8;
    }
    else if ( Id == &_sbh_sizeHeaderList )
    {
      c = 16;
    }
    else if ( Id == (HINSTANCE__ *)0x8000 )
    {
      c = 32;
    }
    else if ( Id == (HINSTANCE__ *)4096 )
    {
      c = 64;
    }
    else if ( Id == (HINSTANCE__ *)&loc_20000 )
    {
      kc = Scaleform::GFx::EventId::ConvertToButtonKeyCode(event);
    }
    v5 = v3[-1].Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::__vftable;
    OnEvent = v5->OnEvent;
    if ( OnEvent )
    {
      v7 = (*((_WORD *)OnEvent + 31) & 0x400) != 0 ? (Scaleform::GFx::Sprite *)OnEvent : 0;
      pparentSprite = v7;
      if ( v7 )
      {
        ToAvmTextFieldBase = (Scaleform::GFx::ButtonDef *)v5[1].ToAvmTextFieldBase;
        v9 = 0;
        pdef = ToAvmTextFieldBase;
        i = 0;
        n = ToAvmTextFieldBase->ButtonActions.Data.Size;
        if ( n )
        {
          while ( 1 )
          {
            v10 = &ToAvmTextFieldBase->ButtonActions.Data.Data[v9].pObject->__vftable;
            if ( (c & v10[2] & 0xFFFF01FF) != 0 || kc > 0 && (((int)v10[2] >> 9) & 0x7F) == kc )
            {
              avmParentSpr = (Scaleform::GFx::AS2::AvmSprite *)(&v7->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                              + v7->AvmObjOffset);
              v11 = (Scaleform::GFx::AS2::ASStringContext *)(((int (*)(void))avmParentSpr->GetASEnvironment)() + 116);
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
                    Scaleform::GFx::AS2::AvmSprite::AddActionBuffer(avmParentSpr, v16, AP_Frame);
                    if ( v16 )
                      Scaleform::RefCountNTSImpl::Release(v16);
                    v7 = pparentSprite;
                  }
                  ++v12;
                }
                while ( v12 < v41 );
                handlerFound = 1;
              }
              v2 = event;
            }
            v9 = i + 1;
            i = v9;
            if ( v9 >= n )
              break;
            ToAvmTextFieldBase = pdef;
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
      method.T.Type = 0;
      if ( ((unsigned __int8 (__thiscall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *, int, const Scaleform::GFx::EventId **, Scaleform::GFx::AS2::Value *))pWatchpoints)(
             &v3[-1].pProto,
             v18,
             &event,
             &method) )
      {
        handlerFound = 1;
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
      if ( method.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&method);
    }
    v31 = (Scaleform::GFx::ASStringNode *)event;
    --event->TouchID;
    if ( !v31->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v31);
  }
  return handlerFound;
}
