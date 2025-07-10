void __cdecl Scaleform::GFx::AS2::SelectionCtorFunction::GetControllerMaskByFocusGroup(
        const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // edi
  Scaleform::GFx::AS2::Value *v4; // ecx
  unsigned int v5; // eax
  int ControllerMaskByFocusGroup; // eax
  Scaleform::GFx::AS2::Value *v7; // esi
  double v8; // [esp+8h] [ebp-8h]

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
  ControllerMaskByFocusGroup = Scaleform::GFx::MovieImpl::GetControllerMaskByFocusGroup(pMovieImpl, v5);
  v7 = fn->Result;
  v8 = (double)ControllerMaskByFocusGroup;
  if ( v7->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v7);
  v7->NV.NumberValue = v8;
  v7->T.Type = 3;
}
