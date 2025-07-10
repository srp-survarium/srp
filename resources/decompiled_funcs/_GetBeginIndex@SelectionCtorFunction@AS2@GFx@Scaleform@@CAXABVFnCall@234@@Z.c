void __cdecl Scaleform::GFx::AS2::SelectionCtorFunction::GetBeginIndex(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // edi
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::Environment *Env; // ecx
  unsigned int v4; // eax
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::TextField *v7; // esi
  Scaleform::GFx::AS2::Value *v8; // edi
  Scaleform::GFx::AS2::Environment *v9; // [esp-4h] [ebp-14h]
  double v10; // [esp+8h] [ebp-8h]

  v1 = fn;
  Result = fn->Result;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  Result->T.Type = 3;
  Result->NV.NumberValue = -1.0;
  Env = v1->Env;
  if ( Env )
  {
    v4 = 0;
    if ( Env->StringContext.pContext->GFxExtensions.Value == 1 && v1->NArgs >= 3 )
    {
      v9 = v1->Env;
      v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 2);
      v4 = Scaleform::GFx::AS2::Value::ToUInt32(v5, v9);
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
        fn = (const Scaleform::GFx::AS2::FnCall *)Scaleform::GFx::TextField::GetBeginIndex(v7);
        v8 = v1->Result;
        v10 = (double)(unsigned int)fn;
        if ( v8->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v8);
        v8->T.Type = 3;
        v8->NV.NumberValue = v10;
      }
      Scaleform::RefCountNTSImpl::Release(v7);
    }
  }
}
