void __cdecl Scaleform::GFx::AS2::SelectionCtorFunction::CaptureFocus(int fn)
{
  Scaleform::GFx::AS2::Value *v2; // esi
  Scaleform::GFx::AS2::Environment *v3; // edx
  Scaleform::GFx::AS2::Value *v4; // ecx
  Scaleform::GFx::AS2::Environment *v5; // edx
  Scaleform::GFx::MovieImpl *pMovieImpl; // esi
  Scaleform::Ptr<Scaleform::GFx::Sprite> v7; // ebp
  unsigned int v8; // eax
  Scaleform::GFx::AS2::Value *v9; // ecx
  Scaleform::GFx::Sprite *pObject; // ecx
  Scaleform::GFx::Sprite *v11; // ebx
  Scaleform::GFx::Sprite *v12; // esi
  Scaleform::GFx::CharacterHandle *CharacterHandle; // esi
  Scaleform::GFx::AS2::Value *v14; // edi
  Scaleform::GFx::MovieImpl *v15; // [esp+10h] [ebp-8h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [esp+14h] [ebp-4h] BYREF
  bool v17; // [esp+1Ch] [ebp+4h]

  v2 = *(Scaleform::GFx::AS2::Value **)(fn + 4);
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 0;
  if ( *(int *)(fn + 28) < 1 )
  {
    v17 = 1;
  }
  else
  {
    v3 = *(Scaleform::GFx::AS2::Environment **)(fn + 24);
    v4 = 0;
    if ( *(_DWORD *)(fn + 32) <= 32 * (v3->Stack.Pages.Data.Size - 1) + v3->Stack.pCurrent - v3->Stack.pPageStart )
      v4 = &v3->Stack.Pages.Data.Data[*(_DWORD *)(fn + 32) >> 5]->Values[*(_DWORD *)(fn + 32) & 0x1F];
    v17 = Scaleform::GFx::AS2::Value::ToBool(v4, fn, *(const Scaleform::GFx::AS2::Environment **)(fn + 24));
  }
  v5 = *(Scaleform::GFx::AS2::Environment **)(fn + 24);
  pMovieImpl = v5->Target->pASRoot->pMovieImpl;
  v7.pObject = 0;
  v15 = pMovieImpl;
  if ( *(int *)(fn + 28) >= 2 )
  {
    v8 = *(_DWORD *)(fn + 32) - 1;
    v9 = 0;
    if ( v8 <= 32 * (v5->Stack.Pages.Data.Size - 1) + v5->Stack.pCurrent - v5->Stack.pPageStart )
      v9 = &v5->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    v7.pObject = (Scaleform::GFx::Sprite *)Scaleform::GFx::AS2::Value::ToUInt32(v9, v5);
  }
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&pMovieImpl->FocusGroups[pMovieImpl->FocusGroupIndexes[(unsigned int)v7.pObject]].LastFocused,
    &result);
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
    Scaleform::GFx::MovieImpl::ActivateFocusCapture(pMovieImpl, (unsigned __int8)v7.pObject);
    Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&pMovieImpl->FocusGroups[pMovieImpl->FocusGroupIndexes[(unsigned int)v7.pObject]].LastFocused,
      &result);
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
    pMovieImpl = v15;
  }
  if ( v17 )
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
    v14 = *(Scaleform::GFx::AS2::Value **)(fn + 4);
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
