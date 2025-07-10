void __cdecl Scaleform::GFx::AS2::GAS_ASnativeMouseButtonStates(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v2; // ecx
  unsigned int v3; // eax
  Scaleform::GFx::AS2::Value *Result; // edi
  unsigned int v5; // ebx
  unsigned int CurButtonsState; // esi

  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    v2 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v2 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    v3 = Scaleform::GFx::AS2::Value::ToUInt32(v2, Env);
    Result = fn->Result;
    v5 = v3;
    CurButtonsState = fn->Env->Target->pASRoot->pMovieImpl->mMouseState[0].CurButtonsState;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 2;
    Result->V.BooleanValue = (v5 & CurButtonsState) == v5;
  }
}
