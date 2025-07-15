char __thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        const Scaleform::GFx::EventId *evtId,
        Scaleform::GFx::DisplayObject *dispObject)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::VM *pVM; // esi
  Scaleform::GFx::AS3::Class *Constructor; // eax
  const Scaleform::GFx::EventId *v7; // edi
  unsigned int Id; // edx
  Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *v9; // ecx
  Scaleform::GFx::AS3::Instances::fl_events::Event *v10; // ebx
  unsigned int v11; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event *v12; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *p_evtId; // ecx
  Scaleform::GFx::AS3::Instances::fl_events::Event *v14; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event *v15; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event *v16; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event *v17; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event *v18; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event *v19; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v20; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event *v21; // ecx
  unsigned int ControllerIndex; // ecx
  int p_GetAdvanceStats; // ecx
  int v24; // ecx
  int v25; // ecx
  Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *v26; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v27; // ecx
  unsigned __int8 *p_RefCount; // esi
  unsigned int v29; // eax
  unsigned int v30; // edx
  const Scaleform::GFx::ASString *v31; // esi
  const Scaleform::GFx::ASString *v32; // esi
  char KeyCode; // bl
  bool v34; // bl
  Scaleform::GFx::AS3::Instances::fl_events::MouseEvent **MouseEventObject; // eax
  const Scaleform::GFx::EventId *v37; // ebx
  const Scaleform::GFx::AS3::MovieRoot::MouseState *AS3MouseState; // eax
  Scaleform::GFx::InteractiveObject *v39; // eax
  Scaleform::GFx::InteractiveObject_vtbl **v40; // eax
  Scaleform::GFx::InteractiveObject_vtbl *v41; // eax
  unsigned __int8 *p_RollOverCnt; // esi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v43; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v45; // ecx
  unsigned int v46; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event *v47; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event *v48; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event *v49; // eax
  Scaleform::GFx::AS3::Instances::fl_events::Event *v50; // ecx
  unsigned int v51; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> ev; // [esp+10h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> result; // [esp+14h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v54; // [esp+18h] [ebp-28h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v55; // [esp+1Ch] [ebp-24h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent> v56; // [esp+20h] [ebp-20h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v57; // [esp+24h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v58; // [esp+28h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::KeyboardEvent> v59; // [esp+2Ch] [ebp-14h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v60; // [esp+30h] [ebp-10h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v61; // [esp+34h] [ebp-Ch] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v62; // [esp+38h] [ebp-8h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> v63; // [esp+3Ch] [ebp-4h] BYREF

  pObject = this->pTraits.pObject;
  pVM = pObject->pVM;
  Constructor = Scaleform::GFx::AS3::Traits::GetConstructor(pObject);
  v7 = evtId;
  Id = evtId->Id;
  v9 = (Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *)Constructor;
  v10 = 0;
  v11 = evtId->Id;
  ev.pObject = 0;
  if ( v11 > 0x100000A )
  {
    switch ( v11 )
    {
      case 0x100000Bu:
        MouseEventObject = (Scaleform::GFx::AS3::Instances::fl_events::MouseEvent **)Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                                                                                       v9,
                                                                                       (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v60,
                                                                                       evtId,
                                                                                       (const Scaleform::GFx::ASString *)&pVM[1].__vftable[48].GetAdvanceStats,
                                                                                       (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent>::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent>(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::MouseEvent> *)&evtId,
          *MouseEventObject);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&v60);
        v37 = evtId;
        if ( evtId )
        {
          *(_DWORD *)&evtId->RollOverCnt = (*(_DWORD *)&evtId->RollOverCnt + 1) & 0x8FBFFFFF;
          ev.pObject = (Scaleform::GFx::AS3::Instances::fl_events::Event *)v37;
        }
        AS3MouseState = Scaleform::GFx::AS3::MovieRoot::GetAS3MouseState(
                          (Scaleform::GFx::AS3::MovieRoot *)pVM[1].__vftable,
                          v7->ControllerIndex);
        if ( AS3MouseState && (v39 = AS3MouseState->LastMouseOverObj.pObject) != 0 )
        {
          v40 = &v39->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
              + v39->AvmObjOffset;
          if ( v40[2] )
            v41 = v40[2];
          else
            v41 = v40[1];
          if ( ((unsigned __int8)v41 & 1) != 0 )
            v41 = (Scaleform::GFx::InteractiveObject_vtbl *)((char *)v41 - 1);
          p_RollOverCnt = &v37[2].RollOverCnt;
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&v37[2].RollOverCnt,
            (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v41);
        }
        else
        {
          v43 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&v37[2].RollOverCnt;
          p_RollOverCnt = &v37[2].RollOverCnt;
          if ( v43 )
          {
            if ( ((unsigned __int8)v43 & 1) != 0 )
            {
              *(_DWORD *)p_RollOverCnt = (char *)v43 - 1;
            }
            else
            {
              RefCount = v43->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v43->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v43);
              }
            }
            *(_DWORD *)p_RollOverCnt = 0;
          }
        }
        if ( *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)p_RollOverCnt != this )
          goto LABEL_92;
        v45 = *(Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher **)p_RollOverCnt;
        if ( !*(_DWORD *)p_RollOverCnt )
          goto LABEL_92;
        if ( ((unsigned __int8)v45 & 1) != 0 )
        {
          *(_DWORD *)p_RollOverCnt = (char *)v45 - 1;
          *(_DWORD *)p_RollOverCnt = 0;
          p_evtId = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&evtId;
        }
        else
        {
          v46 = v45->RefCount;
          if ( (v46 & 0x3FFFFF) != 0 )
          {
            v45->RefCount = v46 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v45);
          }
          *(_DWORD *)p_RollOverCnt = 0;
LABEL_92:
          p_evtId = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&evtId;
        }
LABEL_102:
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>(p_evtId);
        goto LABEL_103;
      case 0x100000Cu:
        v47 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                                                                    v9,
                                                                    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v61,
                                                                    evtId,
                                                                    (const Scaleform::GFx::ASString *)&pVM[1].__vftable[46].GetAdvanceStats,
                                                                    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this)->pObject;
        if ( v47 )
        {
          v47->RefCount = (v47->RefCount + 1) & 0x8FBFFFFF;
          ev.pObject = v47;
        }
        p_evtId = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&v61;
        goto LABEL_102;
      case 0x100000Du:
        v48 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                                                                    v9,
                                                                    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v62,
                                                                    evtId,
                                                                    (const Scaleform::GFx::ASString *)&pVM[1].__vftable[47],
                                                                    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this)->pObject;
        if ( v48 )
        {
          v48->RefCount = (v48->RefCount + 1) & 0x8FBFFFFF;
          ev.pObject = v48;
        }
        p_evtId = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&v62;
        goto LABEL_102;
      case 0x100000Eu:
        v49 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                                                                    v9,
                                                                    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v63,
                                                                    evtId,
                                                                    (const Scaleform::GFx::ASString *)&pVM[1].__vftable[50],
                                                                    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this)->pObject;
        if ( v49 )
        {
          v49->RefCount = (v49->RefCount + 1) & 0x8FBFFFFF;
          ev.pObject = v49;
        }
        p_evtId = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&v63;
        goto LABEL_102;
      case 0x1000011u:
      case 0x1000012u:
        v31 = (const Scaleform::GFx::ASString *)pVM[1].__vftable;
        if ( Id == 16777233 )
          v32 = v31 + 74;
        else
          v32 = v31 + 79;
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
          v9,
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&evtId,
          v32,
          0,
          0);
        goto LABEL_58;
      case 0x1000013u:
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
          v9,
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&evtId,
          (const Scaleform::GFx::ASString *)&pVM[1].__vftable[45],
          0,
          0);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&evtId[2],
          (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
        if ( !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
                this,
                (Scaleform::GFx::AS3::Instances::fl_events::Event *)evtId,
                0)
          && dispObject )
        {
          dispObject->Flags |= 0x20u;
        }
        KeyCode = evtId[2].KeyCode;
        goto LABEL_62;
      case 0x1000014u:
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
          v9,
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&evtId,
          (const Scaleform::GFx::ASString *)&pVM[1].__vftable[45].GetAdvanceStats,
          0,
          0);
LABEL_58:
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&evtId[2],
          (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
        if ( !Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
                this,
                (Scaleform::GFx::AS3::Instances::fl_events::Event *)evtId,
                0) )
        {
          if ( dispObject )
            dispObject->Flags |= 0x20u;
        }
        KeyCode = evtId[2].KeyCode;
LABEL_62:
        v34 = (KeyCode & 4) == 0;
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&evtId);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>(&ev);
        return v34;
      default:
        return 1;
    }
  }
  if ( v11 == 16777226 )
  {
    Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
      v9,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&evtId,
      evtId,
      (const Scaleform::GFx::ASString *)&pVM[1].__vftable[49],
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
    v20 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)evtId;
    v21 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)evtId;
    if ( evtId )
    {
      ++*(_DWORD *)&evtId->RollOverCnt;
      v20->RefCount &= 0x8FBFFFFF;
      v20 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)evtId;
      ev.pObject = v21;
    }
    ControllerIndex = v7->ControllerIndex;
    if ( ControllerIndex < 6
      && (p_GetAdvanceStats = (int)&pVM[1].__vftable[26 * ControllerIndex + 55].GetAdvanceStats) != 0
      && (v24 = *(_DWORD *)(p_GetAdvanceStats + 12)) != 0 )
    {
      v25 = v24 + 4 * *(unsigned __int8 *)(v24 + 65);
      if ( *(_DWORD *)(v25 + 8) )
        v26 = *(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)(v25 + 8);
      else
        v26 = *(Scaleform::GFx::AS3::Instances::fl_vec::Vector_object **)(v25 + 4);
      if ( ((unsigned __int8)v26 & 1) != 0 )
        v26 = (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)((char *)v26 - 1);
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&v20[2].RefCount,
        v26);
    }
    else
    {
      v27 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v20[2].RefCount;
      p_RefCount = (unsigned __int8 *)&v20[2].RefCount;
      if ( !v27 )
      {
LABEL_49:
        if ( v20 )
        {
          if ( ((unsigned __int8)v20 & 1) == 0 )
          {
            v30 = v20->RefCount;
            if ( (v30 & 0x3FFFFF) != 0 )
            {
              v20->RefCount = v30 - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v20);
            }
          }
        }
        goto LABEL_103;
      }
      if ( ((unsigned __int8)v27 & 1) != 0 )
      {
        *(_DWORD *)p_RefCount = (char *)v27 - 1;
      }
      else
      {
        v29 = v27->RefCount;
        if ( (v29 & 0x3FFFFF) != 0 )
        {
          v27->RefCount = v29 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v27);
        }
      }
      *(_DWORD *)p_RefCount = 0;
    }
    v20 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)evtId;
    goto LABEL_49;
  }
  if ( v11 > 0x40 )
  {
    switch ( v11 )
    {
      case 0x80u:
        v19 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateKeyboardEventObject(
                                                                    v9,
                                                                    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v59,
                                                                    evtId,
                                                                    (const Scaleform::GFx::ASString *)&pVM[1].__vftable[52],
                                                                    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this)->pObject;
        if ( v19 )
        {
          v19->RefCount = (v19->RefCount + 1) & 0x8FBFFFFF;
          ev.pObject = v19;
        }
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&v59);
        break;
      case 0x2000u:
        v18 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                                                                    v9,
                                                                    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v58,
                                                                    evtId,
                                                                    (const Scaleform::GFx::ASString *)&pVM[1].__vftable[51],
                                                                    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this)->pObject;
        if ( v18 )
        {
          v18->RefCount = (v18->RefCount + 1) & 0x8FBFFFFF;
          ev.pObject = v18;
          v10 = v18;
        }
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&v58);
        *((_BYTE *)v10 + 48) &= ~1u;
        break;
      case 0x4000u:
        v17 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                                                                    v9,
                                                                    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v57,
                                                                    evtId,
                                                                    (const Scaleform::GFx::ASString *)&pVM[1].__vftable[50].GetAdvanceStats,
                                                                    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this)->pObject;
        if ( v17 )
        {
          v17->RefCount = (v17->RefCount + 1) & 0x8FBFFFFF;
          ev.pObject = v17;
          v10 = v17;
        }
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&v57);
        *((_BYTE *)v10 + 48) &= ~1u;
        break;
      default:
        return 1;
    }
  }
  else
  {
    if ( v11 != 64 )
    {
      switch ( v11 )
      {
        case 2u:
          Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
            v9,
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&evtId,
            (const Scaleform::GFx::ASString *)&pVM[1].__vftable[40],
            0,
            0);
          goto LABEL_58;
        case 8u:
          v12 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                                                                      v9,
                                                                      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&result,
                                                                      evtId,
                                                                      (const Scaleform::GFx::ASString *)&pVM[1].__vftable[48],
                                                                      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this)->pObject;
          if ( v12 )
          {
            v12->RefCount = (v12->RefCount + 1) & 0x8FBFFFFF;
            ev.pObject = v12;
          }
          p_evtId = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&result;
          goto LABEL_102;
        case 0x10u:
          v14 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                                                                      v9,
                                                                      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v54,
                                                                      evtId,
                                                                      (const Scaleform::GFx::ASString *)&pVM[1].__vftable[47].GetAdvanceStats,
                                                                      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this)->pObject;
          if ( v14 )
          {
            v14->RefCount = (v14->RefCount + 1) & 0x8FBFFFFF;
            ev.pObject = v14;
          }
          p_evtId = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&v54;
          goto LABEL_102;
        case 0x20u:
          v15 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateMouseEventObject(
                                                                      v9,
                                                                      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v55,
                                                                      evtId,
                                                                      (const Scaleform::GFx::ASString *)&pVM[1].__vftable[49].GetAdvanceStats,
                                                                      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this)->pObject;
          if ( v15 )
          {
            v15->RefCount = (v15->RefCount + 1) & 0x8FBFFFFF;
            ev.pObject = v15;
          }
          p_evtId = (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&v55;
          goto LABEL_102;
        default:
          return 1;
      }
    }
    v16 = (Scaleform::GFx::AS3::Instances::fl_events::Event *)Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateKeyboardEventObject(
                                                                v9,
                                                                (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v56,
                                                                evtId,
                                                                (const Scaleform::GFx::ASString *)&pVM[1].__vftable[51].GetAdvanceStats,
                                                                (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this)->pObject;
    if ( v16 )
    {
      v16->RefCount = (v16->RefCount + 1) & 0x8FBFFFFF;
      ev.pObject = v16;
    }
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>::~SPtr<Scaleform::GFx::AS3::Instances::fl::XMLElement>((Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event> *)&v56);
  }
LABEL_103:
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(this, ev.pObject, dispObject);
  v50 = ev.pObject;
  v34 = (*((_BYTE *)ev.pObject + 48) & 4) == 0;
  if ( ((int)ev.pObject & 1) != 0 )
    return v34;
  v51 = ev.pObject->RefCount;
  if ( (v51 & 0x3FFFFF) == 0 )
    return v34;
  ev.pObject->RefCount = v51 - 1;
  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v50);
  return v34;
}


BOOL __thiscall Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::Instances::fl_events::Event *evtObj,
        Scaleform::GFx::DisplayObject *dispObject)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&evtObj->Target,
    (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)this);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(this, evtObj, dispObject);
  return (*((_BYTE *)evtObj + 48) & 4) == 0;
}
