void __cdecl Scaleform::GFx::AS2::RectangleProto::OffsetPoint(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::AS2::RectangleObject *p_pProto; // edi
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::AS2::Object *v4; // ebx
  Scaleform::GFx::AS2::Value *p_v; // ecx
  Scaleform::GFx::AS2::Environment *Env; // [esp-Ch] [ebp-90h]
  Scaleform::GFx::AS2::Environment *v7; // [esp-Ch] [ebp-90h]
  Scaleform::GFx::AS2::Environment *v8; // [esp-Ch] [ebp-90h]
  Scaleform::GFx::AS2::Value v; // [esp+4h] [ebp-80h] BYREF
  Scaleform::GFx::AS2::Value v10; // [esp+14h] [ebp-70h] BYREF
  Scaleform::GFx::AS2::Value params; // [esp+24h] [ebp-60h] BYREF
  Scaleform::GFx::AS2::Value v12; // [esp+34h] [ebp-50h] BYREF
  Scaleform::GFx::AS2::Value v13; // [esp+44h] [ebp-40h] BYREF
  Scaleform::GFx::AS2::Value v14; // [esp+54h] [ebp-30h] BYREF

  if ( fn->NArgs <= 0 )
    return;
  if ( !fn->ThisPtr || fn->ThisPtr->GetObjectType(fn->ThisPtr) != Object_Rectangle )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Rectangle");
    return;
  }
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
    p_pProto = (Scaleform::GFx::AS2::RectangleObject *)&ThisPtr[-2].pProto;
  else
    p_pProto = 0;
  Env = fn->Env;
  v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
  v4 = Scaleform::GFx::AS2::Value::ToObject(v3, Env);
  `vector constructor iterator'((char *)&v13, 0x10u, 4, (void *(__thiscall *)(void *))Scaleform::GFx::AS2::Value::Value);
  if ( v4 )
  {
    `vector constructor iterator'(
      (char *)&params,
      0x10u,
      2,
      (void *(__thiscall *)(void *))Scaleform::GFx::AS2::Value::Value);
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(fn->Env, v4, &params);
    if ( v4->GetObjectType(&v4->Scaleform::GFx::AS2::ObjectInterface) == Object_Point
      || params.T.Type && params.T.Type != 10 && !Scaleform::GFx::AS2::Value::IsUndefined(&v12) )
    {
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        p_pProto,
        (Scaleform::GFx::ASStringNode *)&fn->Env->StringContext,
        &v13);
      v7 = fn->Env;
      v10.T.Type = 3;
      *(double *)&v.T.Type = Scaleform::GFx::AS2::Value::ToNumber(&params, v7);
      v10.NV.NumberValue = Scaleform::GFx::AS2::Value::ToNumber(&v13, fn->Env) + *(double *)&v.T.Type;
      Scaleform::GFx::AS2::Value::operator=(&v13, &v10);
      if ( v10.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v10);
      v8 = fn->Env;
      v10.T.Type = 3;
      *(double *)&v.T.Type = Scaleform::GFx::AS2::Value::ToNumber(&v12, v8);
      v10.NV.NumberValue = Scaleform::GFx::AS2::Value::ToNumber(&v14, fn->Env) + *(double *)&v.T.Type;
      Scaleform::GFx::AS2::Value::operator=(&v14, &v10);
      if ( v10.T.Type < 5u )
        goto LABEL_27;
      p_v = &v10;
    }
    else
    {
      Scaleform::GFx::AS2::RectangleObject::GetProperties(
        p_pProto,
        (Scaleform::GFx::ASStringNode *)&fn->Env->StringContext,
        &v13);
      v.T.Type = 3;
      v.NV.NumberValue = Scaleform::GFx::NumberUtil::NaN();
      Scaleform::GFx::AS2::Value::operator=(&v13, &v);
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      v.T.Type = 3;
      v.NV.NumberValue = Scaleform::GFx::NumberUtil::NaN();
      Scaleform::GFx::AS2::Value::operator=(&v14, &v);
      if ( v.T.Type < 5u )
        goto LABEL_27;
      p_v = &v;
    }
    Scaleform::GFx::AS2::Value::DropRefs(p_v);
LABEL_27:
    Scaleform::GFx::AS2::RectangleObject::SetProperties(
      p_pProto,
      (Scaleform::GFx::ASStringNode *)&fn->Env->StringContext,
      &v13);
    `vector destructor iterator'(
      (char *)&params,
      0x10u,
      2,
      (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
    `vector destructor iterator'(
      (char *)&v13,
      0x10u,
      4,
      (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
    return;
  }
  Scaleform::GFx::AS2::RectangleObject::GetProperties(
    p_pProto,
    (Scaleform::GFx::ASStringNode *)&fn->Env->StringContext,
    &v13);
  v.T.Type = 3;
  v.NV.NumberValue = Scaleform::GFx::NumberUtil::NaN();
  Scaleform::GFx::AS2::Value::operator=(&v13, &v);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v.T.Type = 3;
  v.NV.NumberValue = Scaleform::GFx::NumberUtil::NaN();
  Scaleform::GFx::AS2::Value::operator=(&v14, &v);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  Scaleform::GFx::AS2::RectangleObject::SetProperties(
    p_pProto,
    (Scaleform::GFx::ASStringNode *)&fn->Env->StringContext,
    &v13);
  `vector destructor iterator'((char *)&v13, 0x10u, 4, (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
}
