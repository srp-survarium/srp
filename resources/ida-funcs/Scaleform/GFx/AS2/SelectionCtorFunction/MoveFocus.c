void __cdecl Scaleform::GFx::AS2::SelectionCtorFunction::MoveFocus(const Scaleform::GFx::AS2::FnCall *fn)
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
  Scaleform::GFx::ASStringNode *pNode; // ebx
  __int16 v15; // ax
  Scaleform::GFx::MovieImpl *v16; // esi
  Scaleform::GFx::InteractiveObject *v17; // ebx
  Scaleform::GFx::InteractiveObject *v18; // ecx
  Scaleform::GFx::AS2::Value *v19; // edi
  Scaleform::GFx::CharacterHandle *v20; // esi
  Scaleform::GFx::CharacterHandle *CharacterHandle; // eax
  Scaleform::GFx::ASStringNode *v22; // ecx
  bool v23; // zf
  Scaleform::Log *v24; // eax
  const char *v25; // [esp-8h] [ebp-68h]
  Scaleform::GFx::AS2::Environment *Env; // [esp-4h] [ebp-64h]
  Scaleform::GFx::AS2::Environment *v27; // [esp-4h] [ebp-64h]
  unsigned __int8 v28; // [esp+Fh] [ebp-51h]
  Scaleform::GFx::ASString v29; // [esp+10h] [ebp-50h] BYREF
  unsigned int v30; // [esp+14h] [ebp-4Ch]
  Scaleform::RefCountNTSImpl *v31; // [esp+18h] [ebp-48h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [esp+1Ch] [ebp-44h] BYREF
  Scaleform::GFx::MovieImpl *v33; // [esp+20h] [ebp-40h]
  Scaleform::GFx::InputEventsQueueEntry::KeyEntry keyEntry; // [esp+24h] [ebp-3Ch] BYREF
  Scaleform::GFx::ProcessFocusKeyInfo pfocusInfo; // [esp+30h] [ebp-30h] BYREF

  v1 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v1);
  v1->T.Type = 0;
  NArgs = fn->NArgs;
  if ( !NArgs )
    return;
  v30 = 0;
  if ( NArgs >= 4 )
  {
    Env = fn->Env;
    v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
    v30 = Scaleform::GFx::AS2::Value::ToUInt32(v3, Env);
  }
  v4 = fn->NArgs < 2;
  v5 = fn->Env;
  pMovieImpl = v5->Target->pASRoot->pMovieImpl;
  v33 = pMovieImpl;
  if ( v4
    || (Type = Scaleform::GFx::AS2::FnCall::Arg(fn, 1)->T.Type) == 0
    || Type == 10
    || Scaleform::GFx::AS2::FnCall::Arg(fn, 1)->T.Type == 1 )
  {
    Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&pMovieImpl->FocusGroups[pMovieImpl->FocusGroupIndexes[v30]].LastFocused,
      &result);
    pObject = result.pObject;
    if ( result.pObject )
    {
      ++result.pObject->RefCount;
      Scaleform::RefCountNTSImpl::Release(pObject);
      ++pObject->RefCount;
    }
    v31 = pObject;
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
  }
  else
  {
    v8 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
    v9 = Scaleform::GFx::AS2::Value::ToCharacter(v8, v5);
    if ( v9 )
      ++v9->RefCount;
    v31 = v9;
  }
  if ( fn->NArgs < 3 )
  {
    LOBYTE(result.pObject) = 0;
  }
  else
  {
    v27 = fn->Env;
    v11 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
    LOBYTE(result.pObject) = Scaleform::GFx::AS2::Value::ToBool(v11, (int)fn, v27);
  }
  v12 = fn->Env;
  v13 = 0;
  if ( fn->FirstArgBottomIndex <= 32 * (v12->Stack.Pages.Data.Size - 1) + v12->Stack.pCurrent - v12->Stack.pPageStart )
    v13 = &v12->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
  Scaleform::GFx::AS2::Value::ToStringImpl(v13, &v29, v12, -1, 0);
  pNode = v29.pNode;
  v28 = 0;
  if ( !strcmp(v29.pNode->pData, "up") )
  {
    v15 = 38;
LABEL_32:
    v16 = v33;
    pfocusInfo.Prev_aRect.x1 = 0.0;
    pfocusInfo.Prev_aRect.y1 = 0.0;
    pfocusInfo.Prev_aRect.x2 = 0.0;
    pfocusInfo.Prev_aRect.y2 = 0.0;
    keyEntry.KeyboardIndex = v30;
    keyEntry.Code = v15;
    pfocusInfo.pFocusGroup = 0;
    pfocusInfo.CurFocused.pObject = 0;
    memset(&pfocusInfo.PrevKeyCode, 0, 13);
    keyEntry.KeysState = v28;
    pfocusInfo.CurFocusIdx = -1;
    Scaleform::GFx::MovieImpl::InitFocusKeyInfo(v33, &pfocusInfo, &keyEntry, result, 0.0);
    v17 = (Scaleform::GFx::InteractiveObject *)v31;
    if ( v31 )
      ++v31->RefCount;
    if ( pfocusInfo.CurFocused.pObject )
      Scaleform::RefCountNTSImpl::Release(pfocusInfo.CurFocused.pObject);
    pfocusInfo.CurFocused.pObject = v17;
    pfocusInfo.ManualFocus = 1;
    Scaleform::GFx::MovieImpl::ProcessFocusKey(v16, KeyDown, &keyEntry, &pfocusInfo);
    Scaleform::GFx::MovieImpl::FinalizeProcessFocusKey(v16, (Scaleform::Ptr<Scaleform::GFx::Sprite>)&pfocusInfo);
    v18 = pfocusInfo.CurFocused.pObject;
    v19 = fn->Result;
    if ( pfocusInfo.CurFocused.pObject )
    {
      v20 = pfocusInfo.CurFocused.pObject->pNameHandle.pObject;
      if ( !v20 )
      {
        CharacterHandle = Scaleform::GFx::DisplayObject::CreateCharacterHandle(pfocusInfo.CurFocused.pObject);
        v18 = pfocusInfo.CurFocused.pObject;
        v20 = CharacterHandle;
      }
    }
    else
    {
      v20 = 0;
    }
    if ( v19->T.Type != 7 || v19->V.pCharHandle != v20 )
    {
      Scaleform::GFx::AS2::Value::DropRefs(v19);
      v19->T.Type = 7;
      v19->NV.Int32Value = (int)v20;
      if ( v20 )
        ++v20->RefCount;
      v18 = pfocusInfo.CurFocused.pObject;
    }
    if ( v18 )
      Scaleform::RefCountNTSImpl::Release(v18);
    v22 = v29.pNode;
    v23 = v29.pNode->RefCount-- == 1;
    if ( v23 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v22);
    if ( v17 )
      Scaleform::RefCountNTSImpl::Release(v17);
    return;
  }
  if ( !strcmp(v29.pNode->pData, "down") )
  {
    v15 = 40;
    goto LABEL_32;
  }
  if ( Scaleform::GFx::ASString::operator==(&v29, "left") )
  {
    v15 = 37;
    goto LABEL_32;
  }
  if ( Scaleform::GFx::ASString::operator==(&v29, "right") )
  {
    v15 = 39;
    goto LABEL_32;
  }
  if ( Scaleform::GFx::ASString::operator==(&v29, "tab") )
  {
LABEL_31:
    v15 = 9;
    goto LABEL_32;
  }
  if ( Scaleform::GFx::ASString::operator==(&v29, "shifttab") )
  {
    v28 = 1;
    goto LABEL_31;
  }
  if ( fn->Env->Target->GetLog(fn->Env->Target) )
  {
    v24 = (Scaleform::Log *)((int (__thiscall *)(Scaleform::GFx::InteractiveObject *, const char *, const char *))fn->Env->Target->GetLog)(
                              fn->Env->Target,
                              "moveFocus - invalid string id for key: '%s'",
                              pNode->pData);
    Scaleform::Log::LogWarning(v24, v25);
  }
  v23 = pNode->RefCount-- == 1;
  if ( v23 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( v31 )
    Scaleform::RefCountNTSImpl::Release(v31);
}
