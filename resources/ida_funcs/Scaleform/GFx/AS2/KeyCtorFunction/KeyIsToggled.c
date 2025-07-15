void __cdecl Scaleform::GFx::AS2::KeyCtorFunction::KeyIsToggled(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::AS2::Value *v2; // ecx
  int v3; // edi
  unsigned int v4; // eax
  Scaleform::GFx::AS2::Value *v5; // eax
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // ecx
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ecx
  Scaleform::GFx::KeyboardState *v8; // ecx
  bool v9; // bl
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::Environment *v11; // [esp-Ch] [ebp-14h]

  Env = fn->Env;
  if ( fn->NArgs >= 1 )
  {
    v2 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v2 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    v3 = Scaleform::GFx::AS2::Value::ToInt32(v2, Env);
    v4 = 0;
    if ( fn->Env->StringContext.pContext->GFxExtensions.Value == 1 && fn->NArgs >= 2 )
    {
      v11 = fn->Env;
      v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
      v4 = Scaleform::GFx::AS2::Value::ToUInt32(v5, v11);
    }
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = &ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    v9 = v4 < 6
      && (v8 = (Scaleform::GFx::KeyboardState *)(&p_pProto[63].pObject[94].ArePropertiesSet + 1660 * v4)) != 0
      && Scaleform::GFx::KeyboardState::IsKeyToggled(v8, v3);
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->V.BooleanValue = v9;
    Result->T.Type = 2;
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(Env, "KeyIsToggled needs one Argument (the key code)");
  }
}
