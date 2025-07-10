void __cdecl Scaleform::GFx::AS2::RectangleProto::Intersects(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  char v2; // bl
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::AS2::Object *v4; // edi
  long double v5; // st7
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::Environment *Env; // [esp-4h] [ebp-BCh]
  Scaleform::GFx::AS2::RectangleObject *pthis; // [esp+10h] [ebp-A8h]
  long double pthisa; // [esp+10h] [ebp-A8h]
  Scaleform::Render::Rect<double> r; // [esp+18h] [ebp-A0h] BYREF
  Scaleform::Render::Rect<double> o1; // [esp+38h] [ebp-80h] BYREF
  Scaleform::Render::Rect<double> o2; // [esp+58h] [ebp-60h] BYREF
  Scaleform::GFx::AS2::Value o2v[4]; // [esp+78h] [ebp-40h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Rectangle )
  {
    ThisPtr = fn->ThisPtr;
    v2 = 0;
    if ( ThisPtr )
      pthis = (Scaleform::GFx::AS2::RectangleObject *)&ThisPtr[-2].pProto;
    else
      pthis = 0;
    if ( fn->NArgs > 0 )
    {
      Env = fn->Env;
      v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v4 = Scaleform::GFx::AS2::Value::ToObject(v3, Env);
      if ( v4 )
      {
        o1.x1 = 0.0;
        o1.y1 = 0.0;
        o1.x2 = 0.0;
        o1.y2 = 0.0;
        `vector constructor iterator'(
          (char *)o2v,
          0x10u,
          4,
          (void *(__thiscall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(pthis, fn->Env, &o1);
        Scaleform::GFx::AS2::GFxObject_GetRectangleProperties(fn->Env, v4, o2v);
        r.x1 = Scaleform::GFx::AS2::Value::ToNumber(&o2v[2], fn->Env);
        r.y1 = Scaleform::GFx::AS2::Value::ToNumber(&o2v[3], fn->Env);
        pthisa = Scaleform::GFx::AS2::Value::ToNumber(o2v, fn->Env);
        v5 = Scaleform::GFx::AS2::Value::ToNumber(&o2v[1], fn->Env);
        o2.x1 = pthisa;
        o2.y1 = v5;
        o2.x2 = pthisa + r.x1;
        o2.y2 = v5 + r.y1;
        r.x1 = 0.0;
        r.y1 = 0.0;
        r.x2 = 0.0;
        r.y2 = 0.0;
        if ( !Scaleform::GFx::AS2::IsRectValid(&o1)
          || !Scaleform::GFx::AS2::IsRectValid(&o2)
          || (Scaleform::Render::Rect<double>::IntersectRect(&o1, &r, &o2), v2 = 1,
                                                                            !Scaleform::GFx::AS2::IsRectValid(&r))
          || 0.0 == r.x2 - r.x1
          || r.y2 - r.y1 == 0.0 )
        {
          v2 = 0;
        }
        `vector destructor iterator'(
          (char *)o2v,
          0x10u,
          4,
          (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      }
    }
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->V.BooleanValue = v2;
    Result->T.Type = 2;
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Rectangle");
  }
}
