void __userpurge Scaleform::GFx::AS3::MovieRoot::GenerateMouseEvents(
        Scaleform::GFx::AS3::MovieRoot *this@<ecx>,
        int a2@<esi>,
        unsigned int mouseIndex,
        char a4)
{
  Scaleform::GFx::MouseState *v5; // edi
  unsigned int v6; // esi
  Scaleform::GFx::InteractiveObject *v7; // edi
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::InteractiveObject *pCharacter; // eax
  Scaleform::GFx::InteractiveObject *v10; // ebp
  Scaleform::GFx::AS3::MovieRoot *v11; // ebp
  Scaleform::GFx::KeyboardState *v12; // ecx
  Scaleform::KeyModifiers *KeyModifiers; // eax
  Scaleform::GFx::MouseState *v14; // edi
  Scaleform::GFx::InteractiveObject *pObject; // edx
  unsigned int PrevButtonsState; // ecx
  unsigned __int8 v17; // cl
  void (__thiscall *v18)(unsigned int, Scaleform::GFx::ButtonEventId *); // edx
  unsigned __int8 RollOverCnt; // al
  unsigned __int8 v20; // al
  int v21; // eax
  void (__thiscall *v22)(unsigned int, Scaleform::GFx::ButtonEventId *); // edx
  char *v23; // edi
  unsigned int v24; // esi
  int v25; // ecx
  int v26; // ecx
  char v27; // al
  unsigned __int8 v28; // al
  int v29; // eax
  Scaleform::GFx::DisplayObject::ScrollRectInfo *pScrollRect; // edi
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy> *v31; // ebp
  unsigned int v32; // esi
  unsigned int v33; // esi
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *i; // eax
  Scaleform::GFx::InteractiveObject *pPlayNext; // ecx
  Scaleform::GFx::InteractiveObject *v36; // esi
  Scaleform::GFx::InteractiveObject *v37; // edi
  int v38; // eax
  int v39; // ecx
  char v40; // al
  char v41; // al
  Scaleform::GFx::InteractiveObject_vtbl *v42; // eax
  bool (__thiscall *OnMouseEvent)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  Scaleform::RefCountNTSImpl *v44; // ecx
  unsigned int v45; // esi
  Scaleform::GFx::AS3::MovieRoot::MouseState::DoubleClickInfo *DoubleClickInfo; // eax
  Scaleform::GFx::MouseState *v47; // ebp
  Scaleform::GFx::InteractiveObject *v48; // edi
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *MouseButtonDownEntity; // eax
  Scaleform::GFx::InteractiveObject *v50; // edi
  Scaleform::GFx::InteractiveObject_vtbl *v51; // eax
  bool (__thiscall *v52)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  Scaleform::GFx::InteractiveObject *v53; // ecx
  Scaleform::RefCountNTSImpl *PrevClickTime; // eax
  int v55; // ebp
  int v56; // ebp
  int v57; // eax
  int v58; // eax
  bool (__thiscall *v59)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  Scaleform::GFx::AS3::MovieRoot::MouseState::DoubleClickInfo *v60; // eax
  bool (__thiscall *v61)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  int WheelDelta; // eax
  bool (__thiscall *v63)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // eax
  Scaleform::GFx::MouseState *v64; // ebp
  char v65; // cl
  Scaleform::GFx::InteractiveObject *v66; // esi
  bool (__thiscall *v67)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v68; // eax
  Scaleform::GFx::InteractiveObject *v69; // esi
  Scaleform::GFx::InteractiveObject *v70; // ecx
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy> > *v71; // ebp
  unsigned int v72; // eax
  int v73; // eax
  Scaleform::GFx::InteractiveObject **p_pObject; // ecx
  Scaleform::GFx::InteractiveObject *v75; // esi
  Scaleform::GFx::AS3::MovieRoot *v76; // eax
  Scaleform::GFx::InteractiveObject *v77; // ecx
  unsigned int v78; // eax
  unsigned __int8 v79; // cl
  Scaleform::GFx::InteractiveObject *pParent; // edi
  Scaleform::GFx::InteractiveObject *v81; // edi
  int v82; // eax
  int v83; // esi
  char v84; // cl
  bool (__thiscall *v85)(Scaleform::GFx::InteractiveObject *, const Scaleform::GFx::EventId *); // edx
  Scaleform::RefCountNTSImpl *Data; // ecx
  unsigned int v87; // esi
  unsigned int Size; // eax
  Scaleform::RefCountNTSImpl **v89; // edi
  unsigned int v90; // edi
  Scaleform::GFx::InteractiveObject *v91; // esi
  Scaleform::GFx::InteractiveObject *v92; // edi
  Scaleform::WeakPtrProxy *WeakProxy; // esi
  Scaleform::WeakPtrProxy *v94; // eax
  bool v95; // zf
  Scaleform::WeakPtrProxy *v96; // eax
  Scaleform::GFx::InteractiveObject *v97; // ecx
  int v98; // [esp+18h] [ebp-A8h]
  unsigned __int8 keyMods; // [esp+28h] [ebp-98h]
  unsigned __int8 buttonIdx; // [esp+29h] [ebp-97h]
  unsigned __int8 buttonIdxa; // [esp+29h] [ebp-97h]
  bool dblClick; // [esp+2Ah] [ebp-96h]
  bool dblClicka; // [esp+2Ah] [ebp-96h]
  unsigned __int8 checkCount; // [esp+2Bh] [ebp-95h]
  Scaleform::GFx::AS3::MovieRoot::MouseState::DoubleClickInfo *dci; // [esp+2Ch] [ebp-94h]
  Scaleform::GFx::ButtonEventId evt; // [esp+30h] [ebp-90h] BYREF
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> TopmostEntity; // [esp+44h] [ebp-7Ch]
  unsigned int idx; // [esp+48h] [ebp-78h] BYREF
  Scaleform::GFx::MouseState *ms; // [esp+4Ch] [ebp-74h]
  Scaleform::KeyModifiers result[4]; // [esp+50h] [ebp-70h] BYREF
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> ActiveEntity; // [esp+54h] [ebp-6Ch]
  Scaleform::GFx::AS3::MovieRoot *v112; // [esp+58h] [ebp-68h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> cur; // [esp+5Ch] [ebp-64h] BYREF
  Scaleform::GFx::ButtonEventId mouseUpEvt; // [esp+60h] [ebp-60h] BYREF
  float v115; // [esp+74h] [ebp-4Ch]
  Scaleform::GFx::InteractiveObject *stage; // [esp+78h] [ebp-48h] BYREF
  unsigned int changeMask; // [esp+7Ch] [ebp-44h] BYREF
  Scaleform::GFx::InteractiveObject *v118; // [esp+80h] [ebp-40h]
  Scaleform::RefCountNTSImpl *v119; // [esp+84h] [ebp-3Ch] BYREF
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> PrevActiveEntity; // [esp+88h] [ebp-38h]
  float x; // [esp+8Ch] [ebp-34h]
  float y; // [esp+90h] [ebp-30h]
  Scaleform::Render::Point<float> pt; // [esp+94h] [ebp-2Ch]
  Scaleform::GFx::MovieImpl::DragState st; // [esp+9Ch] [ebp-24h] BYREF

  v112 = this;
  LOBYTE(dci) = 0;
  if ( mouseIndex < 6 )
    v5 = &this->pMovieImpl->mMouseState[mouseIndex];
  else
    v5 = 0;
  v98 = a2;
  ms = v5;
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v5->ActiveEntity,
    (Scaleform::Ptr<Scaleform::GFx::Sprite> *)&changeMask);
  v6 = changeMask;
  if ( changeMask )
    ++*(_DWORD *)(changeMask + 4);
  ActiveEntity.pObject = (Scaleform::GFx::InteractiveObject *)v6;
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v6);
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)v5,
    (Scaleform::Ptr<Scaleform::GFx::Sprite> *)&changeMask);
  v7 = (Scaleform::GFx::InteractiveObject *)changeMask;
  if ( changeMask )
    ++*(_DWORD *)(changeMask + 4);
  TopmostEntity.pObject = v7;
  if ( v7 )
    Scaleform::RefCountNTSImpl::Release(v7);
  pMovieImpl = this->pMovieImpl;
  st.BoundLT.y = 0.0;
  st.BoundLT.x = 0.0;
  st.BoundRB.y = 0.0;
  st.BoundRB.x = 0.0;
  st.CenterDelta.y = 0.0;
  st.pCharacter = 0;
  st.CenterDelta.x = 0.0;
  st.LockCenter = 0;
  st.Bound = 0;
  st.MouseIndex = -1;
  Scaleform::GFx::MovieImpl::GetDragState(pMovieImpl, mouseIndex, &st);
  if ( st.MouseIndex == mouseIndex && (pCharacter = st.pCharacter) != 0 && (st.pCharacter->Flags & 0x1000) == 0 )
  {
    ++st.pCharacter->RefCount;
    v10 = pCharacter;
    if ( v7 )
      Scaleform::RefCountNTSImpl::Release(v7);
    TopmostEntity.pObject = v10;
  }
  else
  {
    v10 = v7;
  }
  if ( v6 && (*(_BYTE *)(v6 + 62) & 0x10) != 0 )
  {
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v6);
    v6 = 0;
    ActiveEntity.pObject = 0;
  }
  if ( v10 && (v10->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x10) != 0 )
  {
    Scaleform::RefCountNTSImpl::Release(v10);
    TopmostEntity.pObject = 0;
  }
  if ( v6 )
    ++*(_DWORD *)(v6 + 4);
  v11 = v112;
  PrevActiveEntity.pObject = (Scaleform::GFx::InteractiveObject *)v6;
  if ( mouseIndex >= 6 )
    v12 = 0;
  else
    v12 = &v112->pMovieImpl->KeyboardStates[mouseIndex];
  KeyModifiers = Scaleform::GFx::KeyboardState::GetKeyModifiers(v12, &result[3]);
  v14 = ms;
  pObject = TopmostEntity.pObject;
  checkCount = v11->pAVM.pObject->ExtensionsEnabled ? 16 : 1;
  keyMods = KeyModifiers->States;
  PrevButtonsState = ms->PrevButtonsState;
  changeMask = PrevButtonsState ^ ms->CurButtonsState;
  if ( TopmostEntity.pObject )
    v118 = TopmostEntity.pObject;
  else
    v118 = v11->pStage.pObject;
  if ( (PrevButtonsState & 1) != 0 )
  {
    if ( (*((_BYTE *)ms + 52) & 4) != 0 )
    {
      if ( TopmostEntity.pObject == (Scaleform::GFx::InteractiveObject *)v6 )
        goto LABEL_85;
      v6 = (unsigned int)ActiveEntity.pObject;
      if ( ActiveEntity.pObject )
      {
        RollOverCnt = ActiveEntity.pObject->RollOverCnt;
        if ( RollOverCnt )
        {
          v20 = RollOverCnt - 1;
          ActiveEntity.pObject->RollOverCnt = v20;
        }
        else
        {
          v20 = -1;
        }
        evt.ControllerIndex = mouseIndex;
        evt.RollOverCnt = v20;
        v21 = *(_DWORD *)v6;
        evt.KeysState.States = keyMods;
        v22 = *(void (__thiscall **)(unsigned int, Scaleform::GFx::ButtonEventId *))(v21 + 392);
        evt.Id = (unsigned int)&_sbh_sizeHeaderList;
        memset(&evt.WcharCode, 0, 9);
        evt.MouseWheelDelta = 0;
        v22(v6, &evt);
      }
      *((_BYTE *)ms + 52) &= ~4u;
      pObject = TopmostEntity.pObject;
    }
    else
    {
      if ( TopmostEntity.pObject != (Scaleform::GFx::InteractiveObject *)v6 )
      {
LABEL_48:
        v23 = (char *)v11 + 208 * mouseIndex;
        idx = *((_DWORD *)v23 + 112);
        v24 = idx - 1;
        cur.pObject = (Scaleform::GFx::InteractiveObject *)v23;
        if ( (int)(idx - 1) >= 0 )
        {
          while ( 1 )
          {
            if ( pObject )
            {
              v25 = *((_DWORD *)v23 + 111);
              if ( *(Scaleform::GFx::InteractiveObject **)(v25 + 4 * v24) == pObject
                || Scaleform::GFx::DisplayObjectBase::IsAncestor(
                     *(Scaleform::GFx::DisplayObjectBase **)(v25 + 4 * v24),
                     pObject) )
              {
                break;
              }
            }
            v26 = *(_DWORD *)(*((_DWORD *)v23 + 111) + 4 * v24);
            v27 = *(_BYTE *)(v26 + 112);
            if ( v27 )
            {
              v28 = v27 - 1;
              *(_BYTE *)(v26 + 112) = v28;
            }
            else
            {
              v28 = -1;
            }
            evt.RollOverCnt = v28;
            v29 = *((_DWORD *)v23 + 111);
            evt.KeysState.States = keyMods;
            evt.Id = 0x4000;
            memset(&evt.WcharCode, 0, 9);
            evt.MouseWheelDelta = 0;
            evt.ControllerIndex = mouseIndex;
            (*(void (__thiscall **)(_DWORD, Scaleform::GFx::ButtonEventId *))(**(_DWORD **)(v29 + 4 * v24) + 392))(
              *(_DWORD *)(v29 + 4 * v24),
              &evt);
            if ( (--v24 & 0x80000000) != 0 )
              break;
            pObject = TopmostEntity.pObject;
          }
        }
        pScrollRect = cur.pObject[3].pScrollRect;
        v31 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy> *)&cur.pObject[3].72;
        v32 = (unsigned int)&pScrollRect->Rectangle.x1 + v24 - idx + 1;
        if ( v32 >= (unsigned int)pScrollRect )
        {
          if ( v32 >= *(_DWORD *)&cur.pObject[3].Scaleform::GFx::DisplayObject::Flags )
            Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
              v31,
              v31,
              v32 + (v32 >> 2));
        }
        else
        {
          dci = (Scaleform::GFx::AS3::MovieRoot::MouseState::DoubleClickInfo *)&v31->Data[(_DWORD)pScrollRect - 1];
          if ( pScrollRect != (Scaleform::GFx::DisplayObject::ScrollRectInfo *)v32 )
          {
            idx = (unsigned int)pScrollRect - v32;
            do
            {
              if ( dci->PrevClickTime )
                Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)dci->PrevClickTime);
              dci = (Scaleform::GFx::AS3::MovieRoot::MouseState::DoubleClickInfo *)((char *)dci - 4);
              --idx;
            }
            while ( idx );
          }
          if ( v32 < v31->Policy.Capacity >> 1 )
            Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
              v31,
              v31,
              v32);
        }
        v31->Size = v32;
        if ( v32 > (unsigned int)pScrollRect )
        {
          v33 = v32 - (_DWORD)pScrollRect;
          for ( i = &v31->Data[(_DWORD)pScrollRect]; v33; --v33 )
          {
            if ( i )
              i->pObject = 0;
            ++i;
          }
        }
        if ( ActiveEntity.pObject )
        {
          ++ActiveEntity.pObject->RefCount;
          pPlayNext = cur.pObject[3].pPlayNext;
          if ( pPlayNext )
            Scaleform::RefCountNTSImpl::Release(pPlayNext);
          v36 = ActiveEntity.pObject;
          v37 = cur.pObject;
          cur.pObject[3].pPlayNext = ActiveEntity.pObject;
          v38 = (*(int (__thiscall **)(int, int))(*((_DWORD *)&v36->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                  + v36->AvmObjOffset)
                                                + 4))(
                  (int)v36 + 4 * v36->AvmObjOffset,
                  v98);
          if ( v38 )
            v39 = v38 - 28;
          else
            v39 = 0;
          v40 = *(_BYTE *)(v39 + 32);
          if ( v40 )
          {
            v41 = v40 - 1;
            *(_BYTE *)(v39 + 32) = v41;
          }
          else
          {
            v41 = -1;
          }
          BYTE1(TopmostEntity.pObject) = a4;
          LOBYTE(TopmostEntity.pObject) = v41;
          v42 = v36->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
          HIWORD(TopmostEntity.pObject) = (unsigned __int8)dci;
          OnMouseEvent = v42->OnMouseEvent;
          evt.WcharCode = 16777227;
          memset(&evt.KeyCode, 0, 9);
          OnMouseEvent(v36, (const Scaleform::GFx::EventId *)&evt.WcharCode);
          v44 = v37[3].pPlayNext;
          if ( v44 )
            Scaleform::RefCountNTSImpl::Release(v44);
          v37[3].pPlayNext = 0;
        }
        goto LABEL_85;
      }
      if ( v6 )
      {
        v17 = *(_BYTE *)(v6 + 112);
        *(_BYTE *)(v6 + 112) = v17 + 1;
        evt.ControllerIndex = mouseIndex;
        v18 = *(void (__thiscall **)(unsigned int, Scaleform::GFx::ButtonEventId *))(*(_DWORD *)v6 + 392);
        evt.KeysState.States = keyMods;
        evt.RollOverCnt = v17;
        evt.Id = 0x8000;
        memset(&evt.WcharCode, 0, 9);
        evt.MouseWheelDelta = 0;
        v18(v6, &evt);
        pObject = TopmostEntity.pObject;
      }
      *((_BYTE *)v14 + 52) |= 4u;
    }
  }
  if ( pObject != (Scaleform::GFx::InteractiveObject *)v6 )
  {
    v11 = v112;
    pObject = TopmostEntity.pObject;
    goto LABEL_48;
  }
LABEL_85:
  buttonIdx = 0;
  v45 = 0;
  do
  {
    if ( ((changeMask >> v45) & 1) != 0 && ((1 << v45) & ms->PrevButtonsState) != 0 )
    {
      DoubleClickInfo = Scaleform::GFx::AS3::MovieRoot::MouseState::GetDoubleClickInfo(
                          &v112->mMouseState[mouseIndex],
                          v45);
      v47 = ms;
      dci = DoubleClickInfo;
      v48 = Scaleform::GFx::MouseState::GetMouseButtonDownEntity(
              ms,
              (Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&idx,
              (Scaleform::Ptr<Scaleform::GFx::Sprite>)v45)->pObject;
      if ( idx )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)idx);
      if ( v48 )
      {
        evt.AsciiCode = buttonIdx;
        evt.Id = 4096;
        evt.WcharCode = 0;
        evt.KeyCode = 0;
        evt.MouseWheelDelta = 0;
        evt.ControllerIndex = mouseIndex;
        evt.RollOverCnt = 0;
        evt.KeysState.States = keyMods;
        MouseButtonDownEntity = Scaleform::GFx::MouseState::GetMouseButtonDownEntity(
                                  v47,
                                  &cur,
                                  (Scaleform::Ptr<Scaleform::GFx::Sprite>)v45);
        MouseButtonDownEntity->pObject->OnMouseEvent(MouseButtonDownEntity->pObject, &evt);
        if ( cur.pObject )
          Scaleform::RefCountNTSImpl::Release(cur.pObject);
      }
      v50 = v118;
      mouseUpEvt.ControllerIndex = mouseIndex;
      mouseUpEvt.AsciiCode = buttonIdx;
      v51 = v118->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable;
      mouseUpEvt.KeysState.States = keyMods;
      v52 = v51->OnMouseEvent;
      mouseUpEvt.Id = 32;
      mouseUpEvt.WcharCode = 0;
      mouseUpEvt.KeyCode = 0;
      mouseUpEvt.MouseWheelDelta = 0;
      mouseUpEvt.RollOverCnt = 0;
      v52(v118, &mouseUpEvt);
      if ( (*((_BYTE *)v47 + 52) & 4) == 0 )
        goto LABEL_112;
      dblClick = 0;
      v53 = (Scaleform::GFx::InteractiveObject *)(Scaleform::Timer::GetTicks() / 0x3E8);
      PrevClickTime = (Scaleform::RefCountNTSImpl *)dci->PrevClickTime;
      stage = v53;
      if ( PrevClickTime )
      {
        pt.x = v47->LastPosition.x;
        pt.y = v47->LastPosition.y;
        if ( v53 <= (Scaleform::GFx::InteractiveObject *)&PrevClickTime[37].RefCount )
        {
          v115 = dci->PrevPosition.x * 0.05000000074505806;
          v55 = (int)v115;
          v115 = pt.x * 0.05000000074505806;
          if ( v55 == (int)v115 )
          {
            v115 = dci->PrevPosition.y * 0.05000000074505806;
            v56 = (int)v115;
            v115 = 0.05000000074505806 * pt.y;
            if ( v56 == (int)v115 )
            {
              dblClick = 1;
              v57 = (*(int (__thiscall **)(int))(*((_DWORD *)&v50->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                                 + v50->AvmObjOffset)
                                               + 4))((int)v50 + 4 * v50->AvmObjOffset);
              v58 = v57 ? v57 - 28 : 0;
              if ( (*(_BYTE *)(v58 + 33) & 2) != 0 )
              {
                evt.ControllerIndex = mouseIndex;
                v59 = v50->OnMouseEvent;
                evt.KeysState.States = keyMods;
                evt.AsciiCode = buttonIdx;
                evt.Id = 16777229;
                evt.WcharCode = 0;
                evt.KeyCode = 0;
                evt.MouseWheelDelta = 0;
                evt.RollOverCnt = 0;
                v59(v50, &evt);
                v60 = dci;
                v47 = ms;
                dci->PrevClickTime = 0;
LABEL_111:
                x = v47->LastPosition.x;
                y = v47->LastPosition.y;
                v60->PrevPosition.x = x;
                v60->PrevPosition.y = y;
LABEL_112:
                Scaleform::GFx::MouseState::SetMouseButtonDownEntity(v47, v45, 0);
                goto LABEL_113;
              }
            }
          }
          v47 = ms;
        }
      }
      result[3].States = v50 == Scaleform::GFx::MouseState::GetMouseButtonDownEntity(
                                  v47,
                                  (Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&v119,
                                  (Scaleform::Ptr<Scaleform::GFx::Sprite>)v45)->pObject;
      if ( v119 )
        Scaleform::RefCountNTSImpl::Release(v119);
      if ( result[3].States )
      {
        evt.ControllerIndex = mouseIndex;
        v61 = v50->OnMouseEvent;
        evt.KeysState.States = keyMods;
        evt.AsciiCode = buttonIdx;
        evt.Id = 16777228;
        evt.WcharCode = 0;
        evt.KeyCode = 0;
        evt.MouseWheelDelta = 0;
        evt.RollOverCnt = 0;
        v61(v50, &evt);
      }
      if ( dblClick )
      {
        v60 = dci;
        dci->PrevClickTime = 0;
      }
      else
      {
        dci->PrevClickTime = (unsigned int)stage;
        v60 = dci;
      }
      goto LABEL_111;
    }
LABEL_113:
    ++v45;
    ++buttonIdx;
  }
  while ( buttonIdx < checkCount );
  WheelDelta = ms->WheelDelta;
  if ( WheelDelta )
  {
    mouseUpEvt.ControllerIndex = mouseIndex;
    mouseUpEvt.MouseWheelDelta = WheelDelta;
    v63 = v118->OnMouseEvent;
    mouseUpEvt.KeysState.States = keyMods;
    mouseUpEvt.Id = 16777230;
    memset(&mouseUpEvt.WcharCode, 0, 9);
    mouseUpEvt.RollOverCnt = 0;
    v63(v118, &mouseUpEvt);
  }
  v64 = ms;
  if ( (*((_BYTE *)ms + 52) & 8) != 0 )
  {
    v65 = ms->WheelDelta;
    v66 = v118;
    mouseUpEvt.ControllerIndex = mouseIndex;
    v67 = v118->OnMouseEvent;
    mouseUpEvt.KeysState.States = keyMods;
    mouseUpEvt.MouseWheelDelta = v65;
    mouseUpEvt.Id = 8;
    memset(&mouseUpEvt.WcharCode, 0, 9);
    mouseUpEvt.RollOverCnt = 0;
    v67(v118, &mouseUpEvt);
    LOBYTE(dci) = 1;
    if ( !Scaleform::GFx::MouseState::GetMouseButtonDownEntity(
            v64,
            (Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&v119,
            0)->pObject
      || (LOBYTE(dci) = 3,
          dblClicka = 1,
          Scaleform::GFx::MouseState::GetMouseButtonDownEntity(
            v64,
            (Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&stage,
            0)->pObject == v66) )
    {
      dblClicka = 0;
    }
    if ( ((unsigned __int8)dci & 2) != 0 )
    {
      LOBYTE(dci) = (unsigned __int8)dci & 0xFD;
      if ( stage )
        Scaleform::RefCountNTSImpl::Release(stage);
    }
    if ( ((unsigned __int8)dci & 1) != 0 && v119 )
      Scaleform::RefCountNTSImpl::Release(v119);
    if ( dblClicka )
    {
      evt.Id = 8;
      memset(&evt.WcharCode, 0, 9);
      evt.MouseWheelDelta = 0;
      evt.ControllerIndex = mouseIndex;
      evt.RollOverCnt = 0;
      evt.KeysState.States = keyMods;
      v68 = Scaleform::GFx::MouseState::GetMouseButtonDownEntity(
              v64,
              (Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&stage,
              0);
      v68->pObject->PropagateMouseEvent(v68->pObject, &evt);
      if ( stage )
        Scaleform::RefCountNTSImpl::Release(stage);
    }
  }
  v69 = TopmostEntity.pObject;
  v70 = ActiveEntity.pObject;
  if ( TopmostEntity.pObject == ActiveEntity.pObject )
  {
    if ( !TopmostEntity.pObject )
    {
      v87 = (unsigned int)&v112->mMouseState[mouseIndex];
      Size = v112->mMouseState[mouseIndex].RolloverStack.Data.Size;
      if ( Size )
      {
        v89 = (Scaleform::RefCountNTSImpl **)(*(_DWORD *)v87 + 4 * Size - 4);
        idx = v112->mMouseState[mouseIndex].RolloverStack.Data.Size;
        do
        {
          if ( *v89 )
            Scaleform::RefCountNTSImpl::Release(*v89);
          --v89;
          --idx;
        }
        while ( idx );
        if ( (*(_DWORD *)(v87 + 8) & 0xFFFFFFFE) != 0 )
        {
          if ( *(_DWORD *)v87 )
          {
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *(void **)v87);
            *(_DWORD *)v87 = 0;
          }
          *(_DWORD *)(v87 + 8) = 0;
        }
      }
      else if ( !v112->mMouseState[mouseIndex].RolloverStack.Data.Policy.Capacity )
      {
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &v112->mMouseState[mouseIndex].RolloverStack.Data,
          &v112->mMouseState[mouseIndex],
          0);
      }
      *(_DWORD *)(v87 + 4) = 0;
    }
  }
  else
  {
    if ( TopmostEntity.pObject )
      ++TopmostEntity.pObject->RefCount;
    if ( v70 )
      Scaleform::RefCountNTSImpl::Release(v70);
    ActiveEntity.pObject = v69;
    if ( v69 )
    {
      v71 = (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy> > *)((char *)v112 + 208 * mouseIndex);
      v72 = v71[37].Data.Size;
      if ( v72 && (v73 = v72 - 1, v73 >= 0) )
      {
        p_pObject = &v71[37].Data.Data[v73].pObject;
        while ( *p_pObject != TopmostEntity.pObject )
        {
          --v73;
          --p_pObject;
          if ( v73 < 0 )
            goto LABEL_140;
        }
      }
      else
      {
LABEL_140:
        v75 = TopmostEntity.pObject;
        v76 = v112;
        ++TopmostEntity.pObject->RefCount;
        v77 = v76->pStage.pObject;
        v78 = v71[37].Data.Size;
        cur.pObject = v75;
        stage = v77;
        idx = v78;
        while ( v75 != stage && (!v78 || v71[37].Data.Data[v78 - 1].pObject != v75) )
        {
          v79 = v75->RollOverCnt;
          v75->RollOverCnt = v79 + 1;
          mouseUpEvt.RollOverCnt = v79;
          mouseUpEvt.ControllerIndex = mouseIndex;
          mouseUpEvt.KeysState.States = keyMods;
          mouseUpEvt.Id = 0x2000;
          memset(&mouseUpEvt.WcharCode, 0, 9);
          mouseUpEvt.MouseWheelDelta = 0;
          v75->OnMouseEvent(v75, &mouseUpEvt);
          Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,323>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
            v71 + 37,
            idx,
            &cur);
          pParent = v75->pParent;
          if ( pParent )
            ++pParent->RefCount;
          Scaleform::RefCountNTSImpl::Release(v75);
          v75 = pParent;
          cur.pObject = pParent;
          if ( !pParent )
            goto LABEL_151;
          v78 = idx;
        }
        if ( v75 )
          Scaleform::RefCountNTSImpl::Release(v75);
      }
LABEL_151:
      v81 = TopmostEntity.pObject;
      v82 = (*(int (__thiscall **)(char *, int))(*((_DWORD *)&TopmostEntity.pObject->__vftable
                                                 + TopmostEntity.pObject->AvmObjOffset)
                                               + 4))(
              (char *)&TopmostEntity.pObject->__vftable + 4 * TopmostEntity.pObject->AvmObjOffset,
              v98);
      if ( v82 )
        v83 = v82 - 28;
      else
        v83 = 0;
      v84 = *(_BYTE *)(v83 + 32);
      *(_BYTE *)(v83 + 32) = v84 + 1;
      v85 = v81->OnMouseEvent;
      LOBYTE(TopmostEntity.pObject) = v84;
      BYTE1(TopmostEntity.pObject) = a4;
      HIWORD(TopmostEntity.pObject) = (unsigned __int8)dci;
      evt.WcharCode = 16777226;
      memset(&evt.KeyCode, 0, 9);
      v85(v81, (const Scaleform::GFx::EventId *)&evt.WcharCode);
      Data = (Scaleform::RefCountNTSImpl *)v71[38].Data.Data;
      if ( Data )
        Scaleform::RefCountNTSImpl::Release(Data);
      v71[38].Data.Data = 0;
      v64 = ms;
    }
    *((_BYTE *)v64 + 52) |= 4u;
  }
  buttonIdxa = 0;
  v90 = 0;
  do
  {
    if ( ((changeMask >> v90) & 1) != 0 && ((1 << v90) & v64->PrevButtonsState) == 0 )
    {
      v91 = ActiveEntity.pObject;
      mouseUpEvt.Id = 16;
      mouseUpEvt.WcharCode = 0;
      mouseUpEvt.KeyCode = 0;
      mouseUpEvt.MouseWheelDelta = 0;
      mouseUpEvt.ControllerIndex = mouseIndex;
      mouseUpEvt.RollOverCnt = 0;
      mouseUpEvt.KeysState.States = keyMods;
      if ( !ActiveEntity.pObject )
        v91 = v112->pStage.pObject;
      mouseUpEvt.AsciiCode = buttonIdxa;
      v91->OnMouseEvent(v91, &mouseUpEvt);
      Scaleform::GFx::MouseState::SetMouseButtonDownEntity(v64, v90, v91);
      *((_BYTE *)v64 + 52) |= 4u;
    }
    ++v90;
    ++buttonIdxa;
  }
  while ( buttonIdxa < checkCount );
  if ( ActiveEntity.pObject )
  {
    v92 = ActiveEntity.pObject;
    WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(ActiveEntity.pObject);
    v94 = v64->ActiveEntity.pProxy.pObject;
    if ( v94 )
    {
      v95 = v94->RefCount-- == 1;
      if ( v95 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v94);
    }
    v64->ActiveEntity.pProxy.pObject = WeakProxy;
  }
  else
  {
    v96 = v64->ActiveEntity.pProxy.pObject;
    if ( v96 )
    {
      v95 = v96->RefCount-- == 1;
      if ( v95 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v96);
    }
    v92 = ActiveEntity.pObject;
    v64->ActiveEntity.pProxy.pObject = 0;
  }
  v97 = PrevActiveEntity.pObject;
  *((_BYTE *)v64 + 52) &= ~8u;
  v64->WheelDelta = 0;
  if ( v97 )
    Scaleform::RefCountNTSImpl::Release(v97);
  if ( TopmostEntity.pObject )
    Scaleform::RefCountNTSImpl::Release(TopmostEntity.pObject);
  if ( v92 )
    Scaleform::RefCountNTSImpl::Release(v92);
}
