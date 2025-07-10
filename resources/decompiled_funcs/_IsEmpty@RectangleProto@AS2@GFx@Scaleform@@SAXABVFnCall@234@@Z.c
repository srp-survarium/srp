void __cdecl Scaleform::GFx::AS2::RectangleProto::IsEmpty(const Scaleform::GFx::AS2::FnCall *fn)
{
  char v1; // bl
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::RectangleObject *p_pProto; // ecx
  long double v4; // st7
  long double v5; // st7
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::Value *v7; // esi
  int i; // edi
  Scaleform::GFx::AS2::ASStringContext *v; // [esp+0h] [ebp-60h]
  double v10; // [esp+10h] [ebp-50h]
  long double v11; // [esp+10h] [ebp-50h]
  Scaleform::GFx::AS2::Value params[4]; // [esp+20h] [ebp-40h] BYREF
  _UNKNOWN *retaddr; // [esp+60h] [ebp+0h] BYREF

  v1 = 0;
  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Rectangle )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::AS2::RectangleObject *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    v = &fn->Env->StringContext;
    params[0].T.Type = 0;
    params[1].T.Type = 0;
    params[2].T.Type = 0;
    params[3].T.Type = 0;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(p_pProto, v, params);
    v10 = Scaleform::GFx::AS2::Value::ToNumber(&params[2], fn->Env);
    if ( (HIDWORD(v10) & 0x7FF00000) == 0x7FF00000 && (unsigned int)&loc_FFFFF & HIDWORD(v10) | LODWORD(v10)
      || (v4 = Scaleform::GFx::AS2::Value::ToNumber(&params[3], fn->Env), Scaleform::GFx::NumberUtil::IsNaN(v4))
      || (Scaleform::GFx::AS2::Value::ToNumber(params, fn->Env),
          Scaleform::GFx::AS2::Value::ToNumber(&params[1], fn->Env),
          v11 = Scaleform::GFx::AS2::Value::ToNumber(&params[2], fn->Env),
          v5 = Scaleform::GFx::AS2::Value::ToNumber(&params[3], fn->Env),
          v11 <= 0.0)
      || v5 <= 0.0 )
    {
      v1 = 1;
    }
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 2;
    Result->V.BooleanValue = v1;
    v7 = (Scaleform::GFx::AS2::Value *)&retaddr;
    for ( i = 3; i >= 0; --i )
    {
      --v7;
      if ( v7->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v7);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Rectangle");
  }
}
