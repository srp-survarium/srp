void __usercall Scaleform::GFx::AS2::PointProto::Offset(char a1@<dil>, const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::PointObject *p_pProto; // edi
  bool v4; // cc
  const Scaleform::GFx::AS2::Value *v5; // eax
  const Scaleform::GFx::AS2::Value *v6; // eax
  long double v7; // st7
  long double v8; // st7
  Scaleform::GFx::AS2::Environment *v9; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-8h] [ebp-3Ch]
  Scaleform::Render::Point<double> pt; // [esp+4h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value v13; // [esp+14h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v14; // [esp+24h] [ebp-10h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Point )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::AS2::PointObject *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    v4 = fn->NArgs <= 0;
    v14.T.Type = 0;
    v13.T.Type = 0;
    if ( !v4 )
    {
      v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      Scaleform::GFx::AS2::Value::operator=(&v14, v5);
      if ( fn->NArgs > 1 )
      {
        v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        Scaleform::GFx::AS2::Value::operator=(&v13, v6);
      }
    }
    Scaleform::GFx::AS2::PointObject::GetProperties(p_pProto, fn->Env, &pt);
    v7 = Scaleform::GFx::AS2::Value::ToNumber(&v14, fn->Env);
    Env = fn->Env;
    pt.x = v7 + pt.x;
    v8 = Scaleform::GFx::AS2::Value::ToNumber(&v13, Env);
    v9 = fn->Env;
    pt.y = v8 + pt.y;
    Scaleform::GFx::AS2::PointObject::SetProperties(p_pProto, (int)p_pProto, (int)fn, v9, &pt, a1);
    if ( v13.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v13);
    if ( v14.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v14);
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Point");
  }
}
