void __cdecl Scaleform::GFx::AS2::GAS_GlobalIsFinite(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::AS2::Value *v2; // ecx
  long double v3; // st7
  Scaleform::GFx::AS2::Value *v4; // esi
  Scaleform::GFx::AS2::Value *Result; // esi
  double v6; // [esp+4h] [ebp-8h]

  if ( fn->NArgs < 1 )
    goto LABEL_9;
  Env = fn->Env;
  v2 = 0;
  if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
    v2 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
  if ( (v3 = Scaleform::GFx::AS2::Value::ToNumber(v2, Env), v6 = v3, (HIDWORD(v6) & 0x7FF00000) == 0x7FF00000)
    && (unsigned int)&loc_FFFFF & HIDWORD(v6) | LODWORD(v6)
    || v3 == -INFINITY
    || v3 == INFINITY )
  {
LABEL_9:
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->V.BooleanValue = 0;
    Result->T.Type = 2;
  }
  else
  {
    v4 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v4);
    v4->V.BooleanValue = 1;
    v4->T.Type = 2;
  }
}
