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
  long double v9; // st7
  long double v10; // st7
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp+Ch] [ebp-104h]
  Scaleform::GFx::AS2::RectangleObject *p_pProto; // [esp+58h] [ebp-B8h]
  long double v14; // [esp+58h] [ebp-B8h]
  Scaleform::Render::Rect<double> pdest; // [esp+60h] [ebp-B0h] BYREF
  long double v16; // [esp+80h] [ebp-90h]
  long double v17; // [esp+88h] [ebp-88h]
  Scaleform::Render::Rect<double> r; // [esp+90h] [ebp-80h] BYREF
  Scaleform::Render::Rect<double> v19; // [esp+B0h] [ebp-60h] BYREF
  Scaleform::GFx::AS2::Value v20; // [esp+D0h] [ebp-40h] BYREF
  Scaleform::GFx::AS2::Value v21; // [esp+E0h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value v22; // [esp+F0h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v23; // [esp+100h] [ebp-10h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Rectangle )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::AS2::RectangleObject *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
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
      Scaleform::GFx::AS2::RectangleObject::SetProperties(
        v5,
        (Scaleform::GFx::ASStringNode *)&fn->Env->StringContext,
        Rectangle_NaNParams);
    }
    else
    {
      pdest.x1 = Scaleform::GFx::NumberUtil::NaN();
      pdest.y1 = Scaleform::GFx::NumberUtil::NaN();
      pdest.x2 = Scaleform::GFx::NumberUtil::NaN();
      pdest.y2 = Scaleform::GFx::NumberUtil::NaN();
      Env = fn->Env;
      v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v7 = Scaleform::GFx::AS2::Value::ToObject(v6, Env);
      if ( v7 )
      {
        r.x1 = 0.0;
        r.y1 = 0.0;
        r.x2 = 0.0;
        r.y2 = 0.0;
        `vector constructor iterator'(
          (char *)&v20,
          0x10u,
          4,
          (void *(__thiscall *)(void *))Scaleform::GFx::AS2::Value::Value);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(p_pProto, fn->Env, &r);
        Scaleform::GFx::AS2::GFxObject_GetRectangleProperties(fn->Env, v7, &v20);
        v16 = Scaleform::GFx::AS2::Value::ToNumber(&v22, fn->Env);
        v17 = Scaleform::GFx::AS2::Value::ToNumber(&v23, fn->Env);
        v14 = Scaleform::GFx::AS2::Value::ToNumber(&v20, fn->Env);
        v8 = Scaleform::GFx::AS2::Value::ToNumber(&v21, fn->Env);
        v19.x1 = v14;
        v19.y1 = v8;
        v19.x2 = v14 + v16;
        v19.y2 = v8 + v17;
        Scaleform::GFx::AS2::ValidateRect(&r);
        Scaleform::GFx::AS2::ValidateRect(&v19);
        Scaleform::Render::Rect<double>::UnionRect(&r, &pdest, &v19);
        v9 = Scaleform::GFx::AS2::Value::ToNumber(&v20, fn->Env);
        if ( Scaleform::GFx::NumberUtil::IsNaN(v9) )
          pdest.x1 = Scaleform::GFx::NumberUtil::NaN();
        v10 = Scaleform::GFx::AS2::Value::ToNumber(&v21, fn->Env);
        if ( Scaleform::GFx::NumberUtil::IsNaN(v10) )
          pdest.y1 = Scaleform::GFx::NumberUtil::NaN();
        `vector destructor iterator'(
          (char *)&v20,
          0x10u,
          4,
          (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
      }
      Scaleform::GFx::AS2::RectangleObject::SetProperties(v5, fn->Env, &pdest);
    }
    if ( v5 )
    {
      RefCount = v5->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
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
