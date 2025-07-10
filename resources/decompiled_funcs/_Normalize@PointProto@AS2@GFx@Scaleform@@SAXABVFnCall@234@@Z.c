void __usercall Scaleform::GFx::AS2::PointProto::Normalize(char a1@<dil>, const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::PointObject *p_pProto; // edi
  const Scaleform::GFx::AS2::Value *v4; // eax
  long double v5; // st7
  Scaleform::GFx::AS2::Environment *Env; // [esp-Ch] [ebp-38h]
  long double v8; // [esp+4h] [ebp-28h]
  Scaleform::Render::Point<double> pt1; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value p; // [esp+1Ch] [ebp-10h] BYREF

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
      Scaleform::GFx::AS2::Value::Value(&p, v4);
      Scaleform::GFx::AS2::PointObject::GetProperties(p_pProto, fn->Env, &pt1);
      v8 = Scaleform::GFx::AS2::Value::ToNumber(&p, fn->Env);
      v5 = v8 / sqrt(pt1.x * pt1.x + pt1.y * pt1.y);
      Env = fn->Env;
      pt1.x = pt1.x * v5;
      pt1.y = v5 * pt1.y;
      Scaleform::GFx::AS2::PointObject::SetProperties(p_pProto, (int)p_pProto, (int)fn, Env, &pt1, a1);
      if ( p.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&p);
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
