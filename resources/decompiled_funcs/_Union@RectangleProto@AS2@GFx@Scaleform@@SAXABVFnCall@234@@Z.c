void __cdecl Scaleform::GFx::AS2::RectangleProto::Union(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::RectangleObject *v3; // eax
  Scaleform::GFx::AS2::RectangleObject *v4; // eax
  Scaleform::GFx::AS2::RectangleObject *v5; // edi
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::AS2::Object *v7; // ebx
  long double v8; // st7
  long double v; // st7
  long double v10; // st7
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *v_4; // [esp+Ch] [ebp-104h]
  Scaleform::GFx::AS2::RectangleObject *pthis; // [esp+58h] [ebp-B8h]
  long double pthisa; // [esp+58h] [ebp-B8h]
  Scaleform::Render::Rect<double> ret; // [esp+60h] [ebp-B0h] BYREF
  long double v16; // [esp+80h] [ebp-90h]
  long double v17; // [esp+88h] [ebp-88h]
  Scaleform::Render::Rect<double> o1; // [esp+90h] [ebp-80h] BYREF
  Scaleform::Render::Rect<double> o2; // [esp+B0h] [ebp-60h] BYREF
  Scaleform::GFx::AS2::Value o2v[4]; // [esp+D0h] [ebp-40h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Rectangle )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      pthis = (Scaleform::GFx::AS2::RectangleObject *)&ThisPtr[-2].pProto;
    else
      pthis = 0;
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v3 = (Scaleform::GFx::AS2::RectangleObject *)pHeap->Alloc(pHeap, 52u, 0);
    if ( v3 )
    {
      Scaleform::GFx::AS2::RectangleObject::RectangleObject(v3, fn->Env);
      v5 = v4;
    }
    else
    {
      v5 = 0;
    }
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v5);
    if ( fn->NArgs <= 0 )
    {
      Scaleform::GFx::AS2::RectangleObject::SetProperties(v5, &fn->Env->StringContext, Rectangle_NaNParams);
    }
    else
    {
      ret.x1 = Scaleform::GFx::NumberUtil::NaN();
      ret.y1 = Scaleform::GFx::NumberUtil::NaN();
      ret.x2 = Scaleform::GFx::NumberUtil::NaN();
      ret.y2 = Scaleform::GFx::NumberUtil::NaN();
      v_4 = fn->Env;
      v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v7 = Scaleform::GFx::AS2::Value::ToObject(v6, v_4);
      if ( v7 )
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
        Scaleform::GFx::AS2::GFxObject_GetRectangleProperties(fn->Env, v7, o2v);
        v16 = Scaleform::GFx::AS2::Value::ToNumber(&o2v[2], fn->Env);
        v17 = Scaleform::GFx::AS2::Value::ToNumber(&o2v[3], fn->Env);
        pthisa = Scaleform::GFx::AS2::Value::ToNumber(o2v, fn->Env);
        v8 = Scaleform::GFx::AS2::Value::ToNumber(&o2v[1], fn->Env);
        o2.x1 = pthisa;
        o2.y1 = v8;
        o2.x2 = pthisa + v16;
        o2.y2 = v8 + v17;
        Scaleform::GFx::AS2::ValidateRect(&o1);
        Scaleform::GFx::AS2::ValidateRect(&o2);
        Scaleform::Render::Rect<double>::UnionRect(&o1, &ret, &o2);
        v = Scaleform::GFx::AS2::Value::ToNumber(o2v, fn->Env);
        if ( Scaleform::GFx::NumberUtil::IsNaN(v) )
          ret.x1 = Scaleform::GFx::NumberUtil::NaN();
        v10 = Scaleform::GFx::AS2::Value::ToNumber(&o2v[1], fn->Env);
        if ( Scaleform::GFx::NumberUtil::IsNaN(v10) )
          ret.y1 = Scaleform::GFx::NumberUtil::NaN();
        `vector destructor iterator'(
          (char *)o2v,
          0x10u,
          4,
          (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      }
      Scaleform::GFx::AS2::RectangleObject::SetProperties(v5, fn->Env, &ret);
    }
    if ( v5 )
    {
      RefCount = v5->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v5->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
      }
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
