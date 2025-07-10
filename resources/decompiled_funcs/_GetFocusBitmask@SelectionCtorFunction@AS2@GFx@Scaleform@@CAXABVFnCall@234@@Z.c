void __cdecl Scaleform::GFx::AS2::SelectionCtorFunction::GetFocusBitmask(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // esi
  Scaleform::GFx::AS2::Environment *Env; // eax
  unsigned int v4; // edi
  __int16 v5; // bx
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::InteractiveObject *v7; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  Scaleform::GFx::Sprite *pObject; // esi
  Scaleform::GFx::AS2::Value *v10; // esi
  Scaleform::GFx::AS2::Environment *v11; // [esp-8h] [ebp-1Ch]
  Scaleform::RefCountNTSImpl *v12; // [esp+Ch] [ebp-8h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [esp+10h] [ebp-4h] BYREF
  unsigned __int16 bm; // [esp+18h] [ebp+4h]

  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 1;
  Env = fn->Env;
  v4 = 0;
  if ( Env )
  {
    if ( Env->StringContext.pContext->GFxExtensions.Value == 1 )
    {
      v5 = 1;
      if ( fn->NArgs >= 1 )
      {
        v11 = fn->Env;
        v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v7 = Scaleform::GFx::AS2::Value::ToCharacter(v6, v11);
        v12 = v7;
        if ( v7 )
          ++v7->RefCount;
        bm = 0;
        do
        {
          pMovieImpl = fn->Env->Target->pASRoot->pMovieImpl;
          Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
            (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&pMovieImpl->FocusGroups[pMovieImpl->FocusGroupIndexes[v4]].LastFocused,
            (Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&result);
          pObject = result.pObject;
          if ( result.pObject )
          {
            ++result.pObject->RefCount;
            Scaleform::RefCountNTSImpl::Release(pObject);
          }
          if ( pObject == v12 )
            bm |= v5;
          if ( pObject )
            Scaleform::RefCountNTSImpl::Release(pObject);
          ++v4;
          v5 *= 2;
        }
        while ( v4 < 6 );
        v10 = fn->Result;
        if ( v10->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
        v10->T.Type = 3;
        v10->NV.NumberValue = (double)bm;
        if ( v12 )
          Scaleform::RefCountNTSImpl::Release(v12);
      }
    }
  }
}
