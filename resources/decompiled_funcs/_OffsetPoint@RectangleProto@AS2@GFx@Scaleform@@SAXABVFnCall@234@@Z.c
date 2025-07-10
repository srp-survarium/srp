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
  Scaleform::GFx::AS2::Value o2v[2]; // [esp+24h] [ebp-60h] BYREF
  Scaleform::GFx::AS2::Value o1v[4]; // [esp+44h] [ebp-40h] BYREF

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
  `vector constructor iterator'((char *)o1v, 0x10u, 4, (void *(__thiscall *)(void *))Scaleform::GFx::AS2::Value::Value);
  if ( v4 )
  {
    `vector constructor iterator'(
      (char *)o2v,
      0x10u,
      2,
      (void *(__thiscall *)(void *))Scaleform::GFx::AS2::Value::Value);
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(fn->Env, v4, o2v);
    if ( v4->GetObjectType(&v4->Scaleform::GFx::AS2::ObjectInterface) == Object_Point
      || o2v[0].T.Type && o2v[0].T.Type != 10 && !Scaleform::GFx::AS2::Value::IsUndefined(&o2v[1]) )
    {
      Scaleform::GFx::AS2::RectangleObject::GetProperties(p_pProto, &fn->Env->StringContext, o1v);
      v7 = fn->Env;
      v10.T.Type = 3;
      *(double *)&v.T.Type = Scaleform::GFx::AS2::Value::ToNumber(o2v, v7);
      v10.NV.NumberValue = Scaleform::GFx::AS2::Value::ToNumber(o1v, fn->Env) + *(double *)&v.T.Type;
      Scaleform::GFx::AS2::Value::operator=(o1v, &v10);
      if ( v10.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v10);
      v8 = fn->Env;
      v10.T.Type = 3;
      *(double *)&v.T.Type = Scaleform::GFx::AS2::Value::ToNumber(&o2v[1], v8);
      v10.NV.NumberValue = Scaleform::GFx::AS2::Value::ToNumber(&o1v[1], fn->Env) + *(double *)&v.T.Type;
      Scaleform::GFx::AS2::Value::operator=(&o1v[1], &v10);
      if ( v10.T.Type < 5u )
        goto LABEL_27;
      p_v = &v10;
    }
    else
    {
      Scaleform::GFx::AS2::RectangleObject::GetProperties(p_pProto, &fn->Env->StringContext, o1v);
      v.T.Type = 3;
      v.NV.NumberValue = Scaleform::GFx::NumberUtil::NaN();
      Scaleform::GFx::AS2::Value::operator=(o1v, &v);
      if ( v.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v);
      v.T.Type = 3;
      v.NV.NumberValue = Scaleform::GFx::NumberUtil::NaN();
      Scaleform::GFx::AS2::Value::operator=(&o1v[1], &v);
      if ( v.T.Type < 5u )
        goto LABEL_27;
      p_v = &v;
    }
    Scaleform::GFx::AS2::Value::DropRefs(p_v);
LABEL_27:
    Scaleform::GFx::AS2::RectangleObject::SetProperties(p_pProto, &fn->Env->StringContext, o1v);
    `vector destructor iterator'((char *)o2v, 0x10u, 2, (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
    `vector destructor iterator'((char *)o1v, 0x10u, 4, (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
    return;
  }
  Scaleform::GFx::AS2::RectangleObject::GetProperties(p_pProto, &fn->Env->StringContext, o1v);
  v.T.Type = 3;
  v.NV.NumberValue = Scaleform::GFx::NumberUtil::NaN();
  Scaleform::GFx::AS2::Value::operator=(o1v, &v);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v.T.Type = 3;
  v.NV.NumberValue = Scaleform::GFx::NumberUtil::NaN();
  Scaleform::GFx::AS2::Value::operator=(&o1v[1], &v);
  if ( v.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  Scaleform::GFx::AS2::RectangleObject::SetProperties(p_pProto, &fn->Env->StringContext, o1v);
  `vector destructor iterator'((char *)o1v, 0x10u, 4, (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
}
