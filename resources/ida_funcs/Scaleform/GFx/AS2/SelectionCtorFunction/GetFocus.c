void __cdecl Scaleform::GFx::AS2::SelectionCtorFunction::GetFocus(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // edi
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::Environment *Env; // ecx
  unsigned int v4; // eax
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::DisplayObject *v7; // esi
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::AS2::Value *v9; // edi
  Scaleform::GFx::CharacterHandle *v10; // ebp
  int pNode; // eax
  Scaleform::GFx::AS2::Environment *v12; // [esp-4h] [ebp-10h]

  v1 = fn;
  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 1;
  Env = v1->Env;
  if ( Env )
  {
    v4 = 0;
    if ( Env->StringContext.pContext->GFxExtensions.Value == 1 && v1->NArgs >= 1 )
    {
      v12 = v1->Env;
      v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      v4 = Scaleform::GFx::AS2::Value::ToUInt32(v5, v12);
    }
    pMovieImpl = v1->Env->Target->pASRoot->pMovieImpl;
    Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&pMovieImpl->FocusGroups[pMovieImpl->FocusGroupIndexes[v4]].LastFocused,
      (Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&fn);
    v7 = (Scaleform::GFx::DisplayObject *)fn;
    if ( fn )
    {
      ++fn->Result;
      Scaleform::RefCountNTSImpl::Release(v7);
      pObject = v7->pNameHandle.pObject;
      if ( !pObject )
        pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v7);
      v9 = v1->Result;
      v10 = pObject;
      if ( v9->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v9);
      v9->T.Type = 5;
      pNode = (int)v10->NamePath.pNode;
      v9->NV.Int32Value = pNode;
      ++*(_DWORD *)(pNode + 12);
      Scaleform::RefCountNTSImpl::Release(v7);
    }
  }
}
