void __cdecl Scaleform::GFx::AS2::RectangleProto::ContainsRectangle(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v2; // ecx
  Scaleform::GFx::AS2::Object *v3; // ebx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::RectangleObject *p_pProto; // edi
  long double x; // st7
  bool v7; // al
  long double y; // [esp+8h] [ebp-A8h]
  Scaleform::Render::Rect<double> r1; // [esp+20h] [ebp-90h] BYREF
  Scaleform::GFx::AS2::Value r2v[4]; // [esp+40h] [ebp-70h] BYREF
  Scaleform::Render::Size<double> sz; // [esp+80h] [ebp-30h] BYREF
  Scaleform::Render::Rect<double> r2; // [esp+90h] [ebp-20h] BYREF

  if ( fn->NArgs > 0 )
  {
    Env = fn->Env;
    v2 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v2 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    v3 = Scaleform::GFx::AS2::Value::ToObject(v2, Env);
    if ( v3 )
    {
      if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Rectangle )
      {
        ThisPtr = fn->ThisPtr;
        if ( ThisPtr )
          p_pProto = (Scaleform::GFx::AS2::RectangleObject *)&ThisPtr[-2].pProto;
        else
          p_pProto = 0;
        r1.x1 = 0.0;
        r1.y1 = 0.0;
        r1.x2 = 0.0;
        r1.y2 = 0.0;
        `vector constructor iterator'(
          (char *)r2v,
          0x10u,
          4,
          (void *(__thiscall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(p_pProto, fn->Env, &r1);
        Scaleform::GFx::AS2::GFxObject_GetRectangleProperties(fn->Env, v3, r2v);
        if ( !r2v[0].T.Type
          || r2v[0].T.Type == 10
          || !r2v[1].T.Type
          || r2v[1].T.Type == 10
          || Scaleform::GFx::AS2::Value::IsUndefined(&r2v[2])
          || Scaleform::GFx::AS2::Value::IsUndefined(&r2v[3]) )
        {
          `vector destructor iterator'(
            (char *)r2v,
            0x10u,
            4,
            (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
        }
        else
        {
          sz.Width = Scaleform::GFx::AS2::Value::ToNumber(&r2v[2], fn->Env);
          sz.Height = Scaleform::GFx::AS2::Value::ToNumber(&r2v[3], fn->Env);
          y = Scaleform::GFx::AS2::Value::ToNumber(&r2v[1], fn->Env);
          x = Scaleform::GFx::AS2::Value::ToNumber(r2v, fn->Env);
          Scaleform::Render::Rect<double>::Rect<double>(&r2, x, y, &sz);
          v7 = Scaleform::Render::Rect<double>::Contains(&r1, &r2);
          Scaleform::GFx::AS2::Value::SetBool(fn->Result, v7);
          `vector destructor iterator'(
            (char *)r2v,
            0x10u,
            4,
            (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
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
}
