void __cdecl Scaleform::GFx::AS2::SelectionCtorFunction::SetFocus(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::Environment *Env; // edi
  Scaleform::GFx::Sprite *v4; // ebp
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::AS2::Environment *v6; // ecx
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::InteractiveObject *v8; // eax
  Scaleform::GFx::AS2::Value *v9; // eax
  Scaleform::GFx::InteractiveObject *v10; // eax
  Scaleform::Ptr<Scaleform::GFx::Sprite> v11; // edi
  Scaleform::GFx::AS2::Value *v12; // eax
  Scaleform::GFx::AS2::Value *v13; // esi
  Scaleform::GFx::AS2::Value *v14; // esi
  Scaleform::GFx::AS2::Environment *v15; // [esp-8h] [ebp-40h]
  Scaleform::GFx::ASStringNode *v16; // [esp+Ch] [ebp-2Ch] BYREF
  Scaleform::GFx::AS2::Value v17; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::Environment::GetVarParams v18; // [esp+20h] [ebp-18h] BYREF
  char Variable; // [esp+3Ch] [ebp+4h]

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 2;
  Result->V.BooleanValue = 0;
  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    if ( Env )
    {
      v4 = 0;
      if ( Scaleform::GFx::AS2::FnCall::Arg(fn, 0)->T.Type == 5 )
      {
        v17.T.Type = 0;
        v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        Scaleform::GFx::AS2::Value::ToStringImpl(v5, (Scaleform::GFx::ASString *)&v16, Env, -1, 0);
        v18.VarName = (const Scaleform::GFx::ASString *)&v16;
        v6 = fn->Env;
        v18.pResult = &v17;
        memset(&v18.pWithStack, 0, 16);
        Variable = Scaleform::GFx::AS2::Environment::FindVariable(v6, 0, (int)fn, &v18, 0, 0);
        v7 = v16;
        --v16->RefCount;
        if ( !v7->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v7);
        if ( Variable && v17.T.Type == 7 )
        {
          v8 = Scaleform::GFx::AS2::Value::ToCharacter(&v17, fn->Env);
          if ( v8 )
            ++v8->RefCount;
          v4 = (Scaleform::GFx::Sprite *)v8;
        }
        if ( v17.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v17);
      }
      else
      {
        v9 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v10 = Scaleform::GFx::AS2::Value::ToCharacter(v9, Env);
        if ( v10 )
          ++v10->RefCount;
        v4 = (Scaleform::GFx::Sprite *)v10;
      }
      v11.pObject = 0;
      if ( fn->Env->StringContext.pContext->GFxExtensions.Value == 1 && fn->NArgs >= 2 )
      {
        v15 = fn->Env;
        v12 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v11.pObject = (Scaleform::GFx::Sprite *)Scaleform::GFx::AS2::Value::ToUInt32(v12, v15);
      }
      if ( v4 )
      {
        if ( v4->IsFocusEnabled(v4, GFx_FocusMovedByKeyboard) )
        {
          Scaleform::GFx::MovieImpl::SetKeyboardFocusTo(
            fn->Env->Target->pASRoot->pMovieImpl,
            v4,
            v11,
            GFx_FocusMovedByKeyboard);
          v13 = fn->Result;
          Scaleform::GFx::AS2::Value::DropRefs(v13);
          v13->T.Type = 2;
          v13->V.BooleanValue = 1;
        }
        Scaleform::RefCountNTSImpl::Release(v4);
      }
      else
      {
        Scaleform::GFx::MovieImpl::SetKeyboardFocusTo(
          fn->Env->Target->pASRoot->pMovieImpl,
          0,
          v11,
          GFx_FocusMovedByKeyboard);
        v14 = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v14);
        v14->T.Type = 2;
        v14->V.BooleanValue = 1;
      }
    }
  }
}
