void __cdecl Scaleform::GFx::AS2::SelectionCtorFunction::SetControllerFocusGroup(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // edi
  Scaleform::GFx::AS2::Value *v5; // ecx
  unsigned int v6; // eax
  Scaleform::GFx::AS2::Environment *v7; // edx
  unsigned int v8; // eax
  Scaleform::GFx::AS2::Value *v9; // ecx
  unsigned int v10; // eax
  bool v11; // al
  Scaleform::GFx::AS2::Value *v12; // esi
  bool v13; // bl
  unsigned int v14; // [esp+Ch] [ebp+4h]

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  if ( fn->NArgs >= 2 )
  {
    Env = fn->Env;
    pMovieImpl = Env->Target->pASRoot->pMovieImpl;
    v5 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v5 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    v6 = Scaleform::GFx::AS2::Value::ToUInt32(v5, fn->Env);
    v7 = fn->Env;
    v14 = v6;
    v8 = fn->FirstArgBottomIndex - 1;
    v9 = 0;
    if ( v8 <= 32 * (v7->Stack.Pages.Data.Size - 1) + v7->Stack.pCurrent - v7->Stack.pPageStart )
      v9 = &v7->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    v10 = Scaleform::GFx::AS2::Value::ToUInt32(v9, v7);
    v11 = pMovieImpl->SetControllerFocusGroup(pMovieImpl, v14, v10);
    v12 = fn->Result;
    v13 = v11;
    Scaleform::GFx::AS2::Value::DropRefs(v12);
    v12->V.BooleanValue = v13;
    v12->T.Type = 2;
  }
}
