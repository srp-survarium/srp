void __cdecl Scaleform::GFx::AS2::RectangleProto::InflatePoint(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::RectangleObject *p_pProto; // edi
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::AS2::Object *v4; // ebx
  Scaleform::GFx::AS2::Environment *v5; // ecx
  Scaleform::GFx::AS2::Environment *v6; // edx
  Scaleform::GFx::AS2::Environment *Env; // [esp-Ch] [ebp-40h]
  Scaleform::Render::Point<double> o2; // [esp+4h] [ebp-30h] BYREF
  Scaleform::Render::Rect<double> o1; // [esp+14h] [ebp-20h] BYREF

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
        o1.x1 = 0.0;
        o1.y1 = 0.0;
        o1.x2 = 0.0;
        o1.y2 = 0.0;
        Scaleform::GFx::AS2::RectangleObject::GetProperties(p_pProto, v5, &o1);
        Scaleform::GFx::AS2::GFxObject_GetPointProperties(fn->Env, v4, &o2);
        v6 = fn->Env;
        o1.x1 = o1.x1 - o2.x;
        o1.x2 = o2.x + o1.x2;
        o1.y1 = o1.y1 - o2.y;
        o1.y2 = o2.y + o1.y2;
        Scaleform::GFx::AS2::RectangleObject::SetProperties(p_pProto, v6, &o1);
      }
      else
      {
        Scaleform::GFx::AS2::RectangleObject::SetProperties(p_pProto, &fn->Env->StringContext, Rectangle_NaNParams);
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
