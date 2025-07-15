void __cdecl Scaleform::GFx::AS2::SelectionCtorFunction::FindFocus(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v1; // esi
  int NArgs; // eax
  Scaleform::GFx::AS2::Value *v3; // eax
  bool v4; // cc
  Scaleform::GFx::AS2::Environment *v5; // esi
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebx
  unsigned __int8 Type; // al
  Scaleform::GFx::AS2::Value *v8; // eax
  Scaleform::GFx::InteractiveObject *v9; // eax
  Scaleform::GFx::Sprite *pObject; // esi
  Scaleform::GFx::AS2::Value *v11; // eax
  Scaleform::GFx::AS2::Environment *v12; // eax
  Scaleform::GFx::AS2::Value *v13; // ecx
  Scaleform::GFx::Sprite *v14; // esi
  const Scaleform::GFx::AS2::Value *v15; // eax
  unsigned __int8 v16; // bl
  Scaleform::GFx::InteractiveObject *v17; // eax
  Scaleform::GFx::Sprite *ModalClip; // eax
  Scaleform::GFx::AS2::Value *v19; // eax
  Scaleform::GFx::AS2::Environment *v20; // eax
  Scaleform::GFx::DisplayObject *v21; // ebx
  Scaleform::GFx::CharacterHandle *CharacterHandle; // edi
  Scaleform::GFx::CharacterHandle *v23; // eax
  Scaleform::GFx::CharacterHandle *v24; // esi
  Scaleform::GFx::InteractiveObject *v25; // edi
  Scaleform::WeakPtrProxy *WeakProxy; // esi
  Scaleform::WeakPtrProxy *v27; // eax
  Scaleform::WeakPtrProxy *v28; // eax
  Scaleform::GFx::MovieImpl *v29; // esi
  Scaleform::GFx::AS2::Value *v30; // ecx
  unsigned int v31; // ebx
  unsigned int v32; // edi
  Scaleform::GFx::InteractiveObject *v33; // eax
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v34; // ecx
  Scaleform::GFx::DisplayObjectBase *v35; // esi
  __m128 *v36; // eax
  char v37; // fps^1
  bool v38; // c0
  char v39; // c2
  bool v40; // c3
  char v41; // ah
  double v42; // st7
  double v43; // st6
  bool v44; // c0
  double v45; // st7
  char v46; // fps^1
  bool v47; // c0
  char v48; // c2
  bool v49; // c3
  char v50; // ah
  double v51; // st7
  char v52; // fps^1
  bool v53; // c0
  char v54; // c2
  bool v55; // c3
  char v56; // fps^1
  bool v57; // c0
  char v58; // c2
  bool v59; // c3
  Scaleform::GFx::AS2::Value *v60; // esi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v62; // zf
  Scaleform::GFx::ASStringNode *v63; // ecx
  Scaleform::GFx::AS2::Environment *Env; // [esp+C50h] [ebp-F4h]
  Scaleform::GFx::AS2::Environment *v65; // [esp+C50h] [ebp-F4h]
  Scaleform::GFx::AS2::Environment *v66; // [esp+C50h] [ebp-F4h]
  __int16 v67; // [esp+C64h] [ebp-E0h]
  float v68; // [esp+C64h] [ebp-E0h]
  unsigned __int8 v69; // [esp+C6Ah] [ebp-DAh]
  char v70; // [esp+C6Bh] [ebp-D9h]
  Scaleform::GFx::ASString v71; // [esp+C6Ch] [ebp-D8h] BYREF
  unsigned int v72; // [esp+C70h] [ebp-D4h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [esp+C74h] [ebp-D0h] BYREF
  Scaleform::GFx::DisplayObject *v74; // [esp+C78h] [ebp-CCh]
  Scaleform::RefCountWeakSupportImpl *v75; // [esp+C7Ch] [ebp-C8h]
  Scaleform::GFx::MovieImpl *v76; // [esp+C80h] [ebp-C4h]
  Scaleform::GFx::AS2::Value v77; // [esp+C84h] [ebp-C0h] BYREF
  Scaleform::GFx::ProcessFocusKeyInfo pfocusInfo; // [esp+C94h] [ebp-B0h] BYREF
  Scaleform::GFx::InputEventsQueueEntry::KeyEntry keyEntry; // [esp+CC8h] [ebp-7Ch] BYREF
  Scaleform::GFx::FocusGroupDescr pfocusGroup; // [esp+CD4h] [ebp-70h] BYREF
  _BYTE v81[16]; // [esp+D14h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> v82; // [esp+D24h] [ebp-20h] BYREF

  v1 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v1);
  v1->T.Type = 0;
  NArgs = fn->NArgs;
  if ( !NArgs )
    return;
  v72 = 0;
  if ( NArgs >= 6 )
  {
    Env = fn->Env;
    v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 5);
    v72 = Scaleform::GFx::AS2::Value::ToUInt32(v3, Env);
  }
  v4 = fn->NArgs < 4;
  v5 = fn->Env;
  pMovieImpl = v5->Target->pASRoot->pMovieImpl;
  v76 = pMovieImpl;
  if ( v4
    || (Type = Scaleform::GFx::AS2::FnCall::Arg(fn, 3)->T.Type) == 0
    || Type == 10
    || Scaleform::GFx::AS2::FnCall::Arg(fn, 3)->T.Type == 1 )
  {
    Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&pMovieImpl->FocusGroups[pMovieImpl->FocusGroupIndexes[v72]].LastFocused,
      (Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&result);
    pObject = result.pObject;
    if ( result.pObject )
    {
      ++result.pObject->RefCount;
      Scaleform::RefCountNTSImpl::Release(pObject);
      ++pObject->RefCount;
    }
    v75 = pObject;
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
  }
  else
  {
    v8 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
    v9 = Scaleform::GFx::AS2::Value::ToCharacter(v8, v5);
    if ( v9 )
      ++v9->RefCount;
    v75 = v9;
  }
  if ( fn->NArgs < 5 )
  {
    LOBYTE(result.pObject) = 0;
  }
  else
  {
    v65 = fn->Env;
    v11 = Scaleform::GFx::AS2::FnCall::Arg(fn, 4);
    LOBYTE(result.pObject) = Scaleform::GFx::AS2::Value::ToBool(v11, v65);
  }
  v12 = fn->Env;
  v13 = 0;
  if ( fn->FirstArgBottomIndex <= 32 * (v12->Stack.Pages.Data.Size - 1) + v12->Stack.pCurrent - v12->Stack.pPageStart )
    v13 = &v12->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
  Scaleform::GFx::AS2::Value::ToStringImpl(v13, &v71, v12, -1, 0);
  v69 = 0;
  if ( !strcmp(v71.pNode->pData, "up") )
  {
    v67 = 38;
LABEL_32:
    v14 = 0;
    v4 = fn->NArgs < 2;
    v74 = 0;
    if ( !v4 )
    {
      v15 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
      Scaleform::GFx::AS2::Value::Value(&v77, v15);
      v16 = v77.T.Type;
      if ( v77.T.Type < 2u || v77.T.Type == 10 )
      {
        ModalClip = Scaleform::GFx::MovieImpl::GetModalClip(v76, v72);
        if ( ModalClip )
          ++ModalClip->RefCount;
        v14 = ModalClip;
        v74 = ModalClip;
      }
      else
      {
        v17 = Scaleform::GFx::AS2::Value::ToCharacter(&v77, fn->Env);
        if ( v17 )
          ++v17->RefCount;
        v14 = (Scaleform::GFx::Sprite *)v17;
        v74 = v17;
      }
      if ( v16 >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v77);
    }
    if ( fn->NArgs < 3 )
    {
      v70 = 0;
    }
    else
    {
      v66 = fn->Env;
      v19 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
      v70 = Scaleform::GFx::AS2::Value::ToBool(v19, v66);
    }
    pfocusInfo.Prev_aRect.x1 = 0.0;
    pfocusInfo.Prev_aRect.y1 = 0.0;
    pfocusInfo.pFocusGroup = 0;
    pfocusInfo.Prev_aRect.x2 = 0.0;
    pfocusInfo.CurFocused.pObject = 0;
    pfocusInfo.Prev_aRect.y2 = 0.0;
    memset(&pfocusInfo.PrevKeyCode, 0, 13);
    keyEntry.Code = v67;
    keyEntry.KeyboardIndex = v72;
    v72 = v67;
    v20 = fn->Env;
    pfocusInfo.CurFocusIdx = -1;
    keyEntry.KeysState = v69;
    Scaleform::GFx::FocusGroupDescr::FocusGroupDescr(&pfocusGroup, v20->StringContext.pContext->pHeap);
    v21 = v74;
    if ( v14 )
    {
      CharacterHandle = v74->pNameHandle.pObject;
      if ( CharacterHandle || (CharacterHandle = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v74)) != 0 )
        ++CharacterHandle->RefCount;
    }
    else
    {
      CharacterHandle = 0;
    }
    v23 = pfocusGroup.ModalClip.pObject;
    if ( pfocusGroup.ModalClip.pObject )
    {
      --pfocusGroup.ModalClip.pObject->RefCount;
      v24 = v23;
      if ( v23->RefCount <= 0 )
      {
        Scaleform::GFx::CharacterHandle::~CharacterHandle(v23);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v24);
      }
    }
    pfocusGroup.ModalClip.pObject = CharacterHandle;
    v25 = (Scaleform::GFx::InteractiveObject *)v75;
    if ( v75 )
    {
      WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(v75);
      v27 = pfocusGroup.LastFocused.pProxy.pObject;
      if ( pfocusGroup.LastFocused.pProxy.pObject )
      {
        --pfocusGroup.LastFocused.pProxy.pObject->RefCount;
        if ( !v27->RefCount )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v27);
      }
      pfocusGroup.LastFocused.pProxy.pObject = WeakProxy;
    }
    else
    {
      v28 = pfocusGroup.LastFocused.pProxy.pObject;
      if ( pfocusGroup.LastFocused.pProxy.pObject )
      {
        --pfocusGroup.LastFocused.pProxy.pObject->RefCount;
        if ( !v28->RefCount )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v28);
      }
      pfocusGroup.LastFocused.pProxy.pObject = 0;
    }
    v29 = v76;
    Scaleform::GFx::MovieImpl::InitFocusKeyInfo(v76, &pfocusInfo, &keyEntry, result, COERCE_FLOAT(&pfocusGroup));
    pfocusInfo.ManualFocus = 1;
    Scaleform::GFx::MovieImpl::ProcessFocusKey(v29, KeyDown, &keyEntry, &pfocusInfo);
    if ( !pfocusInfo.CurFocused.pObject || pfocusInfo.CurFocused.pObject == v25 )
    {
      if ( v70 && pfocusGroup.TabableArray.Data.Size )
      {
        if ( v67 == 9 )
        {
          v30 = fn->Result;
          if ( (v69 & 1) != 0 )
            Scaleform::GFx::AS2::Value::SetAsCharacter(
              v30,
              pfocusGroup.TabableArray.Data.Data[pfocusGroup.TabableArray.Data.Size - 1].pObject);
          else
            Scaleform::GFx::AS2::Value::SetAsCharacter(v30, pfocusGroup.TabableArray.Data.Data->pObject);
        }
        else
        {
          v31 = 0;
          v32 = 0;
          v68 = 1.1754944e-38;
          result.pObject = (Scaleform::GFx::Sprite *)pfocusGroup.TabableArray.Data.Size;
          do
          {
            v33 = pfocusGroup.TabableArray.Data.Data[v32].pObject;
            v34 = &pfocusGroup.TabableArray.Data.Data[v32];
            if ( v33 )
              ++v33->RefCount;
            v35 = v34->pObject;
            if ( (pfocusInfo.InclFocusEnabled
               || ((unsigned __int8 (__thiscall *)(Scaleform::GFx::DisplayObjectBase *))v35->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].SetMatrix3D)(v35))
              && ((unsigned __int8 (__thiscall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::GFx::MovieImpl *, _DWORD))v35->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].SetMatrix)(
                   v35,
                   v76,
                   pfocusInfo.KeyboardIndex) )
            {
              Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(v35, &v82);
              v36 = (__m128 *)((int (__thiscall *)(Scaleform::GFx::DisplayObjectBase *, _BYTE *))v35->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable[1].UpdateTransform3D)(
                                v35,
                                v81);
              Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v82, (Scaleform::Render::Rect<float> *)&v77, v36);
              switch ( v72 )
              {
                case '%':
                  v53 = v68 < 1.1754944e-38;
                  v54 = 0;
                  v55 = v68 == 1.1754944e-38;
                  v50 = v52;
                  v51 = v68;
                  v43 = *(float *)&v77.V.FunctionValue.pLocalFrame;
                  goto LABEL_87;
                case '&':
                  v47 = v68 < 1.1754944e-38;
                  v48 = 0;
                  v49 = v68 == 1.1754944e-38;
                  v50 = v46;
                  v51 = v68;
                  v43 = *((float *)&v77.NV + 3);
LABEL_87:
                  if ( !__SETP__(v50 & 0x44, 0) )
                    goto LABEL_84;
                  if ( v43 > v51 )
                  {
                    v68 = v43;
                    v31 = v32;
                  }
                  break;
                case '\'':
                  v57 = v68 < 1.1754944e-38;
                  v58 = 0;
                  v59 = v68 == 1.1754944e-38;
                  v41 = v56;
                  v42 = v68;
                  v43 = *(float *)&v77.T.Type;
                  goto LABEL_80;
                case '(':
                  v38 = v68 < 1.1754944e-38;
                  v39 = 0;
                  v40 = v68 == 1.1754944e-38;
                  v41 = v37;
                  v42 = v68;
                  v43 = *(float *)&v77.V.pStringNode;
LABEL_80:
                  if ( __SETP__(v41 & 0x44, 0) )
                  {
                    v44 = v43 < v42;
                    v45 = v43;
                    if ( !v44 )
                      break;
                  }
                  else
                  {
LABEL_84:
                    v45 = v43;
                  }
                  v68 = v45;
                  v31 = v32;
                  break;
                default:
                  break;
              }
            }
            Scaleform::RefCountNTSImpl::Release(v35);
            ++v32;
          }
          while ( v32 < (unsigned int)result.pObject );
          Scaleform::GFx::AS2::Value::SetAsCharacter(fn->Result, pfocusGroup.TabableArray.Data.Data[v31].pObject);
          v21 = v74;
          v25 = (Scaleform::GFx::InteractiveObject *)v75;
        }
      }
      else
      {
        v60 = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v60);
        v60->T.Type = 1;
      }
    }
    else
    {
      Scaleform::GFx::AS2::Value::SetAsCharacter(fn->Result, pfocusInfo.CurFocused.pObject);
    }
    Scaleform::GFx::FocusGroupDescr::~FocusGroupDescr(&pfocusGroup);
    if ( pfocusInfo.CurFocused.pObject )
      Scaleform::RefCountNTSImpl::Release(pfocusInfo.CurFocused.pObject);
    if ( v21 )
      Scaleform::RefCountNTSImpl::Release(v21);
    pNode = v71.pNode;
    v62 = v71.pNode->RefCount-- == 1;
    if ( v62 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( v25 )
      Scaleform::RefCountNTSImpl::Release(v25);
    return;
  }
  if ( !strcmp(v71.pNode->pData, "down") )
  {
    v67 = 40;
    goto LABEL_32;
  }
  if ( Scaleform::GFx::ASString::operator==(&v71, "left") )
  {
    v67 = 37;
    goto LABEL_32;
  }
  if ( Scaleform::GFx::ASString::operator==(&v71, "right") )
  {
    v67 = 39;
    goto LABEL_32;
  }
  if ( Scaleform::GFx::ASString::operator==(&v71, "tab") )
  {
LABEL_31:
    v67 = 9;
    goto LABEL_32;
  }
  if ( Scaleform::GFx::ASString::operator==(&v71, "shifttab") )
  {
    v69 = 1;
    goto LABEL_31;
  }
  v63 = v71.pNode;
  v62 = v71.pNode->RefCount-- == 1;
  if ( v62 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v63);
  if ( v75 )
    Scaleform::RefCountNTSImpl::Release(v75);
}
