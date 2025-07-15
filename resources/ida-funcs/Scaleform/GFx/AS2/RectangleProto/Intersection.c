void __cdecl Scaleform::GFx::AS2::RectangleProto::Intersection(const Scaleform::GFx::AS2::FnCall *fn)
{
  bool v1; // zf
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::RectangleObject *p_pProto; // ebx
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::Object *v5; // edi
  long double v6; // st7
  long double v7; // st7
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::RectangleObject *v9; // eax
  Scaleform::GFx::AS2::RectangleObject *v10; // eax
  Scaleform::GFx::AS2::RectangleObject *v11; // edi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-8h] [ebp-CCh]
  Scaleform::Render::Rect<double> pdest; // [esp+Ch] [ebp-B8h] BYREF
  long double v15; // [esp+2Ch] [ebp-98h]
  long double v16; // [esp+34h] [ebp-90h]
  long double v17; // [esp+3Ch] [ebp-88h]
  Scaleform::Render::Rect<double> v18; // [esp+44h] [ebp-80h] BYREF
  Scaleform::Render::Rect<double> r; // [esp+64h] [ebp-60h] BYREF
  Scaleform::GFx::AS2::Value v20; // [esp+84h] [ebp-40h] BYREF
  Scaleform::GFx::AS2::Value v21; // [esp+94h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value v22; // [esp+A4h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v23; // [esp+B4h] [ebp-10h] BYREF

  pdest.x1 = 0.0;
  pdest.y1 = 0.0;
  v1 = fn->ThisPtr == 0;
  pdest.x2 = 0.0;
  pdest.y2 = 0.0;
  if ( v1 || fn->ThisPtr->GetObjectType(fn->ThisPtr) != Object_Rectangle )
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
  if ( fn->NArgs > 0 )
  {
    Env = fn->Env;
    v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
    v5 = Scaleform::GFx::AS2::Value::ToObject(v4, Env);
    if ( v5 )
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
      Scaleform::GFx::AS2::GFxObject_GetRectangleProperties(fn->Env, v5, &v20);
      v15 = Scaleform::GFx::AS2::Value::ToNumber(&v22, fn->Env);
      v16 = Scaleform::GFx::AS2::Value::ToNumber(&v23, fn->Env);
      v17 = Scaleform::GFx::AS2::Value::ToNumber(&v20, fn->Env);
      v6 = Scaleform::GFx::AS2::Value::ToNumber(&v21, fn->Env);
      v18.x1 = v17;
      v18.y1 = v6;
      v18.x2 = v17 + v15;
      v18.y2 = v6 + v16;
      if ( Scaleform::GFx::AS2::IsRectValid(&v18)
        && (Scaleform::Render::Rect<double>::IntersectRect(&r, &pdest, &v18), Scaleform::GFx::AS2::IsRectValid(&pdest)) )
      {
        v7 = 0.0;
        if ( 0.0 != pdest.x2 - pdest.x1 && pdest.y2 - pdest.y1 != 0.0 )
          goto LABEL_15;
      }
      else
      {
        v7 = 0.0;
      }
      pdest.x1 = v7;
      pdest.y1 = v7;
      pdest.x2 = v7;
      pdest.y2 = v7;
LABEL_15:
      `vector destructor iterator'(
        (char *)&v20,
        0x10u,
        4,
        (void (__thiscall *)(void *))Scaleform::GFx::AS2::Value::~Value);
    }
  }
  pHeap = fn->Env->StringContext.pContext->pHeap;
  v9 = (Scaleform::GFx::AS2::RectangleObject *)pHeap->Alloc(pHeap, 52u, 0);
  if ( v9 )
  {
    Scaleform::GFx::AS2::RectangleObject::RectangleObject(v9, fn->Env);
    v11 = v10;
  }
  else
  {
    v11 = 0;
  }
  Scaleform::GFx::AS2::RectangleObject::SetProperties(v11, fn->Env, &pdest);
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v11);
  if ( v11 )
  {
    RefCount = v11->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v11->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
    }
  }
}
