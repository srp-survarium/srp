void __cdecl Scaleform::GFx::AS2::RectangleProto::Intersects(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  char v2; // bl
  Scaleform::GFx::AS2::Value *v3; // eax
  Scaleform::GFx::AS2::Object *v4; // edi
  long double v5; // st7
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::GFx::AS2::Environment *Env; // [esp-4h] [ebp-BCh]
  Scaleform::GFx::AS2::RectangleObject *p_pProto; // [esp+10h] [ebp-A8h]
  long double v9; // [esp+10h] [ebp-A8h]
  Scaleform::Render::Rect<double> pdest; // [esp+18h] [ebp-A0h] BYREF
  Scaleform::Render::Rect<double> r; // [esp+38h] [ebp-80h] BYREF
  Scaleform::Render::Rect<double> v12; // [esp+58h] [ebp-60h] BYREF
  Scaleform::GFx::AS2::Value v13; // [esp+78h] [ebp-40h] BYREF
  Scaleform::GFx::AS2::Value v14; // [esp+88h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value v15; // [esp+98h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v16; // [esp+A8h] [ebp-10h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Rectangle )
  {
    ThisPtr = fn->ThisPtr;
    v2 = 0;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::AS2::RectangleObject *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    if ( fn->NArgs > 0 )
    {
      Env = fn->Env;
      v3 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v4 = Scaleform::GFx::AS2::Value::ToObject(v3, Env);
      if ( v4 )
      {
        r.x1 = 0.0;
        r.y1 = 0.0;
        r.x2 = 0.0;
        r.y2 = 0.0;
        `vector constructor iterator'(
          (char *)&v13,
          0x10u,
          4,
          (void *(__thiscall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(p_pProto, fn->Env, &r);
        Scaleform::GFx::AS2::GFxObject_GetRectangleProperties(fn->Env, v4, &v13);
        pdest.x1 = Scaleform::GFx::AS2::Value::ToNumber(&v15, fn->Env);
        pdest.y1 = Scaleform::GFx::AS2::Value::ToNumber(&v16, fn->Env);
        v9 = Scaleform::GFx::AS2::Value::ToNumber(&v13, fn->Env);
        v5 = Scaleform::GFx::AS2::Value::ToNumber(&v14, fn->Env);
        v12.x1 = v9;
        v12.y1 = v5;
        v12.x2 = v9 + pdest.x1;
        v12.y2 = v5 + pdest.y1;
        pdest.x1 = 0.0;
        pdest.y1 = 0.0;
        pdest.x2 = 0.0;
        pdest.y2 = 0.0;
        if ( !Scaleform::GFx::AS2::IsRectValid(&r)
          || !Scaleform::GFx::AS2::IsRectValid(&v12)
          || (Scaleform::Render::Rect<double>::IntersectRect(&r, &pdest, &v12),
              v2 = 1,
              !Scaleform::GFx::AS2::IsRectValid(&pdest))
          || 0.0 == pdest.x2 - pdest.x1
          || pdest.y2 - pdest.y1 == 0.0 )
        {
          v2 = 0;
        }
        `vector destructor iterator'(
          (char *)&v13,
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
