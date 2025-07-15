void __cdecl Scaleform::GFx::AS2::SelectionCtorFunction::SetFocus(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // edi
  Scaleform::GFx::AS2::Environment *Env; // edi
  Scaleform::GFx::Sprite *v4; // ebp
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::AS2::Environment *v6; // ecx
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::InteractiveObject *v8; // eax
  Scaleform::GFx::AS2::Value *v9; // eax
  Scaleform::GFx::InteractiveObject *v10; // eax
  unsigned int v11; // edi
  Scaleform::GFx::AS2::Value *v12; // eax
  Scaleform::GFx::AS2::Value *v13; // esi
  Scaleform::GFx::AS2::Value *v14; // esi
  Scaleform::GFx::AS2::Environment *v15; // [esp-8h] [ebp-40h]
  Scaleform::GFx::ASString result; // [esp+Ch] [ebp-2Ch] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+10h] [ebp-28h] BYREF
  Scaleform::GFx::AS2::Environment::GetVarParams params; // [esp+20h] [ebp-18h] BYREF
  char retVal; // [esp+3Ch] [ebp+4h]

  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 2;
  v2->V.BooleanValue = 0;
  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    if ( Env )
    {
      v4 = 0;
      if ( Scaleform::GFx::AS2::FnCall::Arg(fn, 0)->T.Type == 5 )
      {
        val.T.Type = 0;
        v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        Scaleform::GFx::AS2::Value::ToStringImpl(v5, &result, Env, -1, 0);
        params.VarName = &result;
        v6 = fn->Env;
        params.pResult = &val;
        memset(&params.pWithStack, 0, 16);
        retVal = Scaleform::GFx::AS2::Environment::FindVariable(v6, 0, (int)fn, &params, 0, 0);
        pNode = result.pNode;
        --result.pNode->RefCount;
        if ( !pNode->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        if ( retVal && val.T.Type == 7 )
        {
          v8 = Scaleform::GFx::AS2::Value::ToCharacter(&val, fn->Env);
          if ( v8 )
            ++v8->RefCount;
          v4 = (Scaleform::GFx::Sprite *)v8;
        }
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
      }
      else
      {
        v9 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v10 = Scaleform::GFx::AS2::Value::ToCharacter(v9, Env);
        if ( v10 )
          ++v10->RefCount;
        v4 = (Scaleform::GFx::Sprite *)v10;
      }
      v11 = 0;
      if ( fn->Env->StringContext.pContext->GFxExtensions.Value == 1 && fn->NArgs >= 2 )
      {
        v15 = fn->Env;
        v12 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v11 = Scaleform::GFx::AS2::Value::ToUInt32(v12, v15);
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
