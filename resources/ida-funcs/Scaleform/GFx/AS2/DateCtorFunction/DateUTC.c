void __cdecl Scaleform::GFx::AS2::DateCtorFunction::DateUTC(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v2; // ecx
  long double v3; // st7
  int v4; // eax
  void *v5; // ecx
  int v6; // eax
  Scaleform::GFx::AS2::Environment *v7; // edx
  unsigned int v8; // eax
  Scaleform::GFx::AS2::Value *v9; // ecx
  int v10; // edi
  Scaleform::GFx::AS2::Value *v11; // eax
  Scaleform::GFx::AS2::Value *v12; // eax
  Scaleform::GFx::AS2::Value *v13; // eax
  Scaleform::GFx::AS2::Value *v14; // eax
  Scaleform::GFx::AS2::Value *v15; // eax
  Scaleform::GFx::AS2::Value *v16; // esi
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::Environment *v18; // [esp-4h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *v19; // [esp-4h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *v20; // [esp-4h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *v21; // [esp-4h] [ebp-2Ch]
  Scaleform::GFx::AS2::Environment *v22; // [esp-4h] [ebp-2Ch]
  int v23; // [esp+10h] [ebp-18h]
  double v24; // [esp+18h] [ebp-10h]
  double v25; // [esp+20h] [ebp-8h]

  if ( fn->NArgs < 2 )
  {
    Result = fn->Result;
    if ( Result->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->NV.NumberValue = 0.0;
    Result->T.Type = 3;
  }
  else
  {
    Env = fn->Env;
    v2 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v2 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    v3 = Scaleform::GFx::AS2::Value::ToNumber(v2, fn->Env);
    v4 = (int)v3;
    if ( (unsigned int)(int)v3 > 0x63 )
    {
      v5 = (void *)(int)v3;
      v23 = (int)v3;
    }
    else
    {
      v5 = (void *)(v4 + 1900);
      v23 = v4 + 1900;
    }
    v6 = Scaleform::GFx::AS2::StartOfYear(v5);
    v7 = fn->Env;
    v25 = (double)v6;
    v8 = fn->FirstArgBottomIndex - 1;
    v24 = 0.0;
    v9 = 0;
    if ( v8 <= 32 * (v7->Stack.Pages.Data.Size - 1) + v7->Stack.pCurrent - v7->Stack.pPageStart )
      v9 = &v7->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    v10 = (int)Scaleform::GFx::AS2::Value::ToNumber(v9, v7);
    if ( v10 )
      v25 = (double)dword_6F8914[12 * Scaleform::GFx::AS2::IsLeapYear(v23) + v10] + v25;
    if ( fn->NArgs >= 3 )
    {
      v18 = fn->Env;
      v11 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
      v25 = (double)((int)Scaleform::GFx::AS2::Value::ToNumber(v11, v18) - 1) + v25;
    }
    if ( fn->NArgs >= 4 )
    {
      v19 = fn->Env;
      v12 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
      v24 = Scaleform::GFx::AS2::Value::ToNumber(v12, v19) * 3600000.0 + 0.0;
    }
    if ( fn->NArgs >= 5 )
    {
      v20 = fn->Env;
      v13 = Scaleform::GFx::AS2::FnCall::Arg(fn, 4);
      v24 = Scaleform::GFx::AS2::Value::ToNumber(v13, v20) * 60000.0 + v24;
    }
    if ( fn->NArgs >= 6 )
    {
      v21 = fn->Env;
      v14 = Scaleform::GFx::AS2::FnCall::Arg(fn, 5);
      v24 = Scaleform::GFx::AS2::Value::ToNumber(v14, v21) * 1000.0 + v24;
    }
    if ( fn->NArgs >= 7 )
    {
      v22 = fn->Env;
      v15 = Scaleform::GFx::AS2::FnCall::Arg(fn, 6);
      v24 = Scaleform::GFx::AS2::Value::ToNumber(v15, v22) + v24;
    }
    v16 = fn->Result;
    if ( v16->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v16);
    v16->NV.NumberValue = v25 * 86400000.0 + v24;
    v16->T.Type = 3;
  }
}
