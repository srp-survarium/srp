void __cdecl Scaleform::GFx::AS2::SelectionCtorFunction::GetControllerFocusGroup(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // edi
  Scaleform::GFx::AS2::Value *v4; // ecx
  unsigned int v5; // eax
  long double v6; // st7
  Scaleform::GFx::AS2::Value *v7; // esi

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  Env = fn->Env;
  pMovieImpl = Env->Target->pASRoot->pMovieImpl;
  if ( fn->NArgs < 1 )
  {
    v5 = 0;
  }
  else
  {
    v4 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v4 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    v5 = Scaleform::GFx::AS2::Value::ToUInt32(v4, Env);
  }
  v6 = (double)pMovieImpl->GetControllerFocusGroup(pMovieImpl, v5);
  v7 = fn->Result;
  if ( v7->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v7);
  v7->NV.NumberValue = v6;
  v7->T.Type = 3;
}
