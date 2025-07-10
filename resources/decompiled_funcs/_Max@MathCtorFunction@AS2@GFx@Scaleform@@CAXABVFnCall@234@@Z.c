void __cdecl Scaleform::GFx::AS2::MathCtorFunction::Max(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v2; // ecx
  Scaleform::GFx::AS2::Environment *v3; // edx
  unsigned int v4; // eax
  Scaleform::GFx::AS2::Value *v5; // ecx
  long double v6; // st7
  Scaleform::GFx::AS2::Value *Result; // esi
  double arg0; // [esp+Ch] [ebp-8h]

  Env = fn->Env;
  v2 = 0;
  if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
    v2 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
  arg0 = Scaleform::GFx::AS2::Value::ToNumber(v2, fn->Env);
  v3 = fn->Env;
  v4 = fn->FirstArgBottomIndex - 1;
  v5 = 0;
  if ( v4 <= 32 * (v3->Stack.Pages.Data.Size - 1) + v3->Stack.pCurrent - v3->Stack.pPageStart )
    v5 = &v3->Stack.Pages.Data.Data[v4 >> 5]->Values[v4 & 0x1F];
  v6 = Scaleform::GFx::AS2::Value::ToNumber(v5, fn->Env);
  if ( arg0 > v6 )
    v6 = arg0;
  Result = fn->Result;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->NV.NumberValue = v6;
  Result->T.Type = 3;
}
