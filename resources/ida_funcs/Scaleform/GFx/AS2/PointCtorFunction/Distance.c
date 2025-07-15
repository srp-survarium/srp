// local variable allocation has failed, the output may be wrong!
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
  Scaleform::GFx::AS2::Value d; // [esp+8h] [ebp-70h] OVERLAPPED BYREF
  Scaleform::GFx::AS2::Value xd; // [esp+18h] [ebp-60h] BYREF
  Scaleform::GFx::AS2::Value yd; // [esp+28h] [ebp-50h] BYREF
  Scaleform::GFx::AS2::Value o2[2]; // [esp+38h] [ebp-40h] BYREF
  Scaleform::GFx::AS2::Value o1[2]; // [esp+58h] [ebp-20h] BYREF

  *(double *)&d.T.Type = Scaleform::GFx::NumberUtil::NaN();
  Result = fn->Result;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2 = *(double *)&d.T.Type;
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
          (char *)o1,
          0x10u,
          2,
          (void *(__thiscall *)(void *))Scaleform::GFx::AS2::Value::Value);
        `vector constructor iterator'(
          (char *)o2,
          0x10u,
          2,
          (void *(__thiscall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::GFxObject_GetPointProperties(fn->Env, v7, o1);
        Scaleform::GFx::AS2::GFxObject_GetPointProperties(fn->Env, v11, o2);
        Scaleform::GFx::AS2::Value::Value(&xd, o2);
        Scaleform::GFx::AS2::Value::Sub(&xd, fn->Env, o1);
        Scaleform::GFx::AS2::Value::Mul(&xd, fn->Env, &xd);
        Scaleform::GFx::AS2::Value::Value(&yd, &o2[1]);
        Scaleform::GFx::AS2::Value::Sub(&yd, fn->Env, &o1[1]);
        Scaleform::GFx::AS2::Value::Mul(&yd, fn->Env, &yd);
        Scaleform::GFx::AS2::Value::Add(&xd, fn->Env, &yd);
        v15 = fn->Env;
        d.T.Type = 3;
        d.NV.NumberValue = sqrt(Scaleform::GFx::AS2::Value::ToNumber(&xd, v15));
        *(double *)&d.T.Type = Scaleform::GFx::AS2::Value::ToNumber(&d, fn->Env);
        v13 = fn->Result;
        if ( v13->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v13);
        v14 = *(double *)&d.T.Type;
        v13->T.Type = 3;
        v13->NV.NumberValue = v14;
        if ( yd.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&yd);
        if ( xd.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&xd);
        `vector destructor iterator'(
          (char *)o2,
          0x10u,
          2,
          (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
        `vector destructor iterator'(
          (char *)o1,
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
