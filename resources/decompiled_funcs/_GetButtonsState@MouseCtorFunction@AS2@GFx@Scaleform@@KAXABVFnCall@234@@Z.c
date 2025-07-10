void __cdecl Scaleform::GFx::AS2::MouseCtorFunction::GetButtonsState(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebx
  unsigned int v4; // edi
  Scaleform::GFx::AS2::Value *v5; // ecx
  int v6; // eax
  Scaleform::GFx::AS2::Value *v7; // esi
  unsigned int v8; // edi

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  Env = fn->Env;
  pMovieImpl = Env->Target->pASRoot->pMovieImpl;
  v4 = 0;
  if ( fn->NArgs > 0 )
  {
    v5 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v5 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    v4 = (__int64)Scaleform::GFx::AS2::Value::ToNumber(v5, Env);
  }
  if ( v4 < pMovieImpl->GetMouseCursorCount(pMovieImpl) )
  {
    if ( v4 < 6 )
      v6 = (int)&pMovieImpl->mMouseState[v4];
    else
      v6 = 0;
    v7 = fn->Result;
    v8 = *(_DWORD *)(v6 + 24);
    if ( v7->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 3;
    v7->NV.NumberValue = (double)v8;
  }
}
