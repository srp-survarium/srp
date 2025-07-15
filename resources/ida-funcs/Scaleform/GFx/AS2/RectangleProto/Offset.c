void __cdecl Scaleform::GFx::AS2::RectangleProto::Offset(const Scaleform::GFx::AS2::FnCall *fn)
{
  bool v1; // cc
  const Scaleform::GFx::AS2::Value *v2; // eax
  const Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::RectangleObject *p_pProto; // edi
  Scaleform::GFx::AS2::Value *v6; // esi
  int i; // edi
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // [esp-Ch] [ebp-8Ch]
  Scaleform::GFx::AS2::Environment *Env; // [esp-8h] [ebp-88h]
  Scaleform::GFx::AS2::Environment *v10; // [esp-8h] [ebp-88h]
  long double v11; // [esp+8h] [ebp-78h]
  long double v12; // [esp+8h] [ebp-78h]
  Scaleform::GFx::AS2::Value v; // [esp+10h] [ebp-70h] BYREF
  Scaleform::GFx::AS2::Value dy; // [esp+20h] [ebp-60h] BYREF
  Scaleform::GFx::AS2::Value v15; // [esp+30h] [ebp-50h] BYREF
  Scaleform::GFx::AS2::Value o1[4]; // [esp+40h] [ebp-40h] BYREF
  _UNKNOWN *retaddr; // [esp+80h] [ebp+0h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Rectangle )
  {
    v1 = fn->NArgs <= 0;
    v15.T.Type = 0;
    dy.T.Type = 0;
    if ( !v1 )
    {
      v2 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      Scaleform::GFx::AS2::Value::operator=(&v15, v2);
      if ( fn->NArgs > 1 )
      {
        v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        Scaleform::GFx::AS2::Value::operator=(&dy, v3);
      }
    }
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::AS2::RectangleObject *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    p_StringContext = &fn->Env->StringContext;
    o1[0].T.Type = 0;
    o1[1].T.Type = 0;
    o1[2].T.Type = 0;
    o1[3].T.Type = 0;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(p_pProto, p_StringContext, o1);
    Env = fn->Env;
    v.T.Type = 3;
    v11 = Scaleform::GFx::AS2::Value::ToNumber(o1, Env);
    v.NV.NumberValue = Scaleform::GFx::AS2::Value::ToNumber(&v15, fn->Env) + v11;
    Scaleform::GFx::AS2::Value::operator=(o1, &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    v10 = fn->Env;
    v.T.Type = 3;
    v12 = Scaleform::GFx::AS2::Value::ToNumber(&o1[1], v10);
    v.NV.NumberValue = Scaleform::GFx::AS2::Value::ToNumber(&dy, fn->Env) + v12;
    Scaleform::GFx::AS2::Value::operator=(&o1[1], &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    Scaleform::GFx::AS2::RectangleObject::SetProperties(p_pProto, &fn->Env->StringContext, o1);
    v6 = (Scaleform::GFx::AS2::Value *)&retaddr;
    for ( i = 3; i >= 0; --i )
    {
      --v6;
      if ( v6->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v6);
    }
    if ( dy.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&dy);
    if ( v15.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v15);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Rectangle");
  }
}
