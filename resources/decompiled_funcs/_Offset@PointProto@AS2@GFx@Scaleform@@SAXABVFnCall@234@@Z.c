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
  Scaleform::Render::Point<double> pt1; // [esp+4h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value dy; // [esp+14h] [ebp-20h] BYREF
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
    dy.T.Type = 0;
    if ( !v4 )
    {
      v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      Scaleform::GFx::AS2::Value::operator=(&v14, v5);
      if ( fn->NArgs > 1 )
      {
        v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        Scaleform::GFx::AS2::Value::operator=(&dy, v6);
      }
    }
    Scaleform::GFx::AS2::PointObject::GetProperties(p_pProto, fn->Env, &pt1);
    v7 = Scaleform::GFx::AS2::Value::ToNumber(&v14, fn->Env);
    Env = fn->Env;
    pt1.x = v7 + pt1.x;
    v8 = Scaleform::GFx::AS2::Value::ToNumber(&dy, Env);
    v9 = fn->Env;
    pt1.y = v8 + pt1.y;
    Scaleform::GFx::AS2::PointObject::SetProperties(p_pProto, (int)p_pProto, (int)fn, v9, &pt1, a1);
    if ( dy.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&dy);
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
