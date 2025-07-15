void __cdecl Scaleform::GFx::AS2::PointCtorFunction::Distance(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // edi
  long double v2; // st7
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v4; // ecx
  Scaleform::GFx::AS2::Object *v5; // eax
  Scaleform::GFx::AS2::Environment *v6; // edx
  Scaleform::GFx::AS2::Object *v7; // edi
  unsigned int v8; // eax
  Scaleform::GFx::AS2::Value *v9; // ecx
  Scaleform::GFx::AS2::Object *v10; // eax
  Scaleform::GFx::AS2::Object *v11; // ebx
  Scaleform::GFx::AS2::Value *v12; // esi
  Scaleform::GFx::AS2::Value *v13; // esi
  long double v14; // st7
  Scaleform::GFx::AS2::Environment *v15; // [esp-8h] [ebp-80h]
  Scaleform::GFx::AS2::Value v16; // [esp+8h] [ebp-70h] BYREF
  Scaleform::GFx::AS2::Value v17; // [esp+18h] [ebp-60h] BYREF
  Scaleform::GFx::AS2::Value v18; // [esp+28h] [ebp-50h] BYREF
  Scaleform::GFx::AS2::Value v; // [esp+38h] [ebp-40h] BYREF
  Scaleform::GFx::AS2::Value v20; // [esp+48h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value params; // [esp+58h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v22; // [esp+68h] [ebp-10h] BYREF

  *(double *)&v16.T.Type = Scaleform::GFx::NumberUtil::NaN();
  Result = fn->Result;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2 = *(double *)&v16.T.Type;
  Result->T.Type = 3;
  Result->NV.NumberValue = v2;
  if ( fn->NArgs > 1 )
  {
    Env = fn->Env;
    v4 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v4 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    v5 = Scaleform::GFx::AS2::Value::ToObject(v4, Env);
    v6 = fn->Env;
    v7 = v5;
    v8 = fn->FirstArgBottomIndex - 1;
    v9 = 0;
    if ( v8 <= 32 * (v6->Stack.Pages.Data.Size - 1) + v6->Stack.pCurrent - v6->Stack.pPageStart )
      v9 = &v6->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    v10 = Scaleform::GFx::AS2::Value::ToObject(v9, fn->Env);
    v11 = v10;
    if ( v7 && v10 )
    {
      if ( v7->GetObjectType(&v7->Scaleform::GFx::AS2::ObjectInterface) == Object_Point
        || v11->GetObjectType(&v11->Scaleform::GFx::AS2::ObjectInterface) == Object_Point )
      {
        `vector constructor iterator'(
          (char *)&params,
          0x10u,
          2,
          (void *(__thiscall *)(void *))Scaleform::GFx::AS2::Value::Value);
        `vector constructor iterator'(
          (char *)&v,
          0x10u,
          2,
          (void *(__thiscall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::GFxObject_GetPointProperties(fn->Env, v7, &params);
        Scaleform::GFx::AS2::GFxObject_GetPointProperties(fn->Env, v11, &v);
        Scaleform::GFx::AS2::Value::Value(&v17, &v);
        Scaleform::GFx::AS2::Value::Sub(&v17, fn->Env, &params);
        Scaleform::GFx::AS2::Value::Mul(&v17, fn->Env, &v17);
        Scaleform::GFx::AS2::Value::Value(&v18, &v20);
        Scaleform::GFx::AS2::Value::Sub(&v18, fn->Env, &v22);
        Scaleform::GFx::AS2::Value::Mul(&v18, fn->Env, &v18);
        Scaleform::GFx::AS2::Value::Add(&v17, fn->Env, &v18);
        v15 = fn->Env;
        v16.T.Type = 3;
        v16.NV.NumberValue = sqrt(Scaleform::GFx::AS2::Value::ToNumber(&v17, v15));
        *(double *)&v16.T.Type = Scaleform::GFx::AS2::Value::ToNumber(&v16, fn->Env);
        v13 = fn->Result;
        if ( v13->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v13);
        v14 = *(double *)&v16.T.Type;
        v13->T.Type = 3;
        v13->NV.NumberValue = v14;
        if ( v18.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v18);
        if ( v17.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v17);
        `vector destructor iterator'(
          (char *)&v,
          0x10u,
          2,
          (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
        `vector destructor iterator'(
          (char *)&params,
          0x10u,
          2,
          (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      }
      else
      {
        v12 = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v12);
        v12->T.Type = 0;
      }
    }
  }
}
