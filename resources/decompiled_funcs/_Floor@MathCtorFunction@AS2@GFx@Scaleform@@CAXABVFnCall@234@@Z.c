void __cdecl Scaleform::GFx::AS2::MathCtorFunction::Floor(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v2; // ecx
  double X; // st7
  double v4; // st7
  Scaleform::GFx::AS2::Value *Result; // esi

  Env = fn->Env;
  v2 = 0;
  if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
    v2 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
  X = Scaleform::GFx::AS2::Value::ToNumber(v2, fn->Env);
  v4 = floor(X);
  Result = fn->Result;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->NV.NumberValue = v4;
  Result->T.Type = 3;
}
