void __cdecl Scaleform::GFx::AS2::SelectionCtorFunction::SetSelection(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::Environment *Env; // ecx
  unsigned int v4; // eax
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::TextField *v7; // edi
  int v8; // ebp
  int v9; // eax
  Scaleform::GFx::AS2::Value *v10; // eax
  int v11; // eax
  Scaleform::GFx::AS2::Value *v12; // eax
  Scaleform::GFx::AS2::Environment *v13; // [esp-8h] [ebp-10h]
  Scaleform::GFx::AS2::Environment *v14; // [esp-8h] [ebp-10h]
  Scaleform::GFx::AS2::Environment *v15; // [esp-4h] [ebp-Ch]

  v1 = fn;
  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  Env = v1->Env;
  if ( Env )
  {
    v4 = 0;
    if ( Env->StringContext.pContext->GFxExtensions.Value == 1 && v1->NArgs >= 3 )
    {
      v15 = v1->Env;
      v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 2);
      v4 = Scaleform::GFx::AS2::Value::ToUInt32(v5, v15);
    }
    pMovieImpl = v1->Env->Target->pASRoot->pMovieImpl;
    Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&pMovieImpl->FocusGroups[pMovieImpl->FocusGroupIndexes[v4]].LastFocused,
      (Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&fn);
    v7 = (Scaleform::GFx::TextField *)fn;
    if ( fn )
    {
      ++fn->Result;
      Scaleform::RefCountNTSImpl::Release(v7);
      if ( v7->GetType(v7) == MouseWheel )
      {
        v8 = 0;
        v9 = 0x7FFFFFFF;
        if ( v1->NArgs >= 2 )
        {
          v13 = v1->Env;
          v10 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
          v11 = Scaleform::GFx::AS2::Value::ToInt32(v10, v13);
          v14 = v1->Env;
          v8 = v11;
          v12 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
          v9 = Scaleform::GFx::AS2::Value::ToInt32(v12, v14);
        }
        Scaleform::GFx::TextField::SetSelection(v7, v8, v9);
      }
      Scaleform::RefCountNTSImpl::Release(v7);
    }
  }
}
