void __cdecl Scaleform::GFx::AS2::RectangleProto::ContainsPoint(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v2; // ecx
  Scaleform::GFx::AS2::PointObject *v3; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::RectangleObject *p_pProto; // ebx
  bool v6; // al
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::Render::Point<double> pt; // [esp+38h] [ebp-50h] BYREF
  Scaleform::Render::Rect<double> r; // [esp+48h] [ebp-40h] BYREF
  Scaleform::GFx::AS2::Value params; // [esp+68h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v11; // [esp+78h] [ebp-10h] BYREF

  if ( fn->NArgs > 0 )
  {
    Env = fn->Env;
    v2 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v2 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    v3 = (Scaleform::GFx::AS2::PointObject *)Scaleform::GFx::AS2::Value::ToObject(v2, fn->Env);
    if ( v3 )
    {
      if ( !fn->ThisPtr || fn->ThisPtr->GetObjectType(fn->ThisPtr) != Object_Rectangle )
      {
        Scaleform::GFx::AS2::Environment::LogScriptError(
          fn->Env,
          "Error: Null or invalid 'this' is used for a method of %s class.\n",
          "Rectangle");
        return;
      }
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
        (char *)&params,
        0x10u,
        2,
        (void *(__thiscall *)(void *))Scaleform::GFx::AS2::Value::Value);
      Scaleform::GFx::AS2::RectangleObject::GetProperties(p_pProto, fn->Env, &r);
      Scaleform::GFx::AS2::GFxObject_GetPointProperties(fn->Env, v3, &params);
      if ( v3->GetObjectType(&v3->Scaleform::GFx::AS2::ObjectInterface) == Object_Point
        || params.T.Type && params.T.Type != 10 && !Scaleform::GFx::AS2::Value::IsUndefined(&v11) )
      {
        Scaleform::GFx::AS2::PointObject::GetProperties(v3, fn->Env, &pt);
        if ( !Scaleform::GFx::NumberUtil::IsNaN(pt.x) && !Scaleform::GFx::NumberUtil::IsNaN(pt.y) )
        {
          if ( pt.x == r.x2 )
            pt.x = pt.x + 1.0;
          if ( pt.y == r.y2 )
            pt.y = pt.y + 1.0;
          v6 = Scaleform::Render::Rect<double>::Contains(&r, &pt);
          Scaleform::GFx::AS2::Value::SetBool(fn->Result, v6);
          `vector destructor iterator'(
            (char *)&params,
            0x10u,
            2,
            (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
          return;
        }
        Result = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->T.Type = 2;
        Result->V.BooleanValue = 0;
      }
      `vector destructor iterator'(
        (char *)&params,
        0x10u,
        2,
        (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
    }
  }
}
