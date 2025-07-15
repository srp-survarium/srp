void __cdecl Scaleform::GFx::AS2::RectangleProto::InflatePoint(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::RectangleObject *p_pProto; // edi
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::AS2::Object *v4; // ebx
  Scaleform::GFx::AS2::Environment *v5; // ecx
  Scaleform::GFx::AS2::Environment *v6; // edx
  Scaleform::GFx::AS2::Environment *Env; // [esp-Ch] [ebp-40h]
  Scaleform::Render::Point<double> pt; // [esp+4h] [ebp-30h] BYREF
  Scaleform::Render::Rect<double> r; // [esp+14h] [ebp-20h] BYREF

  if ( fn->NArgs > 0 )
  {
    if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Rectangle )
    {
      ThisPtr = fn->ThisPtr;
      if ( ThisPtr )
        p_pProto = (Scaleform::GFx::AS2::RectangleObject *)&ThisPtr[-2].pProto;
      else
        p_pProto = 0;
      Env = fn->Env;
      v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v4 = Scaleform::GFx::AS2::Value::ToObject(v3, Env);
      if ( v4 )
      {
        v5 = fn->Env;
        r.x1 = 0.0;
        r.y1 = 0.0;
        r.x2 = 0.0;
        r.y2 = 0.0;
        Scaleform::GFx::AS2::RectangleObject::GetProperties(p_pProto, v5, &r);
        Scaleform::GFx::AS2::GFxObject_GetPointProperties(fn->Env, v4, &pt);
        v6 = fn->Env;
        r.x1 = r.x1 - pt.x;
        r.x2 = pt.x + r.x2;
        r.y1 = r.y1 - pt.y;
        r.y2 = pt.y + r.y2;
        Scaleform::GFx::AS2::RectangleObject::SetProperties(p_pProto, v6, &r);
      }
      else
      {
        Scaleform::GFx::AS2::RectangleObject::SetProperties(
          p_pProto,
          (Scaleform::GFx::ASStringNode *)&fn->Env->StringContext,
          Rectangle_NaNParams);
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
}
