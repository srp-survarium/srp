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
  Scaleform::Render::Rect<double> r; // [esp+20h] [ebp-90h] BYREF
  Scaleform::GFx::AS2::Value v10; // [esp+40h] [ebp-70h] BYREF
  Scaleform::GFx::AS2::Value v11; // [esp+50h] [ebp-60h] BYREF
  Scaleform::GFx::AS2::Value v12; // [esp+60h] [ebp-50h] BYREF
  Scaleform::GFx::AS2::Value v13; // [esp+70h] [ebp-40h] BYREF
  Scaleform::Render::Size<double> sz; // [esp+80h] [ebp-30h] BYREF
  Scaleform::Render::Rect<double> v15; // [esp+90h] [ebp-20h] BYREF

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
        r.x1 = 0.0;
        r.y1 = 0.0;
        r.x2 = 0.0;
        r.y2 = 0.0;
        `vector constructor iterator'(
          (char *)&v10,
          0x10u,
          4,
          (void *(__thiscall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(p_pProto, fn->Env, &r);
        Scaleform::GFx::AS2::GFxObject_GetRectangleProperties(fn->Env, v3, &v10);
        if ( !v10.T.Type
          || v10.T.Type == 10
          || !v11.T.Type
          || v11.T.Type == 10
          || Scaleform::GFx::AS2::Value::IsUndefined(&v12)
          || Scaleform::GFx::AS2::Value::IsUndefined(&v13) )
        {
          `vector destructor iterator'(
            (char *)&v10,
            0x10u,
            4,
            (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
        }
        else
        {
          sz.Width = Scaleform::GFx::AS2::Value::ToNumber(&v12, fn->Env);
          sz.Height = Scaleform::GFx::AS2::Value::ToNumber(&v13, fn->Env);
          y = Scaleform::GFx::AS2::Value::ToNumber(&v11, fn->Env);
          x = Scaleform::GFx::AS2::Value::ToNumber(&v10, fn->Env);
          Scaleform::Render::Rect<double>::Rect<double>(&v15, x, y, &sz);
          v7 = Scaleform::Render::Rect<double>::Contains(&r, &v15);
          Scaleform::GFx::AS2::Value::SetBool(fn->Result, v7);
          `vector destructor iterator'(
            (char *)&v10,
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
