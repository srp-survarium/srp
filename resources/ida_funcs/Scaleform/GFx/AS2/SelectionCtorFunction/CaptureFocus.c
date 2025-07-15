void __cdecl Scaleform::GFx::AS2::SelectionCtorFunction::CaptureFocus(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // esi
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v4; // ecx
  Scaleform::GFx::AS2::Environment *v5; // edx
  Scaleform::GFx::MovieImpl *pMovieImpl; // esi
  unsigned int v7; // ebp
  unsigned int v8; // eax
  Scaleform::GFx::AS2::Value *v9; // ecx
  Scaleform::GFx::Sprite *pObject; // ecx
  Scaleform::GFx::Sprite *v11; // ebx
  Scaleform::GFx::Sprite *v12; // esi
  Scaleform::GFx::CharacterHandle *CharacterHandle; // esi
  Scaleform::GFx::AS2::Value *v14; // edi
  Scaleform::GFx::MovieImpl *proot; // [esp+10h] [ebp-8h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [esp+14h] [ebp-4h] BYREF
  char capture; // [esp+1Ch] [ebp+4h]

  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 0;
  if ( fn->NArgs < 1 )
  {
    capture = 1;
  }
  else
  {
    Env = fn->Env;
    v4 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v4 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    capture = Scaleform::GFx::AS2::Value::ToBool(v4, fn->Env);
  }
  v5 = fn->Env;
  pMovieImpl = v5->Target->pASRoot->pMovieImpl;
  v7 = 0;
  proot = pMovieImpl;
  if ( fn->NArgs >= 2 )
  {
    v8 = fn->FirstArgBottomIndex - 1;
    v9 = 0;
    if ( v8 <= 32 * (v5->Stack.Pages.Data.Size - 1) + v5->Stack.pCurrent - v5->Stack.pPageStart )
      v9 = &v5->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    v7 = Scaleform::GFx::AS2::Value::ToUInt32(v9, v5);
  }
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&pMovieImpl->FocusGroups[pMovieImpl->FocusGroupIndexes[v7]].LastFocused,
    (Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&result);
  pObject = result.pObject;
  if ( result.pObject )
    ++result.pObject->RefCount;
  v11 = pObject;
  if ( pObject )
  {
    Scaleform::RefCountNTSImpl::Release(pObject);
  }
  else
  {
    Scaleform::GFx::MovieImpl::ActivateFocusCapture(pMovieImpl, v7);
    Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&pMovieImpl->FocusGroups[pMovieImpl->FocusGroupIndexes[v7]].LastFocused,
      (Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&result);
    v12 = result.pObject;
    if ( result.pObject )
    {
      ++result.pObject->RefCount;
      Scaleform::RefCountNTSImpl::Release(v12);
      ++v12->RefCount;
    }
    v11 = v12;
    if ( v12 )
      Scaleform::RefCountNTSImpl::Release(v12);
    pMovieImpl = proot;
  }
  if ( capture )
  {
    if ( !v11 )
      return;
    if ( v11->IsFocusEnabled(v11, GFx_FocusMovedByKeyboard) )
      Scaleform::GFx::MovieImpl::SetKeyboardFocusTo(pMovieImpl, v11, v7, GFx_FocusMovedByKeyboard);
  }
  else
  {
    Scaleform::GFx::MovieImpl::HideFocusRect(pMovieImpl, v7);
  }
  if ( v11 )
  {
    CharacterHandle = v11->pNameHandle.pObject;
    v14 = fn->Result;
    if ( !CharacterHandle )
      CharacterHandle = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v11);
    if ( v14->T.Type != 7 || v14->V.pCharHandle != CharacterHandle )
    {
      Scaleform::GFx::AS2::Value::DropRefs(v14);
      v14->T.Type = 7;
      v14->NV.Int32Value = (int)CharacterHandle;
      if ( CharacterHandle )
        ++CharacterHandle->RefCount;
    }
    Scaleform::RefCountNTSImpl::Release(v11);
  }
}
