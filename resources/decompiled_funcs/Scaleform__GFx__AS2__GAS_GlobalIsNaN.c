void __cdecl Scaleform::GFx::AS2::GAS_GlobalIsNaN(const Scaleform::GFx::AS2::FnCall *fn)
{
  char v1; // bl
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::AS2::Value *v3; // ecx
  Scaleform::GFx::AS2::Value *Result; // esi
  double v5; // [esp+8h] [ebp-8h]

  v1 = 1;
  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    v3 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v3 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    v5 = Scaleform::GFx::AS2::Value::ToNumber(v3, Env);
    if ( (HIDWORD(v5) & 0x7FF00000) != 0x7FF00000 || !((unsigned int)&loc_FFFFF & HIDWORD(v5) | LODWORD(v5)) )
      v1 = 0;
  }
  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->V.BooleanValue = v1;
  Result->T.Type = 2;
}
