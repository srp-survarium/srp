void __usercall Scaleform::GFx::AS2::PointProto::Normalize(char a1@<dil>, const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::PointObject *p_pProto; // edi
  const Scaleform::GFx::AS2::Value *v4; // eax
  long double v5; // st7
  Scaleform::GFx::AS2::Environment *Env; // [esp-Ch] [ebp-38h]
  long double v8; // [esp+4h] [ebp-28h]
  Scaleform::Render::Point<double> pt; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v10; // [esp+1Ch] [ebp-10h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Point )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::AS2::PointObject *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    if ( fn->NArgs <= 0 )
    {
      Scaleform::GFx::AS2::PointObject::SetProperties(p_pProto, &fn->Env->StringContext, Point_NanParams);
    }
    else
    {
      v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      Scaleform::GFx::AS2::Value::Value(&v10, v4);
      Scaleform::GFx::AS2::PointObject::GetProperties(p_pProto, fn->Env, &pt);
      v8 = Scaleform::GFx::AS2::Value::ToNumber(&v10, fn->Env);
      v5 = v8 / sqrt(pt.x * pt.x + pt.y * pt.y);
      Env = fn->Env;
      pt.x = pt.x * v5;
      pt.y = v5 * pt.y;
      Scaleform::GFx::AS2::PointObject::SetProperties(p_pProto, (int)p_pProto, (int)fn, Env, &pt, a1);
      if ( v10.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v10);
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Point");
  }
}
